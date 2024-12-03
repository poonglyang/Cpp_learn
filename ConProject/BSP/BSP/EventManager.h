#include <iostream>
#include "WellEvent.h"
#include "StatuesEvent.h"
#include "DevilStatuesEvent.h"
#pragma once
class EventManager
{
private:
	WellEvent wellEvent;
	StatuesEvent statuesEvent;
	DevilStatuesEvent devilStatuesEvent;

public:
	EventManager();

	void EventStart(playHelper::EventEnum eventNum);
};

