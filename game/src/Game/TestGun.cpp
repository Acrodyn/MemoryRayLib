#include "TestGun.h"
#include "System/Core.h"

TestGun::TestGun()
{
	_position = Core::GetScreenCenter();

	_primaryGunRect = { _position.x, _position.y, _primaryGunWidth, _primaryGunHeight };
	_primaryGunPivot = { _primaryGunRect.width / 2.f - 25.f, _primaryGunRect.height / 2.f };
}

void TestGun::Shoot()
{

}

void TestGun::Update()
{
	Gun::Update();

	//_rotation += _rotationSpeed * GetFrameTime();
	DrawRectanglePro(_primaryGunRect, _primaryGunPivot, _angle - 90.f, Fade(LIGHTGRAY, 0.5f));
}
