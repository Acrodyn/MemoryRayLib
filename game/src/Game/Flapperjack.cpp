#include "Flapperjack.h"
#include "TestGun.h"
#include "System/Core.h"

Flapperjack::Flapperjack()
{
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
	// TODO: Position needs to be cached and updated on an event, NOT every frame
	DrawRing(Core::GetScreenCenter(), _innerRadius, _outerRadius, _startangle, _endAngle, _segments, Fade(LIGHTGRAY, 0.5f));
	DrawCircleV(Core::GetScreenCenter(), 5.f, Fade(GREEN, 0.8f));

	UpdateGuns();
}

void Flapperjack::UpdateGuns()
{
	for (auto& gun : _guns)
	{
		gun.second->Update();
	}
}
