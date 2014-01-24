/*
* OGLWindow.h
*
* Created on: Dec 31, 2013
* Author: Andrew Zhabura
*/

#ifndef OGLWindow_h
#define OGLWindow_h

#include <windows.h>
#include <tchar.h>

class OGLWindow
{
public:
	OGLWindow(const char* name, const char* title = "OpenGL Window");
	virtual ~OGLWindow(void);

	HWND Init(HINSTANCE hInstance, HWND hParent, int x, int y, int w, int h);
	const char * getName() const {return m_ClassName;}
	const char * getTitle() const {return m_WindowTitle;}
	HWND getHWND() const { return m_hWnd; }

	void Show();
	void Hide();

	virtual void InitGL() = 0;
	virtual void Display() = 0;
protected:
	void Swap();
private:
	BOOL InitWindowClass(HINSTANCE hInstance);
	HWND InitInstance(HINSTANCE hInstance, HWND hParent, int x, int y, int w, int h);
	bool CreateContext();

	const char* m_ClassName;
	const char* m_WindowTitle;

	HWND m_hWnd;
	HDC m_hDC;
	HGLRC m_Context;
	int m_curPixelFormat;
	PIXELFORMATDESCRIPTOR m_pfd;
};

#endif // OGLWindow
