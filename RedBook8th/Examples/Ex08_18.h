/*
* Ex08_18.h
*
* Created on: Mar 18, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex08_18_h
#define Ex08_18_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex08_18 : public OGLWindow
{
public:
	Ex08_18();
	~Ex08_18();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();
	void make3DNoiseTexture();
	double noise3(double *ni);
	void setNoiseFrequency(int frequency) 
	{
		freq = frequency;
	}

	GLuint object_prog;

	GLint object_mat_mv_loc;
	GLint object_mat_mvp_loc;

	VBObject object;

	static const int noise3DTexSize = 128;
	GLuint noise3DTexName;
	GLubyte *noise3DTexPtr;
	int freq;
};

#endif // Ex08_18_h