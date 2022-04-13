#include "Port.h"

void Port::spawn(StarFighter* toRespawn)
{
	toRespawn->setPosition(this->position);
}

bool Port::isAlive()
{
	return this->alive;
}
