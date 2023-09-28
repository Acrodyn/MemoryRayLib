#include "Menu.h"
#include "raylib.h"
#include "System/Core.h"

Menu::Menu()
{

}

void Menu::Start()
{
	GamePhase::Start();
	_transitionAlpha = 1.f;
}

void Menu::End()
{
	GamePhase::End();
	_transitionAlpha = 0.f;
}

void Menu::Update()
{
	if (_phaseState == GamePhaseState::Ended)
	{
		return;
	}

	LoopMenu();

	if (_phaseState != GamePhaseState::Running)
	{
		switch (_phaseState)
		{
			case GamePhaseState::Starting:
				TransitionToMenu();
				break;
			case GamePhaseState::Ending:
				TransitionFromMenu();
				break;
		}
	}
}

void Menu::TransitionToMenu()
{
	if (_transitionAlpha < 0.f)
	{
		_phaseState = GamePhaseState::Running;
		return;
	}

	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, _transitionAlpha));
	_transitionAlpha -= _transitionToSpeed * GetFrameTime();
}

void Menu::TransitionFromMenu()
{
	if (_transitionAlpha > 1.f)
	{
		_phaseState = GamePhaseState::Ended;
		return;
	}

	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, _transitionAlpha));
	_transitionAlpha += _transitionFromSpeed * GetFrameTime();
}

void Menu::LoopMenu()
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), DARKGRAY);
	DrawText("Test", 200, 200, 20, WHITE);

	if (_phaseState != GamePhaseState::Ending)
	{
		if (Core::IsInteractPressed())
		{
			_phaseState = GamePhaseState::Ending;
		}
	}
}
