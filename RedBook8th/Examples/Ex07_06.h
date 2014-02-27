/*
* Ex07_06.h
*
* Created on: Feb 27, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex07_06_h
#define Ex07_06_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex07_06 : public OGLWindow
{
public:
	Ex07_06();
	~Ex07_06();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint object_prog;

	GLint object_mat_mvp_loc;
	GLint object_mat_mv_loc;

	VBObject object;
};

#endif // Ex07_06_h