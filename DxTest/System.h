#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>

class System
{
public:
	System() {}
	~System() {}
	bool Initialise();
	void Run();
	void Shutdown();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitialiseWindows(int&, int&);
	void ShutdownWindows();

	LPCWSTR applicationName;
	HINSTANCE hInstance;
	HWND hwnd;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static System* ApplicationHandle = 0;