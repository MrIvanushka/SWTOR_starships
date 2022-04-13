#include "Queue.h"

void Queue::setMaxAmount(int maxAmount)
{
	this->maxAmount = maxAmount;
}

void Queue::setPortAmount(int portAmount)
{
	this->portAmount = portAmount;
}

void Queue::setRespawnTime(float respawnTime)
{
	this->respawnTime = respawnTime;
}

void Queue::update(float dt)
{

	//Check if any ships are dead
	for (int i = 0; i < aliveQueue.size(); i++)
	{
		if (aliveQueue[i]->getAlive() == false)
		{
			respawnQueue.push(aliveQueue[i]);
			aliveQueue.erase(aliveQueue.begin() + i);
		}
	}
	//Check if any ports are dead
	for (int i = 0; i < ports.size(); i++)
	{
		if (ports[i].getAlive() == false)
		{
			ports.erase(ports.begin() + i);
			this->portAmount = ports.size();
		}
	}

	this->estimatedTime += dt;

	//Check ability for spawn
	if (this->estimatedTime >= this->respawnTime && !this->respawnQueue.empty()) {

		//Spawn first object from respawn queue
		spawn(this->respawnQueue.front(), getPortNum());

		//Delete first object from respawn queue
		aliveQueue.push_back(respawnQueue.front());
		respawnQueue.pop();
		this->estimatedTime = 0;
	}

};

void Queue::spawn(StarFighter* toRespawn, int portNumber)
{
	this->ports[portNumber].spawn(toRespawn);
}

int Queue::getPortNum()
{
	int portNum = std::rand() % this->ports.size();
	return portNum;
}