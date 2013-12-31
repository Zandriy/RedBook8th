/*
* glLoader.cpp
*
* Created on: Dec 31, 2013
* Author: Andrew Zhabura
*/

#include "glLoader.h"

// PFNGLCLEARPROC			pglClear = 0;
// PFNGLCLEARCOLORPROC		pglClearColor = 0;
// 
// int GL_1_0_LoadFuncPointers()
// {
// 	glClear = (PFNGLCLEARPROC)wglGetProcAddress("glClear");
// 	glClearColor = (PFNGLCLEARPROC)wglGetProcAddress("glClearColor");
// 
// 	return glClear && glClearColor ? 1 : 0;
// }

/////////////////////////////// GL_VERSION_2_0 ////////////////////////////////

PFNGLBLENDEQUATIONSEPARATEPROC			pglBlendEquationSeparate = 0;
PFNGLDRAWBUFFERSPROC					pglDrawBuffers = 0;
PFNGLSTENCILOPSEPARATEPROC				pglStencilOpSeparate = 0;
PFNGLSTENCILFUNCSEPARATEPROC			pglStencilFuncSeparate = 0;
PFNGLSTENCILMASKSEPARATEPROC			pglStencilMaskSeparate = 0;
PFNGLATTACHSHADERPROC					pglAttachShader = 0;
PFNGLBINDATTRIBLOCATIONPROC				pglBindAttribLocation = 0;
PFNGLCOMPILESHADERPROC					pglCompileShader = 0;
PFNGLCREATEPROGRAMPROC					pglCreateProgram = 0;
PFNGLCREATESHADERPROC					pglCreateShader = 0;
PFNGLDELETEPROGRAMPROC					pglDeleteProgram = 0;
PFNGLDELETESHADERPROC					pglDeleteShader = 0;
PFNGLDETACHSHADERPROC					pglDetachShader = 0;
PFNGLDISABLEVERTEXATTRIBARRAYPROC		pglDisableVertexAttribArray = 0;
PFNGLENABLEVERTEXATTRIBARRAYPROC		pglEnableVertexAttribArray = 0;
PFNGLGETACTIVEATTRIBPROC				pglGetActiveAttrib = 0;
PFNGLGETACTIVEUNIFORMPROC				pglGetActiveUniform = 0;
PFNGLGETATTACHEDSHADERSPROC				pglGetAttachedShaders = 0;
PFNGLGETATTRIBLOCATIONPROC				pglGetAttribLocation = 0;
PFNGLGETPROGRAMIVPROC					pglGetProgramiv = 0;
PFNGLGETPROGRAMINFOLOGPROC				pglGetProgramInfoLog = 0;
PFNGLGETSHADERIVPROC					pglGetShaderiv = 0;
PFNGLGETSHADERINFOLOGPROC				pglGetShaderInfoLog = 0;
PFNGLGETSHADERSOURCEPROC				pglGetShaderSource = 0;
PFNGLGETUNIFORMLOCATIONPROC				pglGetUniformLocation = 0;
PFNGLGETUNIFORMFVPROC					pglGetUniformfv = 0;
PFNGLGETUNIFORMIVPROC					pglGetUniformiv = 0;
PFNGLGETVERTEXATTRIBDVPROC				pglGetVertexAttribdv = 0;
PFNGLGETVERTEXATTRIBFVPROC				pglGetVertexAttribfv = 0;
PFNGLGETVERTEXATTRIBIVPROC				pglGetVertexAttribiv = 0;
PFNGLGETVERTEXATTRIBPOINTERVPROC		pglGetVertexAttribPointerv = 0;
PFNGLISPROGRAMPROC						pglIsProgram = 0;
PFNGLISSHADERPROC						pglIsShader = 0;
PFNGLLINKPROGRAMPROC					pglLinkProgram = 0;
PFNGLSHADERSOURCEPROC					pglShaderSource = 0;
PFNGLUSEPROGRAMPROC						pglUseProgram = 0;
PFNGLUNIFORM1FPROC						pglUniform1f = 0;
PFNGLUNIFORM2FPROC						pglUniform2f = 0;
PFNGLUNIFORM3FPROC						pglUniform3f = 0;
PFNGLUNIFORM4FPROC						pglUniform4f = 0;
PFNGLUNIFORM1IPROC						pglUniform1i = 0;
PFNGLUNIFORM2IPROC						pglUniform2i = 0;
PFNGLUNIFORM3IPROC						pglUniform3i = 0;
PFNGLUNIFORM4IPROC						pglUniform4i = 0;
PFNGLUNIFORM1FVPROC						pglUniform1fv = 0;
PFNGLUNIFORM2FVPROC						pglUniform2fv = 0;
PFNGLUNIFORM3FVPROC						pglUniform3fv = 0;
PFNGLUNIFORM4FVPROC						pglUniform4fv = 0;
PFNGLUNIFORM1IVPROC						pglUniform1iv = 0;
PFNGLUNIFORM2IVPROC						pglUniform2iv = 0;
PFNGLUNIFORM3IVPROC						pglUniform3iv = 0;
PFNGLUNIFORM4IVPROC						pglUniform4iv = 0;
PFNGLUNIFORMMATRIX2FVPROC				pglUniformMatrix2fv = 0;
PFNGLUNIFORMMATRIX3FVPROC				pglUniformMatrix3fv = 0;
PFNGLUNIFORMMATRIX4FVPROC				pglUniformMatrix4fv = 0;
PFNGLVALIDATEPROGRAMPROC				pglValidateProgram = 0;
PFNGLVERTEXATTRIB1DPROC					pglVertexAttrib1d = 0;
PFNGLVERTEXATTRIB1DVPROC				pglVertexAttrib1dv = 0;
PFNGLVERTEXATTRIB1FPROC					pglVertexAttrib1f = 0;
PFNGLVERTEXATTRIB1FVPROC				pglVertexAttrib1fv = 0;
PFNGLVERTEXATTRIB1SPROC					pglVertexAttrib1s = 0;
PFNGLVERTEXATTRIB1SVPROC				pglVertexAttrib1sv = 0;
PFNGLVERTEXATTRIB2DPROC					pglVertexAttrib2d = 0;
PFNGLVERTEXATTRIB2DVPROC				pglVertexAttrib2dv = 0;
PFNGLVERTEXATTRIB2FPROC					pglVertexAttrib2f = 0;
PFNGLVERTEXATTRIB2FVPROC				pglVertexAttrib2fv = 0;
PFNGLVERTEXATTRIB2SPROC					pglVertexAttrib2s = 0;
PFNGLVERTEXATTRIB2SVPROC				pglVertexAttrib2sv = 0;
PFNGLVERTEXATTRIB3DPROC					pglVertexAttrib3d = 0;
PFNGLVERTEXATTRIB3DVPROC				pglVertexAttrib3dv = 0;
PFNGLVERTEXATTRIB3FPROC					pglVertexAttrib3f = 0;
PFNGLVERTEXATTRIB3FVPROC				pglVertexAttrib3fv = 0;
PFNGLVERTEXATTRIB3SPROC					pglVertexAttrib3s = 0;
PFNGLVERTEXATTRIB3SVPROC				pglVertexAttrib3sv = 0;
PFNGLVERTEXATTRIB4NBVPROC				pglVertexAttrib4Nbv = 0;
PFNGLVERTEXATTRIB4NIVPROC				pglVertexAttrib4Niv = 0;
PFNGLVERTEXATTRIB4NSVPROC				pglVertexAttrib4Nsv = 0;
PFNGLVERTEXATTRIB4NUBPROC				pglVertexAttrib4Nub = 0;
PFNGLVERTEXATTRIB4NUBVPROC				pglVertexAttrib4Nubv = 0;
PFNGLVERTEXATTRIB4NUIVPROC				pglVertexAttrib4Nuiv = 0;
PFNGLVERTEXATTRIB4NUSVPROC				pglVertexAttrib4Nusv = 0;
PFNGLVERTEXATTRIB4BVPROC				pglVertexAttrib4bv = 0;
PFNGLVERTEXATTRIB4DPROC					pglVertexAttrib4d = 0;
PFNGLVERTEXATTRIB4DVPROC				pglVertexAttrib4dv = 0;
PFNGLVERTEXATTRIB4FPROC					pglVertexAttrib4f = 0;
PFNGLVERTEXATTRIB4FVPROC				pglVertexAttrib4fv = 0;
PFNGLVERTEXATTRIB4IVPROC				pglVertexAttrib4iv = 0;
PFNGLVERTEXATTRIB4SPROC					pglVertexAttrib4s = 0;
PFNGLVERTEXATTRIB4SVPROC				pglVertexAttrib4sv = 0;
PFNGLVERTEXATTRIB4UBVPROC				pglVertexAttrib4ubv = 0;
PFNGLVERTEXATTRIB4UIVPROC				pglVertexAttrib4uiv = 0;
PFNGLVERTEXATTRIB4USVPROC				pglVertexAttrib4usv = 0;
PFNGLVERTEXATTRIBPOINTERPROC			pglVertexAttribPointer = 0;

int GL_2_0_LoadFuncPointers()
{
	glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)wglGetProcAddress("glBlendEquationSeparate");
	glDrawBuffers = (PFNGLDRAWBUFFERSPROC)wglGetProcAddress("glDrawBuffers");
	glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)wglGetProcAddress("glStencilOpSeparate");
	glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)wglGetProcAddress("glStencilFuncSeparate");
	glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)wglGetProcAddress("glStencilMaskSeparate");
	glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
	glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
	glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
	glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
	glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
	glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
	glDetachShader = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
	glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glDisableVertexAttribArray");
	glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
	glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)wglGetProcAddress("glGetActiveAttrib");
	glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)wglGetProcAddress("glGetActiveUniform");
	glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)wglGetProcAddress("glGetAttachedShaders");
	glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
	glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
	glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
	glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)wglGetProcAddress("glGetShaderSource");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
	glGetUniformfv = (PFNGLGETUNIFORMFVPROC)wglGetProcAddress("glGetUniformfv");
	glGetUniformiv = (PFNGLGETUNIFORMIVPROC)wglGetProcAddress("glGetUniformiv");
	glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)wglGetProcAddress("glGetVertexAttribdv");
	glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)wglGetProcAddress("glGetVertexAttribfv");
	glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)wglGetProcAddress("glGetVertexAttribiv");
	glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)wglGetProcAddress("glGetVertexAttribPointerv");
	glIsProgram = (PFNGLISPROGRAMPROC)wglGetProcAddress("glIsProgram");
	glIsShader = (PFNGLISSHADERPROC)wglGetProcAddress("glIsShader");
	glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
	glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
	glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
	glUniform1f = (PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f");
	glUniform2f = (PFNGLUNIFORM2FPROC)wglGetProcAddress("glUniform2f");
	glUniform3f = (PFNGLUNIFORM3FPROC)wglGetProcAddress("glUniform3f");
	glUniform4f = (PFNGLUNIFORM4FPROC)wglGetProcAddress("glUniform4f");
	glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
	glUniform2i = (PFNGLUNIFORM2IPROC)wglGetProcAddress("glUniform2i");
	glUniform3i = (PFNGLUNIFORM3IPROC)wglGetProcAddress("glUniform3i");
	glUniform4i = (PFNGLUNIFORM4IPROC)wglGetProcAddress("glUniform4i");
	glUniform1fv = (PFNGLUNIFORM1FVPROC)wglGetProcAddress("glUniform1fv");
	glUniform2fv = (PFNGLUNIFORM2FVPROC)wglGetProcAddress("glUniform2fv");
	glUniform3fv = (PFNGLUNIFORM3FVPROC)wglGetProcAddress("glUniform3fv");
	glUniform4fv = (PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
	glUniform1iv = (PFNGLUNIFORM1IVPROC)wglGetProcAddress("glUniform1iv");
	glUniform2iv = (PFNGLUNIFORM2IVPROC)wglGetProcAddress("glUniform2iv");
	glUniform3iv = (PFNGLUNIFORM3IVPROC)wglGetProcAddress("glUniform3iv");
	glUniform4iv = (PFNGLUNIFORM4IVPROC)wglGetProcAddress("glUniform4iv");
	glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)wglGetProcAddress("glUniformMatrix2fv");
	glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)wglGetProcAddress("glUniformMatrix3fv");
	glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
	glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)wglGetProcAddress("glValidateProgram");
	glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)wglGetProcAddress("glVertexAttrib1d");
	glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)wglGetProcAddress("glVertexAttrib1dv");
	glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)wglGetProcAddress("glVertexAttrib1f");
	glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)wglGetProcAddress("glVertexAttrib1fv");
	glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)wglGetProcAddress("glVertexAttrib1s");
	glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)wglGetProcAddress("glVertexAttrib1sv");
	glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)wglGetProcAddress("glVertexAttrib2d");
	glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)wglGetProcAddress("glVertexAttrib2dv");
	glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)wglGetProcAddress("glVertexAttrib2f");
	glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)wglGetProcAddress("glVertexAttrib2fv");
	glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)wglGetProcAddress("glVertexAttrib2s");
	glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)wglGetProcAddress("glVertexAttrib2sv");
	glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)wglGetProcAddress("glVertexAttrib3d");
	glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)wglGetProcAddress("glVertexAttrib3dv");
	glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)wglGetProcAddress("glVertexAttrib3f");
	glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)wglGetProcAddress("glVertexAttrib3fv");
	glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)wglGetProcAddress("glVertexAttrib3s");
	glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)wglGetProcAddress("glVertexAttrib3sv");
	glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)wglGetProcAddress("glVertexAttrib4Nbv");
	glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)wglGetProcAddress("glVertexAttrib4Niv");
	glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)wglGetProcAddress("glVertexAttrib4Nsv");
	glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)wglGetProcAddress("glVertexAttrib4Nub");
	glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)wglGetProcAddress("glVertexAttrib4Nubv");
	glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)wglGetProcAddress("glVertexAttrib4Nuiv");
	glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)wglGetProcAddress("glVertexAttrib4Nusv");
	glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)wglGetProcAddress("glVertexAttrib4bv");
	glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)wglGetProcAddress("glVertexAttrib4d");
	glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)wglGetProcAddress("glVertexAttrib4dv");
	glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)wglGetProcAddress("glVertexAttrib4f");
	glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)wglGetProcAddress("glVertexAttrib4fv");
	glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)wglGetProcAddress("glVertexAttrib4iv");
	glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)wglGetProcAddress("glVertexAttrib4s");
	glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)wglGetProcAddress("glVertexAttrib4sv");
	glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)wglGetProcAddress("glVertexAttrib4ubv");
	glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)wglGetProcAddress("glVertexAttrib4uiv");
	glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)wglGetProcAddress("glVertexAttrib4usv");
	glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");

	return ( glBlendEquationSeparate &&	glDrawBuffers && glStencilOpSeparate &&	glStencilFuncSeparate && glStencilMaskSeparate
		&&	glAttachShader && glBindAttribLocation && glCompileShader && glCreateProgram &&	glCreateShader && glDeleteProgram
		&&	glDeleteShader && glDetachShader && glDisableVertexAttribArray && glEnableVertexAttribArray && glGetActiveAttrib
		&& glGetActiveUniform && glGetAttachedShaders && glGetAttribLocation && glGetProgramiv && glGetProgramInfoLog
		&& glGetShaderiv && glGetShaderInfoLog && glGetShaderSource && glGetUniformLocation && glGetUniformfv && glGetUniformiv
		&& glGetVertexAttribdv && glGetVertexAttribfv && glGetVertexAttribiv && glGetVertexAttribPointerv && glIsProgram
		&& glIsShader && glLinkProgram && glShaderSource && glUseProgram && glUniform1f && glUniform2f && glUniform3f
		&& glUniform4f && glUniform1i && glUniform2i && glUniform3i && glUniform4i && glUniform1fv && glUniform2fv
		&& glUniform3fv && glUniform4fv && glUniform1iv && glUniform2iv && glUniform3iv && glUniform4iv && glUniformMatrix2fv
		&& glUniformMatrix3fv && glUniformMatrix4fv && glValidateProgram && glVertexAttrib1d && glVertexAttrib1dv
		&& glVertexAttrib1f && glVertexAttrib1fv && glVertexAttrib1s && glVertexAttrib1sv && glVertexAttrib2d
		&& glVertexAttrib2dv && glVertexAttrib2f && glVertexAttrib2fv && glVertexAttrib2s && glVertexAttrib2sv
		&& glVertexAttrib3d && glVertexAttrib3dv && glVertexAttrib3f && glVertexAttrib3fv && glVertexAttrib3s
		&& glVertexAttrib3sv && glVertexAttrib4Nbv && glVertexAttrib4Niv && glVertexAttrib4Nsv && glVertexAttrib4Nub
		&& glVertexAttrib4Nubv && glVertexAttrib4Nuiv && glVertexAttrib4Nusv && glVertexAttrib4bv && glVertexAttrib4d
		&& glVertexAttrib4dv && glVertexAttrib4f && glVertexAttrib4fv && glVertexAttrib4iv && glVertexAttrib4s
		&& glVertexAttrib4sv && glVertexAttrib4ubv && glVertexAttrib4uiv && glVertexAttrib4usv && glVertexAttribPointer)
		? 1 : 0;
}

PFNGLGENBUFFERSPROC					pglGenBuffers = 0;
PFNGLBINDBUFFERPROC					pglBindBuffer = 0;
PFNGLBUFFERDATAPROC					pglBufferData = 0;

int GL_1_5_LoadFuncPointers()
{
	glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
	glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");

	return glGenBuffers ? 1 : 0;
}

PFNGLGENVERTEXARRAYSPROC		pglGenVertexArrays = 0;
PFNGLBINDVERTEXARRAYPROC		pglBindVertexArray = 0;

int GL_3_0_LoadFuncPointers()
{
	glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
	glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");

	return glGenVertexArrays && glBindVertexArray ? 1 : 0;
}
