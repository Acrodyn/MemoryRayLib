#pragma once

#include "SystemGlobals.h"
#include "raylib.h"

class GamePhase;

class Core
{
public:
	Core();
	void Run();

	static bool IsInteractPressed();
	static bool IsInteractDown();
	static Vector2 GetScreenCenter();

private:
	bool Init();
	void Terminate();
	void ReadResolution(int& width, int& height); // TODO: Switch to read config, more generalized
	void InitAppState(AppPhase newState);
	void CheckForPhaseChange();
	AppPhase GetNextPhase();

private:
	AppPhase _currentState = AppPhase::Unset;
	GamePhase* _gamePhase = nullptr;
};