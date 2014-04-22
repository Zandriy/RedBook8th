/*
* Ex07_lights.cpp
*
* Created on: Feb 25, 2014
* Author: Andrew Zhabura
*/

#include "Ex07_lights.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

Ex07_lights::Ex07_lights()
	: OGLWindow("Ex07_lights", "Ex 07-lights (M)")
{
}

Ex07_lights::~Ex07_lights()
{
	glUseProgram(0);
	glDeleteProgram(render_prog);
}

void Ex07_lights::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  render_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh07_lights.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh07_lights.frag" },
		{ GL_NONE, NULL }
	};

	render_prog = LoadShaders( render_shaders );

	glLinkProgram(render_prog);

	mv_mat_loc = glGetUniformLocation(render_prog, "model_matrix");
	prj_mat_loc = glGetUniformLocation(render_prog, "proj_matrix");
	col_amb_loc = glGetUniformLocation(render_prog, "color_ambient");
	col_diff_loc = glGetUniformLocation(render_prog, "color_diffuse");
	col_spec_loc = glGetUniformLocation(render_prog, "color_specular");

	object.LoadFromVBM("Media/torus.vbm", 0, 1, 2);
}

void Ex07_lights::Display()
{
	static const unsigned int start_time = GetTickCount() - 50000;
	float t = float((GetTickCount() - start_time)) / float(0x3FFF);
	static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 0.8f);

	vmath::mat4 mv_matrix(vmath::mat4::identity());
	vmath::mat4 prj_matrix(vmath::mat4::identity());

	mv_matrix = vmath::translate(vmath::vec3(0.0f, 0.0f, -70.0f)) *
		vmath::rotate(80.0f * 3.0f * t, Y) * vmath::rotate(50.0f * 3.0f * t, Z);

	float aspect = float(getHeight()) / getWidth();
	prj_matrix = vmath::perspective(35.0f, 1.0f / aspect, 0.1f, 100.0f) * mv_matrix;

	glUseProgram(render_prog);

	glUniformMatrix4fv(mv_mat_loc, 1, GL_FALSE, mv_matrix);
	glUniformMatrix4fv(prj_mat_loc, 1, GL_FALSE, prj_matrix);

	// Clear, select the rendering program and draw a full screen quad
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	object.Render();

	Swap();
}

void Ex07_lights::keyboard( unsigned char key, int x, int y )
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
