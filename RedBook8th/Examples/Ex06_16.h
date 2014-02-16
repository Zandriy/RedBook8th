/*
* Ex06_16.h
*
* Created on: Feb 16, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex06_16_h
#define Ex06_16_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex06_16 : public OGLWindow
{
public:
	Ex06_16();
	~Ex06_16();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint base_prog;
	GLuint tex;
	GLuint vao;
	GLuint quad_vbo;
	GLint tc_rotate_loc;
};

#endif // Ex06_16_h