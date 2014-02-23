/*
* Ex06_30.h
*
* Created on: Feb 14, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex06_30_h
#define Ex06_30_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex06_30 : public OGLWindow
{
private:
	enum VAO_IDs { Triangles, NumVAOs };
	enum Buffer_IDs { ArrayBuffer, NumBuffers };
	enum Attrib_IDs { vPosition = 0 };

	GLuint  VAOs[NumVAOs];
	GLuint  Buffers[NumBuffers];

	static const GLuint  NumVertices = 6;
public:
	Ex06_30();
	~Ex06_30();
	void InitGL();
private:
	void Display();

	GLuint program, base_prog;
	GLuint vao;
	GLuint quad_vbo;
	
	GLsizei TexWidth, TexHeight;
	GLuint framebuffer, texture;
	GLuint buf_color;
};

#endif // Ex06_30_h