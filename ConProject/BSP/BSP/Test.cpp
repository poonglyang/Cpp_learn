#include <iostream>
#include "ItemManager.h"
#include "Inventory.h"
#include "Player.h"
#include "Item_Equipable.h"
#include "Item_Consumables.h"
#include "Item_Material.h"
#include "ShopBase.h"

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

	Player player = Player(
		100,	// hp
		100,	// maxHp
		50,		// mp
		50,		// maxMp
		10,		// atk
		20,		// 크리확률 
		1.2f,	// 크리 배율
		0,		// 방무
		10,		// 방어력
		0.8f,	// 명중률
		0.2f,	// 회피율
		0.3f,	// 방패 막기 확률
		5,		// 행동력
		itemManager);
	player.inventory->SetMoney(1000000, false);
	
	player.inventory->PushItem(100001, 30);
	Item_Equipable* tempItem = itemManager.GetEquipableItem(1);

	player.inventory->PushItem(tempItem);
	
	/*
	player.PrintPlayerInfo();

	Item_Equipable tempItem = itemManager.GetEquipableItem(1);

	player.inventory->PushItem(&tempItem);
	player.inventory->PrintEquipableInventory();

	player.EquipSelect(0);
	player.PrintPlayerInfo();
	player.PrintEquip();
	player.Dequip((int)itemDatas::EquipSlot::Weapon_Right);
	player.Dequip((int)itemDatas::EquipSlot::Weapon_Left);
	player.inventory->PrintEquipableInventory();
	player.PrintPlayerInfo();
	player.PrintEquip();
	*/

	ShopBase consumableShop = ShopBase("소모품 상점", (int)itemDatas::ItemType::Consumables, itemManager);
	consumableShop.PrintSellItem(player.inventory);
	consumableShop.Buy(player.inventory);
	player.inventory->PrintConsumableInventory();
	consumableShop.PrintSellItem(player.inventory);

	/*ShopBase materialShop = ShopBase("재료 상점", (int)itemDatas::ItemType::Materials, itemManager);
	materialShop.PrintSellItem(player.inventory);
	materialShop.Sell(player.inventory);
	player.inventory->PrintConsumableInventory();
	player.inventory->PrintEquipableInventory();
	cout << player.inventory->GetMoney() << endl;*/

}