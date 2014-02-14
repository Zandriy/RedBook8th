/*
* Ex06_04.h
*
* Created on: Feb 14, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex06_04_h
#define Ex06_04_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex06_04 : public OGLWindow
{
public:
	Ex06_04();
	~Ex06_04();
	void InitGL();
private:
	void Display();

	GLuint base_prog;
	GLuint vao;
	GLuint quad_vbo;
	GLuint tex;
};

#endif // Ex06_04_h