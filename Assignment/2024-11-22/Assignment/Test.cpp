#include <iostream>
#include "ItemData.h"
#include "Item_Equipable.h"
//#include "Item_Consumables.h"
#include "Item_Material.h"

using namespace std;
using namespace itemDatas;


int main() {
	Item_Equipable* equipItem1 = new Item_Equipable(
		1, "�ʺ��ڿ� ������", 10, (int)itemDatas::ItemType::Equipable, 
		"�˿� �� �Թ��� �ʺ��ڰ� ���� ���� ������",
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,
		20, 0, 5, 1, 5, 0, 0, 5, 0, 0, 0);

	equipItem1->PrintItemInfo();

	Item_Equipable* equipItem2 = new Item_Equipable(
		2, "��ü �� ������", 99999999,(int)itemDatas::ItemType::Equipable,
		"��ȭ�ô� �� ���������  �����Ǵ� �����\n\t�������ϴٰ� ������ ������ ���� �ɷ�ġ�� �ø���",
		(int)itemDatas::EquipSlot::Necklace,
		10000, 10000, 999, 999, 999, 999, 999, 999, 999, 999, 999);

	equipItem2->PrintItemInfo();

	delete equipItem1;
	equipItem1 = nullptr;

	delete equipItem2;
	equipItem2 = nullptr;

	Item_Material* misc1 = new Item_Material(
		3, "����", 1, 10, 3, (int)itemDatas::ItemType::Materials, "����(����)");

	misc1->PrintItemInfo();

	delete misc1;
	misc1 = nullptr;



	/* ���߿� �κ��丮 Ŭ�������� �߰��� ���
	vector<ItemBase> inventory;
	ItemBase* equipItem = dynamic_cast<ItemBase*>(equipItem1);
	inventory.push_back(*equipItem);
	*/
}