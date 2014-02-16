/*
* Ex06_16.cpp
*
* Created on: Feb 16, 2014
* Author: Andrew Zhabura
*/

#include "Ex06_16.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

Ex06_16::Ex06_16()
	: OGLWindow("Example06_16", "Example 6.16")
{
}

Ex06_16::~Ex06_16()
{
	glUseProgram(0);
	glDeleteProgram(base_prog);
	glDeleteTextures(1, &tex);
	glDeleteVertexArrays(1, &tex);
}

void Ex06_16::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  base_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh06_16.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh06_16.frag" },
		{ GL_NONE, NULL }
	};

	base_prog = LoadShaders( base_shaders );

	glGenBuffers(1, &quad_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, quad_vbo);

	static const GLfloat quad_data[] =
	{
		1.0f, -1.0f,
		-1.0f, -1.0f,
		-1.0f, 1.0f,
		1.0f, 1.0f,

		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(quad_data), quad_data, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(8 * sizeof(float)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glLinkProgram(base_prog);

	char buf[1024];
	glGetProgramInfoLog(base_prog, 1024, NULL, buf);

	tc_rotate_loc = glGetUniformLocation(base_prog, "tc_rotate");

	vglImageData image;

	tex = vglLoadTexture("Media/cloud.dds", 0, &image);

	glTexParameteri(image.target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	vglUnloadImage(&image);
}

void Ex06_16::Display()
{
	static const unsigned int start_time = GetTickCount() - 10000;
	float t = float((GetTickCount() - start_time)) / float(0x3FFF);
	static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

	vmath::mat4 tc_matrix(vmath::mat4::identity());

	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_CULL_FACE);
	glUseProgram(base_prog);

	tc_matrix = vmath::rotate(t * 170.0f, X) *
		vmath::rotate(t * 137.0f, Y) *
		vmath::rotate(t * 93.0f, Z);

	glUniformMatrix4fv(tc_rotate_loc, 1, GL_FALSE, tc_matrix);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glFlush();
}

void Ex06_16::keyboard( unsigned char key, int x, int y )
{
	switch( key ) {
	case 'M': 
		for (int i = 0; i < 5000; ++i)
			Display();
		break;
	default:
		OGLWindow::keyboard(key, x, y);
		break;
	}
}
