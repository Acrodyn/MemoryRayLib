#include "BulletPool.h"
#include "Bullet.h"
#include "System/Core.h"
#include "raymath.h"

BulletPool::BulletPool()
{
	ExtendPool(50);
}

BulletPool::~BulletPool()
{
	
}

void BulletPool::Update()
{
	for (auto& bullet : _bullets)
	{
		bullet->Update();
	}
}

void BulletPool::ActivateBullet(Vector2 position, Vector2 direction)
{
	for (auto& bullet : _bullets)
	{
		if (!bullet->IsActive())
		{
			bullet->Activate(position, direction);
			return;
		}
	}

	ExtendPool(50);
	ActivateBullet(position, direction);
}

void BulletPool::ExtendPool(int extendBy)
{
	for (int i = 0; i < extendBy; ++i)
	{
		_bullets.push_back(new Bullet());
	}
}

std::vector<Bullet*> BulletPool::GetActiveBullets()
{
	std::vector<Bullet*> activeBullets;

	for (auto& buller : _bullets)
	{
		if (buller->IsActive())
		{
			activeBullets.push_back(buller);
		}
	}

	return activeBullets;
}
