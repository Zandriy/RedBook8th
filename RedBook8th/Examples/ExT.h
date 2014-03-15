/*
* ExT.h
*
* Created on: Feb 25, 2014
* Author: Andrew Zhabura
*/

#ifndef ExT_h
#define ExT_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class ExT : public OGLWindow
{
public:
	ExT();
	~ExT();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	// Program, vao and vbo to render a full screen quad
	GLuint  render_prog;
 
 	// Uniform locations
 	GLint   mv_mat_loc;
 	GLint   prj_mat_loc;
 	GLint   col_amb_loc;
 	GLint   col_diff_loc;
	GLint   col_spec_loc;

	// Object to render
	VBObject    object;
};

#endif // ExT_h