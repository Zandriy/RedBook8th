/*
* Ex06_01.h
*
* Created on: Feb 14, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex06_01_h
#define Ex06_01_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex06_01 : public OGLWindow
{
public:
	Ex06_01();
	~Ex06_01();
	void InitGL();
private:
	void Display();

	GLuint base_prog;
	GLuint vao;
	GLuint quad_vbo;
	GLuint tex;
};

#endif // Ex06_01_h