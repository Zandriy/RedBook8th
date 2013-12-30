#include "glLoader.h"

PFNGLCLEARPROC			pglClear = 0;
PFNGLCLEARCOLORPROC		pglClearColor = 0;

void GL_1_0_LoadFuncPointers()
{
	//glClear = (PFNGLCLEARPROC)wglGetProcAddress("glClear");
	//glClearColor = (PFNGLCLEARCOLORPROC)wglGetProcAddress("glClearColor");

	//return (glClear && glClearColor);
}
