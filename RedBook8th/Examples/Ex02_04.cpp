/*
* Ex02_04.cpp
*
* Created on: Jan 15, 2014
* Author: Andrew Zhabura
*/

#include "Ex02_04.h"

#include "GL/LoadShaders.h"

#include <fstream>

/* Helper function to convert GLSL types to storage sizes */
size_t
	TypeSize(GLenum type)
{
	size_t size;
#define CASE(Enum, Count, Type) \
case Enum: size = Count * sizeof(Type); break
	switch (type) {
		CASE(GL_FLOAT, 1, GLfloat);
		CASE(GL_FLOAT_VEC2, 2, GLfloat);
		CASE(GL_FLOAT_VEC3, 3, GLfloat);
		CASE(GL_FLOAT_VEC4, 4, GLfloat);
		CASE(GL_INT, 1, GLint);
		CASE(GL_INT_VEC2, 2, GLint);
		CASE(GL_INT_VEC3, 3, GLint);
		CASE(GL_INT_VEC4, 4, GLint);
		CASE(GL_UNSIGNED_INT, 1, GLuint);
		CASE(GL_UNSIGNED_INT_VEC2, 2, GLuint);
		CASE(GL_UNSIGNED_INT_VEC3, 3, GLuint);
		CASE(GL_UNSIGNED_INT_VEC4, 4, GLuint);
		CASE(GL_BOOL, 1, GLboolean);
		CASE(GL_BOOL_VEC2, 2, GLboolean);
		CASE(GL_BOOL_VEC3, 3, GLboolean);
		CASE(GL_BOOL_VEC4, 4, GLboolean);
		CASE(GL_FLOAT_MAT2, 4, GLfloat);
		CASE(GL_FLOAT_MAT2x3, 6, GLfloat);
		CASE(GL_FLOAT_MAT2x4, 8, GLfloat);
		CASE(GL_FLOAT_MAT3, 9, GLfloat);
		CASE(GL_FLOAT_MAT3x2, 6, GLfloat);
		CASE(GL_FLOAT_MAT3x4, 12, GLfloat);
		CASE(GL_FLOAT_MAT4, 16, GLfloat);
		CASE(GL_FLOAT_MAT4x2, 8, GLfloat);
		CASE(GL_FLOAT_MAT4x3, 12, GLfloat);
#undef CASE
	default:
		fprintf(stderr, "Unknown type: 0x%x\n", type);
		exit(EXIT_FAILURE);
		break;
	}
	return size;
}

Ex02_04::Ex02_04()
	: OGLWindow("Example02_04", "Example 2.4")
{
}

void Ex02_04::InitGL()
{
	if (! LoadGL() )
		return;

	GLuint program;
	glClearColor(0.7, 0.7, 0.9, 1.0);
	ShaderInfo shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh02_04.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh02_04.frag" },
		{ GL_NONE, NULL }
	};
	program = LoadShaders(shaders);
	glUseProgram(program);
	/* Initialize uniform values in uniform block "Uniforms" */
	GLuint uboIndex;
	GLint uboSize;
	GLuint ubo;
	GLvoid *buffer;
	/* Find the uniform buffer index for "Uniforms", and
	** determine the block’s sizes */
	uboIndex = glGetUniformBlockIndex(program, "Uniforms");
	glGetActiveUniformBlockiv(program, uboIndex,
		GL_UNIFORM_BLOCK_DATA_SIZE, &uboSize);
	buffer = malloc(uboSize);
	if (buffer == NULL) {
		fprintf(stderr, "Unable to allocate buffer\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		enum { Translation, Scale, Rotation, Enabled, NumUniforms };
		/* Values to be stored in the buffer object */
		GLfloat scale = 0.5;
		GLfloat translation[] = { 0.1, 0.1, 0.0 };
		GLfloat rotation[] = { 30, 0.0, 0.0, 1.0 };
		GLint enabled = GL_TRUE;
		/* Since we know the names of the uniforms
		** in our block, make an array of those values */
		const GLchar* names[NumUniforms] = {
			"translation",
			"scale",
			"rotation",
			"enabled"
		};
		/* Query the necessary attributes to determine
		** where in the buffer we should write
		** the values */
		GLuint indices[NumUniforms];
		GLint size[NumUniforms];
		GLint offset[NumUniforms];
		GLint type[NumUniforms];
		glGetUniformIndices(program, NumUniforms, names, indices);
		glGetActiveUniformsiv(program, NumUniforms, indices,
			GL_UNIFORM_OFFSET, offset);
		glGetActiveUniformsiv(program, NumUniforms, indices,
			GL_UNIFORM_SIZE, size);
		glGetActiveUniformsiv(program, NumUniforms, indices,
			GL_UNIFORM_TYPE, type);
		/* Copy the uniform values into the buffer */
		memcpy((char*)buffer + offset[Scale], &scale,
   			size[Scale] * TypeSize(type[Scale]));
		memcpy((char*)buffer + offset[Translation], &translation,
			size[Translation] * TypeSize(type[Translation]));
		memcpy((char*)buffer + offset[Rotation], &rotation,
			size[Rotation] * TypeSize(type[Rotation]));
		memcpy((char*)buffer + offset[Enabled], &enabled,
			size[Enabled] * TypeSize(type[Enabled]));

		/* Create the uniform buffer object, initialize
		** its storage, and associated it with the shader
		** program */
  		glGenBuffers(1, &ubo);
		glBindBuffer(GL_UNIFORM_BUFFER, ubo);
		glBufferData(GL_UNIFORM_BUFFER, uboSize,
			buffer, GL_STATIC_DRAW);
		glBindBufferBase(GL_UNIFORM_BUFFER, uboIndex, ubo);
	}

	glGenVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[Triangles]);

	GLfloat  vertices[NumVertices][2] = {
		{ -0.90, -0.90 },  // Triangle 1
		{  0.85, -0.90 },
		{ -0.90,  0.85 },
		{  0.90, -0.85 },  // Triangle 2
		{  0.90,  0.90 },
		{ -0.85,  0.90 }
	};

	glGenBuffers(NumBuffers, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
		vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(vPosition, 2, GL_FLOAT,
		GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);
}

void Ex02_04::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);

	Swap();
}
