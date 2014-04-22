/*
* Ex06_mipmap.cpp
*
* Created on: Feb 16, 2014
* Author: Andrew Zhabura
*/

#include "Ex06_mipmap.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

Ex06_mipmap::Ex06_mipmap()
	: OGLWindow("Example06_mipmap", "Example 6.mipmap")
{
}

Ex06_mipmap::~Ex06_mipmap()
{
	glUseProgram(0);
	glDeleteProgram(mipmap_prog);
	glDeleteTextures(1, &tex);
	glDeleteVertexArrays(1, &tex);
}

void Ex06_mipmap::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  mipmap_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/mip_filters.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/mip_filters.frag" },
		{ GL_NONE, NULL }
	};

	mipmap_prog = LoadShaders( mipmap_shaders );

	glLinkProgram(mipmap_prog);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	static const GLfloat plane_vertices[] =
	{
		-20.0f, 0.0f, -50.0f,
		-20.0f, 0.0f,  50.0f,
		20.0f, 0.0f, -50.0f,
		20.0f, 0.0f,  50.0f
	};

	static const GLfloat plane_texcoords[] =
	{
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};

	static const GLushort plane_indices[] =
	{
		0, 1, 2, 3
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(plane_vertices) + sizeof(plane_texcoords), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(plane_vertices), plane_vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(plane_vertices), sizeof(plane_texcoords), plane_texcoords);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(plane_vertices)));
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &element_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(plane_indices), plane_indices, GL_STATIC_DRAW);

	tc_rotate_loc = glGetUniformLocation(mipmap_prog, "tc_rotate");

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexStorage2D(GL_TEXTURE_2D, 7, GL_RGBA8, 64, 64);

	unsigned int * data = new unsigned int [64 * 64];

	unsigned int colors[] = { 0xFF0000FF, 0xFF00FF00, 0xFFFF0000, 0xFF00FFFF, 0xFFFF00FF, 0xFFFFFF00, 0xFFFFFFFF };

	int i, j;

	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 64 * 64; j++)
		{
			data[j] = colors[i];
		}
		glTexSubImage2D(GL_TEXTURE_2D, i, 0, 0, 64 >> i, 64 >> i, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, 4.5f);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	delete [] data;
}

void Ex06_mipmap::Display()
{
	static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

	vmath::mat4 tc_matrix(vmath::mat4::identity());

	glClearColor(0.0f, 0.25f, 0.3f, 1.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_ALWAYS);
	glDisable(GL_CULL_FACE);
	glUseProgram(mipmap_prog);

	float aspect = float(getHeight()) / getWidth();

	tc_matrix = vmath::translate(vmath::vec3(0.0f, 0.0f, -60.0f)) * vmath::rotate(80.0f * 3.0f * 0.03f, X);
	tc_matrix = vmath::perspective(35.0f, 1.0f / aspect, 0.1f, 700.0f) * tc_matrix;

	glUniformMatrix4fv(tc_rotate_loc, 1, GL_FALSE, tc_matrix);
	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);

	glDrawElements(GL_TRIANGLE_STRIP, 8, GL_UNSIGNED_SHORT, NULL);
	glDrawElements(GL_TRIANGLE_STRIP, 8, GL_UNSIGNED_SHORT, BUFFER_OFFSET(8 * sizeof(GLushort)));

	Swap();
}
