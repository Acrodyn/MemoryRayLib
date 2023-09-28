#include "Flapperjack.h"
#include "System/Core.h"

Flapperjack::Flapperjack()
{
	_flapPosition = { (GetScreenWidth()) / 2.0f, GetScreenHeight() / 2.0f };

	_primaryGunRect = { _flapPosition.x, _flapPosition.y, _primaryGunWidth, _primaryGunHeight };
	_primaryGunPivot = { _primaryGunRect.width / 2.f - 25.f, _primaryGunRect.height / 2.f };
}

void Flapperjack::Update()
{
	DrawRing(_flapPosition, _innerRadius, _outerRadius, _startangle, _endAngle, _segments, Fade(LIGHTGRAY, 0.5f));

	DrawCircleV(_flapPosition, 5.f, GREEN);

	_rotation += _rotationSpeed * GetFrameTime();
	DrawRectanglePro(_primaryGunRect, _primaryGunPivot, _rotation, Fade(LIGHTGRAY, 0.5f));
}
