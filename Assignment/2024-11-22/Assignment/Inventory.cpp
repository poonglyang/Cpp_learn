#include "Inventory.h"

int Inventory::GetItemTypeById(int id)
{
	if (id < 100000) {
		return (int)itemDatas::ItemType::Equipable;
	}
	else if (id < 200000) {
		return (int)itemDatas::ItemType::Equipable;
	}
	else if (id < 300000) {
		return (int)itemDatas::ItemType::Equipable;
	}
	else {
		cout << "[Error : �̵� ���̵� �� ������� �߱淹 �����Ѱž�]" << endl;
		return 0; 
	}
}

Inventory::Inventory(int equipable_MaxInventoryCapacity, int consumables_MaxInventoryCapacity, int materials_MaxInventoryCapacity, ItemManager itemManager)
	: equipable_MaxInventoryCapacity(equipable_MaxInventoryCapacity),
	consumables_MaxInventoryCapacity(consumables_MaxInventoryCapacity),
	materials_MaxInventoryCapacity(materials_MaxInventoryCapacity),
	itemManager(itemManager)
{
	equipable_CurrentInventoryCount = 0;
	consumables_CurrentInventoryCount = 0;
	materials_CurrentInventoryCount = 0;
}

int Inventory::CountItem(int id)
{
	int count = 0;

	if (id < 100000) {
		// id�� 10�� �̸��� ���� �ݵ�� �ִٰ� �����ؾ���
		for (auto& item : equipable) {
			if (item.GetItemId() == id) {
				count += item.GetItemCount();
			}
		}
	}
	else if (id < 200000) {
		for (auto& item : consumables) {
			if (item.GetItemId() == id) {
				count += item.GetItemCount();
			}
		}
	}
	else if (id < 300000) {
		for (auto& item : materials) {
			if (item.GetItemId() == id) {
				count += item.GetItemCount();
			}
		}
	}
	else {
		cout << "� �������� ����̴ϱ�???" << endl;
	}
	return count;
}

bool Inventory::PushItem(ItemBase& weaponItme)
{
	if (++equipable_CurrentInventoryCount > equipable_MaxInventoryCapacity) {
		return false;
	}
	else {
		equipable.push_back(weaponItme);
		return true;
	}
}

template<typename T>
int Inventory::AddItemAndReturnRemaining(int id, int count, vector<T> inventory)
{
	for (auto& findItem : inventory) {
		if (findItem.GetItemId() == id) {
			// ���� ������ �������� �ִٸ�
			count = findItem.SetItemCount(count, true);
		}

		if (count == 0) {
			// �� �־����� for�� ����
			break;
		}
	}

	return count;
}

int Inventory::PushItem(int id, int count)
{
	switch (GetItemTypeById(id))
	{
	case (int)itemDatas::ItemType::Consumables :
		if (++consumables_CurrentInventoryCount > consumables_MaxInventoryCapacity) {
			// ������ ���� ��
			count = AddItemAndReturnRemaining(id, count, consumables);

			return count;
		}
		else {
			count = AddItemAndReturnRemaining(id, count, consumables);

			if (count > 0) {
				ItemBase a = itemManager.GetItem<Item_Consumables>(id, count);
				consumables.push_back(a);
			}
			return 0;
		}
		break;

	case (int)itemDatas::ItemType::Materials :
		if (++materials_CurrentInventoryCount > materials_MaxInventoryCapacity) {
			return false;
		}
		else {
			count = AddItemAndReturnRemaining(id, count, materials);

			if (count > 0) {
				ItemBase a = itemManager.GetItem<Item_Material>(id, count);
				consumables.push_back(a);
			}
			return 0;
		}
		break;
	default:
		cout << "���� ��ü�� �ȵȴٰ� ����" << endl;
		return 0;
		break;
	}

}

ItemBase Inventory::PopItem(int id, int count)
{
	if (id < 100000) {
		// id�� 10�� ������ ���� �ݵ�� �ִٰ� �����ؾ���
		for (auto& itemId : equipable) {			
			if (itemId.GetItemId() == id) {
				itemId.SetItemCount(-count, true);
			}
		}
	}
	else if (id < 200000) {

	}
	else if (id < 300000) {

	}
	else {
		cout << "� �������� ����̴ϱ�???";
	}

	return ItemBase();
}
