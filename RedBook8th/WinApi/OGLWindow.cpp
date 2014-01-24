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
{
}

OGLWindow::~OGLWindow(void)
{
	delete [] m_ClassName;
	delete [] m_WindowTitle;
	DestroyWindow(m_hWnd);
}

HWND OGLWindow::Init(HINSTANCE hInstance, HWND hParent, int x, int y, int w, int h)
{
	if ( !InitWindowClass(hInstance) )
		return NULL;

	return InitInstance(hInstance, hParent, x, y, w, h);
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

HWND OGLWindow::InitInstance(HINSTANCE hInstance, HWND hParent, int x, int y, int w, int h)
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

	if ( !CreateContext() )
	{
		DestroyWindow(m_hWnd);
		m_hWnd = NULL;
	}

	MoveWindow(m_hWnd, x, y, w, h, FALSE);
	ShowWindow(m_hWnd, SW_HIDE); 

	BOOL makeCurResult = wglMakeCurrent( m_hDC, m_Context );

	return m_hWnd; 
}

void OGLWindow::Show()
{
	ShowWindow(m_hWnd, SW_SHOW); 
	UpdateWindow(m_hWnd);

	BOOL makeCurResult = wglMakeCurrent( m_hDC, m_Context );
	if (makeCurResult == TRUE)
		Display();
}

void OGLWindow::Hide()
{
	BOOL makeCurResult = wglMakeCurrent( NULL, NULL );

	ShowWindow(m_hWnd, SW_HIDE); 
	UpdateWindow(m_hWnd);
}

bool OGLWindow::CreateContext()
{
	if ( m_Context )
		return false;

	// get the device context (DC)
	m_hDC = GetDC( m_hWnd );

	// prepare the pixel format for the DC
	ZeroMemory( &m_pfd, sizeof( m_pfd ) );
	m_pfd.nSize = sizeof( m_pfd );
	m_pfd.nVersion = 1;
	m_pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER;
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


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return TRUE;//WinParent::Instance()->MainWindowLoop(hWnd, message, wParam, lParam);
}