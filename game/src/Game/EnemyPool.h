#pragma once

#include "raylib.h"

#include<vector>

class Enemy;

class EnemyPool
{
public:
	EnemyPool();
	~EnemyPool();

	void Update();
	void ActivateEnemy(Vector2 position, Vector2 direction);
	void ExtendPool(int extendBy);
	std::vector<Enemy*> GetActiveEnemies();

private:
	std::vector<Enemy*> _enemies;
};