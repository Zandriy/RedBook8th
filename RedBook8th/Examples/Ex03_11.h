/*
* Ex03_11.h
*
* Created on: Feb 04, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex03_11_h
#define Ex03_11_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex03_11 : public OGLWindow
{
private:
	enum VAO_IDs { Triangles, NumVAOs };
	enum Buffer_IDs { ArrayBuffer, NumBuffers };
	enum Attrib_IDs { vPosition = 0, fPosition = 1 };

	GLuint  VAOs[NumVAOs];
	GLuint  Buffers[NumBuffers];

	static const GLuint  NumVertices = 4;
public:
	Ex03_11();
	~Ex03_11();
	void InitGL();
private:
	void Display();

	GLuint render_prog;
 	GLuint vao[1];
 	GLuint vbo[1];
 	VBObject object;
 
 	GLint render_view_matrix_loc;
 	GLint render_projection_matrix_loc;
 	GLuint color_buffer;
 	GLuint model_matrix_buffer;
};

#endif // Ex03_11_h