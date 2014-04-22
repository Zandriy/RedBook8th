/*
* Ex12_11.cpp
*
* Created on: Apr 17, 2014
* Author: Andrew Zhabura
*/

#include "Ex12_11.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

#include "GL/LoadShaders.h"

Ex12_11::Ex12_11()
	: OGLWindow("Example12_11", "Example 12.11")
{
}

Ex12_11::~Ex12_11()
{
	glUseProgram(0);
	glDeleteProgram(compute_prog);
	glDeleteProgram(render_prog);
	glDeleteTextures(1, &output_image);
	glDeleteVertexArrays(1, &render_vao);
}

void Ex12_11::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  compShaders[] = {
		{ GL_COMPUTE_SHADER, "Shaders/sh12_11.comp" },
		{ GL_NONE, NULL }
	};

	compute_prog = LoadShaders( compShaders );

	glLinkProgram(compute_prog);

	// Load a texture to process
	input_image = vglLoadTexture("Media/TantolundenCube.dds", 0, NULL);

	glGenTextures(1, &intermediate_image);
	glBindTexture(GL_TEXTURE_2D, intermediate_image);
	glTexStorage2D(GL_TEXTURE_2D, 8, GL_RGBA32F, 1024, 1024);

	// This is the texture that the compute program will write into
	glGenTextures(1, &output_image);
	glBindTexture(GL_TEXTURE_2D, output_image);
	glTexStorage2D(GL_TEXTURE_2D, 8, GL_RGBA32F, 1024, 1024);

	// Now create a simple program to visualize the result
	ShaderInfo  rendShaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh12_11.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh12_11.frag" },
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

void Ex12_11::Display()
{
	// Activate the compute program and bind the output texture image
	glUseProgram(compute_prog);
	glBindImageTexture(0, input_image, 0, GL_FALSE, 0, GL_READ_ONLY, GL_RGBA32F);
	glBindImageTexture(1, intermediate_image, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);
	glDispatchCompute(1, 1024, 1);

	glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);

	glBindImageTexture(0, intermediate_image, 0, GL_FALSE, 0, GL_READ_ONLY, GL_RGBA32F);
	glBindImageTexture(1, output_image, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);
	glDispatchCompute(1, 1024, 1);

	// Now bind the texture for rendering _from_
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, output_image);

	// Clear, select the rendering program and draw a full screen quad
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(render_prog);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	Swap();
}
