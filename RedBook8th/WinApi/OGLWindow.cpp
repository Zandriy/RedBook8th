/*
* OGLWindow.cpp
*
* Created on: Dec 31, 2013
* Author: Andrew Zhabura
*/

#include "OGLWindow.h"
#include "WinParent.h"

#include <GL/glLoader.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

OGLWindow::OGLWindow(const char* name, const char* title)
	: m_ClassName(name)
	, m_WindowTitle(title)
	, m_hWnd(NULL)
	, m_hDC(NULL)
	, m_Context(NULL)
	, m_curPixelFormat(0)
	, m_glLoaded(false)
{
}

OGLWindow::~OGLWindow(void)
{
	delete [] m_ClassName;
	delete [] m_WindowTitle;
	DestroyWindow(m_hWnd);
}

HWND OGLWindow::Init(HINSTANCE hInstance, HWND hParent, bool doubleBuf, int x, int y, int w, int h)
{
	if ( !InitWindowClass(hInstance) )
		return NULL;

	return InitInstance(hInstance, hParent, doubleBuf, x, y, w, h);
}

BOOL OGLWindow::InitWindowClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcx; 

	// Fill in the Window class structure with parameters 
	// that describe the main Window. 

	wcx.cbSize = sizeof(wcx);          // size of structure 
	wcx.style = CS_PARENTDC;          // use parent DC 
	wcx.lpfnWndProc = WndProc;     // points to Window procedure 
	wcx.cbClsExtra = 0;                // no extra class memory 
	wcx.cbWndExtra = 0;                // no extra Window memory 
	wcx.hInstance = hInstance;         // handle to instance 
	wcx.hIcon = LoadIcon(NULL, 
		IDI_APPLICATION);              // predefined app. icon 
	wcx.hCursor = LoadCursor(NULL, 
		IDC_ARROW);                    // predefined arrow 
	wcx.hbrBackground = (HBRUSH)GetStockObject( 
		BLACK_BRUSH);                  // white background brush 
	wcx.lpszMenuName =  NULL;    // name of menu resource 
	wcx.lpszClassName = m_ClassName;  // name of Window class 
	wcx.hIconSm = (HICON)LoadImage(hInstance, // small class icon 
		MAKEINTRESOURCE(5),
		IMAGE_ICON, 
		GetSystemMetrics(SM_CXSMICON), 
		GetSystemMetrics(SM_CYSMICON), 
		LR_DEFAULTCOLOR); 

	// Register the Window class. 
	return RegisterClassEx(&wcx); 
}

HWND OGLWindow::InitInstance(HINSTANCE hInstance, HWND hParent, bool doubleBuf, int x, int y, int w, int h)
{
	// Create the main Window.
	m_hWnd = CreateWindow( 
		m_ClassName,        // name of Window class 
		m_WindowTitle,       // title-bar string 
		WS_BORDER | WS_CHILD/* | WS_CLIPSIBLINGS | WS_CLIPCHILDREN*/, //  
		0,       // default horizontal position 
		0,       // default vertical position 
		1,       // default width 
		1,       // default height 
		hParent,         // no owner Window 
		(HMENU) NULL,        // use class menu 
		hInstance,           // handle to application instance 
		(LPVOID) NULL);      // no Window-creation data 

	if ( !CreateContext(doubleBuf) )
	{
		DestroyWindow(m_hWnd);
		m_hWnd = NULL;
	}

	m_width = w;
	m_height = h;

	MoveWindow(m_hWnd, x, y, w, h, FALSE);
	ShowWindow(m_hWnd, SW_HIDE); 

	BOOL makeCurResult = wglMakeCurrent( m_hDC, m_Context );

	return m_hWnd; 
}

void OGLWindow::Show()
{
	MoveWindow(m_hWnd, 0, 0, m_width, m_height, FALSE);
	ShowWindow(m_hWnd, SW_SHOW); 
	UpdateWindow(m_hWnd);

	BOOL makeCurResult = wglMakeCurrent( m_hDC, m_Context );
	if (makeCurResult == TRUE)
	{
		glViewport(0, 0, m_width, m_height);
		Display();
	}
}

void OGLWindow::Hide()
{
	BOOL makeCurResult = wglMakeCurrent( NULL, NULL );

	ShowWindow(m_hWnd, SW_HIDE); 
	UpdateWindow(m_hWnd);
}

void OGLWindow::Reshape(int width, int height)
{
	m_width = width;
	m_height = height;
}

bool OGLWindow::CreateContext(bool doubleBuf)
{
	if ( m_Context )
		return false;

	// get the device context (DC)
	m_hDC = GetDC( m_hWnd );

	// prepare the pixel format for the DC
	ZeroMemory( &m_pfd, sizeof( m_pfd ) );
	m_pfd.nSize = sizeof( m_pfd );
	m_pfd.nVersion = 1;
	m_pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
	if (doubleBuf) m_pfd.dwFlags |= PFD_DOUBLEBUFFER;
	m_pfd.iPixelType = PFD_TYPE_RGBA;
	m_pfd.cColorBits = 24;
	m_pfd.cDepthBits = 16;
	m_pfd.iLayerType = PFD_MAIN_PLANE;
	m_curPixelFormat = ChoosePixelFormat( m_hDC, &m_pfd );

	if ( ! m_curPixelFormat )
		return false;

	// Check whether we get hardware accelerated pixel format or not
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory( &pfd, sizeof( pfd ) );
	if ( ! DescribePixelFormat(m_hDC, m_curPixelFormat, sizeof(pfd), &pfd) )
		return false;

	// We got software-accelerated pixel format, but we use it now for 
	// Windows Remote Desktop
	//if ( pfd.dwFlags & PFD_GENERIC_FORMAT )
	//	return false;

	// set the pixel format for the DC
	BOOL bSetPF = SetPixelFormat( m_hDC, m_curPixelFormat, &m_pfd );
	if ( ! bSetPF )
		return false;

	// create the render context (RC)
	m_Context = wglCreateContext( m_hDC );

	if ( !m_Context )
		return false;

	return true;
}

void OGLWindow::Swap()
{
	SwapBuffers(m_hDC);
}

bool OGLWindow::LoadGL()
{
	if (!m_glLoaded)
	{
		bool b12 = GL_1_2_LoadFuncPointers();
		bool b13 = GL_1_3_LoadFuncPointers();
		bool b14 = GL_1_4_LoadFuncPointers();
		bool b15 = GL_1_5_LoadFuncPointers();
		bool b20 = GL_2_0_LoadFuncPointers();
		bool b30 = GL_3_0_LoadFuncPointers();
		bool b31 = GL_3_1_LoadFuncPointers();
		bool b32 = GL_3_2_LoadFuncPointers();
		bool b33 = GL_3_3_LoadFuncPointers();
		bool b40 = GL_4_0_LoadFuncPointers();
		bool b41 = GL_4_1_LoadFuncPointers();
		bool b42 = GL_4_2_LoadFuncPointers();
		bool b43 = GL_4_3_LoadFuncPointers();

		m_glLoaded = b12 && b13 && b14 && b15 && b20 && b30 && b31 && b32 && b33
			&& b40 && b41 && b42 && b43;
	}
	 return m_glLoaded;
}

void OGLWindow::keyboard( unsigned char key, int x, int y ) 
{
	switch(key)
	{
	case VK_UP:
		break;
	case VK_DOWN:
		break;
	case VK_LEFT:
		break;
	case VK_RIGHT:
		break;
	case VK_INSERT:
		break;
	case VK_SPACE:
		Display();
		break;
	default:
		break;
	}
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return TRUE;//WinParent::Instance()->MainWindowLoop(hWnd, message, wParam, lParam);
}