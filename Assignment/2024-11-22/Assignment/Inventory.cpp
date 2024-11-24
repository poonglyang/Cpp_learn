#include "Inventory.h"

int Inventory::GetItemTypeById(int id)
{
	if (id < 100000) {
		return (int)itemDatas::ItemType::Equipable;
	}
	else if (id < 200000) {
		return (int)itemDatas::ItemType::Consumables;
	}
	else if (id < 300000) {
		return (int)itemDatas::ItemType::Materials;
	}
	else {
		cout << "[Error : �̵� ���̵� �� ������� �߱淹 �����Ѱž�]" << endl;
		return 0; 
	}
}

Inventory::Inventory(int equipable_MaxInventoryCapacity, int consumables_MaxInventoryCapacity, int materials_MaxInventoryCapacity, ItemManager& itemManager)
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
			if (item->GetItemId() == id) {
				count += item->GetItemCount();
			}
		}
	}
	else if (id < 200000) {
		for (auto& item : consumables) {
			if (item->GetItemId() == id) {
				count += item->GetItemCount();
			}
		}
	}
	else if (id < 300000) {
		for (auto& item : materials) {
			if (item->GetItemId() == id) {
				count += item->GetItemCount();
			}
		}
	}
	else {
		cout << "� �������� ����̴ϱ�???" << endl;
	}
	return count;
}

bool Inventory::PushItem(ItemBase* weaponItme)
{
	if (equipable.size() + 1 > equipable_MaxInventoryCapacity) {
		return false;
	}
	else {
		//ItemBase* tempItem =  weaponItme;
		equipable.push_back(weaponItme);
		return true;
	}
}

template<typename T>
int Inventory::AddItemAndReturnRemaining(int id, int count, vector<T> inventory)
{
	for (auto findItem : inventory) {
		if (findItem->GetItemId() == id) {
			// ���� ������ �������� �ִٸ�
			count = findItem->SetItemCount(count, true);
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
		if (consumables.size() + 1 > consumables_MaxInventoryCapacity) {
			// ������ ���� ��
			count = AddItemAndReturnRemaining(id, count, consumables);

			return count;
		}
		else {
			// �κ��丮�� ���� ������ ������
			count = AddItemAndReturnRemaining(id, count, consumables);

			if (count > 0) {
				// ������ �ִ� �Ϳ� �� �ְ� ������ ���Ҵٸ�
				int idItemMaxCount = itemManager.GetItemMaxCountById(id);
				if (count > idItemMaxCount) {
					// ���� ���� �������� �ִ� ��ø �������� ���ٸ�
					count -= idItemMaxCount;
					

					Item_Consumables* tempItme = itemManager.GetConsumableItem(id, idItemMaxCount);

					consumables.push_back(tempItme);	// �ִ� ��ø ������ŭ �ְ�
					count = PushItem(id, count);	// PushItem �ٽ��ϱ�
				}
				else {
					// ���� ���� �ִ� ��ø �������� ���ٸ�
					Item_Consumables* tempItme = itemManager.GetConsumableItem(id, count);

					consumables.push_back(tempItme);	// �׳� �ְ� ��

				}
			}
			return count;
		}
		break;

	case (int)itemDatas::ItemType::Materials :
		if (materials.size() + 1 > materials_MaxInventoryCapacity) {
			// ������ ���� ��
			count = AddItemAndReturnRemaining(id, count, materials);

			return count;
		}
		else {
			// �κ��丮�� ���� ������ ������
			count = AddItemAndReturnRemaining(id, count, materials);

			if (count > 0) {
				// ������ �ִ� �Ϳ� �� �ְ� ������ ���Ҵٸ�
				int idItemMaxCount = itemManager.GetItemMaxCountById(id);
				if (count > idItemMaxCount) {
					// ���� ���� �������� �ִ� ��ø �������� ���ٸ�
					count -= idItemMaxCount;
					ItemBase* a = itemManager.GetMaterialItem(id, idItemMaxCount);
					materials.push_back(a);	// �ִ� ��ø ������ŭ �ְ�
					count = PushItem(id, count);	// PushItem �ٽ��ϱ�
				}
				else {
					// ���� ���� �ִ� ��ø �������� ���ٸ�
					ItemBase* a = itemManager.GetMaterialItem(id, count);
					materials.push_back(a);	// �׳� �ְ� �����°���~
				}

			}
			return count;
		}
		break;
	default:
		cout << "���� ��ü�� �ȵȴٰ� ����" << endl;
		return 0;
		break;
	}

}

ItemBase* Inventory::PopItem(int index)
{
	// �߸��� �ε������� �˻縦 ���߿� �־�����
	ItemBase* returnItem = equipable[index];
	equipable.erase(equipable.begin() + index);
	return returnItem;
}

void Inventory::PopItem(int id, int count)
{
	int index = 0;
	switch (GetItemTypeById(id))
	{
	case (int)itemDatas::ItemType::Consumables:
		for (auto& item : consumables) {
			if (item->GetItemId() == id) {
				// id�� ����
				if (item->GetItemCount() <= count) {
					// �������� ������ count���� ���� ��
					count -= item->GetItemCount();	// count���� �������� ������ ����
					consumables.erase(consumables.begin() + index);	// ����
				}
				else {
					// ������ ������ ���� �ͺ��� �� ���ٴ� �ǹ��̹Ƿ�
					item->SetItemCount(-count, true);	// count�� �ٲ���
				}
			}

			index++;
		}
		break;

	case (int)itemDatas::ItemType::Materials:
		for (auto& item : materials) {
			if (item->GetItemId() == id) {
				// id�� ����
				if (item->GetItemCount() < count) {
					// �������� ������ count���� ���� ��
					count -= item->GetItemMaxCount();	// count���� �������� ������ ����
					materials.erase(materials.begin() + index);	// ����
				}
				else {
					// ������ ������ ���� �ͺ��� �� ���ٴ� �ǹ��̹Ƿ�
					item->SetItemCount(-count, true);	// count�� �ٲ���
				}
			}

			index++;
		}
		break;
	default:
		cout << "���� ��ü�� �ȵȴٰ� ����" << endl;
		break;
	}
}

void Inventory::PrintEquipableInventory()
{
	cout << "��� �κ��丮" << endl;
	for (ItemBase* item : equipable) {
		Item_Equipable* tempItem = dynamic_cast<Item_Equipable*>(item);
		if (tempItem == nullptr) {
			cout << "[Error : ��� �κ��丮�� ��� �ƴ� �������� ������]" << endl;
		}
		else {
			tempItem->PrintItemInfo();
		}

		/*Item_Equipable* temp = (Item_Equipable*)item;
		temp->PrintItemInfo();*/
	}
}

void Inventory::PrintConsumableInventory()
{
	cout << "�Һ� �κ��丮" << endl;
	for (ItemBase* item : consumables) {
		Item_Consumables* tempItem = dynamic_cast<Item_Consumables*>(item);
		if (tempItem == nullptr) {
			cout << "[Error : ��� �κ��丮�� �Һ� �������� �ƴ� �������� ������]" << endl;
		}
		else {
			tempItem->PrintItemInfo();
		}

	}
}

void Inventory::PrintMaterialInventory()
{
	cout << "��� �κ��丮" << endl;
	for (ItemBase* item : materials) {
		Item_Consumables* tempItem = dynamic_cast<Item_Consumables*>(item);
		if (tempItem == nullptr) {
			cout << "[Error : ��� �κ��丮�� ��� �ƴ� �������� ������]" << endl;
		}
		else {
			tempItem->PrintItemInfo();
		}

		/*Item_Equipable* temp = (Item_Equipable*)item;
		temp->PrintItemInfo();*/
	}
}


