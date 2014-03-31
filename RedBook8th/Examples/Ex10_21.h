/*
* Ex10_21.h
*
* Created on: Mar 31, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex10_21_h
#define Ex10_21_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex10_21 : public OGLWindow
{
public:
	Ex10_21();
	~Ex10_21();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint object_prog;

	GLint object_mat_mvp_loc;

	VBObject object;
};

#endif // Ex10_21_h