#pragma once

#include "System/GamePhase.h"

class Menu : public GamePhase
{
public:
	Menu();

	virtual void Start() override;
	virtual void Update() override;

private:
	void TransitionToMenu();
	void TransitionFromMenu();
	void LoopMenu();

private:
	float _transitionAlpha = 0.f;
	float _transitionToSpeed = 1.f;
	float _transitionFromSpeed = 2.f;
};