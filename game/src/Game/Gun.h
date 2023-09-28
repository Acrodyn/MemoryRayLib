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

private:
	const float ROTATION_SENSITIVITY = 1.f;
	Vector2 _lastMousePosition;
	float _rotationSpeed = 25.f;
};