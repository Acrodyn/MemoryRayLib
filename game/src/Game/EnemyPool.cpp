#include "EnemyPool.h"
#include "Enemy.h"
#include "System/Core.h"
#include "raymath.h"

EnemyPool::EnemyPool()
{
	ExtendPool(50);
}

EnemyPool::~EnemyPool()
{
	
}

void EnemyPool::Update()
{
	for (auto& enemy : _enemies)
	{
		enemy->Update();
	}
}

void EnemyPool::ActivateEnemy(Vector2 position)
{
	for (auto& enemy : _enemies)
	{
		if (!enemy->IsActive())
		{
			enemy->Activate(position, Core::GetScreenCenter());
			return;
		}
	}

	ExtendPool(50);
	ActivateEnemy(position);
}

void EnemyPool::ExtendPool(int extendBy)
{
	for (int i = 0; i < extendBy; ++i)
	{
		_enemies.push_back(new Enemy());
	}
}

std::vector<Enemy*> EnemyPool::GetActiveEnemies()
{
	std::vector<Enemy*> activeEnemies;

	for (auto& enemy : _enemies)
	{
		if (enemy->IsActive())
		{
			activeEnemies.push_back(enemy);
		}
	}


	return activeEnemies;
}
