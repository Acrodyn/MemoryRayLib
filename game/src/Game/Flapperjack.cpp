#include "Flapperjack.h"
#include "System/Core.h"

Flapperjack::Flapperjack()
{
	_position = Core::GetScreenCenter();
}

Flapperjack::~Flapperjack()
{
	
}

void Flapperjack::Update()
{
	DrawRing(_position, _innerRadius, _outerRadius, _startangle, _endAngle, _segments, Fade(LIGHTGRAY, 0.5f));
	DrawCircleV(_position, 5.f, Fade(GREEN, 0.8f));
}
