/*
* Ex08_01.h
*
* Created on: Mar 09, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex08_01_h
#define Ex08_01_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex08_01 : public OGLWindow
{
public:
	Ex08_01();
	~Ex08_01();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint object_prog;

	GLint object_mat_mv_loc;
	GLint object_mat_mvp_loc;

	VBObject object;
};

#endif // Ex08_01_h