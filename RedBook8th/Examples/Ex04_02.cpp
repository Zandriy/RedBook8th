/*
* Ex04_02.cpp
*
* Created on: Feb 10, 2014
* Author: Andrew Zhabura
*/

#include "Ex04_02.h"

#include "GL/LoadShaders.h"

Ex04_02::Ex04_02()
	: OGLWindow("Example04_02", "Example 4.2 (M)")
{
}

void Ex04_02::InitGL()
{
	if (! LoadGL() )
		return;

	glGenVertexArrays( NumVAOs, VAOs );
	glBindVertexArray( VAOs[Triangles] );

	struct VertexData {
		GLfloat color[3];
		GLfloat position[4];
	};

	VertexData vertices[NumVertices] = {
		{{  1.00, 0.00, 0.00 }, { -0.90, -0.90 }},  // Triangle 1
		{{  0.00, 1.00, 0.00 }, {  0.85, -0.90 }},
		{{  0.00, 0.00, 1.00 }, { -0.90,  0.85 }},
		{{  0.04, 0.04, 0.04 }, {  0.90, -0.85 }},  // Triangle 2
		{{  0.40, 0.40, 0.40 }, {  0.90,  0.90 }},
		{{  1.00, 1.00, 1.00 }, { -0.85,  0.90 }}
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

	glVertexAttribPointer( vColor, 3, GL_FLOAT,
		GL_TRUE, sizeof(VertexData), BUFFER_OFFSET(0) );
	glVertexAttribPointer( vPosition, 2, GL_FLOAT,
		GL_FALSE, sizeof(VertexData),
		BUFFER_OFFSET(sizeof(vertices[0].color)) );

	glEnableVertexAttribArray( vColor );
	glEnableVertexAttribArray( vPosition );
}

void Ex04_02::Display()
{
	glClear( GL_COLOR_BUFFER_BIT );

	glBindVertexArray( VAOs[Triangles] );
	glDrawArrays( GL_TRIANGLES, 0, NumVertices );

	glFlush();
}

void Ex04_02::keyboard( unsigned char key, int x, int y )
{
	switch( key ) {
	case 'M': {
		static GLenum  mode = GL_FILL;

		mode = ( mode == GL_FILL ? GL_LINE : GL_FILL );
		glPolygonMode( GL_FRONT_AND_BACK, mode );
		Display();
			  } break;
	default:
		OGLWindow::keyboard(key, x, y);
		break;
	}
}
