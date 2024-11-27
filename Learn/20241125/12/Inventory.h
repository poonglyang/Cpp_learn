#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Item.h"

class Inventory
{
private:
	std::vector<Item> items;
	Item equipArom;
	Item equipWeapon;
public:
	Inventory();
	~Inventory();

	void ShowInventory() const;

	void AddItem(const Item& item);

	Item SellItem(const int index, int& gold);

	void EquipItem(const int index);

	Item GetEquippedArmor() const;

	void SetEquippedArmor(const Item& armor);

	Item GetEquippedWeapon() const;

	void SetEquippedWeapon(const Item& weapon);

};

