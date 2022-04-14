#pragma once
#include "StarFighter.h"
class Army
{
public:

	Army() {}
	Army(int maxAmount) 
	{
		StarFighter* p = nullptr;
		for (int i = 0; i < maxAmount; i++) {
			p = new StarFighter();
			aliveQueue.push_back(p);
		}
	}

	~Army()
	{
		for (int i = 0; i < aliveQueue.size(); i++) delete aliveQueue[i];
		aliveQueue.clear();
	}

	void destroyShip(StarFighter* toDestroy);

	void reviveShip(StarFighter* toRevive);

protected:
	//Queue of ships in the air
	std::vector <StarFighter*> aliveQueue;
};

