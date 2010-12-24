#pragma once
#ifndef __Graphics_h_
#define __Graphics_h_

#include "D3d.h"

class Graphics
{
public:
	Graphics() {}
	~Graphics() {}

	bool Initialise(int, int, HWND);
	void Shutdown();
	void Frame();
	void Render();

	static const bool IsFullScreen = false;
	static const bool IsVsyncEnabled = true;
	static const float ScreenDepth;
	static const float ScreenNear;

private:
	D3d d3d;
};


#endif