/*
* Ex07_01.h
*
* Created on: Feb 25, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex07_01_h
#define Ex07_01_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex07_01 : public OGLWindow
{
public:
	Ex07_01();
	~Ex07_01();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint object_prog;

	GLint object_mat_mvp_loc;

	VBObject object;
};

#endif // Ex07_01_h