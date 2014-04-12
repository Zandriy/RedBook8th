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
	, wot(0.0f)
	, hot(0.0f)
{
}

Ex10_21::~Ex10_21()
{
	glUseProgram(0);
	glDeleteBuffers(1, &vbo);
	glDeleteProgram(prog);
	glDeleteVertexArrays(1, &vao);
}

void Ex10_21::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh10_21.vert" },
		{ GL_GEOMETRY_SHADER, "Shaders/sh10_21.geom" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh10_21.frag" },
		{ GL_NONE, NULL }
	};

	prog = LoadShaders( shaders );
	glLinkProgram(prog);

	model_matrix_pos = glGetUniformLocation(prog, "model_matrix");
	projection_matrix_pos = glGetUniformLocation(prog, "projection_matrix");

	object.LoadFromVBM("Media/ninja.vbm", 0, 1, 2);
}

void Ex10_21::Display()
{
	if (int(wot / 0.5f) != getWidth() || int(hot / 0.5f) != getHeight())
	{
		wot = getWidth() * 0.5f;
		hot = getHeight() * 0.5f;

		glViewportIndexedf(0, 0.0f, 0.0f, wot, hot);
		glViewportIndexedf(1, wot, 0.0f, wot, hot);
		glViewportIndexedf(2, 0.0f, hot, wot, hot);
		glViewportIndexedf(3, wot, hot, wot, hot);
	}


	float t = float(GetTickCount() & 0x3FFF) / float(0x3FFF);
	static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

	glClearColor( 0.3f, 0.1f, 0.2f, 1.0f );
	glClearDepth( 1.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glUseProgram(prog);

	float aspect = hot / wot;

	vmath::mat4 p(vmath::frustum(-1.0f, 1.0f, aspect, -aspect, 1.0f, 5000.0f));
	vmath::mat4 m[4];

	for (int i = 0; i < 4; i++)
	{
		m[i] = vmath::mat4(vmath::translate(0.0f, 0.0f, 100.0f * sinf(6.28318531f * t + i) - 230.0f) *
			vmath::rotate(360.0f * t * float(i + 1), X) *
			vmath::rotate(360.0f * t * float(i + 2), Y) *
			vmath::rotate(360.0f * t * float(5 - i), Z) *
			vmath::translate(0.0f, -80.0f, 0.0f));
	}

	glUniformMatrix4fv(model_matrix_pos, 4, GL_FALSE, m[0]);
	glUniformMatrix4fv(projection_matrix_pos, 1, GL_FALSE, p);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	object.Render();

	glFlush();
}

void Ex10_21::keyboard( unsigned char key, int x, int y )
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

void Ex10_21::Show()
{
	wot = 0.0f;
	hot = 0.0f;
	OGLWindow::Show();
}

void Ex10_21::Hide()
{
	glViewportIndexedf(0, 0.0f, 0.0f, getWidth(), getHeight());
	OGLWindow::Hide();
}