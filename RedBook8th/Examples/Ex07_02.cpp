/*
* Ex07_02.cpp
*
* Created on: Feb 25, 2014
* Author: Andrew Zhabura
*/

#include "Ex07_02.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

Ex07_02::Ex07_02()
	: OGLWindow("Example07_02", "Example 7.2 (M)")
{
}

Ex07_02::~Ex07_02()
{
	glUseProgram(0);
	glDeleteProgram(object_prog);
}

void Ex07_02::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  object_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh07_02.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh07_02.frag" },
		{ GL_NONE, NULL }
	};

	object_prog = LoadShaders( object_shaders );

	glLinkProgram(object_prog);

	object_mat_mvp_loc = glGetUniformLocation(object_prog, "MVPMatrix");

	GLuint object_color_loc = glGetUniformLocation(object_prog, "VertexColor");
	GLuint object_ambient_loc = glGetUniformLocation(object_prog, "Ambient");

	glUseProgram(object_prog);	
	glUniform4fv(object_color_loc, 1, vmath::vec4(0.5f, 0.5f, 0.7f, 0.7f));
	glUniform4fv(object_ambient_loc, 1, vmath::vec4(0.2f, 0.2f, 0.5f, 1.0f));

	object.LoadFromVBM("Media/torus.vbm", 0, 1, 2);
}

void Ex07_02::Display()
{
	static const unsigned int start_time = GetTickCount() - 10000;
	float t = float((GetTickCount() - start_time)) / float(0x3FFF);
	static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

	vmath::mat4 tc_matrix(vmath::mat4::identity());

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDisable(GL_CULL_FACE);

	float aspect = float(getHeight()) / getWidth();

	glUseProgram(object_prog);

	tc_matrix = vmath::translate(vmath::vec3(0.0f, 0.0f, -70.0f)) *
		vmath::rotate(80.0f * 3.0f * t, Y) * vmath::rotate(50.0f * 3.0f * t, Z);

	tc_matrix = vmath::perspective(35.0f, 1.0f / aspect, 0.1f, 100.0f) * tc_matrix;
	glUniformMatrix4fv(object_mat_mvp_loc, 1, GL_FALSE, tc_matrix);

	glClear(GL_DEPTH_BUFFER_BIT);

	object.Render();

	glFlush();
}

void Ex07_02::keyboard( unsigned char key, int x, int y )
{
	switch( key ) {
	case 'M': 
		for (int i = 0; i < 5000; ++i)
			Display();
		break;
	default:
		OGLWindow::keyboard(key, x, y);
		break;
	}
}
