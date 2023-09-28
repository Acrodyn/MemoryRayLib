#pragma once

#include "System/SystemGlobals.h"

class GamePhase
{
public:
	GamePhase();

	virtual void Start();
	virtual void End();
	virtual void Update() = 0;

protected:
	GamePhaseState _phaseState = GamePhaseState::Unset;
};