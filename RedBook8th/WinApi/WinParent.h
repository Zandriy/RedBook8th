#ifndef WinParent_h
#define WinParent_h

#include <windows.h>
#include <tchar.h>
#include <map>

class WinChild;

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

	HINSTANCE m_hInstance;
	HWND m_hwnd;

	std::map<HWND, WinChild*> m_childMap;

	const char* m_ClassName;
	const char* m_WindowTitle;
};

#endif // WinParent_h

