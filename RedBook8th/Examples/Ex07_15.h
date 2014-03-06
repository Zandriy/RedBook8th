/*
* Ex07_15.h
*
* Created on: Mar 6, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex07_15_h
#define Ex07_15_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex07_15 : public OGLWindow
{
public:
	Ex07_15();
	~Ex07_15();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint object_prog;

	GLint object_mat_mvp_loc;
	GLint object_mat_mv_loc;

	VBObject object;
};

#endif // Ex07_15_h