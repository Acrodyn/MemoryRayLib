#include "GamePhase.h"

GamePhase::GamePhase()
{

}

void GamePhase::Start()
{
	_phaseState = GamePhaseState::Starting;
}

bool GamePhase::IsEnded()
{
	return _phaseState == GamePhaseState::Ended;
}
