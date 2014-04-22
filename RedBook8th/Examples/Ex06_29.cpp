/*
* Ex06_29.cpp
*
* Created on: Feb 21, 2014
* Author: Andrew Zhabura
*/

#include "Ex06_29.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/libtarga.h"

#define POINT_COUNT 25

Ex06_29::Ex06_29()
	: OGLWindow("Example06_29", "Example 6.29 (M)")
{
}

static inline float random_float()
{
	float res;
	unsigned int tmp;
	static unsigned int seed = 0x13371337;

	seed *= 16807;

	tmp = seed ^ (seed >> 4) ^ (seed << 15);

	*((unsigned int *) &res) = (tmp >> 9) | 0x3F800000;

	return (res - 1.0f);
}

void Ex06_29::InitGL()
{
	if (! LoadGL() )
		return;

	static ShaderInfo shader_info[] =
	{
		{ GL_VERTEX_SHADER, "Shaders/pointsprites_sphere.vs.glsl", 0 },
		{ GL_FRAGMENT_SHADER, "Shaders/pointsprites_sphere.fs.glsl", 0 },
		{ GL_NONE, NULL, 0 }
	};

	render_prog = LoadShaders(shader_info);

	glUseProgram(render_prog);

	// "model_matrix" is actually an array of 4 matrices
	render_model_matrix_loc = glGetUniformLocation(render_prog, "model_matrix");
	render_projection_matrix_loc = glGetUniformLocation(render_prog, "projection_matrix");

	// A single triangle
	static vmath::vec4 * vertex_positions;

	// Set up the vertex attributes
	glGenVertexArrays(1, vao);
	glBindVertexArray(vao[0]);

	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, POINT_COUNT * sizeof(vmath::vec4), NULL, GL_STATIC_DRAW);

	vertex_positions = (vmath::vec4 *)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	for (int n = 0; n < POINT_COUNT; n++)
	{
		vertex_positions[n] = vmath::vec4(random_float() * 1.5f - 1.0f, random_float() * 2.5f - 1.0f, random_float() * 2.0f - 1.0f, 1.0f);
	}
	glUnmapBuffer(GL_ARRAY_BUFFER);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (const GLvoid *)sizeof(vertex_positions));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);
	glEnable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_POINT_SPRITE);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Ex06_29::Display()
{
	float t = float(GetTickCount() & 0x1FFF) / float(0x1FFF);
	static float q = 0.0f;
	static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

	vmath::mat4 model_matrix;

	// Setup
	glEnable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Activate simple shading program
	glUseProgram(render_prog);

	float aspect = float(getHeight()) / getWidth();

	// Set up the model and projection matrix
	vmath::mat4 projection_matrix(vmath::frustum(-1.0f, 1.0f, -aspect, aspect, 1.0f, 8.0f));
	glUniformMatrix4fv(render_projection_matrix_loc, 1, GL_FALSE, projection_matrix);

	// Draw Arrays...
	model_matrix = vmath::translate(0.0f, 0.0f, -2.0f) *
		vmath::rotate(t * 360.0f, Y) * vmath::rotate(t * 720.0f, Z);
	glUniformMatrix4fv(render_model_matrix_loc, 1, GL_FALSE, model_matrix);
	glDrawArrays(GL_POINTS, 0, POINT_COUNT);

	Swap();
}

void Ex06_29::keyboard( unsigned char key, int x, int y )
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