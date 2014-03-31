/*
* Ex10_07.h
*
* Created on: Mar 25, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex10_07_h
#define Ex10_07_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex10_07 : public OGLWindow
{
public:
	Ex10_07();
	~Ex10_07();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint object_prog;

	GLint object_mat_mvp_loc;

	VBObject object;
};

#endif // Ex10_07_h