/*
* Ex06_01.cpp
*
* Created on: Feb 14, 2014
* Author: Andrew Zhabura
*/

#include "Ex06_01.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"

Ex06_01::Ex06_01()
	: OGLWindow("Example06_01", "Example 6.1")
{
}

Ex06_01::~Ex06_01()
{
	glUseProgram(0);
	glDeleteProgram(base_prog);
	glDeleteTextures(1, &tex);
	glDeleteVertexArrays(1, &tex);
}

void Ex06_01::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  base_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh06_01.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh06_01.frag" },
		{ GL_NONE, NULL }
	};

	base_prog = LoadShaders( base_shaders );

	glGenBuffers(1, &quad_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, quad_vbo);

	static const GLfloat quad_data[] =
	{
		0.75f, -0.75f,
		-0.75f, -0.75f,
		-0.75f, 0.75f,
		0.75f, 0.75f,

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

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexStorage2D(GL_TEXTURE_2D, 4, GL_RGBA8, 8, 8);

	static const unsigned char texture_data[] =
	{
		0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF
	};

	glTexSubImage2D(GL_TEXTURE_2D,
		0,
		0, 0,
		8, 8,
		GL_RED, GL_UNSIGNED_BYTE,
		texture_data);

	static const GLint swizzles[] = { GL_RED, GL_RED, GL_RED, GL_ONE };
	glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzles);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glGenerateMipmap(GL_TEXTURE_2D);
}

void Ex06_01::Display()
{
	float t = float(GetTickCount() & 0x3FFF) / float(0x3FFF);
	static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_CULL_FACE);
	glUseProgram(base_prog);

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glFlush();
}
