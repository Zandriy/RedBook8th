/*
* Ex08_01.cpp
*
* Created on: Mar 9, 2014
* Author: Andrew Zhabura
*/

#include "Ex08_01.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

Ex08_01::Ex08_01()
	: OGLWindow("Example08_01", "Example 8.1 (M)")
{
}

Ex08_01::~Ex08_01()
{
	glUseProgram(0);
	glDeleteProgram(object_prog);
}

void Ex08_01::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  object_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh08_01.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh08_01.frag" },
		{ GL_NONE, NULL }
	};

	object_prog = LoadShaders( object_shaders );

	glLinkProgram(object_prog);


	GLuint LightPosition_loc = glGetUniformLocation(object_prog, "LightPosition");
	GLuint LightColor_loc = glGetUniformLocation(object_prog, "LightColor");
	GLuint EyePosition_loc = glGetUniformLocation(object_prog, "EyePosition");
	GLuint Specular_loc = glGetUniformLocation(object_prog, "Specular");
	GLuint Ambient_loc = glGetUniformLocation(object_prog, "Ambient");

	GLuint Kd_loc = glGetUniformLocation(object_prog, "Kd");
	object_mat_mv_loc = glGetUniformLocation(object_prog, "MVMatrix");
	object_mat_mvp_loc = glGetUniformLocation(object_prog, "MVPMatrix");
	GLuint NormalMatrix_loc = glGetUniformLocation(object_prog, "NormalMatrix");

	GLuint StripeColor_loc = glGetUniformLocation(object_prog, "StripeColor");
	GLuint BackColor_loc = glGetUniformLocation(object_prog, "BackColor");

	GLuint Width_loc = glGetUniformLocation(object_prog, "Width");
	GLuint Fuzz_loc = glGetUniformLocation(object_prog, "Fuzz");
	GLuint Scale_loc = glGetUniformLocation(object_prog, "Scale");

	glUseProgram(object_prog);	

	glUniform3fv(LightPosition_loc, 1, vmath::vec3(0.5f, 0.5f, -1.0f));
	glUniform3fv(LightColor_loc, 1, vmath::vec3(1.0f, 1.0f, 1.0f));
	glUniform3fv(EyePosition_loc, 1, vmath::vec3(-0.5f, -0.5f, 1.0f));
	glUniform3fv(Specular_loc, 1, vmath::vec3(0.1f, 0.1f, 0.1f));
	glUniform4fv(Ambient_loc, 1, vmath::vec4(1.0f, 1.0f, 1.0f, 1.0f));

	glUniform1f(Kd_loc, 1.0f);

	GLfloat normal_matrix[3 * 3] = {
		0.5f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.0f,
		0.0f, 0.0f, 1.0f
	};

	glUniformMatrix3fv(NormalMatrix_loc, 1, GL_TRUE, normal_matrix);

	glUniform3fv(StripeColor_loc, 1, vmath::vec3(0.0f, 0.0f, 0.7f));
	glUniform3fv(BackColor_loc, 1, vmath::vec3(1.0f, 1.0f, 1.0f));

	glUniform1f(Width_loc, 0.5f);
	glUniform1f(Fuzz_loc, 0.1f);
	glUniform1f(Scale_loc, 20.0f);

	object.LoadFromVBM("Media/torus.vbm", 0, 1, 2);
}

void Ex08_01::Display()
{
	static const unsigned int start_time = GetTickCount() - 50000;
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

	glUniformMatrix4fv(object_mat_mv_loc, 1, GL_FALSE, tc_matrix);

	tc_matrix = vmath::perspective(35.0f, 1.0f / aspect, 0.1f, 100.0f) * tc_matrix;
	glUniformMatrix4fv(object_mat_mvp_loc, 1, GL_FALSE, tc_matrix);

	glClear(GL_DEPTH_BUFFER_BIT);

	object.Render();

	glFlush();
}

void Ex08_01::keyboard( unsigned char key, int x, int y )
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
