/*
* Ex07_15.h
*
* Created on: Mar 6, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex07_15_h
#define Ex07_15_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>
#include "Auxiliary/vbm.h"

class Ex07_15 : public OGLWindow
{
public:
	Ex07_15();
	~Ex07_15();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();
	void DrawScene(bool depth_only);

	// Program to render from the light's position
	GLuint render_light_prog;
	struct
	{
		GLint model_view_projection_matrix;
	} render_light_uniforms;

	// FBO to render depth with
	GLuint  depth_fbo;
	GLuint  depth_texture;

	// Program to render the scene from the viewer's position
	GLuint render_scene_prog;
	struct
	{
		GLint model_matrix;
		GLint view_matrix;
		GLint projection_matrix;
		GLint shadow_matrix;
		GLint light_position;
		GLint material_ambient;
		GLint material_diffuse;
		GLint material_specular;
		GLint material_specular_power;
	} render_scene_uniforms;

	// Ground plane
	GLuint  ground_vbo;
	GLuint  ground_vao;

	VBObject object;

	GLint current_width;
	GLint current_height;
};

#endif // Ex07_15_h