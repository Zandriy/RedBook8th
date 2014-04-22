/*
* Ex06_30.cpp
*
* Created on: Feb 23, 2014
* Author: Andrew Zhabura
*/

#include "Ex06_30.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"

Ex06_30::Ex06_30()
	: OGLWindow("Example06_30", "Example 6.30")
	, TexWidth(16)
	, TexHeight(16)
{
}

Ex06_30::~Ex06_30()
{
	glUseProgram(0);
	glDeleteProgram(base_prog);
	glDeleteTextures(1, &texture);
}

void Ex06_30::InitGL()
{
	if (! LoadGL() )
		return;


	/////////////////// For drawing on screen

	ShaderInfo  base_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh06_02.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh06_02.frag" },
		{ GL_NONE, NULL }
	};

	base_prog = LoadShaders( base_shaders );

	glGenBuffers(1, &quad_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, quad_vbo);

	static const GLfloat quad_data[] =
	{
		0.75f, -0.75f,
		-0.75f, -0.75f,
		-0.75f, 0.75f,
		0.75f, 0.75f,

		0.0f, 0.0f,
		5.0f, 0.0f,
		5.0f, 5.0f,
		0.0f, 5.0f
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(quad_data), quad_data, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(8 * sizeof(float)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glLinkProgram(base_prog);

	/////////////////// For drawing on texture

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

	ShaderInfo  shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/triangles.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/triangles.frag" },
		{ GL_NONE, NULL }
	};

	program = LoadShaders(shaders);
	glUseProgram(program);

	glVertexAttribPointer(vPosition, 2, GL_FLOAT,
		GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);

	GLuint renderbuffer;
	// Create an empty texture
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, TexWidth,
		TexHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	// Create a depth buffer for our framebuffer
	glGenRenderbuffers(1, &renderbuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24,
		TexWidth, TexHeight);
	// Attach the texture and depth buffer to the framebuffer
	glGenFramebuffers(1, &framebuffer);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, framebuffer);
	glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER,
		GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
	glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER,
		GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, renderbuffer);
	glEnable(GL_DEPTH_TEST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
}

void Ex06_30::Display()
{
	// Render into the renderbuffer
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, framebuffer);
	glViewport(0, 0, TexWidth, TexHeight);
	glClearColor(1.0, 1.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(program);
	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);
	
	//Generate mipmaps of our texture
	glGenerateMipmap(GL_TEXTURE_2D);
	// Bind to the window-system framebuffer, unbinding from
	// the texture, which we can use to texture other objects
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	// Draw on screen
	glViewport(0, 0, getWidth(), getHeight());
	glClearColor(0.0, 0.0, 0.7, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Render using the texture
	glEnable(GL_TEXTURE_2D);

	glDisable(GL_CULL_FACE);
	glUseProgram(base_prog);

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	Swap();
}