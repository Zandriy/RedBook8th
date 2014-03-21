/*
* Ex09_08.h
*
* Created on: Mar 21, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex09_08_h
#define Ex09_08_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex09_08 : public OGLWindow
{
public:
	Ex09_08();
	void InitGL();

	void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint program;

	GLuint  InnerLoc;  // Inner tessellation paramter
	GLuint  OuterLoc;  // Outer tessellation paramter
	GLuint  PLoc;  // Projection matrix
	GLuint  MVLoc;  // Model View matrix

	GLfloat  Inner;
	GLfloat  Outer;
};

#endif // Ex09_08_h