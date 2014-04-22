/*
* Ex06_10.cpp
*
* Created on: Feb 16, 2014
* Author: Andrew Zhabura
*/

#include "Ex06_10.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"

Ex06_10::Ex06_10()
	: OGLWindow("Example06_10", "Example 6.10 (M)")
{
}

Ex06_10::~Ex06_10()
{
	glUseProgram(0);
	glDeleteProgram(base_prog);
	glDeleteTextures(1, &tex_checkerboard);
	glDeleteVertexArrays(1, &tex_checkerboard);
	glDeleteBuffers(1, &buf_checkerboard);
}

void Ex06_10::InitGL()
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
		4.0f, 0.0f,
		4.0f, 4.0f,
		0.0f, 4.0f
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
	glGenBuffers(1, &buf_checkerboard);

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

	// First, bind a buffer to the GL_PIXEL_UNPACK_BUFFER binding
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, buf_checkerboard);
	// Place our source data into the buffer
	glBufferData(GL_PIXEL_UNPACK_BUFFER,
		sizeof(tex_checkerboard_data),
		tex_checkerboard_data,
		GL_STATIC_DRAW);
	// Bind the texture (possibly creating it)
	glBindTexture(GL_TEXTURE_2D, tex_checkerboard);
	// Allocate storage for the texture data
	glTexStorage2D(GL_TEXTURE_2D, 4, GL_R8, 8, 8);
	// Specify the data for the texture
	glTexSubImage2D(GL_TEXTURE_2D, // target
		0, // First mipmap level
		0, 0, // x and y offset
		8, 8, // width and height
		GL_RED, // Format
		GL_UNSIGNED_BYTE, // Type
		NULL); // data(an offset into buffer)

	static const GLint swizzles[] = { GL_RED, GL_RED, GL_RED, GL_ONE };
	glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzles);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glGenerateMipmap(GL_TEXTURE_2D);
}

void Ex06_10::Display()
{
	static int i = 0;

	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_CULL_FACE);
	glUseProgram(base_prog);

	static const GLenum wrap_modes[] = { GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER, GL_REPEAT, GL_MIRRORED_REPEAT };

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_modes[i]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_modes[i]);

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	Swap();

	++i;
	if (i >= 4)
		i = 0;
}

void Ex06_10::keyboard( unsigned char key, int x, int y )
{
	switch( key ) {
	case 'M': {
		Display();
			  } break;
	default:
		OGLWindow::keyboard(key, x, y);
		break;
	}
}