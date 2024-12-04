#pragma once
#include "ItemBase.h"
class Item_Material : public ItemBase
{
public :
	Item_Material(int id, const std::string& name, int count, int maxCount, int price, int itemType, const std::string& explain);

	Item_Material(const Item_Material& other);

	void PrintItemInfo() override;
};

