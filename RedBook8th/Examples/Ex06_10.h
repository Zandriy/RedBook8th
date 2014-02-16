/*
* Ex06_10.h
*
* Created on: Feb 16, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex06_10_h
#define Ex06_10_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex06_10 : public OGLWindow
{
public:
	Ex06_10();
	~Ex06_10();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint base_prog;
	GLuint vao;
	GLuint quad_vbo;
	GLuint tex_checkerboard;
	GLuint buf_checkerboard;
};

#endif // Ex06_10_h