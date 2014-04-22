/*
* Ex09_08.cpp
*
* Created on: Mar 21, 2014
* Author: Andrew Zhabura
*/

#include "Ex09_08.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Shapes/Teapot.h"

Ex09_08::Ex09_08()
	: OGLWindow("Example09_08", "Example 9.8 (M, U-I, O-P, R)")
	, Inner(1.0)
	, Outer(1.0)
{
}

void Ex09_08::InitGL()
{
	if (! LoadGL() )
		return;

	// Create a vertex array object
	GLuint vao;
	glGenVertexArrays( 1, &vao );
	glBindVertexArray( vao );

	// Create and initialize a buffer object
	enum { ArrayBuffer, ElementBuffer, NumVertexBuffers };
	GLuint buffers[NumVertexBuffers];
	glGenBuffers( NumVertexBuffers, buffers );
	glBindBuffer( GL_ARRAY_BUFFER, buffers[ArrayBuffer] );
	glBufferData( GL_ARRAY_BUFFER, sizeof(TeapotVertices),
		TeapotVertices, GL_STATIC_DRAW );

	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, buffers[ElementBuffer] );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof(TeapotIndices),
		TeapotIndices, GL_STATIC_DRAW );

	// Load shaders and use the resulting shader program
	ShaderInfo  shaders[] = {
		{ GL_VERTEX_SHADER,          "Shaders/teapot.vert" },
		{ GL_TESS_CONTROL_SHADER,    "Shaders/teapot.cont" },
		{ GL_TESS_EVALUATION_SHADER, "Shaders/teapot.eval" },
		{ GL_FRAGMENT_SHADER,        "Shaders/teapot.frag" },
		{ GL_NONE, NULL }
	};

	program = LoadShaders( shaders );
	glUseProgram( program );

	// set up vertex arrays
	GLuint vPosition = glGetAttribLocation( program, "vPosition" );
	glEnableVertexAttribArray( vPosition );
	glVertexAttribPointer( vPosition, 3, GL_DOUBLE, GL_FALSE, 0,
		BUFFER_OFFSET(0) );

	PLoc = glGetUniformLocation( program, "P" );
	MVLoc = glGetUniformLocation( program, "MV" );
	InnerLoc = glGetUniformLocation( program, "Inner" );
	OuterLoc = glGetUniformLocation( program, "Outer" );

	glUniform1f( InnerLoc, Inner );
	glUniform1f( OuterLoc, Outer );

	glPatchParameteri( GL_PATCH_VERTICES, NumTeapotVerticesPerPatch );

	glClearColor( 0.0, 0.0, 0.0, 1.0 );
	glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
}

void Ex09_08::Display()
{
	vmath::mat4 tc_matrix(vmath::mat4::identity());

	float aspect = float(getHeight()) / getWidth();

	glUseProgram(program);


	tc_matrix = vmath::translate(vmath::vec3(-0.1f, -1.0f, -2.9f));

	glUniformMatrix4fv(MVLoc, 1, GL_FALSE, tc_matrix);

	tc_matrix = vmath::perspective(35.0f, 1.0f / aspect, 0.1f, 100.0f) * tc_matrix;

	glUniformMatrix4fv(PLoc, 1, GL_FALSE, tc_matrix);


	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glDrawElements( GL_PATCHES, NumTeapotVertices,
		GL_UNSIGNED_INT, BUFFER_OFFSET(0) );

	Swap();
}

void Ex09_08::keyboard( unsigned char key, int x, int y )
{
	switch( key ) {
	case 'U': 
		Inner--;
		if ( Inner < 1.0 )  Inner = 1.0;
		glUniform1f( InnerLoc, Inner );
		Display();
		break;
	case 'I': 
		Inner++;
		if ( Inner > 64 )  Inner = 64.0;
		glUniform1f( InnerLoc, Inner );
		Display();
		break;
	case 'O': 
		Outer--;
		if ( Outer < 1.0 )  Outer = 1.0;
		glUniform1f( OuterLoc, Outer );
		Display();
		break;
	case 'P': 
		Outer++;
		if ( Outer > 64 )  Outer = 64.0;
		glUniform1f( OuterLoc, Outer );
		Display();
		break;
	case 'R': 
		Inner = 1.0;
		Outer = 1.0;
		glUniform1f( InnerLoc, Inner );
		glUniform1f( OuterLoc, Outer );
		Display();
		break;
	case 'M': {
		static GLenum mode = GL_FILL;
		mode = ( mode == GL_FILL ? GL_LINE : GL_FILL );
		glPolygonMode( GL_FRONT_AND_BACK, mode );
			  } 
			  Display();
			  break;
	default:
		OGLWindow::keyboard(key, x, y);
		break;
	}
}

