/*
* Ex03_07.h
*
* Created on: Feb 03, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex03_07_h
#define Ex03_07_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex03_07 : public OGLWindow
{
public:
	Ex03_07();
	~Ex03_07();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint render_prog;
	GLuint vao[1];
	GLuint vbo[1];
	GLuint ebo[1];

	GLint render_model_matrix_loc;
	GLint render_projection_matrix_loc;
};

#endif // Ex03_07_h