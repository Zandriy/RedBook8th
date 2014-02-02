/*
* Ex03_05.h
*
* Created on: Feb 02, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex03_05_h
#define Ex03_05_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex03_05 : public OGLWindow
{
private:
	enum VAO_IDs { Triangles, NumVAOs };
	enum Buffer_IDs { ArrayBuffer, NumBuffers };
	enum Attrib_IDs { vPosition = 0, fPosition = 1 };

	GLuint  VAOs[NumVAOs];
	GLuint  Buffers[NumBuffers];

	static const GLuint  NumVertices = 4;
public:
	Ex03_05();
	~Ex03_05();
	void InitGL();
private:
	void Display();

	GLuint render_prog;
	GLuint vao[1];
	GLuint vbo[1];
	GLuint ebo[1];

	GLint render_model_matrix_loc;
	GLint render_projection_matrix_loc;
};

#endif // Ex03_05_h