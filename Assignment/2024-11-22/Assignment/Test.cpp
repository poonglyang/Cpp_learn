#include <iostream>
#include "ItemManager.h"
#include "Inventory.h"
#include "Player.h"
#include "Item_Equipable.h"
#include "Item_Consumables.h"
#include "Item_Material.h"

using namespace std;
using namespace itemDatas;


int main() {
	ItemManager itemManager = ItemManager();
	/*

	Inventory* playerInventory = new Inventory(30, 3, 3, itemManager);

	Item_Equipable tempItem = itemManager.GetEquipableItem(1);

	playerInventory->PushItem(&tempItem);

	playerInventory->PrintEquipableInventory();

	Item_Equipable* temp2 = dynamic_cast<Item_Equipable*>(playerInventory->PopItem(0));
	cout << "꺼낸 장비 아이템 " << endl;
	temp2->PrintItemInfo();
	playerInventory->PrintEquipableInventory();

	int a = playerInventory->PushItem(100001, 100);
	cout << "들어가고 남은 아이템 갯수 : " << a << endl;
	playerInventory->PrintConsumableInventory();


	playerInventory->PopItem(100001, 18);
	playerInventory->PrintConsumableInventory();

	delete playerInventory;
	playerInventory = nullptr;*/

	Player player = Player(100, 100, 50, 50, 10, 20, 1.2f, 0, 10, 0.8f, 0.2f, 0.3f, 5, itemManager);

	player.PrintPlayerInfo();

	Item_Equipable tempItem = itemManager.GetEquipableItem(1);

	player.inventory->PushItem(&tempItem);
	player.inventory->PrintEquipableInventory();

	player.EquipSelect(0);
	player.PrintPlayerInfo();
	player.PrintEquip();
}