/*
* Ex11_29.h
*
* Created on: Apr 12, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex11_29_h
#define Ex11_29_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex11_29 : public OGLWindow
{
public:
	Ex11_29();
	~Ex11_29();
	void InitGL();
private:
	void Display();

	// Program to construct the linked list (renders the transparent objects)
	GLuint  list_build_program;

	// Head pointer image and PBO for clearing it
	GLuint  head_pointer_texture;
	GLuint  head_pointer_clear_buffer;
	// Atomic counter buffer
	GLuint  atomic_counter_buffer;
	// Linked list buffer
	GLuint  linked_list_buffer;
	GLuint  linked_list_texture;

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

#endif // Ex11_29_h