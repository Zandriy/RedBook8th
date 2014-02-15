/*
* Ex03_14.h
*
* Created on: Feb 04, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex03_14_h
#define Ex03_14_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex03_14 : public OGLWindow
{
public:
	Ex03_14();
	~Ex03_14();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

 	GLuint render_prog;
 	GLuint vao[1];
 	GLuint vbo[1];
 	VBObject object;
 	GLuint color_tbo;
 	GLuint model_matrix_tbo;
 
 	GLint render_view_matrix_loc;
 	GLint render_projection_matrix_loc;
 	GLuint color_buffer;
 	GLuint model_matrix_buffer;
};

#endif // Ex03_14_h