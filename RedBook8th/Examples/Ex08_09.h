/*
* Ex08_09.h
*
* Created on: Mar 15, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex08_09_h
#define Ex08_09_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex08_09 : public OGLWindow
{
public:
	Ex08_09();
	~Ex08_09();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint object_prog;

	GLint object_mat_mv_loc;
	GLint object_mat_mvp_loc;

	VBObject object;
};

#endif // Ex08_09_h