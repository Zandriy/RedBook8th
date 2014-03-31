/*
* Ex10_15.h
*
* Created on: Mar 31, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex10_15_h
#define Ex10_15_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex10_15 : public OGLWindow
{
public:
	Ex10_15();
	~Ex10_15();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint object_prog;

	GLint object_mat_mvp_loc;

	VBObject object;
};

#endif // Ex10_15_h