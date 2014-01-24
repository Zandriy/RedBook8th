/*
* WinParent.h
*
* Created on: Dec 31, 2013
* Author: Andrew Zhabura
*/

#ifndef WinParent_h
#define WinParent_h

#include <windows.h>
#include <tchar.h>
#include <vector>

class OGLWindow;

class WinParent
{
public:
	~WinParent();

	static WinParent* Instance(); 
	BOOL Init(HINSTANCE hInstance, int nCmdShow);
	int InitMainLoop();

	LRESULT MainWindowLoop(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	WinParent();
	WinParent(WinParent const&);
	WinParent& operator= (WinParent const&);

	BOOL InitApplication(); 
	BOOL InitInstance(int nCmdShow); 
	int InitChilds(int nCmdShow);

	void InitChild(OGLWindow * child, RECT &r);

	HINSTANCE m_hInstance;
	HWND m_hwnd;
	int m_curChild;

	std::vector<OGLWindow*> m_childArr;

	const char* m_ClassName;
	const char* m_WindowTitle;
};

#endif // WinParent_h

