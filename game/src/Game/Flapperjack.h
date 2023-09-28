#pragma once

#include "raylib.h"

class Flapperjack
{
public:
	Flapperjack();

	void Update();

private:
	Vector2 _flapPosition;
	float _innerRadius = 12.f;
	float _outerRadius = 18.f;
	float _startangle = 0.f;
	float _endAngle = 360.f;
	float _segments = 0.f;

	Rectangle _primaryGunRect;
	Vector2 _primaryGunPivot;
	float _primaryGunWidth = 5.f;
	float _primaryGunHeight = 30.f;

	float _rotation = 0.f;
	float _rotationSpeed = 100.f;
};