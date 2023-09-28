#pragma once

#include "raylib.h"

class Gun
{
public:
	Gun();
	virtual ~Gun();

	virtual void Shoot() = 0;
	virtual void Update();

private:
	void RotateTowardMouse();

protected:
	Vector2 _position;
	float _angle = 0.f;
	float _rotationSpeed = 35.f;
};