#pragma once

class Input
{
public:
	Input();
	~Input();

	void Initialise();

	void KeyDown(unsigned int);
	void KeyUp(unsigned int);

	bool IsKeyDown(unsigned int);

private:
	bool keys[256];
};