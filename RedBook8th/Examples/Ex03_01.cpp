/*
* Ex03_01.cpp
*
* Created on: Jun 18, 2014
* Author: Andrew Zhabura
*/

#include "Ex03_01.h"

#include "GL/LoadShaders.h"

Ex03_01::Ex03_01()
	: OGLWindow("Example03_01", "Example 3.1")
{
}

void Ex03_01::InitGL()
{
	//	bool b10 = GL_1_0_LoadFuncPointers();
	bool b15 = GL_1_5_LoadFuncPointers();
	bool b20 = GL_2_0_LoadFuncPointers();
	bool b30 = GL_3_0_LoadFuncPointers();
	bool b31 = GL_3_1_LoadFuncPointers();

	//	if (!b10) return;
	if (!b15) return;
	if (!b20) return;
	if (!b30) return;
	if (!b31) return;

	// Vertex positions
	static const GLfloat positions[] =
	{
		-1.0f, -1.0f, 0.0f, 1.0f,
		1.0f, -1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		-1.0f, 1.0f, 0.0f, 1.0f
	};
	// Vertex colors
	static const GLfloat colors[] =
	{
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
	};

	// Reserve a name for the buffer object.
	glGenBuffers(NumBuffers, Buffers);
	// Bind it to the GL_ARRAY_BUFFER target.
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	// Allocate space for it (sizeof(positions) + sizeof(colors)).
	glBufferData(GL_ARRAY_BUFFER, // target
		sizeof(positions) + sizeof(colors), // total size
		NULL, // no data
		GL_STATIC_DRAW); // usage
	
	 // Set up the vertex attributes
	glGenVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[Triangles]);

	// Put "positions" at offset zero in the buffer.
	glBufferSubData(GL_ARRAY_BUFFER, // target
		0, // offset
		sizeof(positions), // size
		positions); // data
	// Put "colors" at an offset in the buffer equal to the filled size of
	// the buffer so far - i.e., sizeof(positions).
	glBufferSubData(GL_ARRAY_BUFFER, // target
		sizeof(positions), // offset
		sizeof(colors), // size
		colors); // data
	// Now "positions" is at offset 0 and "colors" is directly after it
	// in the same buffer.

	ShaderInfo  shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh03_01.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh03_01.frag" },
		{ GL_NONE, NULL }
	};

	GLuint program = LoadShaders(shaders);
	glUseProgram(program);

    glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, NULL);
    glVertexAttribPointer(fPosition, 3, GL_FLOAT, GL_FALSE, 0, (const GLvoid *)sizeof(positions));
    glEnableVertexAttribArray(vPosition);
    glEnableVertexAttribArray(fPosition);
}

void Ex03_01::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, NumVertices);

	glFlush();
}
