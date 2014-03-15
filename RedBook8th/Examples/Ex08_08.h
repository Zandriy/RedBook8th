/*
* Ex08_08.h
*
* Created on: Mar 15, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex08_08_h
#define Ex08_08_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex08_08 : public OGLWindow
{
public:
	Ex08_08();
	~Ex08_08();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint object_prog;

	GLint object_mat_mvp_loc;

	VBObject object;
};

#endif // Ex08_08_h