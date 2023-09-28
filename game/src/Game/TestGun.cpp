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

	// TODO: This should update on an event, NOT every frame
	_position = Core::GetScreenCenter();
	_primaryGunRect.x = _position.x;
	_primaryGunRect.y = _position.y;

	DrawRectanglePro(_primaryGunRect, _primaryGunPivot, _angle, Fade(LIGHTGRAY, 0.5f));
}
