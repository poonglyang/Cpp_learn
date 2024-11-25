#pragma once
#include <string>
#include "GameEnum.h"
class Item
{

private:
	GameEnums::ItemType type;
	std::string name;
	std::string description;
	int attribute;
	int price;
	int count;


public:
	Item();

	Item(GameEnums::ItemType type, const std::string& name, 
		const std::string& description, int attribute,
		int price, int count);

	std::string GetName() const;

	std::string GetDescription() const;

	GameEnums::ItemType GetType() const;

	int GetAttribute() const;

	int GetPrice() const;

	int GetCount() const;

	void SetCount(int count);
};

