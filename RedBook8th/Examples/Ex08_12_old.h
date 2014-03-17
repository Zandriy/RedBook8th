/*
* Ex08_12.h
*
* Created on: Mar 17, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex08_12_h
#define Ex08_12_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex08_12 : public OGLWindow
{
public:
	Ex08_12();
	~Ex08_12();
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

#endif // Ex08_12_h