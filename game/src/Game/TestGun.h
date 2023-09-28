#pragma once

#include "Gun.h"
#include "raylib.h"

class TestGun : public Gun
{
public:
	TestGun();

	void Shoot() override;
	void Update() override;

private:
	Rectangle _primaryGunRect;
	Vector2 _primaryGunPivot;
	float _primaryGunWidth = 5.f;
	float _primaryGunHeight = 30.f;

	float _rotation = 0.f;
	float _rotationSpeed = 200.f;
};