/*
* Ex09_06.cpp
*
* Created on: Mar 21, 2014
* Author: Andrew Zhabura
*/

#include "Ex09_06.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"

static const GLfloat  zNear = 1.0f;
static const GLfloat  zFar  = 3.0f;

Ex09_06::Ex09_06()
	: OGLWindow("Example09_06", "Example 9.6 (M, R)")
	, rot(true)
{
}

void Ex09_06::InitGL()
{
	if (! LoadGL() )
		return;

	// Create a vertex array object
	enum { Patch, NumVAOs };
	GLuint VAOs[NumVAOs];
	glGenVertexArrays( NumVAOs, VAOs );
	glBindVertexArray( VAOs[Patch] );

	// Create and initialize a buffer object
	enum { Array, NumBuffers };
	GLuint buffers[NumBuffers];
	glGenBuffers( NumBuffers, buffers );
	glBindBuffer( GL_ARRAY_BUFFER, buffers[Array] );

	GLfloat vertices[NumVertices][2] = {
		{ -0.5, -0.5 },
		{  0.5, -0.5 },
		{  0.5,  0.5 },
		{ -0.5,  0.5 }
	};
	glBufferData( GL_ARRAY_BUFFER, sizeof(vertices),
		vertices, GL_STATIC_DRAW );

	// Load shaders and use the resulting shader program
	ShaderInfo  shaders[] = {
		{ GL_VERTEX_SHADER,          "Shaders/simple.vert" },
		{ GL_TESS_CONTROL_SHADER,    "Shaders/simple.cont" },
		{ GL_TESS_EVALUATION_SHADER, "Shaders/simple.eval" },
		{ GL_FRAGMENT_SHADER,        "Shaders/simple.frag" },
		{ GL_NONE, NULL }
	};

	program = LoadShaders( shaders );
	glUseProgram( program );

	// set up vertex arrays
	GLuint vPosition = glGetAttribLocation( program, "vPosition" );
	glEnableVertexAttribArray( vPosition );
	glVertexAttribPointer( vPosition, 2, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(0) );

	PLoc = glGetUniformLocation( program, "P" );
	MVLoc = glGetUniformLocation( program, "MV" );

	glPatchParameteri( GL_PATCH_VERTICES, 4 );

	glEnable( GL_DEPTH_TEST );

	glClearColor( 0.0, 0.0, 0.0, 1.0 );
}

void Ex09_06::Display()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	static const unsigned int start_time = GetTickCount() - 50000;

	static float t = 0.0f;
	if (rot)
		t = float((GetTickCount() - start_time)) / float(0x3FFF);

	rot = true;

	static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

	vmath::mat4 tc_matrix(vmath::mat4::identity());

	float aspect = float(getHeight()) / getWidth();

	glUseProgram(program);

	tc_matrix = vmath::rotate(50.0f * 3.0f * t, Z);

	glUniformMatrix4fv(MVLoc, 1, GL_FALSE, tc_matrix);

	glUniformMatrix4fv(PLoc, 1, GL_FALSE, tc_matrix);

	glDrawArrays( GL_PATCHES, 0, NumVertices );

	Swap();
}

void Ex09_06::keyboard( unsigned char key, int x, int y )
{
	switch( key ) {
	case 'M': {
		rot = false;
		static GLenum mode = GL_FILL;
		mode = ( mode == GL_FILL ? GL_LINE : GL_FILL );
		glPolygonMode( GL_FRONT_AND_BACK, mode );
			  } 
			  Display();
			  break;
	case 'R': 
		for (int i = 0; i < c_repeat; ++i)
			Display();
		break;
	default:
		OGLWindow::keyboard(key, x, y);
		break;
	}
}

