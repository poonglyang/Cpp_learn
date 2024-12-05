#pragma once
#include <vector>
#include "Item_Equipable.h"
#include "Item_Consumables.h"
#include "Item_Material.h"

/// <summary>
/// ��� �������� ������ ������ �ִ� Ŭ����
/// �������� �߰��� ��� �� Ŭ�������� id�� �´� ���� ���������� �����´�
/// �÷��̰� ���۵� �� �ݵ�� ������ �ִ´�.
/// ����� ���� ���̺� ������ ���� ���� �߰��� �� �ִ�.
/// </summary>
class ItemManager
{
private:
	/// <summary>
	/// ���� �������� ����ִ� ����
	/// </summary>
	std::vector<Item_Equipable> equipable_Items;

	/// <summary>
	/// �Һ�� �������� ����ִ� ����
	/// </summary>
	std::vector<Item_Consumables> consumables_Items;

	/// <summary>
	/// ��� �������� ����ִ� ����
	/// </summary>
	std::vector<Item_Material> material_Items;

	/// <summary>
	/// ���� ��ȯ�Ǹ� �ȵǴ� ������
	/// </summary>
	ItemBase* fuck;
public:
	/// <summary>
	/// ������ �Ŵ����� ������
	/// ���⼭ �� �ֿܼ� �� ��� �������� �����Ѵ�
	/// �𸮾�� ���� ��ũ���ͺ� ������Ʈ�� ���� ����
	/// </summary>
	ItemManager();

	/// <summary>
	/// id�� �������� id�� �ش��ϴ� �������� �ִ� ��ø ������ ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <param name="id">������ id</param>
	/// <returns>�ִ� ����</returns>
	int GetItemMaxCountById(int id);

	///// <summary>
	///// �����ۿ� �´� ���� �����ִ� �Լ�
	///// ��� ������ ���� ����� ���� �����޾�����
	///// </summary>
	///// <typeparam name="T">ItemBase, Item_Equipable, Item_Consumables, Item_Material �� �ϳ�</typeparam>
	///// <param name="id">������ id</param>
	///// <param name="count">����</param>
	///// <returns></returns>
	//template<typename T>
	//#if __cplusplus >= 202002L
	//requires std::is_base_of<ItemBase, T>::value
	//#endif
	//T GetItem(int id, int count)
	//{
	//	int itemType = id / 100000;
	//	int index = id - itemType * 100000 - 1;

	//	if (id < 100000) {
	//		T deepCopyItem = T(equipable_Items[index]);
	//		return deepCopyItem;
	//	}
	//	else if (id < 200000) {
	//		T deepCopyItem = T(consumables_Items[index]);
	//		deepCopyItem.SetItemCount(count, false);
	//		return deepCopyItem;
	//	}
	//	else if (id < 300000) {
	//		T deepCopyItem = T(material_Items[index]);
	//		deepCopyItem.SetItemCount(count, false);
	//		return deepCopyItem;
	//	}
	//	else {
	//		//���� �̰� ��µǸ� ����
	//		return fuck;
	//	}
	//}
	
	Item_Equipable* GetEquipableItemByIndex(int index);

	Item_Equipable* GetEquipableItem(int id);

	Item_Consumables* GetConsumableItemByIndex(int index, int count);

	Item_Consumables* GetConsumableItem(int id, int count);

	Item_Material* GetMaterialItem(int id, int count);


	int GetEquipVectorSize();
	int GetConsumableVectorSize();
};

