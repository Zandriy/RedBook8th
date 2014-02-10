/*
* Ex04_02.h
*
* Created on: Feb 10, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex04_02_h
#define Ex04_02_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex04_02 : public OGLWindow
{
private:
	enum VAO_IDs { Triangles, NumVAOs };
	enum Buffer_IDs { ArrayBuffer, NumBuffers };
	enum Attrib_IDs { vPosition = 0, vColor = 1 };

	GLuint  VAOs[NumVAOs];
	GLuint  Buffers[NumBuffers];

	static const GLuint  NumVertices = 6;
public:
	Ex04_02();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();
};

#endif // Ex04_02_h