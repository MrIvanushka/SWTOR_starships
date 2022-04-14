#include "Spawner.h"

void Spawner::update(float dt)
{

	this->estimatedTime += dt;

	//Check ability for spawn
	if (!this->respawnQueue.empty()) {
		if (this->estimatedTime >= this->respawnTime) {

			//Spawn first object from respawn queue
			spawn(this->respawnQueue.front(), getPortNum());

			//Delete first object from respawn queue
			respawnQueue.pop();
			this->estimatedTime = 0;
		}
		//Protection from spawning 
		else 
		{
			this->estimatedTime = 0;
		}
	}
};

void Spawner::spawn(StarFighter* toRespawn, int portNumber)
{
	this->ports[portNumber]->spawn(toRespawn);
}

void Spawner::destroyPort(Port* toDelete)
{
	auto numToDelete = find(this->ports.begin(), this->ports.end(), toDelete);
	auto index = std::distance(this->ports.begin(), numToDelete);
	delete this->ports[index];
}

void Spawner::addDestroyedShip(StarFighter* toDestroy)
{
	this->respawnQueue.push(toDestroy);
	this->aliveQueue->destroyShip(toDestroy);
}

int Spawner::getPortNum()
{
	int portNum = std::rand() % this->ports.size();
	return portNum;
}