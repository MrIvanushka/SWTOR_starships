//Saves coordinates in which new ships spawns
//spawnMethod - spawns new ship at this port coordinates

#pragma once
#include "StarFighter.h"
#include "Transformable.h"
class Port :public Transformable
{
public:
	Port() {
		this->position = Vector3(0, 0, 0);
	}
	Port(Vector3 coord) {
		this->position = coord;
	}
	~Port() {}

	//Spawn method
	void spawn(StarFighter* toRespawn);

	//setMethod
	void setPosition(Vector3 n_coord);
	void setAlive(bool alive);

	//getMethod
	bool getAlive();
protected:
	bool alive;
};

