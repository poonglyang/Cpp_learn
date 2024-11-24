#include "Item_Consumables.h"

Item_Consumables::Item_Consumables(int id, const string& name, int count, int maxCount, int price, int itemType, const string& explain)
	: ItemBase(id, name, count, maxCount, price, (int)itemDatas::ItemType::Consumables, explain)
{
	toCopy = 0;
}

Item_Consumables::Item_Consumables(const Item_Consumables& other)
	: ItemBase(other)
{
	toCopy = other.toCopy;
}

void Item_Consumables::OnUse()
{
	
}

void Item_Consumables::PrintItemInfo()
{
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	cout << "\t" << name << endl << endl;

	cout << "\t" << explain << endl << endl;

	cout << "\t" << "수량 : " << count << endl;
	cout << "\t" << "가격 : " << price << "골드" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
}
