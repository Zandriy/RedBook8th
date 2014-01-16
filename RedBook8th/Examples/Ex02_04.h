/*
* Ex02_04.h
*
* Created on: Jan 15, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex02_04_h
#define Ex02_04_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex02_04 : public OGLWindow
{
private:
	enum VAO_IDs { Triangles, NumVAOs };
	enum Buffer_IDs { ArrayBuffer, NumBuffers };
	enum Attrib_IDs { vPosition = 0 };

	GLuint  VAOs[NumVAOs];
	GLuint  Buffers[NumBuffers];

	static const GLuint  NumVertices = 6;
public:
	Ex02_04();
	void InitGL();
private:
	void Display();
};

#endif // Ex02_04_h