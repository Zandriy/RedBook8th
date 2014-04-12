/*
* Ex11_04.h
*
* Created on: Apr 12, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex11_04_h
#define Ex11_04_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex11_04 : public OGLWindow
{
public:
	Ex11_04();
	~Ex11_04();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();

	// Program to construct the linked list (renders the transparent objects)
	GLuint  list_build_program;

	// Color palette buffer texture
	GLuint  image_palette_buffer;
	GLuint  image_palette_texture;

	// Output image and PBO for clearing it
	GLuint  output_texture;
	GLuint  output_texture_clear_buffer;

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

#endif // Ex11_04_h