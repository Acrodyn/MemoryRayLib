#include "system.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

System::System()
{

}

void System::Run()
{
	if (!Init())
	{
		return;
	}

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		DrawText("My new memory attempt", 200, 200, 20, WHITE);

		EndDrawing();
	}

	Terminate();
}

bool System::Init()
{
	int width = 0;
	int height = 0;

	try
	{
		ReadResolution(width, height);
		InitWindow(width, height, "Memory");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}

	return true;
}

void System::Terminate()
{
	CloseWindow();
}

void System::ReadResolution(int& width, int& height)
{
	std::ifstream configFile;
	std::string line;
	std::vector<std::string> tokens;
	
	configFile.open("resources/Config.txt");

	if (!configFile.is_open())
	{
		throw std::exception("Config not found");
	}

	while (std::getline(configFile, line, '\t'))
	{	
		tokens.push_back(line);
	}

	if (tokens.size() != 2)
	{
		throw std::exception("Corrupt config, resolution data can't be read");
	}

	width = std::stoi(tokens[0]);
	height = std::stoi(tokens[1]);
}