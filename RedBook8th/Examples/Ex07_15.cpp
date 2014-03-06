/*
* Ex07_15.cpp
*
* Created on: Mar 6, 2014
* Author: Andrew Zhabura
*/

#include "Ex07_15.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

Ex07_15::Ex07_15()
	: OGLWindow("Example07_15", "Example 7.15 (M)")
{
}

Ex07_15::~Ex07_15()
{
	glUseProgram(0);
	glDeleteProgram(object_prog);
}

void Ex07_15::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  object_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh07_08.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh07_08.frag" },
		{ GL_NONE, NULL }
	};

	object_prog = LoadShaders( object_shaders );

	glLinkProgram(object_prog);

	object_mat_mvp_loc = glGetUniformLocation(object_prog, "MVPMatrix");
	object_mat_mv_loc = glGetUniformLocation(object_prog, "MVMatrix");
	GLuint object_mat_normal_loc = glGetUniformLocation(object_prog, "NormalMatrix");
	GLuint object_color_loc = glGetUniformLocation(object_prog, "VertexColor");

	GLuint object_Shininess_loc = glGetUniformLocation(object_prog, "Shininess");
	GLuint object_Strength_loc = glGetUniformLocation(object_prog, "Strength");

 	GLuint EyeDirection_loc = glGetUniformLocation(object_prog, "EyeDirection");

	glUseProgram(object_prog);	
	glUniform4fv(object_color_loc, 1, vmath::vec4(0.5f, 0.5f, 0.7f, 0.7f));
	glUniform1f(object_Shininess_loc, 20.0f);
	glUniform1f(object_Strength_loc, 10.5f);

	GLfloat normal_matrix[3 * 3] = {
		0.5f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.0f,
		0.0f, 0.0f, 1.0f
	};

	glUniformMatrix3fv(object_mat_normal_loc, 1, GL_TRUE, normal_matrix);

 	glUniform3fv(EyeDirection_loc, 1, vmath::vec3(-0.5f, -0.5f, 1.0f));

// 	struct LightProperties {
// 		bool isEnabled;
// 		bool isLocal;
// 		bool isSpot;
// 		vmath::vec3 ambient;
// 		vmath::vec3 color;
// 		vmath::vec3 position;
// 		vmath::vec3 halfVector;
// 		vmath::vec3 coneDirection;
// 		float spotCosCutoff;
// 		float spotExponent;
// 		float constantAttenuation;
// 		float linearAttenuation;
// 		float quadraticAttenuation;
// 	};

	GLuint object_light_loc = glGetUniformLocation(object_prog, "Lights[0].isEnabled");
	glUniform1i(object_light_loc, true);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[0].isLocal");
	glUniform1i(object_light_loc, true);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[0].isSpot");
	glUniform1i(object_light_loc, true);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[0].ambient");
	glUniform3fv(object_light_loc, 1, vmath::vec3(0.2f, 0.2f, 0.5f));
	object_light_loc = glGetUniformLocation(object_prog, "Lights[0].color");
	glUniform3fv(object_light_loc, 1, vmath::vec3(0.3f, 0.3f, 1.0f));
	object_light_loc = glGetUniformLocation(object_prog, "Lights[0].position");
	glUniform3fv(object_light_loc, 1, vmath::vec3(0.5f, 0.5f, -1.0f));
	object_light_loc = glGetUniformLocation(object_prog, "Lights[0].halfVector");
	glUniform3fv(object_light_loc, 1, vmath::vec3(1.0f, 1.0f, 0.0f));
	object_light_loc = glGetUniformLocation(object_prog, "Lights[0].coneDirection");
	glUniform3fv(object_light_loc, 1, vmath::vec3(-0.3f, 0.5f, -0.9f));
	object_light_loc = glGetUniformLocation(object_prog, "Lights[0].spotCosCutoff");
	glUniform1f(object_light_loc, 0.8);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[0].spotExponent");
	glUniform1f(object_light_loc, 2.0);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[0].constantAttenuation");
	glUniform1f(object_light_loc, 0.5f);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[0].linearAttenuation");
	glUniform1f(object_light_loc, 0.01f);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[0].quadraticAttenuation");
	glUniform1f(object_light_loc, 0.001f);
	
	object_light_loc = glGetUniformLocation(object_prog, "Lights[1].isEnabled");
	glUniform1i(object_light_loc, true);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[1].isLocal");
	glUniform1i(object_light_loc, true);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[1].isSpot");
	glUniform1i(object_light_loc, false);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[1].ambient");
	glUniform3fv(object_light_loc, 1, vmath::vec3(0.2f, 0.2f, 0.5f));
	object_light_loc = glGetUniformLocation(object_prog, "Lights[1].color");
	glUniform3fv(object_light_loc, 1, vmath::vec3(0.9f, 0.9f, 0.0f));
	object_light_loc = glGetUniformLocation(object_prog, "Lights[1].position");
	glUniform3fv(object_light_loc, 1, vmath::vec3(0.5f, 0.5f, -1.0f));
	object_light_loc = glGetUniformLocation(object_prog, "Lights[1].halfVector");
	glUniform3fv(object_light_loc, 1, vmath::vec3(1.0f, 1.0f, 0.0f));
	object_light_loc = glGetUniformLocation(object_prog, "Lights[1].coneDirection");
	glUniform3fv(object_light_loc, 1, vmath::vec3(-0.3f, 0.5f, -0.9f));
	object_light_loc = glGetUniformLocation(object_prog, "Lights[1].spotCosCutoff");
	glUniform1f(object_light_loc, 0.8);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[1].spotExponent");
	glUniform1f(object_light_loc, 2.0);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[1].constantAttenuation");
	glUniform1f(object_light_loc, 0.5f);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[1].linearAttenuation");
	glUniform1f(object_light_loc, 0.01f);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[1].quadraticAttenuation");
	glUniform1f(object_light_loc, 0.001f);
	
	object_light_loc = glGetUniformLocation(object_prog, "Lights[2].isEnabled");
	glUniform1i(object_light_loc, true);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[2].isLocal");
	glUniform1i(object_light_loc, false);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[2].isSpot");
	glUniform1i(object_light_loc, false);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[2].ambient");
	glUniform3fv(object_light_loc, 1, vmath::vec3(0.2f, 0.2f, 0.5f));
	object_light_loc = glGetUniformLocation(object_prog, "Lights[2].color");
	glUniform3fv(object_light_loc, 1, vmath::vec3(0.7f, 0.0f, 0.0f));
	object_light_loc = glGetUniformLocation(object_prog, "Lights[2].position");
	glUniform3fv(object_light_loc, 1, vmath::vec3(0.5f, 0.5f, -1.0f));
	object_light_loc = glGetUniformLocation(object_prog, "Lights[2].halfVector");
	glUniform3fv(object_light_loc, 1, vmath::vec3(1.0f, 1.0f, 0.0f));
	object_light_loc = glGetUniformLocation(object_prog, "Lights[2].coneDirection");
	glUniform3fv(object_light_loc, 1, vmath::vec3(-0.3f, 0.5f, -0.9f));
	object_light_loc = glGetUniformLocation(object_prog, "Lights[2].spotCosCutoff");
	glUniform1f(object_light_loc, 0.8);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[2].spotExponent");
	glUniform1f(object_light_loc, 2.0);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[2].constantAttenuation");
	glUniform1f(object_light_loc, 0.5f);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[2].linearAttenuation");
	glUniform1f(object_light_loc, 0.01f);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[2].quadraticAttenuation");
	glUniform1f(object_light_loc, 0.001f);

	object_light_loc = glGetUniformLocation(object_prog, "Lights[3].isEnabled");
	glUniform1i(object_light_loc, false);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[4].isEnabled");
	glUniform1i(object_light_loc, false);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[5].isEnabled");
	glUniform1i(object_light_loc, false);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[6].isEnabled");
	glUniform1i(object_light_loc, false);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[7].isEnabled");
	glUniform1i(object_light_loc, false);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[8].isEnabled");
	glUniform1i(object_light_loc, false);
	object_light_loc = glGetUniformLocation(object_prog, "Lights[9].isEnabled");
	glUniform1i(object_light_loc, false);

	object.LoadFromVBM("Media/torus.vbm", 0, 1, 2);
}

void Ex07_15::Display()
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

void Ex07_15::keyboard( unsigned char key, int x, int y )
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
