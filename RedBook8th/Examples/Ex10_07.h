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

	GLuint base_prog;
	GLint base_mat_model_loc;
	GLint base_mat_proj_loc;

	GLuint fur_prog;
	GLint fur_mat_model_loc;
	GLint fur_mat_proj_loc;
	GLuint fur_texture;

	bool m_spin, m_fur;

	VBObject object;
};

#endif // Ex10_07_h