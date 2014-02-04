/*
* Ex03_10.h
*
* Created on: Feb 04, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex03_10_h
#define Ex03_10_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex03_10 : public OGLWindow
{
private:
	enum VAO_IDs { Triangles, NumVAOs };
	enum Buffer_IDs { ArrayBuffer, NumBuffers };
	enum Attrib_IDs { vPosition = 0, fPosition = 1 };

	GLuint  VAOs[NumVAOs];
	GLuint  Buffers[NumBuffers];

	static const GLuint  NumVertices = 4;
public:
	Ex03_10();
	~Ex03_10();
	void InitGL();
private:
	void Display();

 	GLuint render_prog;
 	GLuint vao[1];
 	GLuint vbo[1];
 	VBObject object;
 	GLuint weight_vbo;
 	GLuint color_vbo;
 
 	GLint render_model_matrix_loc;
 	GLint render_projection_matrix_loc;
};

#endif // Ex03_10_h