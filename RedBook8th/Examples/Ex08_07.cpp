/*
* Ex08_07.cpp
*
* Created on: Mar 14, 2014
* Author: Andrew Zhabura
*/

#include "Ex08_07.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

Ex08_07::Ex08_07()
	: OGLWindow("Example08_07", "Example 8.7 (M)")
{
}

Ex08_07::~Ex08_07()
{
	glUseProgram(0);
	glDeleteProgram(object_prog);
}

void Ex08_07::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  object_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh08_07.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh08_07.frag" },
		{ GL_NONE, NULL }
	};

	object_prog = LoadShaders( object_shaders );

	glLinkProgram(object_prog);

// 	uniform vec4 MCBallCenter;
// 	uniform mat4 MVMatrix;
// 	uniform mat4 MVPMatrix;
// 	uniform mat3 NormalMatrix;

	object_mat_mv_loc = glGetUniformLocation(object_prog, "MVMatrix");
	object_mat_mvp_loc = glGetUniformLocation(object_prog, "MVPMatrix");
	GLuint NormalMatrix_loc = glGetUniformLocation(object_prog, "NormalMatrix");
	GLuint MCBallCenter_loc = glGetUniformLocation(object_prog, "MCBallCenter");

// 	uniform vec4 HalfSpace[5]; // half-spaces used to define star pattern
// 	uniform float StripeWidth;
// 	uniform float InOrOutInit; // -3.0
// 	uniform float FWidth; // = 0.005
// 
// 	uniform vec4 StarColor;
// 	uniform vec4 StripeColor;
// 	uniform vec4 BaseColor;
// 
// 	uniform vec4 LightDir; // light direction, should be normalized
// 	uniform vec4 HVector; // reflection vector for infinite light
// 	uniform vec4 SpecularColor;
// 	uniform float SpecularExponent;
// 
// 	uniform float Ka;
// 	uniform float Kd;
// 	uniform float Ks;

	GLuint HalfSpace0_loc = glGetUniformLocation(object_prog, "HalfSpace[0]");
	GLuint HalfSpace1_loc = glGetUniformLocation(object_prog, "HalfSpace[1]");
	GLuint HalfSpace2_loc = glGetUniformLocation(object_prog, "HalfSpace[2]");
	GLuint HalfSpace3_loc = glGetUniformLocation(object_prog, "HalfSpace[3]");
	GLuint HalfSpace4_loc = glGetUniformLocation(object_prog, "HalfSpace[4]");

	GLuint StripeWidth_loc = glGetUniformLocation(object_prog, "StripeWidth");
	GLuint InOrOutInit_loc = glGetUniformLocation(object_prog, "InOrOutInit");
	GLuint FWidth_loc = glGetUniformLocation(object_prog, "FWidth");

	GLuint StarColor_loc = glGetUniformLocation(object_prog, "StarColor");
	GLuint StripeColor_loc = glGetUniformLocation(object_prog, "StripeColor");
	GLuint BaseColor_loc = glGetUniformLocation(object_prog, "BaseColor");

	GLuint LightDir_loc = glGetUniformLocation(object_prog, "LightDir");
	GLuint HVector_loc = glGetUniformLocation(object_prog, "HVector");
	GLuint SpecularColor_loc = glGetUniformLocation(object_prog, "SpecularColor");
	GLuint SpecularExponent_loc = glGetUniformLocation(object_prog, "SpecularExponent");

	GLuint Ka_loc = glGetUniformLocation(object_prog, "Ka");
	GLuint Kd_loc = glGetUniformLocation(object_prog, "Kd");
	GLuint Ks_loc = glGetUniformLocation(object_prog, "Ks");

	glUseProgram(object_prog);	
	
	GLfloat normal_matrix[3 * 3] = {
		0.5f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.0f,
		0.0f, 0.0f, 1.0f
	};

	glUniformMatrix3fv(NormalMatrix_loc, 1, GL_TRUE, normal_matrix);

	glUniform4fv(MCBallCenter_loc, 1, vmath::vec4(0.0f, 0.0f, 0.0f, 1.0f));

	glUniform4fv(HalfSpace0_loc, 1, vmath::vec4(1.0, 0.0, 0.0, 0.2));
	glUniform4fv(HalfSpace1_loc, 1, vmath::vec4(0.309016994, 0.951056516, 0.0, 0.2));
	glUniform4fv(HalfSpace2_loc, 1, vmath::vec4(-0.809016994, 0.587785252, 0.0, 0.2));
	glUniform4fv(HalfSpace3_loc, 1, vmath::vec4(-0.809016994, -0.587785252, 0.0, 0.2));
	glUniform4fv(HalfSpace4_loc, 1, vmath::vec4(0.309016994, -0.951056516, 0.0, 0.2));

	glUniform1f(StripeWidth_loc, 0.3);
	glUniform1f(InOrOutInit_loc, -3.0);
	glUniform1f(FWidth_loc, 0.005);

	glUniform4fv(StarColor_loc, 1, vmath::vec4(0.6, 0.0, 0.0, 1.0));
	glUniform4fv(StripeColor_loc, 1, vmath::vec4(0.0, 0.3, 0.6, 1.0));
	glUniform4fv(BaseColor_loc, 1, vmath::vec4(0.6, 0.5, 0.0, 1.0));

	glUniform4fv(LightDir_loc, 1, vmath::vec4(0.57735, 0.57735, 0.57735, 0.0));
	glUniform4fv(HVector_loc, 1, vmath::vec4(0.32506, 0.32506, 0.88808, 0.0));
	glUniform4fv(SpecularColor_loc, 1, vmath::vec4(1.0, 1.0, 1.0, 1.0));
	glUniform1f(SpecularExponent_loc, 200.0);

	glUniform1f(Ka_loc, 0.3);
	glUniform1f(Kd_loc, 0.7);
	glUniform1f(Ks_loc, 0.4);

	object.LoadFromVBM("Media/torus.vbm", 0, 1, 2);
}

void Ex08_07::Display()
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

void Ex08_07::keyboard( unsigned char key, int x, int y )
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
