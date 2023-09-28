#include "GamePhase.h"

GamePhase::GamePhase()
{

}

void GamePhase::Start()
{
	_phaseState = GamePhaseState::Starting;
}

void GamePhase::End()
{
	_phaseState = GamePhaseState::Ending;
}
