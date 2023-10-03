#include "Enemy.h"
#include "System/Core.h"
#include "raylib.h"
#include "raymath.h"

#define GET_COLOR(A, B) STAGE_ ## A ## _ ## B

#define STAGE_1_RED CLITERAL(Color){ 125, 0, 0, 255 }
#define STAGE_2_RED CLITERAL(Color){ 111, 0, 0, 255 }
#define STAGE_3_RED CLITERAL(Color){ 97, 0, 0, 255 }
#define STAGE_4_RED CLITERAL(Color){ 83, 0, 0, 255 }
#define STAGE_5_RED CLITERAL(Color){ 70, 0, 0, 255 }

Enemy::Enemy()
{
	_direction = {};
	_position = {};
}

void Enemy::Update()
{
	if (!_isActive)
	{
		return;
	}

	DrawCircleV(_position, _radius, Fade(GetColor(), 0.8f));
	_position = Vector2Lerp(_position, Vector2Add(_position, _direction), _speed * GetFrameTime());
}

void Enemy::Activate(Vector2 position, Vector2 goal)
{
	_position = position;
	_direction = Vector2Normalize(Vector2Subtract(goal, position));
	_isActive = true;
	_currentHP = _maxHP;
}

void Enemy::Delete()
{
	_isActive = false;
}

bool Enemy::IsActive()
{
	return _isActive;
}

Vector2 Enemy::GetPosition()
{
	return _position;
}

float Enemy::GetSize()
{
	return _radius;
}

void Enemy::ReportHit()
{
	if (--_currentHP <= 0)
	{ 
		_isActive = false;
	}
}

CLITERAL(Color) Enemy::GetColor()
{
	switch (_currentHP)
	{
	case 5: 
		return GET_COLOR(5, RED);
	case 4:
		return GET_COLOR(4, RED);
	case 3:
		return GET_COLOR(3, RED);
	case 2:
		return GET_COLOR(2, RED);
	case 1:
		return GET_COLOR(1, RED);
	}
	
}
