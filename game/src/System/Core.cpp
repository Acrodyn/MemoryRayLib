#include "Core.h"
#include "GamePhase.h"
#include "Menu/Menu.h"
#include "Game/Game.h"

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
		CheckForPhaseChange();
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

Vector2 Core::GetScreenCenter()
{
	return { (GetScreenWidth()) / 2.0f, GetScreenHeight() / 2.0f };
}

bool Core::Init()
{
	int width = 1280;
	int height = 800;

	try
	{
		//ReadResolution(width, height);
		SetConfigFlags(FLAG_MSAA_4X_HINT);
		InitWindow(width, height, "Memory");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}

	//InitAppState(AppPhase::Menu);
	InitAppState(AppPhase::Game); // for testing

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

void Core::InitAppState(AppPhase newState)
{
	if (_currentState == newState)
	{
		return;
	}

	_currentState = newState;

	if (_gamePhase != nullptr)
	{
		_gamePhase->End();
		delete _gamePhase;
	}

	switch (_currentState)
	{
	case AppPhase::Menu:
		_gamePhase = new Menu();
		break;
	case AppPhase::Game:
		_gamePhase = new Game();
		break;
	default:
		return;
	}

	_gamePhase->Start();
}

void Core::CheckForPhaseChange()
{
	if (_gamePhase->IsEnded())
	{
		InitAppState(GetNextPhase());
	}
}

AppPhase Core::GetNextPhase()
{
	if (_gamePhase == nullptr)
	{
		return AppPhase::Unset;
	}

	switch (_currentState)
	{
	case AppPhase::Menu:
		return AppPhase::Game;
	case AppPhase::Game:
		return AppPhase::Menu;
	default:
		return AppPhase::Unset;
	}
}
