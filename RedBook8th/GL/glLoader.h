/*
* glLoader.h
*
* Created on: Dec 31, 2013
* Author: Andrew Zhabura
*/

#ifndef glLoader_h
#define glLoader_h

#define GL_GLEXT_PROTOTYPES 1
#include "glcorearb.h"

#pragma comment(lib,"OpenGL32.lib")
//#pragma comment(lib,"glu32.lib")

// enum
// {
// 	false=0,
// 	true=1
// } bool;

#define BUFFER_OFFSET(x)  ((const void*) (x))

#ifdef __cplusplus
extern "C" {
#endif

	/////////////////////////////// GL_VERSION_1_2 ////////////////////////////////

	extern PFNGLDRAWRANGEELEMENTSPROC		pglDrawRangeElements;
	extern PFNGLTEXIMAGE3DPROC				pglTexImage3D;
	extern PFNGLTEXSUBIMAGE3DPROC			pglTexSubImage3D;
	extern PFNGLCOPYTEXSUBIMAGE3DPROC		pglCopyTexSubImage3D;

#define glDrawRangeElements		pglDrawRangeElements
#define glTexImage3D			pglTexImage3D
#define glTexSubImage3D			pglTexSubImage3D
#define glCopyTexSubImage3D		pglCopyTexSubImage3D

	int GL_1_2_LoadFuncPointers();

	/////////////////////////////// GL_VERSION_1_3 ////////////////////////////////

	extern PFNGLACTIVETEXTUREPROC				pglActiveTexture;
	extern PFNGLSAMPLECOVERAGEPROC				pglSampleCoverage;
	extern PFNGLCOMPRESSEDTEXIMAGE3DPROC		pglCompressedTexImage3D;
	extern PFNGLCOMPRESSEDTEXIMAGE2DPROC		pglCompressedTexImage2D;
	extern PFNGLCOMPRESSEDTEXIMAGE1DPROC		pglCompressedTexImage1D;
	extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC		pglCompressedTexSubImage3D;
	extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC		pglCompressedTexSubImage2D;
	extern PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC		pglCompressedTexSubImage1D;
	extern PFNGLGETCOMPRESSEDTEXIMAGEPROC		pglGetCompressedTexImage;

#define glActiveTexture					pglActiveTexture
#define glSampleCoverage				pglSampleCoverage
#define glCompressedTexImage3D			pglCompressedTexImage3D
#define glCompressedTexImage2D			pglCompressedTexImage2D
#define glCompressedTexImage1D			pglCompressedTexImage1D
#define glCompressedTexSubImage3D		pglCompressedTexSubImage3D
#define glCompressedTexSubImage2D		pglCompressedTexSubImage2D
#define glCompressedTexSubImage1D		pglCompressedTexSubImage1D
#define glGetCompressedTexImage			pglGetCompressedTexImage

	int GL_1_3_LoadFuncPointers();

	/////////////////////////////// GL_VERSION_1_4 ////////////////////////////////

	extern PFNGLBLENDFUNCSEPARATEPROC		pglBlendFuncSeparate;
	extern PFNGLMULTIDRAWARRAYSPROC			pglMultiDrawArrays;
	extern PFNGLMULTIDRAWELEMENTSPROC		pglMultiDrawElements;
	extern PFNGLPOINTPARAMETERFPROC			pglPointParameterf;
	extern PFNGLPOINTPARAMETERFVPROC		pglPointParameterfv;
	extern PFNGLPOINTPARAMETERIPROC			pglPointParameteri;
	extern PFNGLPOINTPARAMETERIVPROC		pglPointParameteriv;
	extern PFNGLBLENDCOLORPROC				pglBlendColor;
	extern PFNGLBLENDEQUATIONPROC			pglBlendEquation;

#define glBlendFuncSeparate			pglBlendFuncSeparate
#define glMultiDrawArrays			pglMultiDrawArrays
#define glMultiDrawElements			pglMultiDrawElements
#define glPointParameterf			pglPointParameterf
#define glPointParameterfv			pglPointParameterfv
#define glPointParameteri			pglPointParameteri
#define glPointParameteriv			pglPointParameteriv
#define glBlendColor				pglBlendColor
#define glBlendEquation				pglBlendEquation
	int GL_1_4_LoadFuncPointers();

	/////////////////////////////// GL_VERSION_1_5 ////////////////////////////////

	extern PFNGLGENQUERIESPROC				pglGenQueries;
	extern PFNGLDELETEQUERIESPROC			pglDeleteQueries;
	extern PFNGLISQUERYPROC					pglIsQuery;
	extern PFNGLBEGINQUERYPROC				pglBeginQuery;
	extern PFNGLENDQUERYPROC				pglEndQuery;
	extern PFNGLGETQUERYIVPROC				pglGetQueryiv;
	extern PFNGLGETQUERYOBJECTIVPROC		pglGetQueryObjectiv;
	extern PFNGLGETQUERYOBJECTUIVPROC		pglGetQueryObjectuiv;
	extern PFNGLBINDBUFFERPROC				pglBindBuffer;
	extern PFNGLDELETEBUFFERSPROC			pglDeleteBuffers;
	extern PFNGLGENBUFFERSPROC				pglGenBuffers;
	extern PFNGLISBUFFERPROC				pglIsBuffer;
	extern PFNGLBUFFERDATAPROC				pglBufferData;
	extern PFNGLBUFFERSUBDATAPROC			pglBufferSubData;
	extern PFNGLGETBUFFERSUBDATAPROC		pglGetBufferSubData;
	extern PFNGLMAPBUFFERPROC				pglMapBuffer;
	extern PFNGLUNMAPBUFFERPROC				pglUnmapBuffer;
	extern PFNGLGETBUFFERPARAMETERIVPROC	pglGetBufferParameteriv;
	extern PFNGLGETBUFFERPOINTERVPROC		pglGetBufferPointerv;

#define glGenQueries			pglGenQueries
#define glDeleteQueries			pglDeleteQueries
#define glIsQuery				pglIsQuery
#define glBeginQuery			pglBeginQuery
#define glEndQuery				pglEndQuery
#define glGetQueryiv			pglGetQueryiv
#define glGetQueryObjectiv		pglGetQueryObjectiv
#define glGetQueryObjectuiv		pglGetQueryObjectuiv
#define glBindBuffer			pglBindBuffer
#define glDeleteBuffers			pglDeleteBuffers
#define glGenBuffers			pglGenBuffers
#define glIsBuffer				pglIsBuffer
#define glBufferData			pglBufferData
#define glBufferSubData			pglBufferSubData
#define glGetBufferSubData		pglGetBufferSubData
#define glMapBuffer				pglMapBuffer
#define glUnmapBuffer			pglUnmapBuffer
#define glGetBufferParameteriv	pglGetBufferParameteriv
#define glGetBufferPointerv		pglGetBufferPointerv

	int GL_1_5_LoadFuncPointers();

	/////////////////////////////// GL_VERSION_2_0 ////////////////////////////////

	extern PFNGLBLENDEQUATIONSEPARATEPROC			pglBlendEquationSeparate;
	extern PFNGLDRAWBUFFERSPROC						pglDrawBuffers;
	extern PFNGLSTENCILOPSEPARATEPROC				pglStencilOpSeparate;
	extern PFNGLSTENCILFUNCSEPARATEPROC				pglStencilFuncSeparate;
	extern PFNGLSTENCILMASKSEPARATEPROC				pglStencilMaskSeparate;
	extern PFNGLATTACHSHADERPROC					pglAttachShader;
	extern PFNGLBINDATTRIBLOCATIONPROC				pglBindAttribLocation;
	extern PFNGLCOMPILESHADERPROC					pglCompileShader;
	extern PFNGLCREATEPROGRAMPROC					pglCreateProgram;
	extern PFNGLCREATESHADERPROC					pglCreateShader;
	extern PFNGLDELETEPROGRAMPROC					pglDeleteProgram;
	extern PFNGLDELETESHADERPROC					pglDeleteShader;
	extern PFNGLDETACHSHADERPROC					pglDetachShader;
	extern PFNGLDISABLEVERTEXATTRIBARRAYPROC		pglDisableVertexAttribArray;
	extern PFNGLENABLEVERTEXATTRIBARRAYPROC			pglEnableVertexAttribArray;
	extern PFNGLGETACTIVEATTRIBPROC					pglGetActiveAttrib;
	extern PFNGLGETACTIVEUNIFORMPROC				pglGetActiveUniform;
	extern PFNGLGETATTACHEDSHADERSPROC				pglGetAttachedShaders;
	extern PFNGLGETATTRIBLOCATIONPROC				pglGetAttribLocation;
	extern PFNGLGETPROGRAMIVPROC					pglGetProgramiv;
	extern PFNGLGETPROGRAMINFOLOGPROC				pglGetProgramInfoLog;
	extern PFNGLGETSHADERIVPROC						pglGetShaderiv;
	extern PFNGLGETSHADERINFOLOGPROC				pglGetShaderInfoLog;
	extern PFNGLGETSHADERSOURCEPROC					pglGetShaderSource;
	extern PFNGLGETUNIFORMLOCATIONPROC				pglGetUniformLocation;
	extern PFNGLGETUNIFORMFVPROC					pglGetUniformfv;
	extern PFNGLGETUNIFORMIVPROC					pglGetUniformiv;
	extern PFNGLGETVERTEXATTRIBDVPROC				pglGetVertexAttribdv;
	extern PFNGLGETVERTEXATTRIBFVPROC				pglGetVertexAttribfv;
	extern PFNGLGETVERTEXATTRIBIVPROC				pglGetVertexAttribiv;
	extern PFNGLGETVERTEXATTRIBPOINTERVPROC			pglGetVertexAttribPointerv;
	extern PFNGLISPROGRAMPROC						pglIsProgram;
	extern PFNGLISSHADERPROC						pglIsShader;
	extern PFNGLLINKPROGRAMPROC						pglLinkProgram;
	extern PFNGLSHADERSOURCEPROC					pglShaderSource;
	extern PFNGLUSEPROGRAMPROC						pglUseProgram;
	extern PFNGLUNIFORM1FPROC						pglUniform1f;
	extern PFNGLUNIFORM2FPROC						pglUniform2f;
	extern PFNGLUNIFORM3FPROC						pglUniform3f;
	extern PFNGLUNIFORM4FPROC						pglUniform4f;
	extern PFNGLUNIFORM1IPROC						pglUniform1i;
	extern PFNGLUNIFORM2IPROC						pglUniform2i;
	extern PFNGLUNIFORM3IPROC						pglUniform3i;
	extern PFNGLUNIFORM4IPROC						pglUniform4i;
	extern PFNGLUNIFORM1FVPROC						pglUniform1fv;
	extern PFNGLUNIFORM2FVPROC						pglUniform2fv;
	extern PFNGLUNIFORM3FVPROC						pglUniform3fv;
	extern PFNGLUNIFORM4FVPROC						pglUniform4fv;
	extern PFNGLUNIFORM1IVPROC						pglUniform1iv;
	extern PFNGLUNIFORM2IVPROC						pglUniform2iv;
	extern PFNGLUNIFORM3IVPROC						pglUniform3iv;
	extern PFNGLUNIFORM4IVPROC						pglUniform4iv;
	extern PFNGLUNIFORMMATRIX2FVPROC				pglUniformMatrix2fv;
	extern PFNGLUNIFORMMATRIX3FVPROC				pglUniformMatrix3fv;
	extern PFNGLUNIFORMMATRIX4FVPROC				pglUniformMatrix4fv;
	extern PFNGLVALIDATEPROGRAMPROC					pglValidateProgram;
	extern PFNGLVERTEXATTRIB1DPROC					pglVertexAttrib1d;
	extern PFNGLVERTEXATTRIB1DVPROC					pglVertexAttrib1dv;
	extern PFNGLVERTEXATTRIB1FPROC					pglVertexAttrib1f;
	extern PFNGLVERTEXATTRIB1FVPROC					pglVertexAttrib1fv;
	extern PFNGLVERTEXATTRIB1SPROC					pglVertexAttrib1s;
	extern PFNGLVERTEXATTRIB1SVPROC					pglVertexAttrib1sv;
	extern PFNGLVERTEXATTRIB2DPROC					pglVertexAttrib2d;
	extern PFNGLVERTEXATTRIB2DVPROC					pglVertexAttrib2dv;
	extern PFNGLVERTEXATTRIB2FPROC					pglVertexAttrib2f;
	extern PFNGLVERTEXATTRIB2FVPROC					pglVertexAttrib2fv;
	extern PFNGLVERTEXATTRIB2SPROC					pglVertexAttrib2s;
	extern PFNGLVERTEXATTRIB2SVPROC					pglVertexAttrib2sv;
	extern PFNGLVERTEXATTRIB3DPROC					pglVertexAttrib3d;
	extern PFNGLVERTEXATTRIB3DVPROC					pglVertexAttrib3dv;
	extern PFNGLVERTEXATTRIB3FPROC					pglVertexAttrib3f;
	extern PFNGLVERTEXATTRIB3FVPROC					pglVertexAttrib3fv;
	extern PFNGLVERTEXATTRIB3SPROC					pglVertexAttrib3s;
	extern PFNGLVERTEXATTRIB3SVPROC					pglVertexAttrib3sv;
	extern PFNGLVERTEXATTRIB4NBVPROC				pglVertexAttrib4Nbv;
	extern PFNGLVERTEXATTRIB4NIVPROC				pglVertexAttrib4Niv;
	extern PFNGLVERTEXATTRIB4NSVPROC				pglVertexAttrib4Nsv;
	extern PFNGLVERTEXATTRIB4NUBPROC				pglVertexAttrib4Nub;
	extern PFNGLVERTEXATTRIB4NUBVPROC				pglVertexAttrib4Nubv;
	extern PFNGLVERTEXATTRIB4NUIVPROC				pglVertexAttrib4Nuiv;
	extern PFNGLVERTEXATTRIB4NUSVPROC				pglVertexAttrib4Nusv;
	extern PFNGLVERTEXATTRIB4BVPROC					pglVertexAttrib4bv;
	extern PFNGLVERTEXATTRIB4DPROC					pglVertexAttrib4d;
	extern PFNGLVERTEXATTRIB4DVPROC					pglVertexAttrib4dv;
	extern PFNGLVERTEXATTRIB4FPROC					pglVertexAttrib4f;
	extern PFNGLVERTEXATTRIB4FVPROC					pglVertexAttrib4fv;
	extern PFNGLVERTEXATTRIB4IVPROC					pglVertexAttrib4iv;
	extern PFNGLVERTEXATTRIB4SPROC					pglVertexAttrib4s;
	extern PFNGLVERTEXATTRIB4SVPROC					pglVertexAttrib4sv;
	extern PFNGLVERTEXATTRIB4UBVPROC				pglVertexAttrib4ubv;
	extern PFNGLVERTEXATTRIB4UIVPROC				pglVertexAttrib4uiv;
	extern PFNGLVERTEXATTRIB4USVPROC				pglVertexAttrib4usv;
	extern PFNGLVERTEXATTRIBPOINTERPROC				pglVertexAttribPointer;

#define glBlendEquationSeparate		pglBlendEquationSeparate
#define glDrawBuffers				pglDrawBuffers
#define glStencilOpSeparate			pglStencilOpSeparate
#define glStencilFuncSeparate		pglStencilFuncSeparate
#define glStencilMaskSeparate		pglStencilMaskSeparate
#define glAttachShader				pglAttachShader
#define glBindAttribLocation		pglBindAttribLocation
#define glCompileShader				pglCompileShader
#define glCreateProgram				pglCreateProgram
#define glCreateShader				pglCreateShader
#define glDeleteProgram				pglDeleteProgram
#define glDeleteShader				pglDeleteShader
#define glDetachShader				pglDetachShader
#define glDisableVertexAttribArray	pglDisableVertexAttribArray
#define glEnableVertexAttribArray	pglEnableVertexAttribArray
#define glGetActiveAttrib			pglGetActiveAttrib
#define glGetActiveUniform			pglGetActiveUniform
#define glGetAttachedShaders		pglGetAttachedShaders
#define glGetAttribLocation			pglGetAttribLocation
#define glGetProgramiv				pglGetProgramiv
#define glGetProgramInfoLog			pglGetProgramInfoLog
#define glGetShaderiv				pglGetShaderiv
#define glGetShaderInfoLog			pglGetShaderInfoLog
#define glGetShaderSource			pglGetShaderSource
#define glGetUniformLocation		pglGetUniformLocation
#define glGetUniformfv				pglGetUniformfv
#define glGetUniformiv				pglGetUniformiv
#define glGetVertexAttribdv			pglGetVertexAttribdv
#define glGetVertexAttribfv			pglGetVertexAttribfv
#define glGetVertexAttribiv			pglGetVertexAttribiv
#define glGetVertexAttribPointerv	pglGetVertexAttribPointerv
#define glIsProgram					pglIsProgram
#define glIsShader					pglIsShader
#define glLinkProgram				pglLinkProgram
#define glShaderSource				pglShaderSource
#define glUseProgram				pglUseProgram
#define glUniform1f					pglUniform1f
#define glUniform2f					pglUniform2f
#define glUniform3f					pglUniform3f
#define glUniform4f					pglUniform4f
#define glUniform1i					pglUniform1i
#define glUniform2i					pglUniform2i
#define glUniform3i					pglUniform3i
#define glUniform4i					pglUniform4i
#define glUniform1fv				pglUniform1fv
#define glUniform2fv				pglUniform2fv
#define glUniform3fv				pglUniform3fv
#define glUniform4fv				pglUniform4fv
#define glUniform1iv				pglUniform1iv
#define glUniform2iv				pglUniform2iv
#define glUniform3iv				pglUniform3iv
#define glUniform4iv				pglUniform4iv
#define glUniformMatrix2fv			pglUniformMatrix2fv
#define glUniformMatrix3fv			pglUniformMatrix3fv
#define glUniformMatrix4fv			pglUniformMatrix4fv
#define glValidateProgram			pglValidateProgram
#define glVertexAttrib1d			pglVertexAttrib1d
#define glVertexAttrib1dv			pglVertexAttrib1dv
#define glVertexAttrib1f			pglVertexAttrib1f
#define glVertexAttrib1fv			pglVertexAttrib1fv
#define glVertexAttrib1s			pglVertexAttrib1s
#define glVertexAttrib1sv			pglVertexAttrib1sv
#define glVertexAttrib2d			pglVertexAttrib2d
#define glVertexAttrib2dv			pglVertexAttrib2dv
#define glVertexAttrib2f			pglVertexAttrib2f
#define glVertexAttrib2fv			pglVertexAttrib2fv
#define glVertexAttrib2s			pglVertexAttrib2s
#define glVertexAttrib2sv			pglVertexAttrib2sv
#define glVertexAttrib3d			pglVertexAttrib3d
#define glVertexAttrib3dv			pglVertexAttrib3dv
#define glVertexAttrib3f			pglVertexAttrib3f
#define glVertexAttrib3fv			pglVertexAttrib3fv
#define glVertexAttrib3s			pglVertexAttrib3s
#define glVertexAttrib3sv			pglVertexAttrib3sv
#define glVertexAttrib4Nbv			pglVertexAttrib4Nbv
#define glVertexAttrib4Niv			pglVertexAttrib4Niv
#define glVertexAttrib4Nsv			pglVertexAttrib4Nsv
#define glVertexAttrib4Nub			pglVertexAttrib4Nub
#define glVertexAttrib4Nubv			pglVertexAttrib4Nubv
#define glVertexAttrib4Nuiv			pglVertexAttrib4Nuiv
#define glVertexAttrib4Nusv			pglVertexAttrib4Nusv
#define glVertexAttrib4bv			pglVertexAttrib4bv
#define glVertexAttrib4d			pglVertexAttrib4d
#define glVertexAttrib4dv			pglVertexAttrib4dv
#define glVertexAttrib4f			pglVertexAttrib4f
#define glVertexAttrib4fv			pglVertexAttrib4fv
#define glVertexAttrib4iv			pglVertexAttrib4iv
#define glVertexAttrib4s			pglVertexAttrib4s
#define glVertexAttrib4sv			pglVertexAttrib4sv
#define glVertexAttrib4ubv			pglVertexAttrib4ubv
#define glVertexAttrib4uiv			pglVertexAttrib4uiv
#define glVertexAttrib4usv			pglVertexAttrib4usv
#define glVertexAttribPointer		pglVertexAttribPointer

	int GL_2_0_LoadFuncPointers();

	/////////////////////////////// GL_VERSION_3_0 ////////////////////////////////

	extern PFNGLCOLORMASKIPROC							pglColorMaski;
	extern PFNGLGETBOOLEANI_VPROC						pglGetBooleani_v;
	extern PFNGLGETINTEGERI_VPROC						pglGetIntegeri_v;
	extern PFNGLENABLEIPROC								pglEnablei;
	extern PFNGLDISABLEIPROC							pglDisablei;
	extern PFNGLISENABLEDIPROC							pglIsEnabledi;
	extern PFNGLBEGINTRANSFORMFEEDBACKPROC				pglBeginTransformFeedback;
	extern PFNGLENDTRANSFORMFEEDBACKPROC				pglEndTransformFeedback;
	extern PFNGLBINDBUFFERRANGEPROC						pglBindBufferRange;
	extern PFNGLBINDBUFFERBASEPROC						pglBindBufferBase;
	extern PFNGLTRANSFORMFEEDBACKVARYINGSPROC			pglTransformFeedbackVaryings;
	extern PFNGLGETTRANSFORMFEEDBACKVARYINGPROC			pglGetTransformFeedbackVarying;
	extern PFNGLCLAMPCOLORPROC							pglClampColor;
	extern PFNGLBEGINCONDITIONALRENDERPROC				pglBeginConditionalRender;
	extern PFNGLENDCONDITIONALRENDERPROC				pglEndConditionalRender;
	extern PFNGLVERTEXATTRIBIPOINTERPROC				pglVertexAttribIPointer;
	extern PFNGLGETVERTEXATTRIBIIVPROC					pglGetVertexAttribIiv;
	extern PFNGLGETVERTEXATTRIBIUIVPROC					pglGetVertexAttribIuiv;
	extern PFNGLVERTEXATTRIBI1IPROC						pglVertexAttribI1i;
	extern PFNGLVERTEXATTRIBI2IPROC						pglVertexAttribI2i;
	extern PFNGLVERTEXATTRIBI3IPROC						pglVertexAttribI3i;
	extern PFNGLVERTEXATTRIBI4IPROC						pglVertexAttribI4i;
	extern PFNGLVERTEXATTRIBI1UIPROC					pglVertexAttribI1ui;
	extern PFNGLVERTEXATTRIBI2UIPROC					pglVertexAttribI2ui;
	extern PFNGLVERTEXATTRIBI3UIPROC					pglVertexAttribI3ui;
	extern PFNGLVERTEXATTRIBI4UIPROC					pglVertexAttribI4ui;
	extern PFNGLVERTEXATTRIBI1IVPROC					pglVertexAttribI1iv;
	extern PFNGLVERTEXATTRIBI2IVPROC					pglVertexAttribI2iv;
	extern PFNGLVERTEXATTRIBI3IVPROC					pglVertexAttribI3iv;
	extern PFNGLVERTEXATTRIBI4IVPROC					pglVertexAttribI4iv;
	extern PFNGLVERTEXATTRIBI1UIVPROC					pglVertexAttribI1uiv;
	extern PFNGLVERTEXATTRIBI2UIVPROC					pglVertexAttribI2uiv;
	extern PFNGLVERTEXATTRIBI3UIVPROC					pglVertexAttribI3uiv;
	extern PFNGLVERTEXATTRIBI4UIVPROC					pglVertexAttribI4uiv;
	extern PFNGLVERTEXATTRIBI4BVPROC					pglVertexAttribI4bv;
	extern PFNGLVERTEXATTRIBI4SVPROC					pglVertexAttribI4sv;
	extern PFNGLVERTEXATTRIBI4UBVPROC					pglVertexAttribI4ubv;
	extern PFNGLVERTEXATTRIBI4USVPROC					pglVertexAttribI4usv;
	extern PFNGLGETUNIFORMUIVPROC						pglGetUniformuiv;
	extern PFNGLBINDFRAGDATALOCATIONPROC				pglBindFragDataLocation;
	extern PFNGLGETFRAGDATALOCATIONPROC					pglGetFragDataLocation;
	extern PFNGLUNIFORM1UIPROC							pglUniform1ui;
	extern PFNGLUNIFORM2UIPROC							pglUniform2ui;
	extern PFNGLUNIFORM3UIPROC							pglUniform3ui;
	extern PFNGLUNIFORM4UIPROC							pglUniform4ui;
	extern PFNGLUNIFORM1UIVPROC							pglUniform1uiv;
	extern PFNGLUNIFORM2UIVPROC							pglUniform2uiv;
	extern PFNGLUNIFORM3UIVPROC							pglUniform3uiv;
	extern PFNGLUNIFORM4UIVPROC							pglUniform4uiv;
	extern PFNGLTEXPARAMETERIIVPROC						pglTexParameterIiv;
	extern PFNGLTEXPARAMETERIUIVPROC					pglTexParameterIuiv;
	extern PFNGLGETTEXPARAMETERIIVPROC					pglGetTexParameterIiv;
	extern PFNGLGETTEXPARAMETERIUIVPROC					pglGetTexParameterIuiv;
	extern PFNGLCLEARBUFFERIVPROC						pglClearBufferiv;
	extern PFNGLCLEARBUFFERUIVPROC						pglClearBufferuiv;
	extern PFNGLCLEARBUFFERFVPROC						pglClearBufferfv;
	extern PFNGLCLEARBUFFERFIPROC						pglClearBufferfi;
	extern PFNGLGETSTRINGIPROC							pglGetStringi;
	extern PFNGLISRENDERBUFFERPROC						pglIsRenderbuffer;
	extern PFNGLBINDRENDERBUFFERPROC					pglBindRenderbuffer;
	extern PFNGLDELETERENDERBUFFERSPROC					pglDeleteRenderbuffers;
	extern PFNGLGENRENDERBUFFERSPROC					pglGenRenderbuffers;
	extern PFNGLRENDERBUFFERSTORAGEPROC					pglRenderbufferStorage;
	extern PFNGLGETRENDERBUFFERPARAMETERIVPROC			pglGetRenderbufferParameteriv;
	extern PFNGLISFRAMEBUFFERPROC						pglIsFramebuffer;
	extern PFNGLBINDFRAMEBUFFERPROC						pglBindFramebuffer;
	extern PFNGLDELETEFRAMEBUFFERSPROC					pglDeleteFramebuffers;
	extern PFNGLGENFRAMEBUFFERSPROC						pglGenFramebuffers;
	extern PFNGLCHECKFRAMEBUFFERSTATUSPROC				pglCheckFramebufferStatus;
	extern PFNGLFRAMEBUFFERTEXTURE1DPROC				pglFramebufferTexture1D;
	extern PFNGLFRAMEBUFFERTEXTURE2DPROC				pglFramebufferTexture2D;
	extern PFNGLFRAMEBUFFERTEXTURE3DPROC				pglFramebufferTexture3D;
	extern PFNGLFRAMEBUFFERRENDERBUFFERPROC				pglFramebufferRenderbuffer;
	extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC	pglGetFramebufferAttachmentParameteriv;
	extern PFNGLGENERATEMIPMAPPROC						pglGenerateMipmap;
	extern PFNGLBLITFRAMEBUFFERPROC						pglBlitFramebuffer;
	extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC		pglRenderbufferStorageMultisample;
	extern PFNGLFRAMEBUFFERTEXTURELAYERPROC				pglFramebufferTextureLayer;
	extern PFNGLMAPBUFFERRANGEPROC						pglMapBufferRange;
	extern PFNGLFLUSHMAPPEDBUFFERRANGEPROC				pglFlushMappedBufferRange;
	extern PFNGLBINDVERTEXARRAYPROC						pglBindVertexArray;
	extern PFNGLDELETEVERTEXARRAYSPROC					pglDeleteVertexArrays;
	extern PFNGLGENVERTEXARRAYSPROC						pglGenVertexArrays;
	extern PFNGLISVERTEXARRAYPROC						pglIsVertexArray;

#define glColorMaski							pglColorMaski
#define glGetBooleani_v							pglGetBooleani_v
#define glGetIntegeri_v							pglGetIntegeri_v
#define glEnablei								pglEnablei
#define glDisablei								pglDisablei
#define glIsEnabledi							pglIsEnabledi
#define glBeginTransformFeedback				pglBeginTransformFeedback
#define glEndTransformFeedback					pglEndTransformFeedback
#define glBindBufferRange						pglBindBufferRange
#define glBindBufferBase						pglBindBufferBase
#define glTransformFeedbackVaryings				pglTransformFeedbackVaryings
#define glGetTransformFeedbackVarying			pglGetTransformFeedbackVarying
#define glClampColor							pglClampColor
#define glBeginConditionalRender				pglBeginConditionalRender
#define glEndConditionalRender					pglEndConditionalRender
#define glVertexAttribIPointer					pglVertexAttribIPointer
#define glGetVertexAttribIiv					pglGetVertexAttribIiv
#define glGetVertexAttribIuiv					pglGetVertexAttribIuiv
#define glVertexAttribI1i						pglVertexAttribI1i
#define glVertexAttribI2i						pglVertexAttribI2i
#define glVertexAttribI3i						pglVertexAttribI3i
#define glVertexAttribI4i						pglVertexAttribI4i
#define glVertexAttribI1ui						pglVertexAttribI1ui
#define glVertexAttribI2ui						pglVertexAttribI2ui
#define glVertexAttribI3ui						pglVertexAttribI3ui
#define glVertexAttribI4ui						pglVertexAttribI4ui
#define glVertexAttribI1iv						pglVertexAttribI1iv
#define glVertexAttribI2iv						pglVertexAttribI2iv
#define glVertexAttribI3iv						pglVertexAttribI3iv
#define glVertexAttribI4iv						pglVertexAttribI4iv
#define glVertexAttribI1uiv						pglVertexAttribI1uiv
#define glVertexAttribI2uiv						pglVertexAttribI2uiv
#define glVertexAttribI3uiv						pglVertexAttribI3uiv
#define glVertexAttribI4uiv						pglVertexAttribI4uiv
#define glVertexAttribI4bv						pglVertexAttribI4bv
#define glVertexAttribI4sv						pglVertexAttribI4sv
#define glVertexAttribI4ubv						pglVertexAttribI4ubv
#define glVertexAttribI4usv						pglVertexAttribI4usv
#define glGetUniformuiv							pglGetUniformuiv
#define glBindFragDataLocation					pglBindFragDataLocation
#define glGetFragDataLocation					pglGetFragDataLocation
#define glUniform1ui							pglUniform1ui
#define glUniform2ui							pglUniform2ui
#define glUniform3ui							pglUniform3ui
#define glUniform4ui							pglUniform4ui
#define glUniform1uiv							pglUniform1uiv
#define glUniform2uiv							pglUniform2uiv
#define glUniform3uiv							pglUniform3uiv
#define glUniform4uiv							pglUniform4uiv
#define glTexParameterIiv						pglTexParameterIiv
#define glTexParameterIuiv						pglTexParameterIuiv
#define glGetTexParameterIiv					pglGetTexParameterIiv
#define glGetTexParameterIuiv					pglGetTexParameterIuiv
#define glClearBufferiv							pglClearBufferiv
#define glClearBufferuiv						pglClearBufferuiv
#define glClearBufferfv							pglClearBufferfv
#define glClearBufferfi							pglClearBufferfi
#define glGetStringi							pglGetStringi
#define glIsRenderbuffer						pglIsRenderbuffer
#define glBindRenderbuffer						pglBindRenderbuffer
#define glDeleteRenderbuffers					pglDeleteRenderbuffers
#define glGenRenderbuffers						pglGenRenderbuffers
#define glRenderbufferStorage					pglRenderbufferStorage
#define glGetRenderbufferParameteriv			pglGetRenderbufferParameteriv
#define glIsFramebuffer							pglIsFramebuffer
#define glBindFramebuffer						pglBindFramebuffer
#define glDeleteFramebuffers					pglDeleteFramebuffers
#define glGenFramebuffers						pglGenFramebuffers
#define glCheckFramebufferStatus				pglCheckFramebufferStatus
#define glFramebufferTexture1D					pglFramebufferTexture1D
#define glFramebufferTexture2D					pglFramebufferTexture2D
#define glFramebufferTexture3D					pglFramebufferTexture3D
#define glFramebufferRenderbuffer				pglFramebufferRenderbuffer
#define glGetFramebufferAttachmentParameteriv	pglGetFramebufferAttachmentParameteriv
#define glGenerateMipmap						pglGenerateMipmap
#define glBlitFramebuffer						pglBlitFramebuffer
#define glRenderbufferStorageMultisample		pglRenderbufferStorageMultisample
#define glFramebufferTextureLayer				pglFramebufferTextureLayer
#define glMapBufferRange						pglMapBufferRange
#define glFlushMappedBufferRange				pglFlushMappedBufferRange
#define glBindVertexArray						pglBindVertexArray
#define glDeleteVertexArrays					pglDeleteVertexArrays
#define glGenVertexArrays						pglGenVertexArrays
#define glIsVertexArray							pglIsVertexArray

	int GL_3_0_LoadFuncPointers();

	/////////////////////////////// GL_VERSION_3_1 ////////////////////////////////

	extern PFNGLDRAWARRAYSINSTANCEDPROC					pglDrawArraysInstanced;
	extern PFNGLDRAWELEMENTSINSTANCEDPROC				pglDrawElementsInstanced;
	extern PFNGLTEXBUFFERPROC							pglTexBuffer;
	extern PFNGLPRIMITIVERESTARTINDEXPROC				pglPrimitiveRestartIndex;
	extern PFNGLCOPYBUFFERSUBDATAPROC					pglCopyBufferSubData;
	extern PFNGLGETUNIFORMINDICESPROC					pglGetUniformIndices;
	extern PFNGLGETACTIVEUNIFORMSIVPROC					pglGetActiveUniformsiv;
	extern PFNGLGETACTIVEUNIFORMNAMEPROC				pglGetActiveUniformName;
	extern PFNGLGETUNIFORMBLOCKINDEXPROC				pglGetUniformBlockIndex;
	extern PFNGLGETACTIVEUNIFORMBLOCKIVPROC				pglGetActiveUniformBlockiv;
	extern PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC			pglGetActiveUniformBlockName;
	extern PFNGLUNIFORMBLOCKBINDINGPROC					pglUniformBlockBinding;

#define glDrawArraysInstanced					pglDrawArraysInstanced
#define glDrawElementsInstanced					pglDrawElementsInstanced
#define glTexBuffer								pglTexBuffer
#define glPrimitiveRestartIndex					pglPrimitiveRestartIndex
#define glCopyBufferSubData						pglCopyBufferSubData
#define glGetUniformIndices						pglGetUniformIndices
#define glGetActiveUniformsiv					pglGetActiveUniformsiv
#define glGetActiveUniformName					pglGetActiveUniformName
#define glGetUniformBlockIndex					pglGetUniformBlockIndex
#define glGetActiveUniformBlockiv				pglGetActiveUniformBlockiv
#define glGetActiveUniformBlockName				pglGetActiveUniformBlockName
#define glUniformBlockBinding					pglUniformBlockBinding

	int GL_3_1_LoadFuncPointers();

	/////////////////////////////// GL_VERSION_3_2 ////////////////////////////////

	extern PFNGLDRAWELEMENTSBASEVERTEXPROC				pglDrawElementsBaseVertex;
	extern PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC			pglDrawRangeElementsBaseVertex;
	extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC		pglDrawElementsInstancedBaseVertex;
	extern PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC			pglMultiDrawElementsBaseVertex;
	extern PFNGLPROVOKINGVERTEXPROC						pglProvokingVertex;
	extern PFNGLFENCESYNCPROC							pglFenceSync;
	extern PFNGLISSYNCPROC								pglIsSync;
	extern PFNGLDELETESYNCPROC							pglDeleteSync;
	extern PFNGLCLIENTWAITSYNCPROC						pglClientWaitSync;
	extern PFNGLWAITSYNCPROC							pglWaitSync;
	extern PFNGLGETINTEGER64VPROC						pglGetInteger64v;
	extern PFNGLGETSYNCIVPROC							pglGetSynciv;
	extern PFNGLGETINTEGER64I_VPROC						pglGetInteger64i_v;
	extern PFNGLGETBUFFERPARAMETERI64VPROC				pglGetBufferParameteri64v;
	extern PFNGLFRAMEBUFFERTEXTUREPROC					pglFramebufferTexture;
	extern PFNGLTEXIMAGE2DMULTISAMPLEPROC				pglTexImage2DMultisample;
	extern PFNGLTEXIMAGE3DMULTISAMPLEPROC				pglTexImage3DMultisample;
	extern PFNGLGETMULTISAMPLEFVPROC					pglGetMultisamplefv;
	extern PFNGLSAMPLEMASKIPROC							pglSampleMaski;

#define glDrawElementsBaseVertex			pglDrawElementsBaseVertex
#define glDrawRangeElementsBaseVertex		pglDrawRangeElementsBaseVertex
#define glDrawElementsInstancedBaseVertex	pglDrawElementsInstancedBaseVertex
#define glMultiDrawElementsBaseVertex		pglMultiDrawElementsBaseVertex
#define glProvokingVertex					pglProvokingVertex
#define glFenceSync							pglFenceSync
#define glIsSync							pglIsSync
#define glDeleteSync						pglDeleteSync
#define glClientWaitSync					pglClientWaitSync
#define glWaitSync							pglWaitSync
#define glGetInteger64v						pglGetInteger64v
#define glGetSynciv							pglGetSynciv
#define glGetInteger64i_v					pglGetInteger64i_v
#define glGetBufferParameteri64v			pglGetBufferParameteri64v
#define glFramebufferTexture				pglFramebufferTexture
#define glTexImage2DMultisample				pglTexImage2DMultisample
#define glTexImage3DMultisample				pglTexImage3DMultisample
#define glGetMultisamplefv					pglGetMultisamplefv
#define glSampleMaski						pglSampleMaski

	int GL_3_2_LoadFuncPointers();

	/////////////////////////////// GL_VERSION_3_3 ////////////////////////////////

	extern PFNGLBINDFRAGDATALOCATIONINDEXEDPROC		pglBindFragDataLocationIndexed;
	extern PFNGLGETFRAGDATAINDEXPROC				pglGetFragDataIndex;
	extern PFNGLGENSAMPLERSPROC						pglGenSamplers;
	extern PFNGLDELETESAMPLERSPROC					pglDeleteSamplers;
	extern PFNGLISSAMPLERPROC						pglIsSampler;
	extern PFNGLBINDSAMPLERPROC						pglBindSampler;
	extern PFNGLSAMPLERPARAMETERIPROC				pglSamplerParameteri;
	extern PFNGLSAMPLERPARAMETERIVPROC				pglSamplerParameteriv;
	extern PFNGLSAMPLERPARAMETERFPROC				pglSamplerParameterf;
	extern PFNGLSAMPLERPARAMETERFVPROC				pglSamplerParameterfv;
	extern PFNGLSAMPLERPARAMETERIIVPROC				pglSamplerParameterIiv;
	extern PFNGLSAMPLERPARAMETERIUIVPROC			pglSamplerParameterIuiv;
	extern PFNGLGETSAMPLERPARAMETERIVPROC			pglGetSamplerParameteriv;
	extern PFNGLGETSAMPLERPARAMETERIIVPROC			pglGetSamplerParameterIiv;
	extern PFNGLGETSAMPLERPARAMETERFVPROC			pglGetSamplerParameterfv;
	extern PFNGLGETSAMPLERPARAMETERIUIVPROC			pglGetSamplerParameterIuiv;
	extern PFNGLQUERYCOUNTERPROC					pglQueryCounter;
	extern PFNGLGETQUERYOBJECTI64VPROC				pglGetQueryObjecti64v;
	extern PFNGLGETQUERYOBJECTUI64VPROC				pglGetQueryObjectui64v;
	extern PFNGLVERTEXATTRIBDIVISORPROC				pglVertexAttribDivisor;
	extern PFNGLVERTEXATTRIBP1UIPROC				pglVertexAttribP1ui;
	extern PFNGLVERTEXATTRIBP1UIVPROC				pglVertexAttribP1uiv;
	extern PFNGLVERTEXATTRIBP2UIPROC				pglVertexAttribP2ui;
	extern PFNGLVERTEXATTRIBP2UIVPROC				pglVertexAttribP2uiv;
	extern PFNGLVERTEXATTRIBP3UIPROC				pglVertexAttribP3ui;
	extern PFNGLVERTEXATTRIBP3UIVPROC				pglVertexAttribP3uiv;
	extern PFNGLVERTEXATTRIBP4UIPROC				pglVertexAttribP4ui;
	extern PFNGLVERTEXATTRIBP4UIVPROC				pglVertexAttribP4uiv;

#define glBindFragDataLocationIndexed	pglBindFragDataLocationIndexed
#define glGetFragDataIndex				pglGetFragDataIndex
#define glGenSamplers					pglGenSamplers
#define glDeleteSamplers				pglDeleteSamplers
#define glIsSampler						pglIsSampler
#define glBindSampler					pglBindSampler
#define glSamplerParameteri				pglSamplerParameteri
#define glSamplerParameteriv			pglSamplerParameteriv
#define glSamplerParameterf				pglSamplerParameterf
#define glSamplerParameterfv			pglSamplerParameterfv
#define glSamplerParameterIiv			pglSamplerParameterIiv
#define glSamplerParameterIuiv			pglSamplerParameterIuiv
#define glGetSamplerParameteriv			pglGetSamplerParameteriv
#define glGetSamplerParameterIiv		pglGetSamplerParameterIiv
#define glGetSamplerParameterfv			pglGetSamplerParameterfv
#define glGetSamplerParameterIuiv		pglGetSamplerParameterIuiv
#define glQueryCounter 					pglQueryCounter
#define glGetQueryObjecti64v			pglGetQueryObjecti64v
#define glGetQueryObjectui64v			pglGetQueryObjectui64v
#define glVertexAttribDivisor			pglVertexAttribDivisor
#define glVertexAttribP1ui				pglVertexAttribP1ui
#define glVertexAttribP1uiv				pglVertexAttribP1uiv
#define glVertexAttribP2ui				pglVertexAttribP2ui
#define glVertexAttribP2uiv				pglVertexAttribP2uiv
#define glVertexAttribP3ui				pglVertexAttribP3ui
#define glVertexAttribP3uiv				pglVertexAttribP3uiv
#define glVertexAttribP4ui				pglVertexAttribP4ui
#define glVertexAttribP4uiv				pglVertexAttribP4uiv

	int GL_3_3_LoadFuncPointers();

	/////////////////////////////// GL_VERSION_4_2 ////////////////////////////////

	extern PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC					pglDrawArraysInstancedBaseInstance;
	extern PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC				pglDrawElementsInstancedBaseInstance;
	extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC		pglDrawElementsInstancedBaseVertexBaseInstance;
	extern PFNGLGETINTERNALFORMATIVPROC								pglGetInternalformativ;
	extern PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC					pglGetActiveAtomicCounterBufferiv;
	extern PFNGLBINDIMAGETEXTUREPROC								pglBindImageTexture;
	extern PFNGLMEMORYBARRIERPROC									pglMemoryBarrier;
	extern PFNGLTEXSTORAGE1DPROC									pglTexStorage1D;
	extern PFNGLTEXSTORAGE2DPROC									pglTexStorage2D;
	extern PFNGLTEXSTORAGE3DPROC									pglTexStorage3D;
	extern PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC					pglDrawTransformFeedbackInstanced;
	extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC			pglDrawTransformFeedbackStreamInstanced;

#define glDrawArraysInstancedBaseInstance				pglDrawArraysInstancedBaseInstance
#define glDrawElementsInstancedBaseInstance				pglDrawElementsInstancedBaseInstance
#define glDrawElementsInstancedBaseVertexBaseInstance	pglDrawElementsInstancedBaseVertexBaseInstance
#define glGetInternalformativ							pglGetInternalformativ
#define glGetActiveAtomicCounterBufferiv				pglGetActiveAtomicCounterBufferiv
#define glBindImageTexture								pglBindImageTexture
#define glMemoryBarrier									pglMemoryBarrier
#define glTexStorage1D									pglTexStorage1D
#define glTexStorage2D									pglTexStorage2D
#define glTexStorage3D									pglTexStorage3D
#define glDrawTransformFeedbackInstanced				pglDrawTransformFeedbackInstanced
#define glDrawTransformFeedbackStreamInstanced			pglDrawTransformFeedbackStreamInstanced

	int GL_4_2_LoadFuncPointers();

#ifdef __cplusplus
}
#endif

#endif // glLoader_h
