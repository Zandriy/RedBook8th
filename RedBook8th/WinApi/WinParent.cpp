/*
* WinParent.cpp
*
* Created on: Dec 31, 2013
* Author: Andrew Zhabura
*/

#include "winParent.h"
#include "Examples/Ex01.h"
#include "Examples/Ex02_04.h"
#include "Examples/Ex03_01.h"

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


WinParent* WinParent::Instance()
{
	static WinParent* s_this = NULL;
	if (!s_this)
		s_this = new WinParent;

	return s_this;
}

WinParent::WinParent()
: m_ClassName("MainWindow")
, m_WindowTitle("Main Window Title")
{
}

WinParent::~WinParent()
{
	delete [] m_ClassName;
	delete [] m_WindowTitle;

	for (std::map<HWND, OGLWindow*>::iterator it=m_childMap.begin(); it!=m_childMap.end(); ++it)
		delete it->second; 
}

BOOL WinParent::Init(HINSTANCE hInstance, int nCmdShow)
{
	// Save the application-instance handle. 
	m_hInstance = hInstance;

	return ( InitApplication() && InitInstance(nCmdShow) );
}

int WinParent::InitMainLoop()
{
	MSG msg; 

	BOOL fGotMessage;
	while ((fGotMessage = GetMessage(&msg, (HWND) NULL, 0, 0)) != 0 && fGotMessage != -1) 
	{ 
		TranslateMessage(&msg); 
		DispatchMessage(&msg); 
	} 
	return msg.wParam; 
}

BOOL WinParent::InitApplication()
{
	WNDCLASSEX wcx; 

	// Fill in the Window class structure with parameters 
	// that describe the main Window. 

	wcx.cbSize = sizeof(wcx);          // size of structure 
	wcx.style = CS_HREDRAW | 
		CS_VREDRAW;                    // redraw if size changes 
	wcx.lpfnWndProc = MainWndProc;     // points to Window procedure 
	wcx.cbClsExtra = 0;                // no extra class memory 
	wcx.cbWndExtra = 0;                // no extra Window memory 
	wcx.hInstance = m_hInstance;         // handle to instance 
	wcx.hIcon = LoadIcon(NULL, 
		IDI_APPLICATION);              // predefined app. icon 
	wcx.hCursor = LoadCursor(NULL, 
		IDC_ARROW);                    // predefined arrow 
	wcx.hbrBackground = (HBRUSH)GetStockObject( 
		WHITE_BRUSH);                  // white background brush 
	wcx.lpszMenuName =  NULL;    // name of menu resource 
	wcx.lpszClassName = m_ClassName;  // name of Window class 
	wcx.hIconSm = (HICON)LoadImage(m_hInstance, // small class icon 
		MAKEINTRESOURCE(5),
		IMAGE_ICON, 
		GetSystemMetrics(SM_CXSMICON), 
		GetSystemMetrics(SM_CYSMICON), 
		LR_DEFAULTCOLOR); 

	// Register the Window class. 
	return RegisterClassEx(&wcx); 
}

BOOL WinParent::InitInstance(int nCmdShow)
{
	// Create the main Window.
	m_hwnd = CreateWindow( 
		m_ClassName,        // name of Window class 
		m_WindowTitle,       // title-bar string 
		WS_OVERLAPPEDWINDOW, // top-level Window 
		CW_USEDEFAULT,       // default horizontal position 
		CW_USEDEFAULT,       // default vertical position 
		CW_USEDEFAULT,       // default width 
		CW_USEDEFAULT,       // default height 
		(HWND) NULL,         // no owner Window 
		(HMENU) NULL,        // use class menu 
		m_hInstance,           // handle to application instance 
		(LPVOID) NULL);      // no Window-creation data 

	if (!m_hwnd) 
		return FALSE;

	OGLWindow * child = new Ex03_01;
	m_childMap[child->Init(m_hInstance, m_hwnd, false)] = child;

	RECT mr;
	GetWindowRect(m_hwnd, &mr);
	RECT r;
	GetClientRect(m_hwnd, &r);

	int bound = ((mr.right - mr.left) - (r.right - r.left)) / 2;
	int header = (mr.bottom - mr.top) - (r.bottom - r.top) - bound;
	MoveWindow(m_hwnd, mr.left, mr.top, 512 + 2 * bound, 512 + header + bound, FALSE);

	// Show the Window and send a WM_PAINT message to the Window 
	// procedure. 
	SetWindowText(m_hwnd, child->getTitle());
	ShowWindow(m_hwnd, nCmdShow); 
	UpdateWindow(m_hwnd); 

	GetClientRect(m_hwnd, &r);
	int w = (r.right - r.left);
	int h = (r.bottom - r.top);

	child->MoveAndUpdate(r.left, r.top, w, h, nCmdShow);
	child->InitGL();
	child->Display();

	return TRUE; 
}

LRESULT WinParent::MainWindowLoop(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	OGLWindow *child = NULL;
	for (std::map<HWND, OGLWindow*>::iterator it=m_childMap.begin(); it!=m_childMap.end(); ++it)
	{
 		if (message == WM_KEYUP || it->first == hWnd)
 		{
			child = it->second;
		}
	}

	switch(message)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		if (child)
			child->Display();
		break;
	case WM_SIZE:
		break;;
	case WM_KEYUP:
		switch(wParam)
		{
		case VK_UP:
			break;
		case VK_DOWN:
			break;
		case VK_LEFT:
			break;
		case VK_RIGHT:
			break;
		case VK_F1:
			break;
		case VK_F2:
			break;
		case VK_INSERT:
			break;
		case VK_SPACE:
			if (child)
				child->Display();
			break;
		default:
			break;
		}
		break;
	case WM_SIZING:
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return WinParent::Instance()->MainWindowLoop(hWnd, message, wParam, lParam);
}