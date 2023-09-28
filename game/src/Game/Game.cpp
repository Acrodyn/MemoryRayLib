#include "Game.h"
#include "raylib.h"
#include "System/Core.h"

Game::Game()
{

}

void Game::LoopPhase()
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), GREEN);
	DrawText("Test", 200, 200, 20, BLACK);

	if (_phaseState != GamePhaseState::Ending)
	{
		if (Core::IsInteractPressed())
		{
			_phaseState = GamePhaseState::Ending;
		}
	}
}
