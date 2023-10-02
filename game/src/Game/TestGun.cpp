#include "TestGun.h"
#include "System/Core.h"
#include "raymath.h"

TestGun::TestGun()
{
	_position = Core::GetScreenCenter();

    _rect = { _position.x, _position.y, _width, _height };
	_pivot = { _width / 2.f - 25.f, _height / 2.f };
}

void TestGun::Shoot()
{

}

void TestGun::Update()
{
	Gun::Update();

	DrawRectanglePro(_rect, _pivot, _angle, Fade(LIGHTGRAY, 0.5f));
}

Vector2 TestGun::GetShootPoint()
{
    Vector2 shootPointPosition;

    float sinRotation = sinf(_angle * DEG2RAD);
    float cosRotation = cosf(_angle * DEG2RAD);

    float dx = -_pivot.x;
    float dy = -_pivot.y;

    shootPointPosition.x = _rect.x + (dx + _width + 10.f) * cosRotation - (dy + _height / 2.f) * sinRotation;
    shootPointPosition.y = _rect.y + (dx + _width + 10.f) * sinRotation + (dy + _height / 2.f) * cosRotation;

	return shootPointPosition;
}
