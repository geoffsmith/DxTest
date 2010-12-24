#include "DxTest.h"
#include "System.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdShow)
{
	// initialise
	System system;
	bool result = system.Initialise();
	if (result) system.Run();

	// Shutdown
	system.Shutdown();
	return 0;
}