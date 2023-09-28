#include "Core.h"
#include "raylib.h"
#include "GamePhase.h"
#include "Menu/Menu.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Core::Core()
{

}

void Core::Run()
{
	if (!Init())
	{
		return;
	}

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		_gamePhase->Update();
		
		EndDrawing();
	}

	Terminate();
}

bool Core::IsInteractPressed()
{
	return IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_SPACE);
}

bool Core::IsInteractDown()
{
	return IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_SPACE);;
}

bool Core::Init()
{
	int width = 1280;
	int height = 800;

	try
	{
		//ReadResolution(width, height);
		InitWindow(width, height, "Memory");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}

	InitAppState(AppState::Menu);

	return true;
}

void Core::Terminate()
{
	CloseWindow();
}

void Core::ReadResolution(int& width, int& height)
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

void Core::InitAppState(AppState newState)
{
	if (_currentState == newState)
	{
		return;
	}

	_currentState = newState;

	switch (_currentState)
	{
	case AppState::Menu:
		_gamePhase = new Menu();
		_gamePhase->Start();

		break;
	case AppState::Game:
		break;
	default:
		return;
	}
}