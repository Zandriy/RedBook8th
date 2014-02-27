/*
* Ex03_10.cpp
*
* Created on: Feb 04, 2014
* Author: Andrew Zhabura
*/

#include "Ex03_10.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"

#define INSTANCE_COUNT 200

Ex03_10::Ex03_10()
	: OGLWindow("Example03_10", "Example 3.10 (M)")
{
}

Ex03_10::~Ex03_10()
{
	glUseProgram(0);
	glDeleteProgram(render_prog);
	glDeleteVertexArrays(1, vao);
	glDeleteBuffers(1, vbo);
}

void Ex03_10::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo shader_info[] =
	{
		{ GL_VERTEX_SHADER, "Shaders/sh03_10.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh03_10.frag" },
		{ GL_NONE, NULL }
	};

	render_prog = LoadShaders(shader_info);

	glUseProgram(render_prog);

	// "model_matrix" is actually an array of 4 matrices
	render_model_matrix_loc = glGetUniformLocation(render_prog, "model_matrix");
	render_projection_matrix_loc = glGetUniformLocation(render_prog, "projection_matrix");

	// Load the object
	object.LoadFromVBM("Media/armadillo_low.vbm", 0, 1, 2);

	// Bind its vertex array object so that we can append the instanced attributes
	object.BindVertexArray();

	// Generate the colors of the objects
	vmath::vec4 colors[INSTANCE_COUNT];

	for (int n = 0; n < INSTANCE_COUNT; n++)
	{
		float a = float(n) / 4.0f;
		float b = float(n) / 5.0f;
		float c = float(n) / 6.0f;

		colors[n][0] = 0.5f * (sinf(a + 1.0f) + 1.0f);
		colors[n][1] = 0.5f * (sinf(b + 2.0f) + 1.0f);
		colors[n][2] = 0.5f * (sinf(c + 3.0f) + 1.0f);
		colors[n][3] = 1.0f;
	}

	// Create and allocate the VBO to hold the weights
	// Notice that we use the 'colors' array as the initial data, but only because
	// we know it's the same size.
	glGenBuffers(1, &weight_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, weight_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_DYNAMIC_DRAW);

	// Here is the instanced vertex attribute - set the divisor
	glVertexAttribDivisor(3, 1);
	// It's otherwise the same as any other vertex attribute - set the pointer and enable it
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(3);

	// Same with the instance color array
	glGenBuffers(1, &color_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, color_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

	glVertexAttribDivisor(4, 1);
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(4);

	// Done (unbind the object's VAO)
	glBindVertexArray(0);
}

void Ex03_10::Display()
{
	float t = float(GetTickCount() & 0x3FFFF) / float(0x3FFFF);
	static float q = 0.0f;
	static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);
	int n;

	// Set weights for each instance
	vmath::vec4 weights[INSTANCE_COUNT];

	for (n = 0; n < INSTANCE_COUNT; n++)
	{
		float a = float(n) / 4.0f;
		float b = float(n) / 5.0f;
		float c = float(n) / 6.0f;

		weights[n][0] = 0.5f * (sinf(t * 6.28318531f * 8.0f + a) + 1.0f);
		weights[n][1] = 0.5f * (sinf(t * 6.28318531f * 26.0f + b) + 1.0f);
		weights[n][2] = 0.5f * (sinf(t * 6.28318531f * 21.0f + c) + 1.0f);
		weights[n][3] = 0.5f * (sinf(t * 6.28318531f * 13.0f + a + b) + 1.0f);
	}

	// Bind the weight VBO and change its data
	glBindBuffer(GL_ARRAY_BUFFER, weight_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(weights), weights, GL_DYNAMIC_DRAW);

	// Clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Setup
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	// Activate instancing program
	glUseProgram(render_prog);

	// Set four model matrices
	vmath::mat4 model_matrix[4];

	for (n = 0; n < 4; n++)
	{
		model_matrix[n] = (vmath::scale(5.0f) *
			vmath::rotate(t * 360.0f * 40.0f + float(n + 1) * 29.0f, 0.0f, 1.0f, 0.0f) *
			vmath::rotate(t * 360.0f * 20.0f + float(n + 1) * 35.0f, 0.0f, 0.0f, 1.0f) *
			vmath::rotate(t * 360.0f * 30.0f + float(n + 1) * 67.0f, 0.0f, 1.0f, 0.0f) *
			vmath::translate((float)n * 10.0f - 15.0f, 0.0f, 0.0f) *
			vmath::scale(0.01f));
	}

	glUniformMatrix4fv(render_model_matrix_loc, 4, GL_FALSE, model_matrix[0]);

	float aspect = float(getHeight()) / getWidth() / 2;

	// Set up the projection matrix
	vmath::mat4 projection_matrix(vmath::frustum(-aspect, aspect, -aspect, aspect, 1.0f, 5000.0f) * vmath::translate(0.0f, 0.0f, -100.0f));

	glUniformMatrix4fv(render_projection_matrix_loc, 1, GL_FALSE, projection_matrix);

	// Render INSTANCE_COUNT objects
	object.Render(0, INSTANCE_COUNT);

	glFlush();
}

void Ex03_10::keyboard( unsigned char key, int x, int y )
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