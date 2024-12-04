#include "Item_Material.h"

Item_Material::Item_Material(int id, const std::string& name, int count, int maxCount, int price, int itemType, const std::string& explain)
	: ItemBase(id, name, count, maxCount, price, itemType, explain)
{

}

Item_Material::Item_Material(const Item_Material& other)
	:ItemBase(other.id, other.name, other.count, other.maxCount, other.price, other.itemType, other.explain)
{

}

void Item_Material::PrintItemInfo()
{
	std::cout << "������������������������������������" << std::endl;

	std::cout << "\t" << name << std::endl << std::endl;

	std::cout << "\t" << explain << std::endl << std::endl;

	std::cout << "\t" << "���� : " << count << std::endl;
	std::cout << "\t" << "���� : " << price << "���" << std::endl;
	std::cout << "������������������������������������" << std::endl;

}
