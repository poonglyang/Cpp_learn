#include "EventManager.h"

EventManager::EventManager(int chestSize)
{
	wellEvent = WellEvent();
	statuesEvent = StatuesEvent();
	devilStatuesEvent = DevilStatuesEvent();
}

void EventManager::EventStart(playHelper::EventEnum eventNum, Player* player)
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
	case playHelper::EventEnum::ANGEL_STATUES_EVENT: {
		statuesEvent.EventStart();
		break;
	}
	case playHelper::EventEnum::DEVIL_STATUES_EVENT: {
		devilStatuesEvent.EventStart();
		break;
	case playHelper::EventEnum::BOX_EVENT: {
		ChestEvent chestEvent = ChestEvent();
		chestEvent.EventStart();
		break;
		}
	case playHelper::EventEnum::MONSTER_EVENT: {
		break;
		}
	}
	default: {
		break;
	}
	}
}
