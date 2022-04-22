#include "Port.h"

void Port::spawn(StarFighter* toRespawn)
{
	toRespawn->setPosition(this->position);
}

