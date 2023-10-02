#pragma once

#include "Gun.h"

class TestGun : public Gun
{
public:
	TestGun();

	void Shoot() override;
	void Update() override;
	Vector2 GetShootPoint() override;

private:
	Rectangle _rect;
	Vector2 _pivot;
	float _width = 5.f;
	float _height = 30.f;
};