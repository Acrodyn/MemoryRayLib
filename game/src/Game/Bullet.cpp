#include "Bullet.h"
#include "System/Core.h"
#include "raymath.h"

Bullet::Bullet()
{
	_direction = {};
	_position = {};
}

Bullet::~Bullet()
{
	
}

void Bullet::Update()
{
	if (!_isActive)
	{
		return;
	}

	DrawCircleV(_position, _radius, Fade(GREEN, 0.8f));
	_position = Vector2Lerp(_position, Vector2Add(_position, _direction), _speed * GetFrameTime());

	if (IsOutOfBoundaries())
	{
		Delete();
	}
}

void Bullet::Activate(Vector2 position, Vector2 direction)
{
	_position = position;
	_direction = direction;
	_isActive = true;
}

void Bullet::Delete()
{
	_isActive = false;
}

bool Bullet::IsActive()
{
	return _isActive;
}

bool Bullet::IsOutOfBoundaries()
{
	int display = GetCurrentMonitor();

	return _position.x + _radius < 0.f
		|| _position.x - _radius > GetMonitorWidth(display)
		|| _position.y + _radius < 0.f
		|| _position.y - _radius > GetMonitorHeight(display);
}
