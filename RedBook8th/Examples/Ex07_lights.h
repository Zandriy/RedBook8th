/*
* Ex07_lights.h
*
* Created on: Feb 25, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex07_lights_h
#define Ex07_lights_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex07_lights : public OGLWindow
{
public:
	Ex07_lights();
	~Ex07_lights();
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

#endif // Ex07_lights_h