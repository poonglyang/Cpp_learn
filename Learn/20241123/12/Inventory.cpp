#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::ShowInventory() const
{
	if (items.empty()) {
		std::cout << "인벤토리가 비어있음" << std::endl;
	}
	else {
		std::cout << "======[인벤토리]======" << std::endl;
		for (int i = 0; i < items.size(); ++i) {
			std::cout << i + 1 << ", " << items[i].GetName()
				<< " - " << items[i].GetPrice() << "골드" << std::endl;
		}
		std::cout << "=====================" << std::endl;
	}
}

void Inventory::AddItem(const Item& item)
{
	items.push_back(item);
}

Item Inventory::SellItem(const int index, int& gold)
{
	if (items.empty()) {
		std::cout << "없음" << std::endl;
		return Item();
	}

	Item& soldItem = items[index - 1];

	int price = soldItem.GetPrice();
	gold += price;

	items.erase(items.begin() + (index - 1));

	std::cout << soldItem.GetName() << "을(를) 판매해 " << price << "을 얻었다" << std::endl;
	
	return soldItem;
}

void Inventory::EquipItem(const int index)
{
	// 선택
	Item& item = items[index];

	switch (item.GetType())
	{
	case GameEnums::ItemType::ITEM_EMPTY:
		break;
	case GameEnums::ItemType::ITEM_ARMOR:
		equipArom = item;
		std::cout << item.GetName() << " 방어구를 장착함" << std::endl;
		break;
	case GameEnums::ItemType::ITEM_WEAPON:
		equipWeapon = item;
		std::cout << item.GetName() << " 무기를 장착함" << std::endl;
		break;
	case GameEnums::ItemType::ITEM_RING:
		break;
	case GameEnums::ItemType::ITEM_POTION:
		break;
	case GameEnums::ItemType::ITEM_SOLDOUT:
		break;
	default:
		break;
	}

	items.erase(items.begin() + (index - 1));
	std::cout << "장착된 아이템이 인벤토리에서 삭제됨" << std::endl;

	ShowInventory();

}

Item Inventory::GetEquippedArmor() const
{
	return equipArom;
}

void Inventory::SetEquippedArmor(const Item& armor)
{
}

Item Inventory::GetEquippedWeapon() const
{
	return equipWeapon;
}

void Inventory::SetEquippedWeapon(const Item& weapon)
{
}
