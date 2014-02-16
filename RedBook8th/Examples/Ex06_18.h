/*
* Ex06_18.h
*
* Created on: Feb 16, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex06_18_h
#define Ex06_18_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex06_18 : public OGLWindow
{
public:
	Ex06_18();
	~Ex06_18();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint skybox_prog, object_prog;
	GLuint tex;
	GLint skybox_rotate_loc;

	GLint object_mat_mvp_loc;
	GLint object_mat_mv_loc;

	VBObject object;
	GLuint vao;

	GLuint cube_vbo;
	GLuint cube_element_buffer;
};

#endif // Ex06_18_h