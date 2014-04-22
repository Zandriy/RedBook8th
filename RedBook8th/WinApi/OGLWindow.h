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

	HWND Init(HINSTANCE hInstance, HWND hParent, bool doubleBuf, int x, int y, int w, int h);

	const char * getName() const {return m_ClassName;}
	const char * getTitle() const {return m_WindowTitle;}
	HWND getHWND() const { return m_hWnd; }

	virtual void Show();
	virtual void Hide();

	virtual void InitGL() = 0;
	virtual void Display() = 0;

	virtual void Reshape(int width, int height);
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }

	virtual void keyboard( unsigned char key, int x, int y );
protected:
	void Swap();
	bool LoadGL();

	static const int c_repeat = 1000;
private:
	BOOL InitWindowClass(HINSTANCE hInstance);
	HWND InitInstance(HINSTANCE hInstance, HWND hParent, bool doubleBuf, int x, int y, int w, int h);
	bool CreateContext();
	bool CreateCoreContext();
	void GetGLVersion(int* major, int* minor);

	const char* m_ClassName;
	const char* m_WindowTitle;

	HWND m_hWnd;
	HDC m_hDC;
	HGLRC m_Context;
	HGLRC m_tempContext;
	int m_curPixelFormat;
	PIXELFORMATDESCRIPTOR m_pfd;
	int m_width;
	int m_height;

	static bool m_glLoaded;
	static int m_major;
	static int m_minor;
};

#endif // OGLWindow
