/*
* Ex12_01.cpp
*
* Created on: Apr 17, 2014
* Author: Andrew Zhabura
*/

#include "Ex12_01.h"

#include "GL/LoadShaders.h"

Ex12_01::Ex12_01()
	: OGLWindow("Example12_01", "Example 12.1")
{
}

Ex12_01::~Ex12_01()
{
	glUseProgram(0);
	glDeleteProgram(compute_prog);
	glDeleteProgram(render_prog);
	glDeleteTextures(1, &output_image);
	glDeleteVertexArrays(1, &render_vao);
}

void Ex12_01::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  compShaders[] = {
		{ GL_COMPUTE_SHADER, "Shaders/sh12_01.comp" },
		{ GL_NONE, NULL }
	};

	compute_prog = LoadShaders( compShaders );

	glLinkProgram(compute_prog);

	// This is the texture that the compute program will write into
	glGenTextures(1, &output_image);
	glBindTexture(GL_TEXTURE_2D, output_image);
	glTexStorage2D(GL_TEXTURE_2D, 8, GL_RGBA32F, 256, 256);

	// Now create a simple program to visualize the result
	ShaderInfo  rendShaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh12_01.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh12_01.frag" },
		{ GL_NONE, NULL }
	};

	render_prog = LoadShaders( rendShaders );

	glLinkProgram(render_prog);

	// This is the VAO containing the data to draw the quad (including its associated VBO)
	glGenVertexArrays(1, &render_vao);
	glBindVertexArray(render_vao);
	glEnableVertexAttribArray(0);
	glGenBuffers(1, &render_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, render_vbo);
	static const float verts[] =
	{
		-1.0f, -1.0f, 0.5f, 1.0f,
		1.0f, -1.0f, 0.5f, 1.0f,
		1.0f,  1.0f, 0.5f, 1.0f,
		-1.0f,  1.0f, 0.5f, 1.0f,
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);
}

void Ex12_01::Display()
{
	// Activate the compute program and bind the output texture image
	glUseProgram(compute_prog);
	glBindImageTexture(0, output_image, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);
	glDispatchCompute(8, 16, 1);

	// Now bind the texture for rendering _from_
	glBindTexture(GL_TEXTURE_2D, output_image);

	// Clear, select the rendering program and draw a full screen quad
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(render_prog);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glFlush();
}
