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
		cout << "[Error : 이딴 아이디를 뭔 찐빠짓을 했길레 생성한거야]" << endl;
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
		// id가 10만 미만인 것은 반드시 있다고 가정해야함
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
		cout << "어떤 아이템을 만든겁니까???" << endl;
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
			// 만약 동일한 아이템이 있다면
			count = findItem->SetItemCount(count, true);
		}

		if (count == 0) {
			// 다 넣었으면 for문 종료
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
			// 공간이 없을 때
			count = AddItemAndReturnRemaining(id, count, consumables);

			return count;
		}
		else {
			// 인벤토리에 남은 공간이 있으면
			count = AddItemAndReturnRemaining(id, count, consumables);

			if (count > 0) {
				// 기존에 있는 것에 다 넣고도 넣을게 남았다면
				int idItemMaxCount = itemManager.GetItemMaxCountById(id);
				if (count > idItemMaxCount) {
					// 넣을 것이 아이템의 최대 중첩 갯수보다 많다면
					count -= idItemMaxCount;
					

					Item_Consumables* tempItme = itemManager.GetConsumableItem(id, idItemMaxCount);

					consumables.push_back(tempItme);	// 최대 중첩 갯수만큼 넣고
					count = PushItem(id, count);	// PushItem 다시하기
				}
				else {
					// 넣을 것이 최대 중첩 갯수보다 적다면
					Item_Consumables* tempItme = itemManager.GetConsumableItem(id, count);

					consumables.push_back(tempItme);	// 그냥 넣고 끝

				}
			}
			return count;
		}
		break;

	case (int)itemDatas::ItemType::Materials :
		if (materials.size() + 1 > materials_MaxInventoryCapacity) {
			// 공간이 없을 때
			count = AddItemAndReturnRemaining(id, count, materials);

			return count;
		}
		else {
			// 인벤토리에 남은 공간이 있으면
			count = AddItemAndReturnRemaining(id, count, materials);

			if (count > 0) {
				// 기존에 있는 것에 다 넣고도 넣을게 남았다면
				int idItemMaxCount = itemManager.GetItemMaxCountById(id);
				if (count > idItemMaxCount) {
					// 넣을 것이 아이템의 최대 중첩 갯수보다 많다면
					count -= idItemMaxCount;
					ItemBase* a = itemManager.GetMaterialItem(id, idItemMaxCount);
					materials.push_back(a);	// 최대 중첩 갯수만큼 넣고
					count = PushItem(id, count);	// PushItem 다시하기
				}
				else {
					// 넣을 것이 최대 중첩 갯수보다 적다면
					ItemBase* a = itemManager.GetMaterialItem(id, count);
					materials.push_back(a);	// 그냥 넣고 끝내는거지~
				}

			}
			return count;
		}
		break;
	default:
		cout << "존재 자체가 안된다고 려차" << endl;
		return 0;
		break;
	}

}

ItemBase* Inventory::PopItem(int index)
{
	// 잘못된 인덱스인지 검사를 나중에 넣어주자
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
				// id가 같고
				if (item->GetItemCount() <= count) {
					// 아이템의 갯수가 count보다 적을 때
					count -= item->GetItemCount();	// count에서 아이템의 갯수를 빼고
					consumables.erase(consumables.begin() + index);	// 없엠
				}
				else {
					// 아이템 갯수가 없엘 것보다 더 많다는 의미이므로
					item->SetItemCount(-count, true);	// count로 바꿔줌
				}
			}

			index++;
		}
		break;

	case (int)itemDatas::ItemType::Materials:
		for (auto& item : materials) {
			if (item->GetItemId() == id) {
				// id가 같고
				if (item->GetItemCount() < count) {
					// 아이템의 갯수가 count보다 적을 때
					count -= item->GetItemMaxCount();	// count에서 아이템의 갯수를 빼고
					materials.erase(materials.begin() + index);	// 없엠
				}
				else {
					// 아이템 갯수가 없엘 것보다 더 많다는 의미이므로
					item->SetItemCount(-count, true);	// count로 바꿔줌
				}
			}

			index++;
		}
		break;
	default:
		cout << "존재 자체가 안된다고 려차" << endl;
		break;
	}
}

void Inventory::PrintEquipableInventory()
{
	cout << "장비 인벤토리" << endl;
	for (ItemBase* item : equipable) {
		Item_Equipable* tempItem = dynamic_cast<Item_Equipable*>(item);
		if (tempItem == nullptr) {
			cout << "[Error : 장비 인벤토리에 장비가 아닌 아이템이 들어가있음]" << endl;
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
	cout << "소비 인벤토리" << endl;
	for (ItemBase* item : consumables) {
		Item_Consumables* tempItem = dynamic_cast<Item_Consumables*>(item);
		if (tempItem == nullptr) {
			cout << "[Error : 장비 인벤토리에 소비 아이템이 아닌 아이템이 들어가있음]" << endl;
		}
		else {
			tempItem->PrintItemInfo();
		}

	}
}

void Inventory::PrintMaterialInventory()
{
	cout << "장비 인벤토리" << endl;
	for (ItemBase* item : materials) {
		Item_Consumables* tempItem = dynamic_cast<Item_Consumables*>(item);
		if (tempItem == nullptr) {
			cout << "[Error : 장비 인벤토리에 장비가 아닌 아이템이 들어가있음]" << endl;
		}
		else {
			tempItem->PrintItemInfo();
		}

		/*Item_Equipable* temp = (Item_Equipable*)item;
		temp->PrintItemInfo();*/
	}
}


