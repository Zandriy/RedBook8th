/*
* Ex03_01.h
*
* Created on: Jun 18, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex03_01_h
#define Ex03_01_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex03_01 : public OGLWindow
{
private:
	enum VAO_IDs { Triangles, NumVAOs };
	enum Buffer_IDs { ArrayBuffer, NumBuffers };
	enum Attrib_IDs { vPosition = 0, fPosition = 1 };

	GLuint  VAOs[NumVAOs];
	GLuint  Buffers[NumBuffers];

	static const GLuint  NumVertices = 4;
public:
	Ex03_01();
	void InitGL();
private:
	void Display();
};

#endif // Ex03_01_h