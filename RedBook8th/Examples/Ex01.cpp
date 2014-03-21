/*
* Ex01.cpp
*
* Created on: Dec 31, 2013
* Author: Andrew Zhabura
*/

#include "Ex01.h"

#include "GL/LoadShaders.h"

Ex01::Ex01()
	: OGLWindow("Example1", "Example 1")
{
}

void Ex01::InitGL()
{
	if (! LoadGL() )
		return;

	glGenVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[Triangles]);

	GLfloat  vertices[NumVertices][2] = {
		{ -0.90, -0.90 },  // Triangle 1
		{  0.85, -0.90 },
		{ -0.90,  0.85 },
		{  0.90, -0.85 },  // Triangle 2
		{  0.90,  0.90 },
		{ -0.85,  0.90 }
	};

 	glGenBuffers(NumBuffers, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
		vertices, GL_STATIC_DRAW);

	ShaderInfo  shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/triangles.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/triangles.frag" },
		{ GL_NONE, NULL }
	};

	GLuint program = LoadShaders(shaders);
	glUseProgram(program);

	glVertexAttribPointer(vPosition, 2, GL_FLOAT,
		GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);

	glClearColor(0.4, 0.7, 0.7, 1.0);
}

void Ex01::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);

	glFlush();
}
