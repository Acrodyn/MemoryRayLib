#pragma once

#include "System/GamePhase.h"
#include <unordered_map>

class Flapperjack;
class Gun;
class BulletPool;

enum class GunSlots {
	Primary,
	Back,
	Left,
	Right
};

class Game : public GamePhase
{
public:
	Game();
	~Game();

protected:
	void InitPhase() override;
	void DestroyPhase() override;
	void LoopPhase() override;

private:
	Flapperjack* _flapperjack = nullptr;
	BulletPool* _bulletPool = nullptr;
	std::unordered_map<GunSlots, Gun*> _guns;
	
	float _shootingWaitTime = 0.2f;
	float _currentShootingWaitTime = 0.f;
};