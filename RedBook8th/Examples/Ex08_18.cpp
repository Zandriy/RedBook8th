/*
* Ex08_18.cpp
*
* Created on: Mar 18, 2014
* Author: Andrew Zhabura
*/

#include "Ex08_18.h"

#include "GL/LoadShaders.h"
#include "Auxiliary/vmath.h"
#include "Auxiliary/vermilion.h"
#include <stdio.h>
#include <cmath>

Ex08_18::Ex08_18()
	: OGLWindow("Example08_18", "Example 8.18 (M)")
{
}

Ex08_18::~Ex08_18()
{
	glUseProgram(0);
	glDeleteProgram(object_prog);
}

void Ex08_18::InitGL()
{
	if (! LoadGL() )
		return;

	ShaderInfo  object_shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/sh08_16.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/sh08_18.frag" },
		{ GL_NONE, NULL }
	};

	object_prog = LoadShaders( object_shaders );

	glLinkProgram(object_prog);

	object_mat_mv_loc = glGetUniformLocation(object_prog, "MVMatrix");
	object_mat_mvp_loc = glGetUniformLocation(object_prog, "MVPMatrix");
	GLuint NormalMatrix_loc = glGetUniformLocation(object_prog, "NormalMatrix");

	GLuint Scale_loc = glGetUniformLocation(object_prog, "Scale");
	GLuint LightPosition_loc = glGetUniformLocation(object_prog, "LightPosition");

 	GLuint Color1_loc = glGetUniformLocation(object_prog, "Color1");
 	GLuint Color2_loc = glGetUniformLocation(object_prog, "Color2");
	GLuint NoiseScale_loc = glGetUniformLocation(object_prog, "NoiseScale");

	glUseProgram(object_prog);	

	GLfloat normal_matrix[3 * 3] = {
		0.5f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.0f,
		0.0f, 0.0f, 1.0f
	};

	glUniformMatrix3fv(NormalMatrix_loc, 1, GL_TRUE, normal_matrix);

	glUniform3fv(LightPosition_loc, 1, vmath::vec3(0.5f, 0.5f, -1.0f));
	glUniform1f(Scale_loc, 1.5f);

	glUniform3fv(Color1_loc, 1, vmath::vec3(0.8f, 0.7f, 0.0f));
	glUniform3fv(Color2_loc, 1, vmath::vec3(0.6f, 0.1f, 0.0f));
	glUniform1f(NoiseScale_loc, 1.2f);

	make3DNoiseTexture();

	glGenTextures(1, &noise3DTexName);
	glBindTexture(GL_TEXTURE_3D, noise3DTexName);
	glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA, noise3DTexSize,
		noise3DTexSize, noise3DTexSize, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, noise3DTexPtr);

	object.LoadFromVBM("Media/torus.vbm", 0, 1, 2);
}

void Ex08_18::Display()
{
	glBindTexture(GL_TEXTURE_3D, noise3DTexName);

	static const unsigned int start_time = GetTickCount() - 50000;
	float t = float((GetTickCount() - start_time)) / float(0x3FFF);
	static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
	static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
	static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

	vmath::mat4 tc_matrix(vmath::mat4::identity());

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDisable(GL_CULL_FACE);

	float aspect = float(getHeight()) / getWidth();

	glUseProgram(object_prog);

	tc_matrix = vmath::translate(vmath::vec3(0.0f, 0.0f, -70.0f)) *
		vmath::rotate(80.0f * 3.0f * t, Y) * vmath::rotate(50.0f * 3.0f * t, Z);

	glUniformMatrix4fv(object_mat_mv_loc, 1, GL_FALSE, tc_matrix);

	tc_matrix = vmath::perspective(35.0f, 1.0f / aspect, 0.1f, 100.0f) * tc_matrix;
	glUniformMatrix4fv(object_mat_mvp_loc, 1, GL_FALSE, tc_matrix);

	glClear(GL_DEPTH_BUFFER_BIT);

	object.Render();

	glFlush();
}

void Ex08_18::keyboard( unsigned char key, int x, int y )
{
	switch( key ) {
	case 'M': 
		for (int i = 0; i < 5000; ++i)
			Display();
		break;
	default:
		OGLWindow::keyboard(key, x, y);
		break;
	}
}

void Ex08_18::make3DNoiseTexture()
{
	int f, i, j, k, inc;
	int startFrequency = 4;
	int numOctaves = 4;
	double ni[3];
	double inci, incj, inck;
	int frequency = startFrequency;
	GLubyte *ptr;
	double amp = 0.5;
	if ((noise3DTexPtr = (GLubyte *) malloc(noise3DTexSize *
		noise3DTexSize *
		noise3DTexSize * 4))
		== NULL)
	{
		fprintf(stderr,
			"ERROR: Could not allocate 3D noise texture\n");
		exit(1);
	}
	for (f = 0, inc = 0; f < numOctaves;
		++f, frequency *= 2, ++inc, amp *= 0.5)
	{
		setNoiseFrequency(frequency);
		ptr = noise3DTexPtr;
		ni[0] = ni[1] = ni[2] = 0;
		inci = 1.0 / (noise3DTexSize / frequency);
		for (i = 0; i < noise3DTexSize; ++i, ni[0] += inci)
		{
			incj = 1.0 / (noise3DTexSize / frequency);
			for (j = 0; j < noise3DTexSize; ++j, ni[1] += incj)
			{
				inck = 1.0 / (noise3DTexSize / frequency);
				for (k = 0; k < noise3DTexSize;
					++k, ni[2] += inck, ptr += 4)
				{
					*(ptr+inc) = (GLubyte)(((noise3(ni)+1.0) * amp)
						* 128.0);
				}
			}
		}
	}
}

double Ex08_18::noise3(double *ni)
{
	const int i = 12;
	static int c = 0;
	static int cur = 0;
	if (cur >= i) cur = 0;
	int arr[] = {1, 2, 3, 7, 11, 13, 17, 19, 23, 29, 31, 37, 47, 53, 57};

	static double prevRes = -1.0;

	int i0 = ni[0];
	int i1 = ni[1];
	int i2 = ni[2];

	i0 %= 3;
	i1 %= 3;
	i2 %= 3;

	double res = std::sin( (ni[i0] * arr[cur + i1] - ni[i1] * arr[cur + i2] + ni[i2] * arr[cur + i0]) * (freq % (cur + 1)) );;

	++c;
	if (c % 100 == 0)
		++cur;
	if (c % 1000 == 0)
		prevRes = res;

	if ( prevRes < 0 && prevRes < res)
		res = prevRes - res;

	return res;
}
