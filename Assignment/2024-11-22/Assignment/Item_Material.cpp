#include "Item_Material.h"

Item_Material::Item_Material(int id, const string& name, int count, int maxCount, int price, int itemType, const string& explain)
	: ItemBase(id, name, count, maxCount, price, itemType, explain)
{

}

void Item_Material::PrintItemInfo()
{
	cout << "\t" << GetItemName() << endl << endl;

	cout << "\t" << GetItemExplain() << endl << endl;

	cout << "\t" << "���� : " << GetItemCount() << endl;
	cout << "\t" << "���� : " << GetPrice() << "���" << endl;
}
