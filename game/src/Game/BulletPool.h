#pragma once

#include "raylib.h"

#include<vector>

class Bullet;

class BulletPool
{
public:
	BulletPool();
	~BulletPool();

	void Update();
	void ActivateBullet(Vector2 position, Vector2 direction);
	void ExtendPool(int extendBy);
	std::vector<Bullet*> GetActiveBullets();

private:
	std::vector<Bullet*> _bullets;
};