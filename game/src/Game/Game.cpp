#include "Game.h"
#include "raylib.h"
#include "Flapperjack.h"
#include "TestGun.h"
#include "BulletPool.h"
#include "EnemyPool.h"
#include "Enemy.h"
#include "Bullet.h"
#include "System/Core.h"

#include <algorithm>
#include <random>
#include <chrono>

Game::Game()
{
	_guns[GunSlots::Primary] = new TestGun();

	_lastSpawnPoint = {};

	// UP LEFT
	_spawnBlocks.push_back(std::make_pair(Vector2({ 0.f, -_spawnPadding }), Vector2({ Core::GetDisplayWidth() / 2.f, -_spawnPadding })));	
	// UP RIGHT
	_spawnBlocks.push_back(std::make_pair(Vector2({ Core::GetDisplayWidth() / 2.f, -_spawnPadding }), Vector2({ (float)Core::GetDisplayWidth(), -_spawnPadding })));
	// LEFT UP
	_spawnBlocks.push_back(std::make_pair(Vector2({ -_spawnPadding , 0.f }), Vector2({ -_spawnPadding , Core::GetDisplayHeight() / 2.f})));
	// LEFT DOWN
	_spawnBlocks.push_back(std::make_pair(Vector2({ -_spawnPadding, Core::GetDisplayHeight() / 2.f }), Vector2({ -_spawnPadding, (float)Core::GetDisplayHeight() })));
	// RIGHT UP
	_spawnBlocks.push_back(std::make_pair(Vector2({ Core::GetDisplayWidth() + _spawnPadding, 0.f }), Vector2({ Core::GetDisplayWidth() + _spawnPadding, Core::GetDisplayHeight() / 2.f })));
	// RIGHT DOWN
	_spawnBlocks.push_back(std::make_pair(Vector2({ Core::GetDisplayWidth() + _spawnPadding, Core::GetDisplayHeight() / 2.f }), Vector2({ Core::GetDisplayWidth() + _spawnPadding, (float)Core::GetDisplayHeight() })));
	// DOWN LEFT
	_spawnBlocks.push_back(std::make_pair(Vector2({ 0.f, Core::GetDisplayHeight() + _spawnPadding}), Vector2({ Core::GetDisplayWidth() / 2.f, Core::GetDisplayHeight() + _spawnPadding })));
	// DOWN RIGHT 
	_spawnBlocks.push_back(std::make_pair(Vector2({ Core::GetDisplayWidth() / 2.f, Core::GetDisplayHeight() + _spawnPadding }), Vector2({ (float)Core::GetDisplayWidth(), Core::GetDisplayHeight() + _spawnPadding })));
}

Game::~Game()
{
	for (auto& gun : _guns)
	{
		delete gun.second;
	}
}

void Game::InitPhase()
{
	_flapperjack = new Flapperjack();
	_bulletPool = new BulletPool();
	_enemyPool = new EnemyPool();
}

void Game::DestroyPhase()
{
	delete _flapperjack;
}

void Game::LoopPhase()
{
	DrawRectangle(0, 0, Core::GetDisplayWidth(), Core::GetDisplayHeight(), BLACK);

	_flapperjack->Update();

	for (auto& gun : _guns)
	{
		gun.second->Update();
	}

	if (Core::IsInteractDown())
	{
		if (_currentShootingWaitTime <= 0.f)
		{
			_bulletPool->ActivateBullet(_guns[GunSlots::Primary]->GetShootPoint(), _guns[GunSlots::Primary]->GetShootDirection());
			_currentShootingWaitTime = _shootingWaitTime;
		}
	}

	if (_currentEnemySpawnWaitTime <= 0.f)
	{
		_enemyPool->ActivateEnemy(GetEnemySpawnLocation());
		_currentEnemySpawnWaitTime = _enemySpawnWaitTime;
	}

	_currentShootingWaitTime -= GetFrameTime();
	_currentEnemySpawnWaitTime -= GetFrameTime();

	_bulletPool->Update();
	_enemyPool->Update();

	CheckForCollisions();
}

void Game::CheckForCollisions()
{
	std::vector<Enemy*> activeEnemies = _enemyPool->GetActiveEnemies();
	std::vector<Bullet*> activeBullets = _bulletPool->GetActiveBullets();

	for (auto& enemy : activeEnemies)
	{
		for (auto& bullet : activeBullets)
		{
			if (CheckCollisionCircles(enemy->GetPosition(), enemy->GetSize(), bullet->GetPosition(), bullet->GetSize()))
			{
				enemy->ReportHit();
				bullet->Delete();
			}
		}

		// check with flapperjack for game over
	}
}

Vector2 Game::GetEnemySpawnLocation()
{
	std::pair<Vector2, Vector2>* selectedBlock = nullptr;

	do
	{
		int randomIndex = GetRandomValue(0, _spawnBlocks.size() - 1);
		selectedBlock = &_spawnBlocks[randomIndex];
	} 
	while (&*_lastSpawnPoint == &*selectedBlock);

	_lastSpawnPoint = &(*selectedBlock);
	Vector2 spawnLocation = Vector2({ (float)GetRandomValue(_lastSpawnPoint->first.x, _lastSpawnPoint->second.x), (float)GetRandomValue(_lastSpawnPoint->first.y, _lastSpawnPoint->second.y) });

	return spawnLocation;
}
