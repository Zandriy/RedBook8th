/*
* Ex06_mipmap.h
*
* Created on: Feb 16, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex06_mipmap_h
#define Ex06_mipmap_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex06_mipmap : public OGLWindow
{
public:
	Ex06_mipmap();
	~Ex06_mipmap();
	void InitGL();
private:
	void Display();

	GLuint mipmap_prog;
	GLuint vao;

	GLuint vbo;
	GLuint element_buffer;

	GLuint tex;
	GLint tc_rotate_loc;
};

#endif // Ex06_mipmap_h