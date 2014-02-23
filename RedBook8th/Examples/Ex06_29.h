/*
* Ex06_29.h
*
* Created on: Feb 21, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex06_29_h
#define Ex06_29_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex06_29 : public OGLWindow
{
private:
 	GLuint render_prog;
 	GLuint vao[1];
 	GLuint vbo[1];
 	GLuint sprite_texture;
 
 	GLint render_model_matrix_loc;
 	GLint render_projection_matrix_loc;
public:
	Ex06_29();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();
};

#endif // Ex06_29_h