#pragma once
#include "ItemBase.h"
class Item_Material : public ItemBase
{
public :
	Item_Material(int id, const string& name, int count, int maxCount, int price, int itemType, const string& explain);

	void PrintItemInfo() override;
};

