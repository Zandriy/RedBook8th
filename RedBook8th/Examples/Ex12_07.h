/*
* Ex12_07.h
*
* Created on: Apr 17, 2014
* Author: Andrew Zhabura
*/

#ifndef Ex12_07_h
#define Ex12_07_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex12_07 : public OGLWindow
{
private:
	enum
	{
		PARTICLE_GROUP_SIZE     = 128,
		PARTICLE_GROUP_COUNT    = 8000,
		PARTICLE_COUNT          = (PARTICLE_GROUP_SIZE * PARTICLE_GROUP_COUNT),
		MAX_ATTRACTORS          = 64
	};

	// Compute program
	GLuint  compute_prog;
	GLint   dt_location;

	// Posisition and velocity buffers
	union
	{
		struct
		{
			GLuint position_buffer;
			GLuint velocity_buffer;
		};
		GLuint buffers[2];
	};

	// TBOs
	union
	{
		struct
		{
			GLuint position_tbo;
			GLuint velocity_tbo;
		};
		GLuint tbos[2];
	};

	// Attractor UBO
	GLuint  attractor_buffer;

	// Program, vao and vbo to render a full screen quad
	GLuint  render_prog;
	GLuint  render_vao;
	GLuint  render_vbo;

	// Mass of the attractors
	float attractor_masses[MAX_ATTRACTORS];
public:
	Ex12_07();
	~Ex12_07();
	void InitGL();
	virtual void keyboard( unsigned char key, int x, int y );
private:
	void Display();
};

#endif // Ex12_07_h