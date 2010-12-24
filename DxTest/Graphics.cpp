#include "Graphics.h"


const float Graphics::ScreenDepth = 1000.0f;
const float Graphics::ScreenNear = 0.1f;

bool Graphics::Initialise(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result = this->d3d.Initialise(screenWidth, screenHeight, Graphics::IsVsyncEnabled, hwnd, Graphics::IsFullScreen,
		Graphics::ScreenDepth, Graphics::ScreenNear);
	if (!result)
	{
		MessageBox(hwnd, L"Couldn't initialise Direct3D", L"Error", MB_OK);
		return false;
	}

	return true;
}

void Graphics::Shutdown() 
{  
	this->d3d.Shutdown();
}

void Graphics::Frame() {  }

void Graphics::Render() 
{
	this->d3d.BeginScene(0.5f, 0.5f, 0.5f, 0.5f);
	this->d3d.EndScene();
}



