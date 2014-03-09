/*
* Ex08_03.h
*
* Created on: Mar 09, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex08_03_h
#define Ex08_03_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex08_03 : public OGLWindow
{
public:
	Ex08_03();
	~Ex08_03();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint object_prog;

	GLint object_mat_mv_loc;
	GLint object_mat_mvp_loc;

	VBObject object;
};

#endif // Ex08_03_h