/*
* Ex06_02.cpp
*
* Created on: Feb 14, 2014
* Author: Andrew Zhabura
*/

#include "Ex06_02.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"

Ex06_02::Ex06_02()
	: OGLWindow("Example06_02", "Example 6.2 (M)")
{
}

Ex06_02::~Ex06_02()
{
	glUseProgram(0);
	glDeleteProgram(base_prog);
	glDeleteTextures(1, &tex_checkerboard);
	glDeleteVertexArrays(1, &tex_checkerboard);
	glDeleteTextures(1, &tex_color);
	glDeleteVertexArrays(1, &tex_color);
}

void Ex06_02::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  base_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh06_02.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh06_02.frag" },
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

	glGenTextures(1, &tex_checkerboard);
	glBindTexture(GL_TEXTURE_2D, tex_checkerboard);
	glTexStorage2D(GL_TEXTURE_2D, 4, GL_RGBA8, 8, 8);

	// The following is an 8x8 checkerboard pattern using
	// GL_RED, GL_UNSIGNED_BYTE data.
	static const unsigned char tex_checkerboard_data[] =
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
		tex_checkerboard_data);

	static const GLint swizzles[] = { GL_RED, GL_RED, GL_RED, GL_ONE };
	glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzles);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glGenerateMipmap(GL_TEXTURE_2D);

	glGenTextures(1, &tex_color);
	glBindTexture(GL_TEXTURE_2D, tex_color);
	glTexStorage2D(GL_TEXTURE_2D, 2, GL_RGBA32F, 2, 2);

	// The following data represents a 2x2 texture with red,
	// green, blue, and yellow texels represented as GL_RGBA,
	// GL_FLOAT data.
	static const GLfloat tex_color_data[] =
	{
		// Red texel				Green texel
		1.0f, 0.0f, 0.0f, 1.0f,		0.0f, 1.0f, 0.0f, 1.0f,
		// Blue texel				Yellow texel
		0.0f, 0.0f, 1.0f, 1.0f,		1.0f, 1.0f, 0.0f, 1.0f
	};

	glTexSubImage2D(GL_TEXTURE_2D, // target
		0, // First mipmap level
		0, 0, // x and y offset
		2, 2, // width and height
		GL_RGBA, GL_FLOAT, // format and type
		tex_color_data); // data

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glGenerateMipmap(GL_TEXTURE_2D);
}

void Ex06_02::Display()
{
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_CULL_FACE);
	glUseProgram(base_prog);

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	Swap();
}

void Ex06_02::keyboard( unsigned char key, int x, int y )
{
	switch( key ) {
	case 'M': {
		static bool checker = false;
		checker = !checker;

		if (checker)
			glBindTexture(GL_TEXTURE_2D, tex_checkerboard);
		else
			glBindTexture(GL_TEXTURE_2D, tex_color);

		Display();
			  } break;
	default:
		OGLWindow::keyboard(key, x, y);
		break;
	}
}