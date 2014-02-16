/*
* Ex06_14.h
*
* Created on: Feb 16, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex06_14_h
#define Ex06_14_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex06_14 : public OGLWindow
{
public:
	Ex06_14();
	~Ex06_14();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint base_prog;
	GLuint vao;
	GLuint quad_vbo;
	GLuint tex1;
	GLuint tex2;
	GLint  time_loc;
};

#endif // Ex06_14_h