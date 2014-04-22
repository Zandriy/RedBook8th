/*
* Ex06_14.cpp
*
* Created on: Feb 16, 2014
* Author: Andrew Zhabura
*/

#include "Ex06_14.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

Ex06_14::Ex06_14()
	: OGLWindow("Example06_14", "Example 6.14 (M)")
{
}

Ex06_14::~Ex06_14()
{
	glUseProgram(0);
	glDeleteProgram(base_prog);
	glDeleteTextures(1, &tex1);
	glDeleteVertexArrays(1, &tex1);
	glDeleteTextures(1, &tex2);
	glDeleteVertexArrays(1, &tex2);
}

void Ex06_14::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  base_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh06_14.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh06_14.frag" },
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

	// prog is the name of a linked program containing our example
	// vertex and fragment shaders
	glUseProgram(base_prog);
	// For the first texture, we will use texture unit 0...
	// Get the uniform location
	GLint tex1_uniform_loc = glGetUniformLocation(base_prog, "tex1");
	// Set it to 0
	glUniform1i(tex1_uniform_loc, 0);
	// Select texture unit 0
	glActiveTexture(GL_TEXTURE0);
	// Bind a texture to it
	glBindTexture(GL_TEXTURE_2D, tex1);
	// Repeat the above process for texture unit 1
	GLint tex2_uniform_loc = glGetUniformLocation(base_prog, "tex2");
	glUniform1i(tex2_uniform_loc, 1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, tex2);

 	time_loc = glGetUniformLocation(base_prog, "time");

	vglImageData image;
 
	tex1 = vglLoadTexture("Media/test.dds", 0, &image);

	glTexParameteri(image.target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	vglUnloadImage(&image);

	tex2 = vglLoadTexture("Media/test3.dds", 0, &image);

	vglUnloadImage(&image);
}

void Ex06_14::Display()
{
	float t = float(GetTickCount() & 0x3FFF) / float(0x3FFF);

	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_CULL_FACE);
	glUseProgram(base_prog);

	glUniform1f(time_loc, t);

	glBindVertexArray(vao);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, tex2);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	Swap();
}

void Ex06_14::keyboard( unsigned char key, int x, int y )
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
