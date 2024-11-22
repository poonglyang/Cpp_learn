#include <iostream>
#include "ItemData.h"
#include "Item_Equipable.h"
//#include "Item_Consumables.h"
#include "Item_Material.h"

using namespace std;
using namespace itemDatas;


int main() {
	Item_Equipable* equipItem1 = new Item_Equipable(
		1, "초보자용 나무검", 10, (int)itemDatas::ItemType::Equipable, 
		"검에 막 입문한 초보자가 쓰기 좋은 나무검",
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,
		20, 0, 5, 1, 5, 0, 0, 5, 0, 0, 0);

	equipItem1->PrintItemInfo();

	Item_Equipable* equipItem2 = new Item_Equipable(
		2, "정체 모를 아이템", 99999999,(int)itemDatas::ItemType::Equipable,
		"신화시대 때 만들어졌을  추측되는 목걸이\n\t부조리하다고 생각될 정도로 많은 능력치를 올린다",
		(int)itemDatas::EquipSlot::Necklace,
		10000, 10000, 999, 999, 999, 999, 999, 999, 999, 999, 999);

	equipItem2->PrintItemInfo();

	delete equipItem1;
	equipItem1 = nullptr;

	delete equipItem2;
	equipItem2 = nullptr;

	Item_Material* misc1 = new Item_Material(
		3, "깃털", 1, 10, 3, (int)itemDatas::ItemType::Materials, "깃털(잡탬)");

	misc1->PrintItemInfo();

	delete misc1;
	misc1 = nullptr;



	/* 나중에 인벤토리 클래스에서 추가할 방식
	vector<ItemBase> inventory;
	ItemBase* equipItem = dynamic_cast<ItemBase*>(equipItem1);
	inventory.push_back(*equipItem);
	*/
}