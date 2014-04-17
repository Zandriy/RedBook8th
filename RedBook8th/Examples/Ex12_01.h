/*
* Ex12_01.h
*
* Created on: Apr 17, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex12_01_h
#define Ex12_01_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex12_01 : public OGLWindow
{
private:
	// Member variables
	GLuint  compute_prog;
	GLuint  compute_shader;

	// Texture for compute shader to write into
	GLuint  output_image;

	// Program, vao and vbo to render a full screen quad
	GLuint  render_prog;
	GLuint  render_vao;
	GLuint  render_vbo;
public:
	Ex12_01();
	~Ex12_01();
	void InitGL();
private:
	void Display();
};

#endif // Ex12_01_h