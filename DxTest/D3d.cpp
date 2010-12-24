#include "D3d.h"

D3d::D3d()
{
	this->swapChain = NULL;
	this->device = NULL;
	this->deviceContext = NULL;
	this->renderTargetView = NULL;
	this->depthStencilBuffer = NULL;
	this->depthStencilState = NULL;
	this->depthStencilView = NULL;
	this->rasterState = NULL;
}

D3d::~D3d()
{
}

bool D3d::Initialise(int screenWidth, int screenHeight, bool vSync, HWND hwnd, bool fullScreen, float screenDepth,
	float screenNear)
{
	this->isVsyncEnabled = vSync;

	// Create a dx graphics interface factory
	IDXGIFactory* factory;
	HRESULT result = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**) &factory);
	if (FAILED(result)) return false;

	// Use the factory to create an adaptor for the primary graphics interface
	IDXGIAdapter* adaptor;
	result = factory->EnumAdapters(0, &adaptor);
	if (FAILED(result)) return false;

	// Enumerate the primary adaptor output
	IDXGIOutput* adaptorOutput;
	result = adaptor->EnumOutputs(0, &adaptorOutput);
	if (FAILED(result)) return false;

	// Get the number of modes that fit the DXGI_FORMAT_R8G8B8A8_UNORM display format for the adaptor output
	unsigned int numModes;
	result = adaptorOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL);
	if (FAILED(result)) return false;

	// Create a list to hold all the possible display modes for this monitor / card
	DXGI_MODE_DESC* displayModeList = new DXGI_MODE_DESC[numModes];
	if (!displayModeList) return false;

	// Now fill the display mode list structures
	result = adaptorOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList);
	if (FAILED(result)) return false;

	// Now go through all the display modes and find the one that matches the screen width and heigh, when a match
	// is found store the numerator and denomiator of the refresh rate for that monitor
	unsigned int numerator;
	unsigned int denominator;
	for (int i = 0; i < numModes; ++i)
	{
		if (displayModeList[i].Width == (unsigned int) screenWidth
			&& displayModeList[i].Height == (unsigned int) screenHeight)
		{
			numerator = displayModeList[i].RefreshRate.Numerator;
			denominator = displayModeList[i].RefreshRate.Denominator;
		}
	}

	// Now we have the numerator and denominator, we can release the structures and interfaces used to get that information
	delete [] displayModeList;
	displayModeList = NULL;
	adaptorOutput->Release();
	adaptorOutput = NULL;
	adaptor->Release();
	adaptor = NULL;
	factory->Release();
	factory = NULL;

	// initialise the swap chain description
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizof(swapChainDesc));

}