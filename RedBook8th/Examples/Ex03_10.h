/*
* Ex03_10.h
*
* Created on: Feb 04, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex03_10_h
#define Ex03_10_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex03_10 : public OGLWindow
{
public:
	Ex03_10();
	~Ex03_10();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

 	GLuint render_prog;
 	GLuint vao[1];
 	GLuint vbo[1];
 	VBObject object;
 	GLuint weight_vbo;
 	GLuint color_vbo;
 
 	GLint render_model_matrix_loc;
 	GLint render_projection_matrix_loc;
};

#endif // Ex03_10_h