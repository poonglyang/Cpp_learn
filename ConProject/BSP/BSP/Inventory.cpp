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
		std::cout << "[Error : �̵� ���̵� �� ������� �߱淹 �����Ѱž�]" << std::endl;
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
	money = 0;
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
		std::cout << "� �������� ����̴ϱ�???" << std::endl;
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
int Inventory::AddItemAndReturnRemaining(int id, int count, std::vector<T> inventory)
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
					count = 0;
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
					Item_Material* a = itemManager.GetMaterialItem(id, idItemMaxCount);
					materials.push_back(a);	// �ִ� ��ø ������ŭ �ְ�
					count = PushItem(id, count);	// PushItem �ٽ��ϱ�
				}
				else {
					// ���� ���� �ִ� ��ø �������� ���ٸ�
					Item_Material* a = itemManager.GetMaterialItem(id, count);
					materials.push_back(a);	// �׳� �ְ� �����°���~
				}

			}
			return count;
		}
		break;
	default:
		std::cout << "���� ��ü�� �ȵȴٰ�" << std::endl;
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
	int k = 0;
	switch (GetItemTypeById(id))
	{
	case (int)itemDatas::ItemType::Consumables:
		
		for (int i = 0; i < consumables.size() - k; i++) {
			if (consumables.empty()) {
				break;
			}

			if (consumables[i]->GetItemId() == id) {
				// id�� ����
				if (consumables[i]->GetItemCount() <= count) {
					// �������� ������ count���� ���� ��
					count -= consumables[i]->GetItemCount();	// count���� �������� ������ ����
					delete consumables[i];
					consumables[i] = nullptr;
					consumables.erase(consumables.begin() + i);	// ����
					++k;
					--i;
				}
				else {
					// ������ ������ ���� �ͺ��� �� ���ٴ� �ǹ��̹Ƿ�
					consumables[i]->SetItemCount(-count, true);	// count�� �ٲ���
					count -= count;
				}
			}
		}

		//for (auto& item : consumables) {
		//	if (item->GetItemId() == id) {
		//		// id�� ����
		//		if (item->GetItemCount() <= count) {
		//			// �������� ������ count���� ���� ��
		//			count -= item->GetItemCount();	// count���� �������� ������ ����
		//			delete consumables[index];
		//			consumables[index] = nullptr;
		//			consumables.erase(consumables.begin() + index);	// ����
		//			--index;
		//		}
		//		else {
		//			// ������ ������ ���� �ͺ��� �� ���ٴ� �ǹ��̹Ƿ�
		//			item->SetItemCount(-count, true);	// count�� �ٲ���
		//			count -= count;
		//		}
		//	}

		//	index++;
		//}
		break;

	case (int)itemDatas::ItemType::Materials:

		for (int i = 0; i < materials.size() - k; i++) {
			if (materials.empty()) {
				break;
			}
			if (materials[i]->GetItemId() == id) {
				// id�� ����
				if (materials[i]->GetItemCount() <= count) {
					// �������� ������ count���� ���� ��
					count -= materials[i]->GetItemCount();		
					delete materials[i];
					materials[i] = nullptr;
					materials.erase(materials.begin() + i);	// ����
					++k;
					--i;
				}
				else {
					// ������ ������ ���� �ͺ��� �� ���ٴ� �ǹ��̹Ƿ�
					materials[i]->SetItemCount(-count, true);	
					count -= count;
				}
			}
		}

		//for (auto& item : materials) {
		//	if (item->GetItemId() == id) {
		//		// id�� ����
		//		if (item->GetItemCount() < count) {
		//			// �������� ������ count���� ���� ��
		//			count -= item->GetItemMaxCount();	// count���� �������� ������ ����
		//			delete materials[index];
		//			materials[index] = nullptr;
		//			materials.erase(materials.begin() + index);	// ����
		//			--index;
		//		}
		//		else {
		//			// ������ ������ ���� �ͺ��� �� ���ٴ� �ǹ��̹Ƿ�
		//			item->SetItemCount(-count, true);	// count�� �ٲ���
		//			count -= count;
		//		}
		//	}

		//	index++;
		//}
		break;
	default:
		std::cout << "���� ��ü�� �ȵȴٰ�" << std::endl;
		break;
	}
}

bool Inventory::isEquipableFull()
{
	return equipable.size() < equipable_MaxInventoryCapacity ? false : true;
}

bool Inventory::isCanDequip()
{
	return equipable.size() + 1 <= equipable_MaxInventoryCapacity ? true : false;;
}

bool Inventory::isConsumablesFull()
{
	return consumables.size() < consumables_MaxInventoryCapacity ? false : true;
}

bool Inventory::isMaterialFull()
{
	return materials.size() < materials_MaxInventoryCapacity ? false : true;
}

int Inventory::GetMoney()
{
	return money;
}

void Inventory::SetMoney(int delta, bool isAdd)
{
	if (isAdd) {
		money += delta;
	}
	else {
		money = delta;
	}
}

int Inventory::GetEquipableInventorySize()
{
	return equipable.size();
}

int Inventory::GetConsumableInventorySize()
{
	return consumables.size();
}

int Inventory::GetMaterialInventorySize()
{
	return materials.size();
}

int Inventory::GetEquipableInventoryItemIdByIndex(int index)
{
	return equipable[index]->GetItemId();
}

int Inventory::GetEquipableInventoryItemPriceByIndex(int index)
{
	return equipable[index]->GetPrice();
}

int Inventory::GetConsumableInventoryItemIdByIndex(int index)
{
	return consumables[index]->GetItemId();
}

int Inventory::GetConsumableInventoryItemPriceByIndex(int index)
{
	return consumables[index]->GetPrice();
}

int Inventory::GetMaterialsInventoryItemIdByIndex(int index)
{
	return materials[index]->GetItemId();
}

int Inventory::GetMaterialsInventoryItemPriceByIndex(int index)
{
	return materials[index]->GetPrice();
}

void Inventory::PrintEquipableInventory()
{
	std::cout << "��� �κ��丮" << std::endl;
	int count = 0;
	for (ItemBase* item : equipable) {
		Item_Equipable* tempItem = dynamic_cast<Item_Equipable*>(item);
		if (tempItem == nullptr) {
			std::cout << "[Error : ��� �κ��丮�� ��� �ƴ� �������� ������]" << std::endl;
		}
		else {
			std::cout << count << ".\t";
			tempItem->PrintItemInfo();
		}
		count ++;
		/*Item_Equipable* temp = (Item_Equipable*)item;
		temp->PrintItemInfo();*/
	}
}

void Inventory::PrintConsumableInventory()
{
	int count = 0;
	for (ItemBase* item : consumables) {
		Item_Consumables* tempItem = dynamic_cast<Item_Consumables*>(item);
		if (tempItem == nullptr) {
			std::cout << "[Error : ��� �κ��丮�� �Һ� �������� �ƴ� �������� ������]" << std::endl;
		}
		else {
			std::cout << "["<<count << "]" << std::endl;
			tempItem->PrintItemInfo();
		}
		count ++;
	}
}

void Inventory::PrintMaterialInventory()
{
	std::cout << "��� �κ��丮" << std::endl;
	int count = 0;
	for (ItemBase* item : materials) {
		Item_Material* tempItem = dynamic_cast<Item_Material*>(item);
		if (tempItem == nullptr) {
			std::cout << "[Error : ��� �κ��丮�� ��� �ƴ� �������� ������]" << std::endl;
		}
		else {
			std::cout << "[" << count << "]" << std::endl;
			tempItem->PrintItemInfo();
		}
		count++;
	}
}


