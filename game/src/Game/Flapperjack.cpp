#include "Flapperjack.h"
#include "TestGun.h"
#include "System/Core.h"

Flapperjack::Flapperjack()
{
	_flapPosition = Core::GetScreenCenter();
	_guns[GunSlots::Primary] = new TestGun();
}

Flapperjack::~Flapperjack()
{
	for (auto& gun : _guns)
	{
		delete gun.second;
	}
}

void Flapperjack::Update()
{
	DrawRing(_flapPosition, _innerRadius, _outerRadius, _startangle, _endAngle, _segments, Fade(LIGHTGRAY, 0.5f));
	DrawCircleV(_flapPosition, 5.f, GREEN);

	UpdateGuns();
}

void Flapperjack::UpdateGuns()
{
	for (auto& gun : _guns)
	{
		gun.second->Update();
	}
}
