#pragma once

#include "System/GamePhase.h"

class Game : public GamePhase
{
public:
	Game();

	virtual void Start() override;
	virtual void Update() override;
};