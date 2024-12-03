#include "EventManager.h"

EventManager::EventManager()
{
	wellEvent = WellEvent();
	statuesEvent = StatuesEvent();
}

void EventManager::EventStart(playHelper::EventEnum eventNum)
{
	switch (eventNum)
	{
	case playHelper::EventEnum::SHOP_EVENT: {
		break;
	}
	case playHelper::EventEnum::WELL_EVENT: {
		wellEvent.EventStart();
		break;
	}
	case playHelper::EventEnum::STATUES_EVENT: {
		statuesEvent.EventStart();
		break;
	}
	case playHelper::EventEnum::BOX_EVENT: {
		break;
	}
	case playHelper::EventEnum::MONSTER_EVENT: {
		break;
	}
	default: {
		break;
	}
	}
}
