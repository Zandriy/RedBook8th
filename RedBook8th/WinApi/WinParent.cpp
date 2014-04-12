/*
* WinParent.cpp
*
* Created on: Dec 31, 2013
* Author: Andrew Zhabura
*/

#include "winParent.h"
#include <algorithm>

#include "Examples/Ex01.h"
#include "Examples/Ex02_04.h"
#include "Examples/Ex03_01.h"
#include "Examples/Ex03_02.h"
#include "Examples/Ex03_05.h"
#include "Examples/Ex03_07.h"
#include "Examples/Ex03_10.h"
#include "Examples/Ex03_11.h"
#include "Examples/Ex03_14.h"
#include "Examples/Ex04_01.h"
#include "Examples/Ex04_02.h"
#include "Examples/Ex05_09.h"
#include "Examples/Ex06_02.h"
#include "Examples/Ex06_03.h"
#include "Examples/Ex06_04.h"
#include "Examples/Ex06_10.h"
#include "Examples/Ex06_14.h"
#include "Examples/Ex06_16.h"
#include "Examples/Ex06_18.h"
#include "Examples/Ex06_mipmap.h"
#include "Examples/Ex06_mip_filters.h"
#include "Examples/Ex06_29.h"
#include "Examples/Ex06_30.h"
#include "Examples/Ex07_01.h"
#include "Examples/Ex07_02.h"
#include "Examples/Ex07_03.h"
#include "Examples/Ex07_04.h"
#include "Examples/Ex07_05.h"
#include "Examples/Ex07_06.h"
#include "Examples/Ex07_08.h"
#include "Examples/Ex07_15.h"
#include "Examples/Ex07_lights.h"
#include "Examples/Ex08_01.h"
#include "Examples/Ex08_03.h"
#include "Examples/Ex08_07.h"
#include "Examples/Ex08_08.h"
#include "Examples/Ex08_09.h"
#include "Examples/Ex08_11.h"
#include "Examples/Ex08_12.h"
#include "Examples/Ex08_13.h"
#include "Examples/Ex08_16.h"
#include "Examples/Ex08_18.h"
#include "Examples/Ex08_19.h"
#include "Examples/Ex08_20.h"
#include "Examples/Ex08_21.h"
#include "Examples/Ex09_06.h"
#include "Examples/Ex09_08.h"
#include "Examples/Ex10_07.h"
#include "Examples/Ex10_15.h"
#include "Examples/Ex10_21.h"
#include "Examples/Ex11_04.h"
#include "Examples/Ex11_29.h"

#include "Examples/ExTest.h"

#define EXAMPLES_QTY 53
#define CUR_EXAMPLE EXAMPLES_QTY-2

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
	, m_hwnd(NULL)
	, m_curChild(-1)
{
}

void deleteOGL (OGLWindow* win)
{
	delete win;
}

WinParent::~WinParent()
{
	delete [] m_ClassName;
	delete [] m_WindowTitle;

	for_each (m_childArr.begin(), m_childArr.end(), deleteOGL);
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

	RECT mr;
	GetWindowRect(m_hwnd, &mr);
	RECT r;
	GetClientRect(m_hwnd, &r);

	int bound = ((mr.right - mr.left) - (r.right - r.left)) / 2;
	int header = (mr.bottom - mr.top) - (r.bottom - r.top) - bound;
	MoveWindow(m_hwnd, mr.left, mr.top, 512 + 2 * bound, 512 + header + bound, FALSE);

	// Show the Window and send a WM_PAINT message to the Window 
	// procedure. 
	ShowWindow(m_hwnd, nCmdShow); 

	m_curChild = InitChilds(nCmdShow);
	SetWindowText(m_hwnd, m_childArr[m_curChild]->getTitle());
	m_childArr[m_curChild]->Show();

	return TRUE; 
}

int WinParent::InitChilds(int nCmdShow)
{
	RECT r;
	GetClientRect(m_hwnd, &r);

	OGLWindow * child = new Ex01;
	InitChild(child, r);
	child = new Ex02_04;
	InitChild(child, r);
	child = new Ex03_01;
	InitChild(child, r);
	child = new Ex03_02;
	InitChild(child, r);
	child = new Ex03_05;
	InitChild(child, r);
	child = new Ex03_07;
	InitChild(child, r);
	child = new Ex03_10;
	InitChild(child, r);
	child = new Ex03_11;
	InitChild(child, r);
	child = new Ex03_14;
	InitChild(child, r);
	child = new Ex04_01;
	InitChild(child, r);
	child = new Ex04_02;
	InitChild(child, r);
	child = new Ex05_09;
	InitChild(child, r);
	child = new Ex06_02;
	InitChild(child, r);
	child = new Ex06_03;
	InitChild(child, r);
	child = new Ex06_04;
	InitChild(child, r);
	child = new Ex06_10;
	InitChild(child, r);
	child = new Ex06_14;
	InitChild(child, r);
	child = new Ex06_16;
	InitChild(child, r);
	child = new Ex06_18;
	InitChild(child, r);
	child = new Ex06_mipmap;
	InitChild(child, r);
	child = new Ex06_mip_filters;
	InitChild(child, r);
	child = new Ex06_29;
	InitChild(child, r);
	child = new Ex06_30;
	InitChild(child, r);
	child = new Ex07_01;
	InitChild(child, r);
	child = new Ex07_02;
	InitChild(child, r);
	child = new Ex07_03;
	InitChild(child, r);
	child = new Ex07_04;
	InitChild(child, r);
	child = new Ex07_05;
	InitChild(child, r);
	child = new Ex07_06;
	InitChild(child, r);
	child = new Ex07_08;
	InitChild(child, r);
	child = new Ex07_15;
	InitChild(child, r);
	child = new Ex07_lights;
	InitChild(child, r);
	child = new Ex08_01;
	InitChild(child, r);
	child = new Ex08_03;
	InitChild(child, r);
	child = new Ex08_07;
	InitChild(child, r);
	child = new Ex08_08;
	InitChild(child, r);
	child = new Ex08_09;
	InitChild(child, r);
	child = new Ex08_11;
	InitChild(child, r);
	child = new Ex08_12;
	InitChild(child, r);
	child = new Ex08_13;
	InitChild(child, r);
	child = new Ex08_16;
	InitChild(child, r);
	child = new Ex08_18;
	InitChild(child, r);
	child = new Ex08_19;
	InitChild(child, r);
	child = new Ex08_20;
	InitChild(child, r);
	child = new Ex08_21;
	InitChild(child, r);
	child = new Ex09_06;
	InitChild(child, r);
	child = new Ex09_08;
	InitChild(child, r);
	child = new Ex10_07;
	InitChild(child, r);
	child = new Ex10_15;
	InitChild(child, r);
	child = new Ex10_21;
	InitChild(child, r);
	child = new Ex11_04;
	InitChild(child, r);
	child = new Ex11_29;
	InitChild(child, r);

	child = new ExTest;
	InitChild(child, r);

	if (m_childArr.size() != EXAMPLES_QTY)
		exit(1);

	return CUR_EXAMPLE;
}

void WinParent::InitChild(OGLWindow * child, RECT &r)
{
	child->Init(m_hInstance, m_hwnd, false, r.left, r.top, r.right - r.left, r.bottom - r.top);
	child->InitGL();
	m_childArr.push_back(child);
}

LRESULT WinParent::MainWindowLoop(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// 	for (std::map<HWND, OGLWindow*>::iterator it=m_childArr.begin(); it!=m_childArr.end(); ++it)
	// 	{
	// // 		if (message == WM_KEYUP || it->first == hWnd)
	// // 		{
	// 			child = it->second;
	// /*		}*/
	// 	}
	// 	OGLWindow *child = NULL;
	// 	for (std::map<HWND, OGLWindow*>::iterator it=m_childMap.begin(); it!=m_childMap.end(); ++it)
	// 	{
	//  		if (message == WM_KEYUP || it->first == hWnd)
	//  		{
	// 			child = it->second;
	// 		}
	// 
	switch(message)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		m_childArr[m_curChild]->Display();
		break;
	case WM_SIZE:
		{
			if (m_curChild < 0) break;
			int nWidth = LOWORD(lParam);
			int nHight = HIWORD(lParam);
			m_childArr[m_curChild]->Reshape(nWidth, nHight);
			m_childArr[m_curChild]->Show();
		}
		break;
	case WM_KEYUP:
		switch(wParam)
		{
		case VK_ESCAPE:
			exit(EXIT_SUCCESS);
			break;
		case VK_F2:
			{
				int nWidth = m_childArr[m_curChild]->getWidth();
				int nHight = m_childArr[m_curChild]->getHeight();
				m_childArr[m_curChild]->Hide();
				m_curChild--;
				if (m_curChild < 0)
					m_curChild = EXAMPLES_QTY-1;
				SetWindowText(m_hwnd, m_childArr[m_curChild]->getTitle());
				m_childArr[m_curChild]->Reshape(nWidth, nHight);
				m_childArr[m_curChild]->Show();
			}
			break;
		case VK_F3:
			{
				int nWidth = m_childArr[m_curChild]->getWidth();
				int nHight = m_childArr[m_curChild]->getHeight();
				m_childArr[m_curChild]->Hide();
				m_curChild++;
				if (m_curChild >= EXAMPLES_QTY)
					m_curChild = 0;
				SetWindowText(m_hwnd, m_childArr[m_curChild]->getTitle());
				m_childArr[m_curChild]->Reshape(nWidth, nHight);
				m_childArr[m_curChild]->Show();
			}
			break;
		default:
			m_childArr[m_curChild]->keyboard(wParam, 0, 0);
			break;
		}
		break;
	case WM_SIZING:
		{
// 			if (m_curChild < 0) break;
// 			int nWidth = LOWORD(lParam);
// 			int nHight = HIWORD(lParam);
// 			m_childArr[m_curChild]->Reshape(nWidth, nHight);
// 			m_childArr[m_curChild]->Show();
		}
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