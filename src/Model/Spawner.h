#pragma once
#include "StarFighter.h"
#include <queue>
#include "Port.h"
#include "Army.h"
#include <algorithm>
#include <iostream>
class Spawner
{
public:

	//Constructors
	Spawner() {
		this->maxAmount = 0;
		this->portAmount = 0;
		this->respawnTime = 0.f;
		this->estimatedTime = 0.f;
		this->aliveQueue = nullptr;
	}

	Spawner(int maxAmount, int portAmount, float respawnTime) {

		this->maxAmount = maxAmount;
		this->portAmount = portAmount;
		this->respawnTime = respawnTime;
		this->estimatedTime = 0;
		Port* p = nullptr;

		for (int i = 0; i < portAmount; i++)
		{
			p = new Port();
			ports.push_back(p);
		}

		this->aliveQueue = new Army(maxAmount);
	}

	~Spawner()
	{
		if (!respawnQueue.empty())	for (int i = 0; i < respawnQueue.size(); i++) delete respawnQueue.front();
		ports.clear();
		delete this->aliveQueue;
	}

	//Update method
	void update(float dt);

	//Spawn method
	void spawn(StarFighter* toRespawn, int portNumber);

	void destroyPort(Port* toDelete);

	void destroyShip(StarFighter* toDestroy);

protected:

	int getPortNum();

	//Queue of ships waiting for respawn
	std::queue <StarFighter*> respawnQueue;

	//Alive ports
	std::vector <Port*> ports;

	int maxAmount;
	int portAmount;
	Army* aliveQueue;

	//Time in which new ship spawns
	float respawnTime;

	//Time estimated since last spawn
	float estimatedTime;

};

