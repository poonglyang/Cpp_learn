#include "EventManager.h"

EventManager::EventManager(int chestSize)
{
	wellEvent = WellEvent();
	statuesEvent = StatuesEvent();
	devilStatuesEvent = DevilStatuesEvent();
	shopEvent = ShopEvent();
}

void EventManager::EventStart(playHelper::EventEnum eventNum, Player* player)
{
	switch (eventNum)
	{
	case playHelper::EventEnum::SHOP_EVENT: {
		shopEvent.EventStart(player);
		break;
	}
	case playHelper::EventEnum::WELL_EVENT: {
		wellEvent.EventStart(player);
		break;
	}
	case playHelper::EventEnum::ANGEL_STATUES_EVENT: {
		statuesEvent.EventStart(player);
		break;
	}
	case playHelper::EventEnum::DEVIL_STATUES_EVENT: {
		devilStatuesEvent.EventStart(player);
		break;
	case playHelper::EventEnum::BOX_EVENT: {
		ChestEvent chestEvent = ChestEvent();
		chestEvent.EventStart(player);
		break;
		}
	case playHelper::EventEnum::MONSTER_EVENT: {
		BattleEvent battleEvent = BattleEvent();
		battleEvent.EventStart(player);
		break;
		}
	}
	default: {
		break;
	}
	}
}
