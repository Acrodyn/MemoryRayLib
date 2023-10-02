#include "Game.h"
#include "raylib.h"
#include "Flapperjack.h"
#include "TestGun.h"
#include "BulletPool.h"
#include "System/Core.h"

Game::Game()
{
	_guns[GunSlots::Primary] = new TestGun();
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

	_currentShootingWaitTime -= GetFrameTime();

	_bulletPool->Update();
}
