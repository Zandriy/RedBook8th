/*
* Ex06_02.h
*
* Created on: Feb 14, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex06_02_h
#define Ex06_02_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex06_02 : public OGLWindow
{
public:
	Ex06_02();
	~Ex06_02();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint base_prog;
	GLuint vao;
	GLuint quad_vbo;
	GLuint tex_checkerboard;
	GLuint tex_color;
};

#endif // Ex06_02_h