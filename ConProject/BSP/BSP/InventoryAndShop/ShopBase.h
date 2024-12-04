#pragma once
#include "Inventory.h"
#include "ItemManager.h"

using namespace itemDatas;

class ShopBase
{
protected:
	Inventory* shopInventory;

	std::string name;

	int sellItemType;

public:
	ShopBase(const std::string& name, int sellItemType, ItemManager& itemManager);

	void Buy(Inventory*& buyerInventory);

	void Sell(Inventory*& sellerInventroy);

	void PrintSellItem(Inventory*& sellerInventroy);
	
};

