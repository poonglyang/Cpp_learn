#include <iostream>
#include "WellEvent.h"
#include "StatuesEvent.h"
#include "DevilStatuesEvent.h"
#include "ChestEvent.h"
#include "ShopEvent.h"
#include "BattleEvent.h"

#pragma once
class EventManager
{
private:
	WellEvent wellEvent;
	StatuesEvent statuesEvent;
	DevilStatuesEvent devilStatuesEvent;
	ShopEvent shopEvent;

public:
	EventManager(int chestSize);

	void EventStart(playHelper::EventEnum eventNum, Player* player);

	EventManager() {};
};

