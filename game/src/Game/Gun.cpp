#include "Gun.h"
#include "System/Core.h"
#include <math.h>
#include <raymath.h>
#include <iostream>

Gun::Gun()
{
	_position = Core::GetScreenCenter();
	_lastMousePosition = GetMousePosition();
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
	Vector2 currentMousePosition = GetMousePosition();
	float mouseDeltaX = fmax(_lastMousePosition.x, currentMousePosition.x) - fmin(_lastMousePosition.x, currentMousePosition.x);
	float mouseDeltaY = fmax(_lastMousePosition.y, currentMousePosition.y) - fmin(_lastMousePosition.y, currentMousePosition.y);

	if (mouseDeltaX > ROTATION_SENSITIVITY || mouseDeltaY > ROTATION_SENSITIVITY)
	{
		float deltaX = currentMousePosition.x - _lastMousePosition.x;
		float deltaY = currentMousePosition.y - _lastMousePosition.y;

		_lastMousePosition = currentMousePosition;

		float from = _angle * DEG2RAD;
		float to = atan2(deltaY, deltaX);

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

}
