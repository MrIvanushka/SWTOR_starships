#pragma once
class Damageable
{
	void takeDamage(float damage);
	bool isAlive();
protected:
	void die();
	float hp;
	bool alive;
};

