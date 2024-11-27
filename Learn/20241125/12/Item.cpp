#include "Item.h"

Item::Item()
{
}

Item::Item(GameEnums::ItemType type, const std::string& name, const std::string& description, int attribute, int price, int count)
	: type(type), name(name), description(description), attribute(attribute), price(price), count(count)
{
}

std::string Item::GetName() const
{
	return name;
}

std::string Item::GetDescription() const
{
	return description;
}

GameEnums::ItemType Item::GetType() const
{
	return type;
}

int Item::GetAttribute() const
{
	return attribute;
}

int Item::GetPrice() const
{
	return price;
}

int Item::GetCount() const
{
	return count;
}

void Item::SetCount(int count)
{

}
