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
	float _innerRadius = 12.f;
	float _outerRadius = 18.f;
	float _startangle = 0.f;
	float _endAngle = 360.f;
	int _segments = 0;

	std::unordered_map<GunSlots, Gun*> _guns;
};