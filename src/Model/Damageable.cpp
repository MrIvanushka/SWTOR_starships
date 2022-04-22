#include "Damageable.h"

void Damageable::takeDamage(float damage)
{
	this->hp -= damage;
	if (this->hp < 0) {
		die();
	}
}

void Damageable::die()
{
}

bool Damageable::isAlive()
{
	return this->alive;
}
