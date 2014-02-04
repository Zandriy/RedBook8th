/*
* Ex03_11.cpp
*
* Created on: Feb 04, 2014
* Author: Andrew Zhabura
*/

#include "Ex03_11.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"

#define INSTANCE_COUNT 200

Ex03_11::Ex03_11()
	: OGLWindow("Example03_11", "Example 3.11")
{
}

Ex03_11::~Ex03_11()
{
	glUseProgram(0);
	glDeleteProgram(render_prog);
	glDeleteVertexArrays(1, vao);
	glDeleteBuffers(1, vbo);
}

void Ex03_11::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo shader_info[] =
	{
		{ GL_VERTEX_SHADER, "Shaders/sh03_11.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh03_11.frag" },
		{ GL_NONE, NULL }
	};

	render_prog = LoadShaders(shader_info);

	glUseProgram(render_prog);

	// "model_matrix" is actually an array of 4 matrices
	render_view_matrix_loc = glGetUniformLocation(render_prog, "view_matrix");
	render_projection_matrix_loc = glGetUniformLocation(render_prog, "projection_matrix");

	// Load the object
	object.LoadFromVBM("Media/armadillo_low.vbm", 0, 1, 2);

	// Bind its vertex array object so that we can append the instanced attributes
	object.BindVertexArray();

    // Get the locations of the vertex attributes in 'prog', which is the
    // (linked) program object that we're going to be rendering with. Note
    // that this isn't really necessary because we specified locations for
    // all the attributes in our vertex shader. This code could be made
    // more concise by assuming the vertex attributes are where we asked
    // the compiler to put them.
    int position_loc    = glGetAttribLocation(render_prog, "position");
    int normal_loc      = glGetAttribLocation(render_prog, "normal");
    int color_loc       = glGetAttribLocation(render_prog, "color");
    int matrix_loc      = glGetAttribLocation(render_prog, "model_matrix");

    // Configure the regular vertex attribute arrays - position and color.
    /*
    // This is commented out here because the VBM object takes care
    // of it for us.
    glBindBuffer(GL_ARRAY_BUFFER, position_buffer);
    glVertexAttribPointer(position_loc, 4, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(position_loc);
    glBindBuffer(GL_ARRAY_BUFFER, normal_buffer);
    glVertexAttribPointer(normal_loc, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(normal_loc);
    */

    // Generate the colors of the objects
    vmath::vec4 colors[INSTANCE_COUNT];

    for (int n = 0; n < INSTANCE_COUNT; n++)
    {
        float a = float(n) / 4.0f;
        float b = float(n) / 5.0f;
        float c = float(n) / 6.0f;

        colors[n][0] = 0.5f + 0.25f * (sinf(a + 1.0f) + 1.0f);
        colors[n][1] = 0.5f + 0.25f * (sinf(b + 2.0f) + 1.0f);
        colors[n][2] = 0.5f + 0.25f * (sinf(c + 3.0f) + 1.0f);
        colors[n][3] = 1.0f;
    }

    glGenBuffers(1, &color_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, color_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_DYNAMIC_DRAW);

    // Now we set up the color array. We want each instance of our geometry
    // to assume a different color, so we'll just pack colors into a buffer
    // object and make an instanced vertex attribute out of it.
    glBindBuffer(GL_ARRAY_BUFFER, color_buffer);
    glVertexAttribPointer(color_loc, 4, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(color_loc);
    // This is the important bit... set the divisor for the color array to
    // 1 to get OpenGL to give us a new value of 'color' per-instance
    // rather than per-vertex.
    glVertexAttribDivisor(color_loc, 1);

    // Likewise, we can do the same with the model matrix. Note that a
    // matrix input to the vertex shader consumes N consecutive input
    // locations, where N is the number of columns in the matrix. So...
    // we have four vertex attributes to set up.
    glGenBuffers(1, &model_matrix_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, model_matrix_buffer);
    glBufferData(GL_ARRAY_BUFFER, INSTANCE_COUNT * sizeof(vmath::mat4), NULL, GL_DYNAMIC_DRAW);
    // Loop over each column of the matrix...
    for (int i = 0; i < 4; i++)
    {
        // Set up the vertex attribute
        glVertexAttribPointer(matrix_loc + i,              // Location
                              4, GL_FLOAT, GL_FALSE,       // vec4
                              sizeof(vmath::mat4),                // Stride
                              (void *)(sizeof(vmath::vec4) * i)); // Start offset
        // Enable it
        glEnableVertexAttribArray(matrix_loc + i);
        // Make it instanced
        glVertexAttribDivisor(matrix_loc + i, 1);
    }

    // Done (unbind the object's VAO)
    glBindVertexArray(0);
}

void Ex03_11::Display()
{
	float t = float(GetTickCount() & 0x3FFF) / float(0x3FFF);
	static float q = 0.0f;
	static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);
	int n;

	// Clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Setup
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	// Bind the weight VBO and change its data
	glBindBuffer(GL_ARRAY_BUFFER, model_matrix_buffer);

	// Set model matrices for each instance
	vmath::mat4 * matrices = (vmath::mat4 *)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

	for (n = 0; n < INSTANCE_COUNT; n++)
	{
		float a = 50.0f * float(n) / 4.0f;
		float b = 50.0f * float(n) / 5.0f;
		float c = 50.0f * float(n) / 6.0f;

		matrices[n] = vmath::rotate(a + t * 360.0f, 1.0f, 0.0f, 0.0f) *
			vmath::rotate(b + t * 360.0f, 0.0f, 1.0f, 0.0f) *
			vmath::rotate(c + t * 360.0f, 0.0f, 0.0f, 1.0f) *
			vmath::translate(10.0f + a, 40.0f + b, 50.0f + c);
	}

	glUnmapBuffer(GL_ARRAY_BUFFER);

	// Activate instancing program
	glUseProgram(render_prog);

	float aspect = float(getHeight()) / getWidth();

	// Set up the view and projection matrices
	vmath::mat4 view_matrix(vmath::translate(0.0f, 0.0f, -1500.0f) * vmath::rotate(t * 360.0f * 2.0f, 0.0f, 1.0f, 0.0f));
	vmath::mat4 projection_matrix(vmath::frustum(-1.0f, 1.0f, -aspect, aspect, 1.0f, 5000.0f));

	glUniformMatrix4fv(render_view_matrix_loc, 1, GL_FALSE, view_matrix);
	glUniformMatrix4fv(render_projection_matrix_loc, 1, GL_FALSE, projection_matrix);

	// Render INSTANCE_COUNT objects
	object.Render(0, INSTANCE_COUNT);

	vmath::lookat(vmath::vec3(0.0f, 0.0f, 0.0f), vmath::vec3(1.0f, 0.0f, 0.0f), vmath::vec3(0.0f, 1.0f, 0.0f));

	glFlush();
}