#include "Gun.h"
#include <math.h>
#include <raymath.h>
#include <iostream>

Gun::Gun()
{
	_position = { 0.f ,0.f };
}

Gun::~Gun()
{
}

void Gun::Update()
{
	// TODO: Refactor so this is done only once for all guns
	RotateTowardMouse();
}

void Gun::RotateTowardMouse()
{
	Vector2 mousePosition = GetMousePosition();
	float deltaX = _position.x - mousePosition.x;
	float deltaY = _position.y - mousePosition.y;

	float from = _angle * DEG2RAD;
	float to = atan2(-deltaX, deltaY);

	if (FloatEquals(from, to))
	{
		return;
	}

	float fromMod = std::signbit(from) ? PI * 2 + std::fmod(from, PI * 2) : std::fmod(from, PI * 2);
	float toMod = std::signbit(to) ? PI * 2 + std::fmod(to, PI * 2) : std::fmod(to, PI * 2);

	float rotation = toMod - fromMod;
	float rotationDiff = rotation;

	if (rotation > PI)
	{
		rotationDiff = rotation - 2 * PI;
	}
	else if (rotation < -PI)
	{
		rotationDiff = 2 * PI + rotation;
	}

	_angle = Lerp(_angle, _angle + rotationDiff * RAD2DEG, _rotationSpeed * GetFrameTime());
}
