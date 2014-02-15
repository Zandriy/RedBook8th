/*
* Ex03_02.h
*
* Created on: Feb 02, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex03_02_h
#define Ex03_02_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex03_02 : public OGLWindow
{
private:
 	GLuint render_prog;
 	GLuint vao[1];
 	GLuint vbo[1];
 	GLuint sprite_texture;
 
 	GLint render_model_matrix_loc;
 	GLint render_projection_matrix_loc;
public:
	Ex03_02();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();
};

#endif // Ex03_02_h