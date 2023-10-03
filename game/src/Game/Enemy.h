#pragma once

#include "raylib.h"

class Enemy
{
public:
	Enemy();

	void Update();
	void Activate(Vector2 position, Vector2 goal);
	void Delete();
	bool IsActive();
	Vector2 GetPosition();
	float GetSize();
	void ReportHit();

private:
	CLITERAL(Color) GetColor();

private:
	Vector2 _direction;
	Vector2 _position;
	float _speed = 50.f;
	float _radius = 35.f;

	int _maxHP = 2;
	int _currentHP = 0;

	bool _isActive = false;
};