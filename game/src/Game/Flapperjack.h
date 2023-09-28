#pragma once

#include "raylib.h"

#include <unordered_map>

class Gun;

enum class GunSlots {
	Primary,
	Back,
	Left,
	Right
};

class Flapperjack
{
public:
	Flapperjack();
	~Flapperjack();

	void Update();

private:
	void UpdateGuns();

private:
	Vector2 _flapPosition;
	float _innerRadius = 12.f;
	float _outerRadius = 18.f;
	float _startangle = 0.f;
	float _endAngle = 360.f;
	float _segments = 0.f;

	std::unordered_map<GunSlots, Gun*> _guns;
};