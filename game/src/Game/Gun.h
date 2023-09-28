#pragma once

class Gun
{
public:
	Gun();
	virtual ~Gun();

	virtual void Shoot() = 0;
	virtual void Update() = 0;
};