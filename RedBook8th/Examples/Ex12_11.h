/*
* Ex12_11.h
*
* Created on: Apr 17, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex12_11_h
#define Ex12_11_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex12_11 : public OGLWindow
{
private:
	// Member variables
	GLuint  compute_prog;
	GLuint  compute_shader;

	// Texture to process
	GLuint  input_image;

	// Texture for compute shader to write into
	GLuint  intermediate_image;
	GLuint  output_image;

	// Program, vao and vbo to render a full screen quad
	GLuint  render_prog;
	GLuint  render_vao;
	GLuint  render_vbo;
public:
	Ex12_11();
	~Ex12_11();
	void InitGL();
private:
	void Display();
};

#endif // Ex12_11_h