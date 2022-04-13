//Saves coordinates in which new ships spawns
//spawnMethod - spawns new ship at this Port coordinates

#pragma once
#include "StarFighter.h"
#include "Transformable.h"
#include "Damageable.h"
class Port :public Transformable, protected Damageable
{
public:
	Port() {}
	Port(Vector3 coord) {
		this->position = coord;
	}
	~Port() {}

	//Spawn method
	void spawn(StarFighter * toRespawn);
};

