#ifndef Ex01_h
#define Ex01_h

#include "WinApi/OGLWindow.h"
#include <GL/glLoader.h>

class Ex01 : public OGLWindow
{
private:
	enum VAO_IDs { Triangles, NumVAOs };
	enum Buffer_IDs { ArrayBuffer, NumBuffers };
	enum Attrib_IDs { vPosition = 0 };

	GLuint  VAOs[NumVAOs];
	GLuint  Buffers[NumBuffers];

	static const GLuint  NumVertices = 6;
public:
	Ex01();
	void InitGL();
private:
};

#endif // Ex01_h