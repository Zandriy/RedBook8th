/*
* Ex06_18.cpp
*
* Created on: Feb 16, 2014
* Author: Andrew Zhabura
*/

#include "Ex06_18.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

Ex06_18::Ex06_18()
	: OGLWindow("Example06_18", "Example 6.18 (M)")
{
}

Ex06_18::~Ex06_18()
{
	glUseProgram(0);
	glDeleteProgram(skybox_prog);
	glDeleteProgram(object_prog);
	glDeleteTextures(1, &tex);
	glDeleteVertexArrays(1, &tex);
}

void Ex06_18::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  skybox_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/skybox.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/skybox.frag" },
		{ GL_NONE, NULL }
	};

	skybox_prog = LoadShaders( skybox_shaders );

	ShaderInfo  object_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/object_shader.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/object_shader.frag" },
		{ GL_NONE, NULL }
	};

	object_prog = LoadShaders( object_shaders );

	glLinkProgram(object_prog);

	glGenBuffers(1, &cube_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, cube_vbo);

	static const GLfloat cube_vertices[] =
	{
		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f,  1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f,  1.0f,  1.0f
	};

	static const GLushort cube_indices[] =
	{
		0, 1, 2, 3, 6, 7, 4, 5,         // First strip
		2, 6, 0, 4, 1, 5, 3, 7          // Second strip
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &cube_element_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cube_element_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_indices), cube_indices, GL_STATIC_DRAW);

	skybox_rotate_loc = glGetUniformLocation(skybox_prog, "tc_rotate");
	object_mat_mvp_loc = glGetUniformLocation(object_prog, "mat_mvp");
	object_mat_mv_loc = glGetUniformLocation(object_prog, "mat_mv");

	vglImageData image;

	tex = vglLoadTexture("Media/TantolundenCube.dds", 0, &image);

	GLenum e;

	e = glGetError();

	vglUnloadImage(&image);

	object.LoadFromVBM("Media/torus.vbm", 0, 1, 2);
}

void Ex06_18::Display()
{
	static const unsigned int start_time = GetTickCount() - 10000;
	float t = float((GetTickCount() - start_time)) / float(0x3FFF);
	static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

	vmath::mat4 tc_matrix(vmath::mat4::identity());

	glClearColor(0.0f, 0.25f, 0.3f, 1.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDisable(GL_CULL_FACE);
	glUseProgram(skybox_prog);

	glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

	float aspect = float(getHeight()) / getWidth();

	// tc_matrix = vmath::rotate(80.0f * 3.0f * t, Y);// * vmath::rotate(22.0f, Z);
	tc_matrix = vmath::perspective(35.0f, 1.0f / aspect, 0.1f, 100.0f) * tc_matrix;

	glUniformMatrix4fv(skybox_rotate_loc, 1, GL_FALSE, tc_matrix);
	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cube_element_buffer);

	glDrawElements(GL_TRIANGLE_STRIP, 8, GL_UNSIGNED_SHORT, NULL);
	glDrawElements(GL_TRIANGLE_STRIP, 8, GL_UNSIGNED_SHORT, BUFFER_OFFSET(8 * sizeof(GLushort)));

	glUseProgram(object_prog);

	tc_matrix = vmath::translate(vmath::vec3(0.0f, 0.0f, -70.0f)) *
		vmath::rotate(80.0f * 3.0f * t, Y) * vmath::rotate(50.0f * 3.0f * t, Z);

	glUniformMatrix4fv(object_mat_mv_loc, 1, GL_FALSE, tc_matrix);
	tc_matrix = vmath::perspective(35.0f, 1.0f / aspect, 0.1f, 100.0f) * tc_matrix;
	glUniformMatrix4fv(object_mat_mvp_loc, 1, GL_FALSE, tc_matrix);

	glClear(GL_DEPTH_BUFFER_BIT);

	object.Render();

	glFlush();
}

void Ex06_18::keyboard( unsigned char key, int x, int y )
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
