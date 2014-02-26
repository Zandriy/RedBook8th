/*
* ExTest.h
*
* Created on: Feb 25, 2014
* Author: Andrew Zhabura
*/

#ifndef ExTest_h
#define ExTest_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class ExTest : public OGLWindow
{
public:
	ExTest();
	~ExTest();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint object_prog;

	GLint object_mat_mvp_loc;

	VBObject object;
};

#endif // ExTest_h