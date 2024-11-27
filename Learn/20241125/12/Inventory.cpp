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
		std::cout << "�κ��丮�� �������" << std::endl;
	}
	else {
		std::cout << "======[�κ��丮]======" << std::endl;
		for (int i = 0; i < items.size(); ++i) {
			std::cout << i + 1 << ", " << items[i].GetName()
				<< " - " << items[i].GetPrice() << "���" << std::endl;
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
		std::cout << "����" << std::endl;
		return Item();
	}

	Item& soldItem = items[index - 1];

	int price = soldItem.GetPrice();
	gold += price;

	items.erase(items.begin() + (index - 1));

	std::cout << soldItem.GetName() << "��(��) �Ǹ��� " << price << "�� �����" << std::endl;
	
	return soldItem;
}

void Inventory::EquipItem(const int index)
{
	// ����
	Item& item = items[index];

	switch (item.GetType())
	{
	case GameEnums::ItemType::ITEM_EMPTY:
		break;
	case GameEnums::ItemType::ITEM_ARMOR:
		equipArom = item;
		std::cout << item.GetName() << " ���� ������" << std::endl;
		break;
	case GameEnums::ItemType::ITEM_WEAPON:
		equipWeapon = item;
		std::cout << item.GetName() << " ���⸦ ������" << std::endl;
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
	std::cout << "������ �������� �κ��丮���� ������" << std::endl;

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
