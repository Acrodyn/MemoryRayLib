#pragma once

#include "System/SystemGlobals.h"

class GamePhase
{
public:
	GamePhase();

	virtual void Start();
	virtual void Update() = 0;

	bool IsEnded();

protected:
	GamePhaseState _phaseState = GamePhaseState::Unset;
};