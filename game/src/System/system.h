#pragma once

#include "raylib.h"

class System
{
public:
	System();
	void Run();

private:
	bool Init();
	void Terminate();
	void ReadResolution(int& width, int& height);
};