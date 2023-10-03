#pragma once

#include "raylib.h"
#include "System/GamePhase.h"

#include <unordered_map>

class Flapperjack;
class Gun;
class BulletPool;
class EnemyPool;

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
	void CheckForCollisions();
	Vector2 GetEnemySpawnLocation();

private:
	Flapperjack* _flapperjack = nullptr;
	BulletPool* _bulletPool = nullptr;
	EnemyPool* _enemyPool = nullptr;
	std::unordered_map<GunSlots, Gun*> _guns;
	std::vector<std::pair<Vector2, Vector2>> _spawnBlocks;
	std::pair<Vector2, Vector2>* _lastSpawnPoint = nullptr;
	
	float _shootingWaitTime = 0.2f;
	float _currentShootingWaitTime = 0.f;

	float _enemySpawnWaitTime = 1.5f;
	float _currentEnemySpawnWaitTime = 0.f;
	float _spawnPadding = 30.f;
};