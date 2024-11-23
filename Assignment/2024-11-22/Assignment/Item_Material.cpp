#include "Item_Material.h"

Item_Material::Item_Material(int id, const string& name, int count, int maxCount, int price, int itemType, const string& explain)
	: ItemBase(id, name, count, maxCount, price, itemType, explain)
{

}

void Item_Material::PrintItemInfo()
{
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	cout << "\t" << name << endl << endl;

	cout << "\t" << explain << endl << endl;

	cout << "\t" << "수량 : " << count << endl;
	cout << "\t" << "가격 : " << price << "골드" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

}
