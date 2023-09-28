#pragma once

#include "System/GamePhase.h"

class Game : public GamePhase
{
public:
	Game();

protected:
	void LoopPhase() override;
};