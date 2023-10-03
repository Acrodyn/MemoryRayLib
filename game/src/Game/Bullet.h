#pragma once

#include "raylib.h"

class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Activate(Vector2 position, Vector2 direction);
	void Delete();
	bool IsActive();
	Vector2 GetPosition();
	float GetSize();

private:
	bool IsOutOfBoundaries();

private:
	Vector2 _direction;
	Vector2 _position;
	float _speed = 300.f;
	float _radius = 5.f;
	bool _isActive = false;
};