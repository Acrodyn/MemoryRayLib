#include "Game.h"
#include "raylib.h"
#include "Flapperjack.h"
#include "System/Core.h"

Game::Game()
{

}

void Game::InitPhase()
{
	_flapperjack = new Flapperjack();
}

void Game::DestroyPhase()
{
	delete _flapperjack;
}

void Game::LoopPhase()
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
	//("Test", 200, 200, 20, WHITE);

	_flapperjack->Update();

	/*if (_phaseState != GamePhaseState::Ending)
	{
		if (Core::IsInteractPressed())
		{
			_phaseState = GamePhaseState::Ending;
		}
	}*/
}
