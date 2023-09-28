#pragma once

#include "SystemGlobals.h"

class GamePhase;

class Core
{
public:
	Core();
	void Run();

	static bool IsInteractPressed();
	static bool IsInteractDown();

private:
	bool Init();
	void Terminate();
	void ReadResolution(int& width, int& height); // TODO: Switch to read config, more generalized
	void InitAppState(AppState newState);
	void CheckForStateChange();
	AppState GetNextState();

private:
	AppState _currentState = AppState::Unset;
	GamePhase* _gamePhase = nullptr;
};