#include "Item_Material.h"

Item_Material::Item_Material(int id, const string& name, int count, int maxCount, int price, int itemType, const string& explain)
	: ItemBase(id, name, count, maxCount, price, itemType, explain)
{

}

void Item_Material::PrintItemInfo()
{
	cout << "������������������������������������" << endl;

	cout << "\t" << name << endl << endl;

	cout << "\t" << explain << endl << endl;

	cout << "\t" << "���� : " << count << endl;
	cout << "\t" << "���� : " << price << "���" << endl;
	cout << "������������������������������������" << endl;

}
