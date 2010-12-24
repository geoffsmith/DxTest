#include "Input.h"

Input::Input() {}
Input::~Input() {}

void Input::Initialise()
{
	for (int i = 0; i < 256; ++i)
	{
		this->keys[i] = false;
	}
}

void Input::KeyDown(unsigned int input)
{
	this->keys[input] = true;
}

void Input::KeyUp(unsigned int key)
{
	this->keys[key] = false;
}

bool Input::IsKeyDown(unsigned int key)
{
	return this->keys[key];
}