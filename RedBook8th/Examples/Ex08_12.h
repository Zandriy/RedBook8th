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
#include "Auxiliary/vbm.h"

class Ex08_12 : public OGLWindow
{
public:
	Ex08_12();
	~Ex08_12();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint object_prog;

	GLint object_mat_mv_loc;
	GLint object_mat_mvp_loc;
	GLint MortarPct_loc;

	GLuint vao;
	GLuint quad_vbo;

	bool recalc_mat;
};

#endif // Ex08_12_h