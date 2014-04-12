/*
* Ex11_29.cpp
*
* Created on: Apr 12, 2014
* Author: Andrew Zhabura
*/

#include "Ex11_29.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

#define MAX_FRAMEBUFFER_WIDTH 2048
#define MAX_FRAMEBUFFER_HEIGHT 2048

Ex11_29::Ex11_29()
	: OGLWindow("Example11_29", "Example 11.29")
{
}

Ex11_29::~Ex11_29()
{
	glUseProgram(0);
	glDeleteProgram(render_scene_prog);
	glDeleteBuffers(1, &quad_vbo);
	glDeleteVertexArrays(1, &quad_vao);
}

void Ex11_29::InitGL()
{
	if (! LoadGL() )
		return;
	
	GLuint * data;
	render_scene_prog = -1;

	// Create the program for rendering the scene from the viewer's position
	ShaderInfo scene_shaders[] =
	{
		{ GL_VERTEX_SHADER, "Shaders/build_lists.vs.glsl" },
		{ GL_FRAGMENT_SHADER, "Shaders/build_lists.fs.glsl" },
		{ GL_NONE }
	};

	if (render_scene_prog != -1)
		glDeleteProgram(render_scene_prog);

	render_scene_prog = LoadShaders(scene_shaders);

	render_scene_uniforms.model_matrix = glGetUniformLocation(render_scene_prog, "model_matrix");
	render_scene_uniforms.view_matrix = glGetUniformLocation(render_scene_prog, "view_matrix");
	render_scene_uniforms.projection_matrix = glGetUniformLocation(render_scene_prog, "projection_matrix");
	render_scene_uniforms.aspect = glGetUniformLocation(render_scene_prog, "aspect");
	render_scene_uniforms.time = glGetUniformLocation(render_scene_prog, "time");

	ShaderInfo resolve_shaders[] =
	{
		{ GL_VERTEX_SHADER, "Shaders/resolve_lists.vs.glsl" },
		{ GL_FRAGMENT_SHADER, "Shaders/resolve_lists.fs.glsl" },
		{ GL_NONE }
	};

	resolve_program = LoadShaders(resolve_shaders);

	// Create head pointer texture
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &head_pointer_texture);
	glBindTexture(GL_TEXTURE_2D, head_pointer_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_R32UI, MAX_FRAMEBUFFER_WIDTH, MAX_FRAMEBUFFER_HEIGHT, 0, GL_RED_INTEGER, GL_UNSIGNED_INT, NULL);
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindImageTexture(0, head_pointer_texture, 0, GL_TRUE, 0, GL_READ_WRITE, GL_R32UI);

	// Create buffer for clearing the head pointer texture
	glGenBuffers(1, &head_pointer_clear_buffer);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, head_pointer_clear_buffer);
	glBufferData(GL_PIXEL_UNPACK_BUFFER, MAX_FRAMEBUFFER_WIDTH * MAX_FRAMEBUFFER_HEIGHT * sizeof(GLuint), NULL, GL_STATIC_DRAW);
	data = (GLuint *)glMapBuffer(GL_PIXEL_UNPACK_BUFFER, GL_WRITE_ONLY);
	memset(data, 0x00, MAX_FRAMEBUFFER_WIDTH * MAX_FRAMEBUFFER_HEIGHT * sizeof(GLuint));
	glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);

	// Create the atomic counter buffer
	glGenBuffers(1, &atomic_counter_buffer);
	glBindBuffer(GL_ATOMIC_COUNTER_BUFFER, atomic_counter_buffer);
	glBufferData(GL_ATOMIC_COUNTER_BUFFER, sizeof(GLuint), NULL, GL_DYNAMIC_COPY);

	// Create the linked list storage buffer
	glGenBuffers(1, &linked_list_buffer);
	glBindBuffer(GL_TEXTURE_BUFFER, linked_list_buffer);
	glBufferData(GL_TEXTURE_BUFFER, MAX_FRAMEBUFFER_WIDTH * MAX_FRAMEBUFFER_HEIGHT * 3 * sizeof(vmath::vec4), NULL, GL_DYNAMIC_COPY);
	glBindBuffer(GL_TEXTURE_BUFFER, 0);

	// Bind it to a texture (for use as a TBO)
	glGenTextures(1, &linked_list_texture);
	glBindTexture(GL_TEXTURE_BUFFER, linked_list_texture);
	glTexBuffer(GL_TEXTURE_BUFFER, GL_RGBA32UI, linked_list_buffer);
	glBindTexture(GL_TEXTURE_BUFFER, 0);

	glBindImageTexture(1, linked_list_texture, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32UI);

	glGenVertexArrays(1, &quad_vao);
	glBindVertexArray(quad_vao);

	static const GLfloat quad_verts[] =
	{
		-0.0f, -1.0f,
		1.0f, -1.0f,
		-0.0f,  1.0f,
		1.0f,  1.0f,
	};

	glGenBuffers(1, &quad_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, quad_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quad_verts), quad_verts, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);

	glClearDepth(1.0f);

	object.LoadFromVBM("Media/torus.vbm", 0, 1, 2);
}

void Ex11_29::Display()
{
	float aspect = float(getHeight()) / getWidth();

	float t = float(GetTickCount() & 0x3FFFF) / float(0x3FFFF);

	GLuint * data;

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Reset atomic counter
	glBindBufferBase(GL_ATOMIC_COUNTER_BUFFER, 0, atomic_counter_buffer);
	data = (GLuint *)glMapBuffer(GL_ATOMIC_COUNTER_BUFFER, GL_WRITE_ONLY);
	data[0] = 0;
	glUnmapBuffer(GL_ATOMIC_COUNTER_BUFFER);

	// Clear head-pointer image
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, head_pointer_clear_buffer);
	glBindTexture(GL_TEXTURE_2D, head_pointer_texture);
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, current_width, current_height, GL_RED_INTEGER, GL_UNSIGNED_INT, NULL);
	glBindTexture(GL_TEXTURE_2D, 0);

	// Bind head-pointer image for read-write
	glBindImageTexture(0, head_pointer_texture, 0, GL_FALSE, 0, GL_READ_WRITE, GL_R32UI);

	// Bind linked-list buffer for write
	glBindImageTexture(1, linked_list_texture, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32UI);

	glUseProgram(render_scene_prog);

	vmath::mat4 model_matrix = vmath::translate(0.0f, 0.0f, -20.0f) *
		vmath::rotate(t * 360.0f, 0.0f, 0.0f, 1.0f) *
		vmath::rotate(t * 435.0f, 0.0f, 1.0f, 0.0f) *
		vmath::rotate(t * 275.0f, 1.0f, 0.0f, 0.0f);
	vmath::mat4 view_matrix = vmath::mat4::identity();
	vmath::mat4 projection_matrix = vmath::frustum(-1.0f, 1.0f, -aspect, aspect, 1.0f, 500.0f) * vmath::translate(0.0f, 0.0f, -50.0f);

	glUniformMatrix4fv(render_scene_uniforms.model_matrix, 1, GL_FALSE, model_matrix);
	glUniformMatrix4fv(render_scene_uniforms.view_matrix, 1, GL_FALSE, view_matrix);
	glUniformMatrix4fv(render_scene_uniforms.projection_matrix, 1, GL_FALSE, projection_matrix);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	object.Render();

	glDisable(GL_BLEND);

	glBindVertexArray(quad_vao);
	glUseProgram(resolve_program);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glFlush();
}