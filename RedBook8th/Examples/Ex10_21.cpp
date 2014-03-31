/*
* Ex10_21.cpp
*
* Created on: Mar 31, 2014
* Author: Andrew Zhabura
*/

#include "Ex10_21.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

Ex10_21::Ex10_21()
	: OGLWindow("Example10_21", "Example 10.21 (M)")
{
}

Ex10_21::~Ex10_21()
{
	glUseProgram(0);
	glDeleteProgram(object_prog);
}

void Ex10_21::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  object_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh10_07.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh10_07.frag" },
		{ GL_NONE, NULL }
	};

	object_prog = LoadShaders( object_shaders );

	glLinkProgram(object_prog);

	object_mat_mvp_loc = glGetUniformLocation(object_prog, "MVPMatrix");

	GLuint object_color_loc = glGetUniformLocation(object_prog, "VertexColor");

	GLuint Scale_loc = glGetUniformLocation(object_prog, "Scale");
	GLuint Threshold_loc = glGetUniformLocation(object_prog, "Threshold");

	glUseProgram(object_prog);	

	glUniform4fv(object_color_loc, 1, vmath::vec4(1.0f, 0.3f, 0.1f, 0.5f));

	glUniform2fv(Scale_loc, 1, vmath::vec2(50.0f, 70.0f));
	glUniform2fv(Threshold_loc, 1, vmath::vec2(0.13f, 0.13f));

	object.LoadFromVBM("Media/ninja.vbm", 0, 1, 2);
}

void Ex10_21::Display()
{
	static const vmath::vec3 X(0.3f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 0.3f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 0.3f);

	vmath::mat4 tc_matrix(vmath::mat4::identity());

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDisable(GL_CULL_FACE);

	float aspect = float(getHeight()) / getWidth();

	glUseProgram(object_prog);

	static float a = -20.0;
	static bool sign = true; 
	if (sign)
	{
		a += 0.01;
		if (a >= 80.0) sign = false;
	}
	else
	{
		a -= 0.01;
		if (a <= -30.0) sign = true;
	}

	tc_matrix = vmath::translate(vmath::vec3(0.0f, -120.0f + a, -70.0f)) *
		vmath::rotate(a, Y);

	tc_matrix = vmath::perspective(35.0f, 1.0f / aspect, 0.1f, 100.0f) * tc_matrix;
	glUniformMatrix4fv(object_mat_mvp_loc, 1, GL_FALSE, tc_matrix);

	glClear(GL_DEPTH_BUFFER_BIT);

	object.Render();

	glFlush();
}

void Ex10_21::keyboard( unsigned char key, int x, int y )
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
