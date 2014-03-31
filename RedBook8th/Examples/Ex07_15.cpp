/*
* Ex07_15.cpp
*
* Created on: Mar 6, 2014
* Author: Andrew Zhabura
*/

#include "Ex07_15.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

#define FRUSTUM_DEPTH       800.0f
#define DEPTH_TEXTURE_SIZE  2048

Ex07_15::Ex07_15()
	: OGLWindow("Example07_15", "Example 7.15 (M)")
{
}

Ex07_15::~Ex07_15()
{
	glUseProgram(0);
	glDeleteProgram(render_light_prog);
	glDeleteProgram(render_scene_prog);
	glDeleteBuffers(1, &ground_vbo);
	glDeleteVertexArrays(1, &ground_vao);
}

void Ex07_15::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo light_shaders[] =
	{
		{ GL_VERTEX_SHADER, "Shaders/shadowmap_shadow.vs.glsl" },
		{ GL_FRAGMENT_SHADER, "Shaders/shadowmap_shadow.fs.glsl" },
		{ GL_NONE }
	};

	render_light_prog = LoadShaders(light_shaders);

	// Get the location of the projetion_matrix uniform
	render_light_uniforms.model_view_projection_matrix = glGetUniformLocation(render_light_prog, "model_view_projection_matrix");

	// Create the program for rendering the scene from the viewer's position
	ShaderInfo scene_shaders[] =
	{
		{ GL_VERTEX_SHADER, "Shaders/shadowmap_scene.vs.glsl" },
		{ GL_FRAGMENT_SHADER, "Shaders/shadowmap_scene.fs.glsl" },
		{ GL_NONE }
	};

	render_scene_prog = LoadShaders(scene_shaders);

	// Get the locations of all the uniforms in the program
	render_scene_uniforms.model_matrix = glGetUniformLocation(render_scene_prog, "model_matrix");
	render_scene_uniforms.view_matrix = glGetUniformLocation(render_scene_prog, "view_matrix");
	render_scene_uniforms.projection_matrix = glGetUniformLocation(render_scene_prog, "projection_matrix");
	render_scene_uniforms.shadow_matrix = glGetUniformLocation(render_scene_prog, "shadow_matrix");
	render_scene_uniforms.light_position = glGetUniformLocation(render_scene_prog, "light_position");
	render_scene_uniforms.material_ambient = glGetUniformLocation(render_scene_prog, "material_ambient");
	render_scene_uniforms.material_diffuse = glGetUniformLocation(render_scene_prog, "material_diffuse");
	render_scene_uniforms.material_specular = glGetUniformLocation(render_scene_prog, "material_specular");
	render_scene_uniforms.material_specular_power = glGetUniformLocation(render_scene_prog, "material_specular_power");

	// Set the depth texture uniform to unit 0
	glUseProgram(render_scene_prog);
	glUniform1i(glGetUniformLocation(render_scene_prog, "depth_texture"), 0);

	// Create a depth texture
	glGenTextures(1, &depth_texture);
	glBindTexture(GL_TEXTURE_2D, depth_texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32, DEPTH_TEXTURE_SIZE, DEPTH_TEXTURE_SIZE, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_2D, 0);

	// Create FBO to render depth into
	glGenFramebuffers(1, &depth_fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, depth_fbo);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, depth_texture, 0);
	glDrawBuffer(GL_NONE);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	// Upload geometry for the ground plane
	static const float ground_vertices[] =
	{
		-500.0f, -50.0f, -500.0f, 1.0f,
		-500.0f, -50.0f,  500.0f, 1.0f,
		500.0f, -50.0f,  500.0f, 1.0f,
		500.0f, -50.0f, -500.0f, 1.0f,
	};

	static const float ground_normals[] =
	{
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	glGenVertexArrays(1, &ground_vao);
	glGenBuffers(1, &ground_vbo);
	glBindVertexArray(ground_vao);
	glBindBuffer(GL_ARRAY_BUFFER, ground_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(ground_vertices) + sizeof(ground_normals), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(ground_vertices), ground_vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(ground_vertices), sizeof(ground_normals), ground_normals);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (const GLvoid *)sizeof(ground_vertices));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	// Load the object
	object.LoadFromVBM("Media/armadillo_low.vbm", 0, 1, 2);
}

void Ex07_15::Display()
{
	float t = float(GetTickCount() & 0xFFFF) / float(0xFFFF);
	static float q = 0.0f;
	static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

	float r = t - int(t);

	vmath::vec3 light_position = vmath::vec3(sinf(r * 6.0f * 3.141592f) * 300.0f, 200.0f, cosf(r * 4.0f * 3.141592f) * 100.0f + 250.0f);

	// Setup
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	float aspect = float(getHeight()) / getWidth();

	// Matrices for rendering the scene
	vmath::mat4 scene_model_matrix = vmath::rotate(t * 720.0f, Y);
	vmath::mat4 scene_view_matrix = vmath::translate(-300.0f, -300.0f, -500.0f);
	vmath::mat4 scene_projection_matrix = vmath::frustum(-1.0f, 1.0f, -aspect, aspect, 1.0f, FRUSTUM_DEPTH);
	const vmath::mat4 scale_bias_matrix = vmath::mat4(
		vmath::vec4(0.1f, 0.0f, 0.0f, 0.0f),
		vmath::vec4(0.0f, 0.1f, 0.0f, 0.0f),
		vmath::vec4(0.0f, 0.0f, 0.1f, 0.0f),
		vmath::vec4(0.5f, 0.5f, 0.5f, 1.0f)
		);

	// Matrices used when rendering from the light's position
	vmath::mat4 light_view_matrix = lookat(light_position, vmath::vec3(0.0f), Y);
	vmath::mat4 light_projection_matrix(vmath::frustum(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, FRUSTUM_DEPTH));

	// Now we render from the light's position into the depth buffer.
	// Select the appropriate program
	glUseProgram(render_light_prog);
	glUniformMatrix4fv(render_light_uniforms.model_view_projection_matrix, 1, GL_FALSE, light_projection_matrix * light_view_matrix * scene_model_matrix);

	// Bind the 'depth only' FBO and set the viewport to the size of the depth texture
	glBindFramebuffer(GL_FRAMEBUFFER, depth_fbo);
	glViewport(0, 0, DEPTH_TEXTURE_SIZE, DEPTH_TEXTURE_SIZE);

	// Clear
	glClearDepth(1.0f);
	glClear(GL_DEPTH_BUFFER_BIT);

	// Enable polygon offset to resolve depth-fighting isuses
	glEnable(GL_POLYGON_OFFSET_FILL);
	glPolygonOffset(2.0f, 4.0f);
	// Draw from the light's point of view
	DrawScene(true);
	glDisable(GL_POLYGON_OFFSET_FILL);

	// Restore the default framebuffer and field of view
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glViewport(0, 0, current_width, current_height);

	// Now render from the viewer's position
	glUseProgram(render_scene_prog);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	// Setup all the matrices
	glUniformMatrix4fv(render_scene_uniforms.model_matrix, 1, GL_FALSE, scene_model_matrix);
	glUniformMatrix4fv(render_scene_uniforms.view_matrix, 1, GL_FALSE, scene_view_matrix);
	glUniformMatrix4fv(render_scene_uniforms.projection_matrix, 1, GL_FALSE, scene_projection_matrix);
	glUniformMatrix4fv(render_scene_uniforms.shadow_matrix, 1, GL_FALSE, scale_bias_matrix * light_projection_matrix * light_view_matrix);
	glUniform3fv(render_scene_uniforms.light_position, 1, light_position);

	// Bind the depth texture
	glBindTexture(GL_TEXTURE_2D, depth_texture);
	glGenerateMipmap(GL_TEXTURE_2D);

	// Draw
	DrawScene(false);

	glFlush();
}

void Ex07_15::DrawScene(bool depth_only)
{
	// Set material properties for the object
	if (!depth_only)
	{
		glUniform3fv(render_scene_uniforms.material_ambient, 1, vmath::vec3(0.1f, 0.0f, 0.5f));
		glUniform3fv(render_scene_uniforms.material_diffuse, 1, vmath::vec3(0.3f, 0.2f, 0.8f));
		glUniform3fv(render_scene_uniforms.material_specular, 1, vmath::vec3(1.0f, 1.0f, 1.0f));
		glUniform1f(render_scene_uniforms.material_specular_power, 25.0f);
	}

	// Draw the object
	object.Render();

	// Set material properties for the ground
	if (!depth_only)
	{
		glUniform3fv(render_scene_uniforms.material_ambient, 1, vmath::vec3(0.1f, 0.1f, 0.1f));
		glUniform3fv(render_scene_uniforms.material_diffuse, 1, vmath::vec3(0.1f, 0.5f, 0.1f));
		glUniform3fv(render_scene_uniforms.material_specular, 1, vmath::vec3(0.1f, 0.1f, 0.1f));
		glUniform1f(render_scene_uniforms.material_specular_power, 3.0f);
	}

	// Draw the ground
	glBindVertexArray(ground_vao);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glBindVertexArray(0);
}

void Ex07_15::keyboard( unsigned char key, int x, int y )
{
	switch( key ) {
	case 'M': 
		for (int i = 0; i < c_repeat; ++i)
			Display();
		break;
	default:
		OGLWindow::keyboard(key, x, y);
		break;
	}
}
