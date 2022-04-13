#include "Army.h"

void Army::destroyShip(StarFighter* toDestroy)
{
	auto numToDelete = find(this->aliveQueue.begin(), this->aliveQueue.end(), toDestroy);
	auto index = std::distance(this->aliveQueue.begin(), numToDelete);
	delete this->aliveQueue[index];
}

void Army::reviveShip(StarFighter* toRevive)
{
	this->aliveQueue.push_back(toRevive);
}
