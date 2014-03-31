/*
* Ex10_15.cpp
*
* Created on: Mar 31, 2014
* Author: Andrew Zhabura
*/

#include "Ex10_15.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"

Ex10_15::Ex10_15()
	: OGLWindow("Example10_15", "Example 10.15 (M)")
{
}

Ex10_15::~Ex10_15()
{
	glUseProgram(0);
	glDeleteProgram(sort_prog);
	glDeleteProgram(render_prog);
}

void Ex10_15::InitGL()
{
	if (! LoadGL() )
		return;

	glGenTransformFeedbacks(1, &xfb);
	glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, xfb);

	ShaderInfo  sort_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh10_15_sort.vert" },
		{ GL_GEOMETRY_SHADER, "Shaders/sh10_15_sort.geom" },
		{ GL_NONE, NULL }
	};

	sort_prog = LoadShaders( sort_shaders );

	static const char * varyings[] =
	{
		"rf_position", "rf_normal",
		"gl_NextBuffer",
		"lf_position", "lf_normal"
	};

	glTransformFeedbackVaryings(sort_prog, 5, varyings, GL_INTERLEAVED_ATTRIBS);

	glLinkProgram(sort_prog);
	glUseProgram(sort_prog);

	sort_mat_model_loc = glGetUniformLocation(sort_prog, "model_matrix");
	sort_mat_proj_loc = glGetUniformLocation(sort_prog, "projection_matrix");

	glGenVertexArrays(2, vao);
	glGenBuffers(2, vbo);

	for (int i = 0; i < 2; i++)
	{
		glBindBuffer(GL_TRANSFORM_FEEDBACK_BUFFER, vbo[i]);
		glBufferData(GL_TRANSFORM_FEEDBACK_BUFFER, 1024 * 1024 * sizeof(GLfloat), NULL, GL_DYNAMIC_COPY);
		glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, i, vbo[i]);

		glBindVertexArray(vao[i]);
		glBindBuffer(GL_ARRAY_BUFFER, vbo[i]);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(vmath::vec4) + sizeof(vmath::vec3), NULL);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vmath::vec4) + sizeof(vmath::vec3), (GLvoid *)(sizeof(vmath::vec4)));
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
	}
	
	ShaderInfo  render_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh10_15_render.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh10_15_render.frag" },
		{ GL_NONE, NULL }
	};

	render_prog = LoadShaders( render_shaders );
	
	glLinkProgram(render_prog);

	object.LoadFromVBM("Media/ninja.vbm", 0, 1, 2);
}

void Ex10_15::Display()
{
	float t = float(GetTickCount() & 0x3FFF) / float(0x3FFF);
	static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

	glDisable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(sort_prog);

	float aspect = float(getHeight()) / getWidth();

	vmath::mat4 p(vmath::frustum(-1.0f, 1.0f, aspect, -aspect, 1.0f, 5000.0f));
	vmath::mat4 m;

	m = vmath::mat4(vmath::translate(0.0f,
		0.0f,
		100.0f * sinf(6.28318531f * t) - 230.0f) *
		vmath::rotate(360.0f * t, X) *
		vmath::rotate(360.0f * t * 2.0f, Y) *
		vmath::rotate(360.0f * t * 5.0f, Z) *
		vmath::translate(0.0f, -80.0f, 0.0f));

	glUniformMatrix4fv(sort_mat_model_loc, 1, GL_FALSE, m[0]);
	glUniformMatrix4fv(sort_mat_proj_loc, 1, GL_FALSE, p);

	glEnable(GL_RASTERIZER_DISCARD);

	glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, xfb);
	glBeginTransformFeedback(GL_POINTS);

	object.Render();

	glEndTransformFeedback();
	glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0);

	glDisable(GL_RASTERIZER_DISCARD);

	static const vmath::vec4 colors[2] =
	{
		vmath::vec4(0.8f, 0.8f, 0.9f, 0.5f),
		vmath::vec4(0.3f, 1.0f, 0.3f, 0.8f)
	};

	glUseProgram(render_prog);

	glUniform4fv(0, 1, colors[0]);
	glBindVertexArray(vao[0]);
	glDrawTransformFeedbackStream(GL_TRIANGLES, xfb, 0);

	glUniform4fv(0, 1, colors[1]);
	glBindVertexArray(vao[1]);
	glDrawTransformFeedbackStream(GL_TRIANGLES, xfb, 1);

	glFlush();
}

void Ex10_15::keyboard( unsigned char key, int x, int y )
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
