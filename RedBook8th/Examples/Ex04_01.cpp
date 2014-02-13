/*
* Ex04_01.cpp
*
* Created on: Feb 10, 2014
* Author: Andrew Zhabura
*/

#include "Ex04_01.h"

#include "GL/LoadShaders.h"

Ex04_01::Ex04_01()
	: OGLWindow("Example04_01", "Example 4.1")
{
}

void Ex04_01::InitGL()
{
	if (! LoadGL() )
		return;

	glGenVertexArrays( NumVAOs, VAOs );
	glBindVertexArray( VAOs[Triangles] );

	struct VertexData {
		GLubyte color[4];
		GLfloat position[4];
	};

	VertexData vertices[NumVertices] = {
		{{ 255,   0,   0, 255 }, { -0.90, -0.90 }},  // Triangle 1
		{{   0, 255,   0, 255 }, {  0.85, -0.90 }},
		{{   0,   0, 255, 255 }, { -0.90,  0.85 }},
		{{  10,  10,  10, 255 }, {  0.90, -0.85 }},  // Triangle 2
		{{ 100, 100, 100, 255 }, {  0.90,  0.90 }},
		{{ 255, 255, 255, 255 }, { -0.85,  0.90 }}
	};

	glGenBuffers( NumBuffers, Buffers );
	glBindBuffer( GL_ARRAY_BUFFER, Buffers[ArrayBuffer] );
	glBufferData( GL_ARRAY_BUFFER, sizeof(vertices),
		vertices, GL_STATIC_DRAW );

	ShaderInfo  shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/gouraud.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/gouraud.frag" },
		{ GL_NONE, NULL }
	};

	GLuint program = LoadShaders( shaders );
	glUseProgram( program );

	glVertexAttribPointer( vColor, 4, GL_UNSIGNED_BYTE,
		GL_TRUE, sizeof(VertexData), BUFFER_OFFSET(0) );
	glVertexAttribPointer( vPosition, 2, GL_FLOAT,
		GL_FALSE, sizeof(VertexData),
		BUFFER_OFFSET(sizeof(vertices[0].color)) );

	glEnableVertexAttribArray( vColor );
	glEnableVertexAttribArray( vPosition );
}

void Ex04_01::Display()
{
	glClear( GL_COLOR_BUFFER_BIT );

	glBindVertexArray( VAOs[Triangles] );
	glDrawArrays( GL_TRIANGLES, 0, NumVertices );

	glFlush();
}

void Ex04_01::keyboard( unsigned char key, int x, int y )
{
	switch( key ) {
	case 'm': {
		static GLenum  mode = GL_FILL;

		mode = ( mode == GL_FILL ? GL_LINE : GL_FILL );
		glPolygonMode( GL_FRONT_AND_BACK, mode );
		Display();
			  } break;
	}
}
