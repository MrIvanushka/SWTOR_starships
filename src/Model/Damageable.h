#pragma once
class Damageable
{
public:
	void takeDamage(float damage);
	bool isAlive();
private:
	void die();
	float hp;
	bool alive;
};

