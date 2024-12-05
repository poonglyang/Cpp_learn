#include "ShopEvent.h"

void ShopEvent::EventStart(Player* player)
{

}

ShopEvent::ShopEvent()
{
	itemManager = ItemManager();
	shopInventory = Inventory(10, 10, 1, itemManager);

	int equipmentSaleCount = Mathf::Random::Range(0, 4);
	int consumableSaleCount = Mathf::Random::Range(0, 4);

	for (int i = 0; i < equipmentSaleCount; i++) {
		ItemBase* tempItem = itemManager.GetEquipableItemByIndex(Mathf::Random::Range(0, itemManager.GetEquipVectorSize()));
		shopInventory.equipable.push_back(tempItem);
	}

	for (int i = 0; i < consumableSaleCount; i++) {
		ItemBase* tempItem = itemManager.GetConsumableItemByIndex(Mathf::Random::Range(0, itemManager.GetConsumableVectorSize()), 1+rand() % 5);
		shopInventory.consumables.push_back(tempItem);
	}
}

void ShopEvent::EventUpdate()
{
}

void ShopEvent::EventEnd()
{
}

void ShopEvent::RenderEvent()
{
}
