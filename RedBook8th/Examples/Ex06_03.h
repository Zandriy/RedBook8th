/*
* Ex06_03.h
*
* Created on: Feb 14, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex06_03_h
#define Ex06_03_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex06_03 : public OGLWindow
{
public:
	Ex06_03();
	~Ex06_03();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint base_prog;
	GLuint vao;
	GLuint quad_vbo;
	GLuint tex_checkerboard;
	GLuint tex_color;
	GLuint buf_checkerboard;
	GLuint buf_color;
};

#endif // Ex06_03_h