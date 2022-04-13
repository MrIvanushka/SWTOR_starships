#include "Port.h"

void Port::spawn(StarFighter* toRespawn)
{
	toRespawn->setPosition(this->position);
	toRespawn->setAlive(true);
}

void Port::setPosition(Vector3 n_coord)
{
	this->position = n_coord;
}

void Port::setAlive(bool alive)
{
	this->alive = alive;
}

bool Port::getAlive()
{
	return this->alive;
}
