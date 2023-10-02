#pragma once

#include "raylib.h"

class Gun
{
public:
	Gun();
	virtual ~Gun();

	virtual void Shoot() = 0;
	virtual void Update();
	virtual Vector2 GetShootPoint();
	virtual Vector2 GetShootDirection();

private:
	void RotateTowardMouse();

protected:
	Vector2 _position;
	float _angle = 0.f;

private:
	const float ROTATION_SENSITIVITY = 5.f;
	Vector2 _lastMousePosition;
	float _rotationSpeed = 9.f;
};