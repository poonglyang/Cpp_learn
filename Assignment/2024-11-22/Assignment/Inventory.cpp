#include "Inventory.h"

Inventory::Inventory()
{
	equipable_CurrentInventoryCount = 0;
	consumables_CurrentInventoryCount = 0;
	materials_CurrentInventoryCount = 0;
	equipable_MaxInventoryCapacity = 0;
	consumables_MaxInventoryCapacity = 0;
	materials_MaxInventoryCapacity = 0;
}

bool Inventory::PushItem(ItemBase& item)
{
	switch (item.GetItemType())
	{
	case (int)itemDatas::ItemType::Equipable :
		if (++equipable_CurrentInventoryCount > equipable_MaxInventoryCapacity) {

		}
		else {

		}
		break;

	case (int)itemDatas::ItemType::Consumables :

		break;

	case (int)itemDatas::ItemType::Materials :

		break;
	default:
		break;
	}

}
