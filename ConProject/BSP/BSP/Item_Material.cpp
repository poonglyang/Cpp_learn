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
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;

	std::cout << "\t" << name << std::endl << std::endl;

	std::cout << "\t" << explain << std::endl << std::endl;

	std::cout << "\t" << "수량 : " << count << std::endl;
	std::cout << "\t" << "가격 : " << price << "골드" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;

}
