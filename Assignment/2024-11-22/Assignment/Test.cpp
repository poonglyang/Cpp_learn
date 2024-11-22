#include <iostream>
#include "ItemData.h"
#include "Item_Equipable.h"
//#include "Item_Consumables.h"
//#include "Item_Material.h"

using namespace std;
using namespace itemDatas;


int main() {
	vector<ItemBase> inventory;
	

	Item_Equipable* equipItem1 = new Item_Equipable(
		1, "�ʺ��ڿ� ������", (int)itemDatas::ItemType::Equipable, 
		(int)itemDatas::EquipSlot::Weapon_Right,
		20, 0, 5, 1, 5, 0, 0, 5, 0, 0, 0);
	equipItem1->PrintItemInfo();

	Item_Equipable* equipItem2 = new Item_Equipable(
		2, "��ü �� ������", (int)itemDatas::ItemType::Equipable,
		(int)itemDatas::EquipSlot::Necklace,
		10000, 10000, 999, 999, 999, 999, 999, 999, 999, 999, 999);

	equipItem2->PrintItemInfo();

	ItemBase* equipItem = dynamic_cast<ItemBase*>(equipItem1);

	inventory.push_back(*equipItem);

	//delete equipItem1; equipItem1 = nullptr;
	
	delete equipItem1;
	equipItem1 = nullptr;

	//delete equipItem2;
	//equipItem2 = nullptr;
}