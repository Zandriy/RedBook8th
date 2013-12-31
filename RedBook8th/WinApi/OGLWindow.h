#ifndef OGLWindow_h
#define OGLWindow_h

#include <windows.h>
#include <tchar.h>

class OGLWindow
{
public:
	OGLWindow(const char* name, const char* title = "OpenGL Window");
	virtual ~OGLWindow(void);

	HWND Init(HINSTANCE hInstance, HWND hParent);
	const char * getName() const {return m_ClassName;}
	const char * getTitle() const {return m_WindowTitle;}

	void MoveAndUpdate(int x, int y, int w, int h, int nCmdShow);
	virtual void InitGL() = 0;

private:
	BOOL InitWindowClass(HINSTANCE hInstance);
	HWND InitInstance(HINSTANCE hInstance, HWND hParent);
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
