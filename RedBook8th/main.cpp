/*
* main.cpp
*
* Created on: Dec 31, 2013
* Author: Andrew Zhabura
*/

#include "WinApi/WinParent.h" 

// Function prototypes. 

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int); 

// Application entry point. 

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, 
				   LPSTR lpCmdLine, int nCmdShow) 
{ 
	if (!WinParent::Instance()->Init(hinstance, nCmdShow))
		return FALSE; 

	return WinParent::Instance()->InitMainLoop();

	UNREFERENCED_PARAMETER(hPrevInstance); 
	UNREFERENCED_PARAMETER(lpCmdLine); 
}  