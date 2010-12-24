#include "System.h"

bool System::Initialise()
{
	int screenWidth = 0;
	int screenHeight = 0;
	this->InitialiseWindows(screenWidth, screenHeight);

	// setup input
	this->input.Initialise();

	this->graphics.Initialise(screenWidth, screenHeight, this->hwnd);

	return true;
}

void System::Shutdown()
{
	this->graphics.Shutdown();

	this->ShutdownWindows();
}

void System::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	// Loop until we have a quit message
	while (true)
	{
		// Handle the windows messages
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// if windows signals to end the application, then exit out
		if (msg.message == WM_QUIT) break;
		else
		{
			/// Otherwise do the frame processing. If this fails, exit
			if (!Frame())
			{
				MessageBox(this->hwnd, L"Frame processing failed", L"Error", MB_OK);
				break;
			}
		}

		// Check if the user pressed the escape key
		if (this->input.IsKeyDown(VK_ESCAPE)) break;
	}
}

bool System::Frame() 
{
	this->graphics.Frame();

	this->graphics.Render();

	return true;
}

LRESULT CALLBACK System::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	switch (umsg)
	{
	case WM_KEYDOWN:
		this->input.KeyDown((unsigned int) wparam);
		return 0;
	case WM_KEYUP:
		this->input.KeyUp((unsigned int) wparam);
		return 0;
	default:
		return DefWindowProc(hwnd, umsg, wparam, lparam);
	}
}

void System::InitialiseWindows(int& screenWidth, int& screenHeight)
{
	int posX, posY;

	// Get an external pointer for this object
	ApplicationHandle = this;

	// get the instance of this application
	this->hInstance = GetModuleHandle(NULL);

	// Give the application a name
	this->applicationName = L"Engine";

	// Set up the windows class with default settings
	WNDCLASSEX wc;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = this->hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = this->applicationName;
	wc.cbSize = sizeof(WNDCLASSEX);

	// Register the window class
	RegisterClassEx(&wc);

	// Determine the resolution of the client's desktop
	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);

	// Setup the screen settings for full screen or not
	if (false /*Full screen*/)
	{
		DEVMODE dmScreenSettings;
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long) screenWidth;
		dmScreenSettings.dmPelsHeight = (unsigned long) screenHeight;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Change the display settings
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

		// Set the position of the window to top left
		posX = 0;
		posY = 0;
	}
	else
	{
		screenWidth = 800;
		screenHeight = 600;

		posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;
	}

	// Create the window with the screen settings and get its handle
	this->hwnd = CreateWindowEx(WS_EX_APPWINDOW, this->applicationName, this->applicationName,
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP, posX, posY, screenWidth, screenHeight, NULL, NULL,
		this->hInstance, NULL);

	// Bring the window up on the screen and set it as main focus
	ShowWindow(this->hwnd, SW_SHOW);
	SetForegroundWindow(this->hwnd);
	SetFocus(this->hwnd);

	// Hide the mouse cursor
	// ShowCursor(false);
}

void System::ShutdownWindows()
{
	// Show the mouse cursor
	// ShowCursor(true);

	// Fix the display settings if coming from full screen
	if (/* FULL_SCREEN */ false)
	{
		ChangeDisplaySettings(NULL, 0);
	}	

	// Remove the window
	DestroyWindow(this->hwnd);
	this->hwnd = NULL;

	// remove the application instance
	UnregisterClass(this->applicationName, this->hInstance);
	this->hInstance = NULL;

	// Release the pointer to this class
	ApplicationHandle = NULL;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch (umessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
	default:
		return ApplicationHandle->MessageHandler(hwnd, umessage, wparam, lparam);
	}
}