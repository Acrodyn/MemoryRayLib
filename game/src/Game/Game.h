#pragma once

#include "System/GamePhase.h"

class Flapperjack;

class Game : public GamePhase
{
public:
	Game();

protected:
	void InitPhase() override;
	void DestroyPhase() override;
	void LoopPhase() override;

private:
	Flapperjack* _flapperjack = nullptr;
};