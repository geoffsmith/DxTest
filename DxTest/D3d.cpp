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
	/*this->isVsyncEnabled = vSync;

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
	for (unsigned int i = 0; i < numModes; ++i)
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
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

	// Set to a single back buffer
	swapChainDesc.BufferCount = 1;

	// Set the width and height of the back buffer
	swapChainDesc.BufferDesc.Width = screenWidth;
	swapChainDesc.BufferDesc.Height = screenHeight;

	// Set regular 32-bit surface for the back buffer
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

	// Set the refresh rate of the back buffer
	if (this->isVsyncEnabled)
	{
		swapChainDesc.BufferDesc.RefreshRate.Numerator = numerator;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = denominator;
	}
	else
	{
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 0;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	}

	// Set the usage of the back buffer
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

	// Set the handle for the window to render to
	swapChainDesc.OutputWindow = hwnd;

	// Turn multisampling off
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;

	// Set to full screen or windowed
	swapChainDesc.Windowed = !fullScreen;

	// Set the scan line ordering and scaling to unspecified
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	// Discard the back buffer contents after presenting
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	// Don't set the advanced flags
	swapChainDesc.Flags = 0;

	// Set the feature level to dx 11
	D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;

	// Create the swap chain, direct 3d device and direct3d device context
	result = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, &featureLevel, 1, 
		D3D11_SDK_VERSION, &swapChainDesc, &this->swapChain, &this->device, NULL, &this->deviceContext);
	if (FAILED(result)) return false;

	// Get the pointer to the back buffer
	ID3D11Texture2D* backBufferPointer;
	result = this->swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*) &backBufferPointer);
	if (FAILED(result)) return false;

	// Create the render target view with the back buffer pointer
	result = this->device->CreateRenderTargetView(backBufferPointer, NULL, &renderTargetView);
	*/
return true;
}