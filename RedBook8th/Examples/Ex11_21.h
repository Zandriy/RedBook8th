/*
* Ex11_21.h
*
* Created on: Apr 12, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex11_21_h
#define Ex11_21_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex11_21 : public OGLWindow
{
public:
	Ex11_21();
	~Ex11_21();
	void InitGL();
private:
	void Display();

	// Program to construct the linked list (renders the transparent objects)
	GLuint  list_build_program;

	// Color palette buffer texture
	GLuint  image_palette_buffer;
	GLuint  image_palette_texture;

	// Output image and PBO for clearing it
	GLuint  overdraw_count_buffer;
	GLuint  overdraw_count_clear_buffer;

	// Program to render the scene
	GLuint render_scene_prog;
	struct
	{
		GLint aspect;
		GLint time;
		GLint model_matrix;
		GLint view_matrix;
		GLint projection_matrix;
	} render_scene_uniforms;

	// Program to resolve 
	GLuint resolve_program;

	// Full Screen Quad
	GLuint  quad_vbo;
	GLuint  quad_vao;

	GLint current_width;
	GLint current_height;

	VBObject object;
};

#endif // Ex11_21_h