#include "TestGun.h"
#include "System/Core.h"

TestGun::TestGun()
{
	Vector2 screenCenter = Core::GetScreenCenter();

	_primaryGunRect = { screenCenter.x, screenCenter.y, _primaryGunWidth, _primaryGunHeight };
	_primaryGunPivot = { _primaryGunRect.width / 2.f - 25.f, _primaryGunRect.height / 2.f };
}

void TestGun::Shoot()
{

}

void TestGun::Update()
{
	_rotation += _rotationSpeed * GetFrameTime();
	DrawRectanglePro(_primaryGunRect, _primaryGunPivot, _rotation, Fade(LIGHTGRAY, 0.5f));
}
