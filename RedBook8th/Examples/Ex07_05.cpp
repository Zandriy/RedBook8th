/*
* Ex07_05.cpp
*
* Created on: Feb 27, 2014
* Author: Andrew Zhabura
*/

#include "Ex07_05.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

Ex07_05::Ex07_05()
	: OGLWindow("Example07_05", "Example 7.5 (M)")
{
}

Ex07_05::~Ex07_05()
{
	glUseProgram(0);
	glDeleteProgram(object_prog);
}

void Ex07_05::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  object_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh07_05.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh07_05.frag" },
		{ GL_NONE, NULL }
	};

	object_prog = LoadShaders( object_shaders );

	glLinkProgram(object_prog);

	object_mat_mvp_loc = glGetUniformLocation(object_prog, "MVPMatrix");
	object_mat_mv_loc = glGetUniformLocation(object_prog, "MVMatrix");

	GLuint object_color_loc = glGetUniformLocation(object_prog, "VertexColor");
	GLuint object_ambient_loc = glGetUniformLocation(object_prog, "Ambient");
	GLuint object_LightColor_loc = glGetUniformLocation(object_prog, "LightColor");
	GLuint object_LightPosition_loc = glGetUniformLocation(object_prog, "LightPosition");
	GLuint object_Shininess_loc = glGetUniformLocation(object_prog, "Shininess");
	GLuint object_Strength_loc = glGetUniformLocation(object_prog, "Strength");
	GLuint object_mat_normal_loc = glGetUniformLocation(object_prog, "NormalMatrix");


	GLuint EyeDirection_loc = glGetUniformLocation(object_prog, "EyeDirection");
	GLuint ConstantAttenuation_loc = glGetUniformLocation(object_prog, "ConstantAttenuation");
	GLuint LinearAttenuation_loc = glGetUniformLocation(object_prog, "LinearAttenuation");
	GLuint QuadraticAttenuation_loc = glGetUniformLocation(object_prog, "QuadraticAttenuation");

	GLuint ConeDirection_loc = glGetUniformLocation(object_prog, "ConeDirection");
	GLuint SpotCosCutoff_loc = glGetUniformLocation(object_prog, "SpotCosCutoff");
	GLuint SpotExponent_loc = glGetUniformLocation(object_prog, "SpotExponent");

	glUseProgram(object_prog);	
	glUniform4fv(object_color_loc, 1, vmath::vec4(0.5f, 0.5f, 0.7f, 0.7f));
	glUniform3fv(object_ambient_loc, 1, vmath::vec3(0.2f, 0.2f, 0.5f));
	glUniform3fv(object_LightColor_loc, 1, vmath::vec3(0.3f, 0.3f, 1.0f));
	glUniform3fv(object_LightPosition_loc, 1, vmath::vec3(0.5f, 0.5f, -1.0f));
	glUniform1f(object_Shininess_loc, 20.0f);
	glUniform1f(object_Strength_loc, 10.5f);

	GLfloat normal_matrix[3 * 3] = {
		0.5f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.0f,
		0.0f, 0.0f, 1.0f
	};

	glUniformMatrix3fv(object_mat_normal_loc, 1, GL_TRUE, normal_matrix);

	glUniform3fv(EyeDirection_loc, 1, vmath::vec3(0.5f, 0.5f, 1.0f));
	glUniform1f(ConstantAttenuation_loc, 0.5f);
	glUniform1f(LinearAttenuation_loc, 0.01f);
	glUniform1f(QuadraticAttenuation_loc, 0.001f);

	glUniform3fv(ConeDirection_loc, 1, vmath::vec3(-0.3f, 0.5f, -0.9f));
	glUniform1f(SpotCosCutoff_loc, 0.9f);
	glUniform1f(SpotExponent_loc, 2.0f);

	object.LoadFromVBM("Media/torus.vbm", 0, 1, 2);
}

void Ex07_05::Display()
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

void Ex07_05::keyboard( unsigned char key, int x, int y )
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
