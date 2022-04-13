#pragma once
class Damageable
{
protected:
	void takeDamage(float damage);
	void die();
	bool isAlive();
	float hp;
	bool alive;
};

