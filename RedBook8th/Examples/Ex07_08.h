/*
* Ex07_08.h
*
* Created on: Feb 28, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex07_08_h
#define Ex07_08_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex07_08 : public OGLWindow
{
public:
	Ex07_08();
	~Ex07_08();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	GLuint object_prog;

	GLint object_mat_mvp_loc;
	GLint object_mat_mv_loc;

	VBObject object;
};

#endif // Ex07_08_h