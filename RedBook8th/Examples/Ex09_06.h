/*
* Ex09_06.h
*
* Created on: Mar 21, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex09_06_h
#define Ex09_06_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex09_06 : public OGLWindow
{
public:
	Ex09_06();
	void InitGL();

	void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint  PLoc;  // Projection matrix
	GLuint  MVLoc;  // Model View matrix
	GLuint program;

	bool rot;

	static const int  NumVertices = 4;  // vertices in our patch
};

#endif // Ex09_06_h