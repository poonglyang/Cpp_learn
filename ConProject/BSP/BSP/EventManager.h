#include "WellEvent.h"
#include "StatuesEvent.h"
#pragma once
class EventManager
{
private:
	WellEvent wellEvent;
	StatuesEvent statuesEvent;

public:
	EventManager();

	void EventStart(playHelper::EventEnum eventNum);
};

