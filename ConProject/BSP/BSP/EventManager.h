#include <iostream>
#include "WellEvent.h"
#include "StatuesEvent.h"
#include "DevilStatuesEvent.h"
#include "ChestEvent.h"

#pragma once
class EventManager
{
private:
	WellEvent wellEvent;
	StatuesEvent statuesEvent;
	DevilStatuesEvent devilStatuesEvent;

public:
	EventManager(int chestSize);

	void EventStart(playHelper::EventEnum eventNum, Player* player);

	EventManager() {};
};

