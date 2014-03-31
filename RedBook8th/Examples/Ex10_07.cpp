/*
* Ex10_07.cpp
*
* Created on: Mar 25, 2014
* Author: Andrew Zhabura
*/

#include "Ex10_07.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

Ex10_07::Ex10_07()
	: OGLWindow("Example10_07", "Example 10.7 (F, M, S)")
	, m_spin(false)
	, m_fur(true)
{
}

Ex10_07::~Ex10_07()
{
	glUseProgram(0);
	glDeleteProgram(base_prog);
	glDeleteProgram(fur_prog);
}

void Ex10_07::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  base_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh10_07_base.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh10_07_base.frag" },
		{ GL_NONE, NULL }
	};

	base_prog = LoadShaders( base_shaders );

	glLinkProgram(base_prog);

	base_mat_model_loc = glGetUniformLocation(base_prog, "model_matrix");
	base_mat_proj_loc = glGetUniformLocation(base_prog, "projection_matrix");

	ShaderInfo  fur_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh10_07_fur.vert" },
		{ GL_GEOMETRY_SHADER, "Shaders/sh10_07_fur.geom" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh10_07_fur.frag" },
		{ GL_NONE, NULL }
	};

	fur_prog = LoadShaders( fur_shaders );

	glLinkProgram(fur_prog);

	fur_mat_model_loc = glGetUniformLocation(fur_prog, "model_matrix");
	fur_mat_proj_loc = glGetUniformLocation(fur_prog, "projection_matrix");

	glUseProgram(fur_prog);

	glGenTextures(1, &fur_texture);
	unsigned char * tex = (unsigned char *)malloc(1024 * 1024 * 4);
	memset(tex, 0, 1024 * 1024 * 4);

	int n, m;

	for (n = 0; n < 256; n++)
	{
		for (m = 0; m < 1270; m++)
		{
			int x = rand() & 0x3FF;
			int y = rand() & 0x3FF;
			tex[(y * 1024 + x) * 4 + 0] = (rand() & 0x3F) + 0xC0;
			tex[(y * 1024 + x) * 4 + 1] = (rand() & 0x3F) + 0xC0;
			tex[(y * 1024 + x) * 4 + 2] = (rand() & 0x3F) + 0xC0;
			tex[(y * 1024 + x) * 4 + 3] = n;
		}
	}

	glBindTexture(GL_TEXTURE_2D, fur_texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1024, 1024, 0, GL_RGBA, GL_UNSIGNED_BYTE, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	free(tex);

	object.LoadFromVBM("Media/ninja.vbm", 0, 1, 2);
}

void Ex10_07::Display()
{
	float t = float(GetTickCount() & 0x3FFF) / float(0x3FFF);
	static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float aspect = float(getHeight()) / getWidth();

	vmath::mat4 p(vmath::frustum(-1.0f, 1.0f, aspect, -aspect, 1.0f, 5000.0f));
	vmath::mat4 m;

	if (m_spin)
	{
		m = vmath::mat4(vmath::translate(0.0f, 0.0f,
			100.0f * sinf(6.28318531f * t) - 130.0f) *
			vmath::rotate(360.0f * t, X) *
			vmath::rotate(360.0f * t * 1.0f, Y) *
			vmath::rotate(180.0f, Z) *
			vmath::translate(0.0f, -80.0f, 0.0f));
	}
	else
	{
		m = vmath::mat4(vmath::translate(0.0f, 0.0f, - 130.0f) *
			vmath::rotate(360.0f * t * 1.0f, Y) *
			vmath::rotate(180.0f, Z) *
			vmath::translate(0.0f, -80.0f, 0.0f));
	}

	glUseProgram(base_prog);

	glUniformMatrix4fv(base_mat_model_loc, 1, GL_FALSE, m[0]);
	glUniformMatrix4fv(base_mat_proj_loc, 1, GL_FALSE, p);

	glDisable(GL_BLEND);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	object.Render();

	if (m_fur)
	{
		glUseProgram(fur_prog);

		glUniformMatrix4fv(fur_mat_model_loc, 1, GL_FALSE, m[0]);
		glUniformMatrix4fv(fur_mat_proj_loc, 1, GL_FALSE, p);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glDepthMask(GL_FALSE);

		object.Render();
	}

	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);

	glFlush();
}

void Ex10_07::keyboard( unsigned char key, int x, int y )
{
	switch( key ) {
	case 'F': 
		m_fur = !m_fur;
		Display();
		break;
	case 'M': 
		for (int i = 0; i < c_repeat; ++i)
			Display();
		break;
	case 'S': 
		m_spin = !m_spin;
		Display();
		break;
	default:
		OGLWindow::keyboard(key, x, y);
		break;
	}
}
