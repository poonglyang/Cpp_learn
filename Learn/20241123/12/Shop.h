#pragma once
#include <iostream>
#include <vector>
#include "Item.h"
class Shop
{
private:
	std::vector<Item> items;

public:
	Shop();
	~Shop();

	void SetItems();

	void DisplayItems(GameEnums::ItemType tpye) const;

	Item* BuyItem(GameEnums::ItemType type, const int index, int& gold);

	void AddItem(const Item& item);

};

