#pragma once
#include <iostream>
#include "Inventory.h"
#include "ItemManager.h"

using namespace std;
using namespace itemDatas;

class ShopBase
{
protected:
	Inventory* shopInventory;

	string name;

	int sellItemType;

public:
	ShopBase(const string& name, int sellItemType, ItemManager& itemManager);

	void Buy(Inventory*& buyerInventory);

	void Sell(Inventory*& sellerInventroy);

	void PrintSellItem(Inventory*& sellerInventroy);
	
};

