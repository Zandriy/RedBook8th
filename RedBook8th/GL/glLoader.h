#ifndef __glLoader_h__
#define __glLoader_h__



#define GL_GLEXT_PROTOTYPES
#include "glcorearb.h"

// enum
// {
// 	false=0,
// 	true=1
// } bool;

#ifdef __cplusplus
extern "C" {
#endif

	extern PFNGLCLEARPROC			pglClear;
	extern PFNGLCLEARCOLORPROC		pglClearColor;

// #define glClear					pglClear
// #define glClearColor			pglClearColor

	void GL_1_0_LoadFuncPointers();

#ifdef __cplusplus
}
#endif

#endif // !__glLoader_h__
