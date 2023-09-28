#pragma once

#include "System/SystemGlobals.h"

class GamePhase
{
public:
	GamePhase();

	void Start();
	void Update();

	bool IsEnded();

protected:
	void TransitionTo();
	void TransitionFrom();
	virtual void LoopPhase() = 0;

protected:
	GamePhaseState _phaseState = GamePhaseState::Unset;
	float _transitionAlpha = 0.f;
	float _transitionToSpeed = 1.f;
	float _transitionFromSpeed = 2.f;
};