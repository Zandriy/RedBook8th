/*
* Ex08_11.h
*
* Created on: Mar 15, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex08_11_h
#define Ex08_11_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex08_11 : public OGLWindow
{
public:
	Ex08_11();
	~Ex08_11();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint object_prog;

	GLint object_mat_mv_loc;
	GLint object_mat_mvp_loc;

	VBObject object;
};

#endif // Ex08_11_h