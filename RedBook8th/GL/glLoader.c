/*
* glLoader.cpp
*
* Created on: Dec 31, 2013
* Author: Andrew Zhabura
*/

#include "glLoader.h"

/////////////////////////////// GL_VERSION_1_3 ////////////////////////////////

PFNGLACTIVETEXTUREPROC				pglActiveTexture = 0;
PFNGLSAMPLECOVERAGEPROC				pglSampleCoverage = 0;
PFNGLCOMPRESSEDTEXIMAGE3DPROC		pglCompressedTexImage3D = 0;
PFNGLCOMPRESSEDTEXIMAGE2DPROC		pglCompressedTexImage2D = 0;
PFNGLCOMPRESSEDTEXIMAGE1DPROC		pglCompressedTexImage1D = 0;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC		pglCompressedTexSubImage3D = 0;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC		pglCompressedTexSubImage2D = 0;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC		pglCompressedTexSubImage1D = 0;
PFNGLGETCOMPRESSEDTEXIMAGEPROC		pglGetCompressedTexImage = 0;


int GL_1_3_LoadFuncPointers()
{
	glActiveTexture				 = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
	glSampleCoverage			 = (PFNGLSAMPLECOVERAGEPROC)wglGetProcAddress("glSampleCoverage");
	glCompressedTexImage3D		 = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)wglGetProcAddress("glCompressedTexImage3D");
	glCompressedTexImage2D		 = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)wglGetProcAddress("glCompressedTexImage2D");
	glCompressedTexImage1D		 = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)wglGetProcAddress("glCompressedTexImage1D");
	glCompressedTexSubImage3D	 = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)wglGetProcAddress("glCompressedTexSubImage3D");
	glCompressedTexSubImage2D	 = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)wglGetProcAddress("glCompressedTexSubImage2D");
	glCompressedTexSubImage1D	 = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)wglGetProcAddress("glCompressedTexSubImage1D");
	glGetCompressedTexImage		 = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)wglGetProcAddress("glGetCompressedTexImage");

	return (glActiveTexture && glSampleCoverage && glCompressedTexImage3D && glCompressedTexImage2D && 	glCompressedTexImage1D
		&& glCompressedTexSubImage3D && glCompressedTexSubImage2D && glCompressedTexSubImage1D && glGetCompressedTexImage) ? 1 : 0;
}

/////////////////////////////// GL_VERSION_1_5 ////////////////////////////////

PFNGLGENQUERIESPROC				pglGenQueries = 0;
PFNGLDELETEQUERIESPROC			pglDeleteQueries = 0;
PFNGLISQUERYPROC					pglIsQuery = 0;
PFNGLBEGINQUERYPROC				pglBeginQuery = 0;
PFNGLENDQUERYPROC				pglEndQuery = 0;
PFNGLGETQUERYIVPROC				pglGetQueryiv = 0;
PFNGLGETQUERYOBJECTIVPROC		pglGetQueryObjectiv = 0;
PFNGLGETQUERYOBJECTUIVPROC		pglGetQueryObjectuiv = 0;
PFNGLBINDBUFFERPROC				pglBindBuffer = 0;
PFNGLDELETEBUFFERSPROC			pglDeleteBuffers = 0;
PFNGLGENBUFFERSPROC				pglGenBuffers = 0;
PFNGLISBUFFERPROC				pglIsBuffer = 0;
PFNGLBUFFERDATAPROC				pglBufferData = 0;
PFNGLBUFFERSUBDATAPROC			pglBufferSubData = 0;
PFNGLGETBUFFERSUBDATAPROC		pglGetBufferSubData = 0;
PFNGLMAPBUFFERPROC				pglMapBuffer = 0;
PFNGLUNMAPBUFFERPROC				pglUnmapBuffer = 0;
PFNGLGETBUFFERPARAMETERIVPROC	pglGetBufferParameteriv = 0;
PFNGLGETBUFFERPOINTERVPROC		pglGetBufferPointerv = 0;

int GL_1_5_LoadFuncPointers()
{
	glGenQueries = (PFNGLGENQUERIESPROC)wglGetProcAddress("glGenQueries");
	glDeleteQueries = (PFNGLDELETEQUERIESPROC)wglGetProcAddress("glDeleteQueries");
	glIsQuery = (PFNGLISQUERYPROC)wglGetProcAddress("glIsQuery");
	glBeginQuery = (PFNGLBEGINQUERYPROC)wglGetProcAddress("glBeginQuery");
	glEndQuery = (PFNGLENDQUERYPROC)wglGetProcAddress("glEndQuery");
	glGetQueryiv = (PFNGLGETQUERYIVPROC)wglGetProcAddress("glGetQueryiv");
	glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)wglGetProcAddress("glGetQueryObjectiv");
	glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)wglGetProcAddress("glGetQueryObjectuiv");
	glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
	glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
	glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
	glIsBuffer = (PFNGLISBUFFERPROC)wglGetProcAddress("glIsBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
	glBufferSubData = (PFNGLBUFFERSUBDATAPROC)wglGetProcAddress("glBufferSubData");
	glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)wglGetProcAddress("glGetBufferSubData");
	glMapBuffer = (PFNGLMAPBUFFERPROC)wglGetProcAddress("glMapBuffer");
	glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)wglGetProcAddress("glUnmapBuffer");
	glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetBufferParameteriv");
	glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)wglGetProcAddress("glGetBufferPointerv");

	return (glGenQueries && glDeleteQueries && glIsQuery && glBeginQuery && glEndQuery && glGetQueryiv
		&& glGetQueryObjectiv && glGetQueryObjectuiv && glBindBuffer && glDeleteBuffers && glGenBuffers
		&& glIsBuffer && glBufferData && glBufferSubData && glGetBufferSubData && glMapBuffer && glUnmapBuffer
		&& glGetBufferParameteriv && glGetBufferPointerv) ? 1 : 0;
}

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

/////////////////////////////// GL_VERSION_3_0 ////////////////////////////////

PFNGLCOLORMASKIPROC							pglColorMaski = 0;
PFNGLGETBOOLEANI_VPROC						pglGetBooleani_v = 0;
PFNGLGETINTEGERI_VPROC						pglGetIntegeri_v = 0;
PFNGLENABLEIPROC								pglEnablei = 0;
PFNGLDISABLEIPROC							pglDisablei = 0;
PFNGLISENABLEDIPROC							pglIsEnabledi = 0;
PFNGLBEGINTRANSFORMFEEDBACKPROC				pglBeginTransformFeedback = 0;
PFNGLENDTRANSFORMFEEDBACKPROC				pglEndTransformFeedback = 0;
PFNGLBINDBUFFERRANGEPROC						pglBindBufferRange = 0;
PFNGLBINDBUFFERBASEPROC						pglBindBufferBase = 0;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC			pglTransformFeedbackVaryings = 0;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC			pglGetTransformFeedbackVarying = 0;
PFNGLCLAMPCOLORPROC							pglClampColor = 0;
PFNGLBEGINCONDITIONALRENDERPROC				pglBeginConditionalRender = 0;
PFNGLENDCONDITIONALRENDERPROC				pglEndConditionalRender = 0;
PFNGLVERTEXATTRIBIPOINTERPROC				pglVertexAttribIPointer = 0;
PFNGLGETVERTEXATTRIBIIVPROC					pglGetVertexAttribIiv = 0;
PFNGLGETVERTEXATTRIBIUIVPROC					pglGetVertexAttribIuiv = 0;
PFNGLVERTEXATTRIBI1IPROC						pglVertexAttribI1i = 0;
PFNGLVERTEXATTRIBI2IPROC						pglVertexAttribI2i = 0;
PFNGLVERTEXATTRIBI3IPROC						pglVertexAttribI3i = 0;
PFNGLVERTEXATTRIBI4IPROC						pglVertexAttribI4i = 0;
PFNGLVERTEXATTRIBI1UIPROC					pglVertexAttribI1ui = 0;
PFNGLVERTEXATTRIBI2UIPROC					pglVertexAttribI2ui = 0;
PFNGLVERTEXATTRIBI3UIPROC					pglVertexAttribI3ui = 0;
PFNGLVERTEXATTRIBI4UIPROC					pglVertexAttribI4ui = 0;
PFNGLVERTEXATTRIBI1IVPROC					pglVertexAttribI1iv = 0;
PFNGLVERTEXATTRIBI2IVPROC					pglVertexAttribI2iv = 0;
PFNGLVERTEXATTRIBI3IVPROC					pglVertexAttribI3iv = 0;
PFNGLVERTEXATTRIBI4IVPROC					pglVertexAttribI4iv = 0;
PFNGLVERTEXATTRIBI1UIVPROC					pglVertexAttribI1uiv = 0;
PFNGLVERTEXATTRIBI2UIVPROC					pglVertexAttribI2uiv = 0;
PFNGLVERTEXATTRIBI3UIVPROC					pglVertexAttribI3uiv = 0;
PFNGLVERTEXATTRIBI4UIVPROC					pglVertexAttribI4uiv = 0;
PFNGLVERTEXATTRIBI4BVPROC					pglVertexAttribI4bv = 0;
PFNGLVERTEXATTRIBI4SVPROC					pglVertexAttribI4sv = 0;
PFNGLVERTEXATTRIBI4UBVPROC					pglVertexAttribI4ubv = 0;
PFNGLVERTEXATTRIBI4USVPROC					pglVertexAttribI4usv = 0;
PFNGLGETUNIFORMUIVPROC						pglGetUniformuiv = 0;
PFNGLBINDFRAGDATALOCATIONPROC				pglBindFragDataLocation = 0;
PFNGLGETFRAGDATALOCATIONPROC					pglGetFragDataLocation = 0;
PFNGLUNIFORM1UIPROC							pglUniform1ui = 0;
PFNGLUNIFORM2UIPROC							pglUniform2ui = 0;
PFNGLUNIFORM3UIPROC							pglUniform3ui = 0;
PFNGLUNIFORM4UIPROC							pglUniform4ui = 0;
PFNGLUNIFORM1UIVPROC							pglUniform1uiv = 0;
PFNGLUNIFORM2UIVPROC							pglUniform2uiv = 0;
PFNGLUNIFORM3UIVPROC							pglUniform3uiv = 0;
PFNGLUNIFORM4UIVPROC							pglUniform4uiv = 0;
PFNGLTEXPARAMETERIIVPROC						pglTexParameterIiv = 0;
PFNGLTEXPARAMETERIUIVPROC					pglTexParameterIuiv = 0;
PFNGLGETTEXPARAMETERIIVPROC					pglGetTexParameterIiv = 0;
PFNGLGETTEXPARAMETERIUIVPROC					pglGetTexParameterIuiv = 0;
PFNGLCLEARBUFFERIVPROC						pglClearBufferiv = 0;
PFNGLCLEARBUFFERUIVPROC						pglClearBufferuiv = 0;
PFNGLCLEARBUFFERFVPROC						pglClearBufferfv = 0;
PFNGLCLEARBUFFERFIPROC						pglClearBufferfi = 0;
PFNGLGETSTRINGIPROC							pglGetStringi = 0;
PFNGLISRENDERBUFFERPROC						pglIsRenderbuffer = 0;
PFNGLBINDRENDERBUFFERPROC					pglBindRenderbuffer = 0;
PFNGLDELETERENDERBUFFERSPROC					pglDeleteRenderbuffers = 0;
PFNGLGENRENDERBUFFERSPROC					pglGenRenderbuffers = 0;
PFNGLRENDERBUFFERSTORAGEPROC					pglRenderbufferStorage = 0;
PFNGLGETRENDERBUFFERPARAMETERIVPROC			pglGetRenderbufferParameteriv = 0;
PFNGLISFRAMEBUFFERPROC						pglIsFramebuffer = 0;
PFNGLBINDFRAMEBUFFERPROC						pglBindFramebuffer = 0;
PFNGLDELETEFRAMEBUFFERSPROC					pglDeleteFramebuffers = 0;
PFNGLGENFRAMEBUFFERSPROC						pglGenFramebuffers = 0;
PFNGLCHECKFRAMEBUFFERSTATUSPROC				pglCheckFramebufferStatus = 0;
PFNGLFRAMEBUFFERTEXTURE1DPROC				pglFramebufferTexture1D = 0;
PFNGLFRAMEBUFFERTEXTURE2DPROC				pglFramebufferTexture2D = 0;
PFNGLFRAMEBUFFERTEXTURE3DPROC				pglFramebufferTexture3D = 0;
PFNGLFRAMEBUFFERRENDERBUFFERPROC				pglFramebufferRenderbuffer = 0;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC	pglGetFramebufferAttachmentParameteriv = 0;
PFNGLGENERATEMIPMAPPROC						pglGenerateMipmap = 0;
PFNGLBLITFRAMEBUFFERPROC						pglBlitFramebuffer = 0;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC		pglRenderbufferStorageMultisample = 0;
PFNGLFRAMEBUFFERTEXTURELAYERPROC				pglFramebufferTextureLayer = 0;
PFNGLMAPBUFFERRANGEPROC						pglMapBufferRange = 0;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC				pglFlushMappedBufferRange = 0;
PFNGLBINDVERTEXARRAYPROC						pglBindVertexArray = 0;
PFNGLDELETEVERTEXARRAYSPROC					pglDeleteVertexArrays = 0;
PFNGLGENVERTEXARRAYSPROC						pglGenVertexArrays = 0;
PFNGLISVERTEXARRAYPROC						pglIsVertexArray = 0;

int GL_3_0_LoadFuncPointers()
{
	glColorMaski = (PFNGLCOLORMASKIPROC)wglGetProcAddress("glColorMaski");
	glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)wglGetProcAddress("glGetBooleani_v");
	glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)wglGetProcAddress("glGetIntegeri_v");
	glEnablei = (PFNGLENABLEIPROC)wglGetProcAddress("glEnablei");
	glDisablei = (PFNGLDISABLEIPROC)wglGetProcAddress("glDisablei");
	glIsEnabledi = (PFNGLISENABLEDIPROC)wglGetProcAddress("glIsEnabledi");
	glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)wglGetProcAddress("glBeginTransformFeedback");
	glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)wglGetProcAddress("glEndTransformFeedback");
	glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)wglGetProcAddress("glBindBufferRange");
	glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)wglGetProcAddress("glBindBufferBase");
	glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)wglGetProcAddress("glTransformFeedbackVaryings");
	glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)wglGetProcAddress("glGetTransformFeedbackVarying");
	glClampColor = (PFNGLCLAMPCOLORPROC)wglGetProcAddress("glClampColor");
	glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)wglGetProcAddress("glBeginConditionalRender");
	glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)wglGetProcAddress("glEndConditionalRender");
	glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)wglGetProcAddress("glVertexAttribIPointer");
	glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)wglGetProcAddress("glGetVertexAttribIiv");
	glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)wglGetProcAddress("glGetVertexAttribIuiv");
	glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)wglGetProcAddress("glVertexAttribI1i");
	glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)wglGetProcAddress("glVertexAttribI2i");
	glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)wglGetProcAddress("glVertexAttribI3i");
	glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)wglGetProcAddress("glVertexAttribI4i");
	glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)wglGetProcAddress("glVertexAttribI1ui");
	glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)wglGetProcAddress("glVertexAttribI2ui");
	glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)wglGetProcAddress("glVertexAttribI3ui");
	glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)wglGetProcAddress("glVertexAttribI4ui");
	glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)wglGetProcAddress("glVertexAttribI1iv");
	glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)wglGetProcAddress("glVertexAttribI2iv");
	glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)wglGetProcAddress("glVertexAttribI3iv");
	glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)wglGetProcAddress("glVertexAttribI4iv");
	glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)wglGetProcAddress("glVertexAttribI1uiv");
	glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)wglGetProcAddress("glVertexAttribI2uiv");
	glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)wglGetProcAddress("glVertexAttribI3uiv");
	glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)wglGetProcAddress("glVertexAttribI4uiv");
	glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)wglGetProcAddress("glVertexAttribI4bv");
	glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)wglGetProcAddress("glVertexAttribI4sv");
	glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)wglGetProcAddress("glVertexAttribI4ubv");
	glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)wglGetProcAddress("glVertexAttribI4usv");
	glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)wglGetProcAddress("glGetUniformuiv");
	glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)wglGetProcAddress("glBindFragDataLocation");
	glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)wglGetProcAddress("glGetFragDataLocation");
	glUniform1ui = (PFNGLUNIFORM1UIPROC)wglGetProcAddress("glUniform1ui");
	glUniform2ui = (PFNGLUNIFORM2UIPROC)wglGetProcAddress("glUniform2ui");
	glUniform3ui = (PFNGLUNIFORM3UIPROC)wglGetProcAddress("glUniform3ui");
	glUniform4ui = (PFNGLUNIFORM4UIPROC)wglGetProcAddress("glUniform4ui");
	glUniform1uiv = (PFNGLUNIFORM1UIVPROC)wglGetProcAddress("glUniform1uiv");
	glUniform2uiv = (PFNGLUNIFORM2UIVPROC)wglGetProcAddress("glUniform2uiv");
	glUniform3uiv = (PFNGLUNIFORM3UIVPROC)wglGetProcAddress("glUniform3uiv");
	glUniform4uiv = (PFNGLUNIFORM4UIVPROC)wglGetProcAddress("glUniform4uiv");
	glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)wglGetProcAddress("glTexParameterIiv");
	glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)wglGetProcAddress("glTexParameterIuiv");
	glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)wglGetProcAddress("glGetTexParameterIiv");
	glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)wglGetProcAddress("glGetTexParameterIuiv");
	glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)wglGetProcAddress("glClearBufferiv");
	glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)wglGetProcAddress("glClearBufferuiv");
	glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)wglGetProcAddress("glClearBufferfv");
	glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)wglGetProcAddress("glClearBufferfi");
	glGetStringi = (PFNGLGETSTRINGIPROC)wglGetProcAddress("glGetStringi");
	glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)wglGetProcAddress("glIsRenderbuffer");
	glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)wglGetProcAddress("glBindRenderbuffer");
	glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)wglGetProcAddress("glDeleteRenderbuffers");
	glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)wglGetProcAddress("glGenRenderbuffers");
	glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)wglGetProcAddress("glRenderbufferStorage");
	glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetRenderbufferParameteriv");
	glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)wglGetProcAddress("glIsFramebuffer");
	glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)wglGetProcAddress("glBindFramebuffer");
	glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)wglGetProcAddress("glDeleteFramebuffers");
	glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)wglGetProcAddress("glGenFramebuffers");
	glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckFramebufferStatus");
	glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)wglGetProcAddress("glFramebufferTexture1D");
	glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)wglGetProcAddress("glFramebufferTexture2D");
	glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)wglGetProcAddress("glFramebufferTexture3D");
	glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)wglGetProcAddress("glFramebufferRenderbuffer");
	glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)wglGetProcAddress("glGetFramebufferAttachmentParameteriv");
	glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
	glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)wglGetProcAddress("glBlitFramebuffer");
	glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)wglGetProcAddress("glRenderbufferStorageMultisample");
	glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)wglGetProcAddress("glFramebufferTextureLayer");
	glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)wglGetProcAddress("glMapBufferRange");
	glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)wglGetProcAddress("glFlushMappedBufferRange");
	glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
	glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
	glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
	glIsVertexArray = (PFNGLISVERTEXARRAYPROC)wglGetProcAddress("glIsVertexArray");

	return (glColorMaski && glGetBooleani_v && glGetIntegeri_v && glEnablei && glDisablei && glIsEnabledi && glBeginTransformFeedback
		&& glEndTransformFeedback && glBindBufferRange && glBindBufferBase && glTransformFeedbackVaryings && glGetTransformFeedbackVarying
		&& glClampColor && glBeginConditionalRender && glEndConditionalRender && glVertexAttribIPointer && glGetVertexAttribIiv
		&& glGetVertexAttribIuiv && glVertexAttribI1i && glVertexAttribI2i && glVertexAttribI3i && glVertexAttribI4i && glVertexAttribI1ui
		&& glVertexAttribI2ui && glVertexAttribI3ui && glVertexAttribI4ui && glVertexAttribI1iv && glVertexAttribI2iv && glVertexAttribI3iv
		&& glVertexAttribI4iv && glVertexAttribI1uiv && glVertexAttribI2uiv && glVertexAttribI3uiv && glVertexAttribI4uiv && glVertexAttribI4bv
		&& glVertexAttribI4sv && glVertexAttribI4ubv && glVertexAttribI4usv && glGetUniformuiv && glBindFragDataLocation && glGetFragDataLocation
		&& glUniform1ui && glUniform2ui && glUniform3ui && glUniform4ui && glUniform1uiv && glUniform2uiv && glUniform3uiv && glUniform4uiv
		&& glTexParameterIiv && glTexParameterIuiv && glGetTexParameterIiv && glGetTexParameterIuiv && glClearBufferiv && glClearBufferuiv
		&& glClearBufferfv && glClearBufferfi && glGetStringi && glIsRenderbuffer && glBindRenderbuffer && glDeleteRenderbuffers && glGenRenderbuffers
		&& glRenderbufferStorage && glGetRenderbufferParameteriv && glIsFramebuffer && glBindFramebuffer && glDeleteFramebuffers && glGenFramebuffers
		&& glCheckFramebufferStatus && glFramebufferTexture1D && glFramebufferTexture2D && glFramebufferTexture3D && glFramebufferRenderbuffer
		&& glGetFramebufferAttachmentParameteriv && glGenerateMipmap && glBlitFramebuffer && glRenderbufferStorageMultisample && glFramebufferTextureLayer
		&& glMapBufferRange && glFlushMappedBufferRange && glBindVertexArray && glDeleteVertexArrays && glGenVertexArrays && glIsVertexArray) ? 1 : 0;
}

/////////////////////////////// GL_VERSION_3_1 ////////////////////////////////

PFNGLDRAWARRAYSINSTANCEDPROC					pglDrawArraysInstanced = 0;
PFNGLDRAWELEMENTSINSTANCEDPROC				pglDrawElementsInstanced = 0;
PFNGLTEXBUFFERPROC							pglTexBuffer = 0;
PFNGLPRIMITIVERESTARTINDEXPROC				pglPrimitiveRestartIndex = 0;
PFNGLCOPYBUFFERSUBDATAPROC					pglCopyBufferSubData = 0;
PFNGLGETUNIFORMINDICESPROC					pglGetUniformIndices = 0;
PFNGLGETACTIVEUNIFORMSIVPROC					pglGetActiveUniformsiv = 0;
PFNGLGETACTIVEUNIFORMNAMEPROC				pglGetActiveUniformName = 0;
PFNGLGETUNIFORMBLOCKINDEXPROC				pglGetUniformBlockIndex = 0;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC				pglGetActiveUniformBlockiv = 0;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC			pglGetActiveUniformBlockName = 0;
PFNGLUNIFORMBLOCKBINDINGPROC					pglUniformBlockBinding = 0;

int GL_3_1_LoadFuncPointers()
{
	glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)wglGetProcAddress("glDrawArraysInstanced");
	glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)wglGetProcAddress("glDrawElementsInstanced");
	glTexBuffer = (PFNGLTEXBUFFERPROC)wglGetProcAddress("glTexBuffer");
	glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)wglGetProcAddress("glPrimitiveRestartIndex");
	glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)wglGetProcAddress("glCopyBufferSubData");
	glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)wglGetProcAddress("glGetUniformIndices");
	glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)wglGetProcAddress("glGetActiveUniformsiv");
	glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)wglGetProcAddress("glGetActiveUniformName");
	glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)wglGetProcAddress("glGetUniformBlockIndex");
	glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)wglGetProcAddress("glGetActiveUniformBlockiv");
	glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)wglGetProcAddress("glGetActiveUniformBlockName");
	glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)wglGetProcAddress("glUniformBlockBinding");

	return (glDrawArraysInstanced && glDrawElementsInstanced && glTexBuffer && glPrimitiveRestartIndex && glCopyBufferSubData
		&& glGetUniformIndices && glGetActiveUniformsiv && glGetActiveUniformName && glGetUniformBlockIndex
		&& glGetActiveUniformBlockiv && glGetActiveUniformBlockName && glUniformBlockBinding) ? 1 : 0;
}

/////////////////////////////// GL_VERSION_3_2 ////////////////////////////////

PFNGLDRAWELEMENTSBASEVERTEXPROC				pglDrawElementsBaseVertex = 0;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC			pglDrawRangeElementsBaseVertex = 0;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC		pglDrawElementsInstancedBaseVertex = 0;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC			pglMultiDrawElementsBaseVertex = 0;
PFNGLPROVOKINGVERTEXPROC						pglProvokingVertex = 0;
PFNGLFENCESYNCPROC							pglFenceSync = 0;
PFNGLISSYNCPROC								pglIsSync = 0;
PFNGLDELETESYNCPROC							pglDeleteSync = 0;
PFNGLCLIENTWAITSYNCPROC						pglClientWaitSync = 0;
PFNGLWAITSYNCPROC							pglWaitSync = 0;
PFNGLGETINTEGER64VPROC						pglGetInteger64v = 0;
PFNGLGETSYNCIVPROC							pglGetSynciv = 0;
PFNGLGETINTEGER64I_VPROC						pglGetInteger64i_v = 0;
PFNGLGETBUFFERPARAMETERI64VPROC				pglGetBufferParameteri64v = 0;
PFNGLFRAMEBUFFERTEXTUREPROC					pglFramebufferTexture = 0;
PFNGLTEXIMAGE2DMULTISAMPLEPROC				pglTexImage2DMultisample = 0;
PFNGLTEXIMAGE3DMULTISAMPLEPROC				pglTexImage3DMultisample = 0;
PFNGLGETMULTISAMPLEFVPROC					pglGetMultisamplefv = 0;
PFNGLSAMPLEMASKIPROC							pglSampleMaski = 0;

int GL_3_2_LoadFuncPointers()
{
	glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)wglGetProcAddress("glDrawElementsBaseVertex");
	glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)wglGetProcAddress("glDrawRangeElementsBaseVertex");
	glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)wglGetProcAddress("glDrawElementsInstancedBaseVertex");
	glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)wglGetProcAddress("glMultiDrawElementsBaseVertex");
	glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)wglGetProcAddress("glProvokingVertex");
	glFenceSync = (PFNGLFENCESYNCPROC)wglGetProcAddress("glFenceSync");
	glIsSync = (PFNGLISSYNCPROC)wglGetProcAddress("glIsSync");
	glDeleteSync = (PFNGLDELETESYNCPROC)wglGetProcAddress("glDeleteSync");
	glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)wglGetProcAddress("glClientWaitSync");
	glWaitSync = (PFNGLWAITSYNCPROC)wglGetProcAddress("glWaitSync");
	glGetInteger64v = (PFNGLGETINTEGER64VPROC)wglGetProcAddress("glGetInteger64v");
	glGetSynciv = (PFNGLGETSYNCIVPROC)wglGetProcAddress("glGetSynciv");
	glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)wglGetProcAddress("glGetInteger64i_v");
	glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)wglGetProcAddress("glGetBufferParameteri64v");
	glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)wglGetProcAddress("glFramebufferTexture");
	glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)wglGetProcAddress("glTexImage2DMultisample");
	glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)wglGetProcAddress("glTexImage3DMultisample");
	glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)wglGetProcAddress("glGetMultisamplefv");
	glSampleMaski = (PFNGLSAMPLEMASKIPROC)wglGetProcAddress("glSampleMaski");

	return (glDrawElementsBaseVertex && glDrawRangeElementsBaseVertex && glDrawElementsInstancedBaseVertex && glMultiDrawElementsBaseVertex && 
		glProvokingVertex && glFenceSync && glIsSync && glDeleteSync && glClientWaitSync && glWaitSync && glGetInteger64v && 
		glGetSynciv && glGetInteger64i_v && glGetBufferParameteri64v && glFramebufferTexture && glTexImage2DMultisample && 
		glTexImage3DMultisample && glGetMultisamplefv && glSampleMaski) ? 1 : 0;
}

/////////////////////////////// GL_VERSION_3_3 ////////////////////////////////

PFNGLBINDFRAGDATALOCATIONINDEXEDPROC		pglBindFragDataLocationIndexed = 0;
PFNGLGETFRAGDATAINDEXPROC				pglGetFragDataIndex = 0;
PFNGLGENSAMPLERSPROC						pglGenSamplers = 0;
PFNGLDELETESAMPLERSPROC					pglDeleteSamplers = 0;
PFNGLISSAMPLERPROC						pglIsSampler = 0;
PFNGLBINDSAMPLERPROC						pglBindSampler = 0;
PFNGLSAMPLERPARAMETERIPROC				pglSamplerParameteri = 0;
PFNGLSAMPLERPARAMETERIVPROC				pglSamplerParameteriv = 0;
PFNGLSAMPLERPARAMETERFPROC				pglSamplerParameterf = 0;
PFNGLSAMPLERPARAMETERFVPROC				pglSamplerParameterfv = 0;
PFNGLSAMPLERPARAMETERIIVPROC				pglSamplerParameterIiv = 0;
PFNGLSAMPLERPARAMETERIUIVPROC			pglSamplerParameterIuiv = 0;
PFNGLGETSAMPLERPARAMETERIVPROC			pglGetSamplerParameteriv = 0;
PFNGLGETSAMPLERPARAMETERIIVPROC			pglGetSamplerParameterIiv = 0;
PFNGLGETSAMPLERPARAMETERFVPROC			pglGetSamplerParameterfv = 0;
PFNGLGETSAMPLERPARAMETERIUIVPROC			pglGetSamplerParameterIuiv = 0;
PFNGLQUERYCOUNTERPROC					pglQueryCounter = 0;
PFNGLGETQUERYOBJECTI64VPROC				pglGetQueryObjecti64v = 0;
PFNGLGETQUERYOBJECTUI64VPROC				pglGetQueryObjectui64v = 0;
PFNGLVERTEXATTRIBDIVISORPROC				pglVertexAttribDivisor = 0;
PFNGLVERTEXATTRIBP1UIPROC				pglVertexAttribP1ui = 0;
PFNGLVERTEXATTRIBP1UIVPROC				pglVertexAttribP1uiv = 0;
PFNGLVERTEXATTRIBP2UIPROC				pglVertexAttribP2ui = 0;
PFNGLVERTEXATTRIBP2UIVPROC				pglVertexAttribP2uiv = 0;
PFNGLVERTEXATTRIBP3UIPROC				pglVertexAttribP3ui = 0;
PFNGLVERTEXATTRIBP3UIVPROC				pglVertexAttribP3uiv = 0;
PFNGLVERTEXATTRIBP4UIPROC				pglVertexAttribP4ui = 0;
PFNGLVERTEXATTRIBP4UIVPROC				pglVertexAttribP4uiv = 0;

int GL_3_3_LoadFuncPointers()
{
	glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)wglGetProcAddress("glBindFragDataLocationIndexed");
	glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC)wglGetProcAddress("glGetFragDataIndex");
	glGenSamplers = (PFNGLGENSAMPLERSPROC)wglGetProcAddress("glGenSamplers");
	glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)wglGetProcAddress("glDeleteSamplers");
	glIsSampler = (PFNGLISSAMPLERPROC)wglGetProcAddress("glIsSampler");
	glBindSampler = (PFNGLBINDSAMPLERPROC)wglGetProcAddress("glBindSampler");
	glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)wglGetProcAddress("glSamplerParameteri");
	glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)wglGetProcAddress("glSamplerParameteriv");
	glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)wglGetProcAddress("glSamplerParameterf");
	glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)wglGetProcAddress("glSamplerParameterfv");
	glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)wglGetProcAddress("glSamplerParameterIiv");
	glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)wglGetProcAddress("glSamplerParameterIuiv");
	glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)wglGetProcAddress("glGetSamplerParameteriv");
	glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)wglGetProcAddress("glGetSamplerParameterIiv");
	glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)wglGetProcAddress("glGetSamplerParameterfv");
	glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)wglGetProcAddress("glGetSamplerParameterIuiv");
	glQueryCounter  = (PFNGLQUERYCOUNTERPROC)wglGetProcAddress("glQueryCounter");
	glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC)wglGetProcAddress("glGetQueryObjecti64v");
	glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)wglGetProcAddress("glGetQueryObjectui64v");
	glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)wglGetProcAddress("glVertexAttribDivisor");
	glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC)wglGetProcAddress("glVertexAttribP1ui");
	glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC)wglGetProcAddress("glVertexAttribP1uiv");
	glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC)wglGetProcAddress("glVertexAttribP2ui");
	glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC)wglGetProcAddress("glVertexAttribP2uiv");
	glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC)wglGetProcAddress("glVertexAttribP3ui");
	glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC)wglGetProcAddress("glVertexAttribP3uiv");
	glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC)wglGetProcAddress("glVertexAttribP4ui");
	glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC)wglGetProcAddress("glVertexAttribP4uiv");

	return (glBindFragDataLocationIndexed && glGetFragDataIndex && glGenSamplers && glDeleteSamplers && glIsSampler && 
		glBindSampler && glSamplerParameteri && glSamplerParameteriv && glSamplerParameterf && 
		glSamplerParameterfv && glSamplerParameterIiv && glSamplerParameterIuiv && glGetSamplerParameteriv && 
		glGetSamplerParameterIiv && glGetSamplerParameterfv && glGetSamplerParameterIuiv && glQueryCounter  && 
		glGetQueryObjecti64v && glGetQueryObjectui64v && glVertexAttribDivisor && glVertexAttribP1ui && 
		glVertexAttribP1uiv && glVertexAttribP2ui && glVertexAttribP2uiv && glVertexAttribP3ui && 
		glVertexAttribP3uiv && glVertexAttribP4ui && glVertexAttribP4uiv) ? 1 : 0;
}
