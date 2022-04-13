#pragma once
#include "StarFighter.h"
#include <queue>
#include "Port.h"

class Queue
{
public:

	//Constructors
	Queue() {
		this->maxAmount = 0;
		this->portAmount = 0;
		this->respawnTime = 0.f;
		this->estimatedTime = 0.f;
	}

	Queue(int maxAmount, int portAmount, float respawnTime) {

		this->maxAmount = maxAmount;
		this->portAmount = portAmount;
		this->respawnTime = respawnTime;
		this->estimatedTime = 0;
		StarFighter* p = nullptr;
		for (int i = 0; i < portAmount; i++) ports.push_back(Port());
		for (int i = 0; i < maxAmount; i++) {
			p = new StarFighter();
			aliveQueue.push_back(p);
			spawn(p, getPortNum());
		}
	}

	~Queue()
	{
		for (int i = 0; i < aliveQueue.size(); i++) delete aliveQueue[i];
		if (!respawnQueue.empty())	for (int i = 0; i < respawnQueue.size(); i++) delete respawnQueue.front();
		aliveQueue.clear();
		ports.clear();
	}

	//setMethods
	void setMaxAmount(int maxAmount);
	void setPortAmount(int portAmount);
	void setRespawnTime(float respawnTime);

	//Update method
	void update(float dt);

	//Spawn method
	void spawn(StarFighter* toRespawn, int portNumber);

protected:

	int getPortNum();

	//Queue of ships waiting for respawn
	std::queue <StarFighter*> respawnQueue;

	//Queue of ships in the air
	std::vector <StarFighter*> aliveQueue;

	//Alive ports
	std::vector <Port> ports;


	int maxAmount;
	int portAmount;

	//Time in which new ship spawns
	float respawnTime;

	//Time estimated since last spawn
	float estimatedTime;

};

