#pragma once

#include "raylib.h"

class Flapperjack
{
public:
	Flapperjack();
	~Flapperjack();

	void Update();

private:
	Vector2 _position;
	float _innerRadius = 12.f;
	float _outerRadius = 18.f;
	float _startangle = 0.f;
	float _endAngle = 360.f;
	int _segments = 0;
};