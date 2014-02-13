/*
* Ex05_09.h
*
* Created on: Feb 13, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex05_09_h
#define Ex05_09_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex05_09 : public OGLWindow
{
public:
	Ex05_09();
	~Ex05_09();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint update_prog;
	GLuint vao[2];
	GLuint vbo[2];
	GLuint xfb;

	GLuint render_prog;
	GLuint geometry_vbo;
	GLuint render_vao;
	GLint render_model_matrix_loc;
	GLint render_projection_matrix_loc;

	GLuint geometry_tex;

	GLuint geometry_xfb;
	GLuint particle_xfb;

	GLint model_matrix_loc;
	GLint projection_matrix_loc;
	GLint triangle_count_loc;
	GLint time_step_loc;

	VBObject object;
};

#endif // Ex05_09_h