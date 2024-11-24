#pragma once
#include <iostream>
#include <vector>
#include "ItemBase.h"
#include "ItemData.h"
#include "ItemManager.h"
#include "Item_Equipable.h"
#include "Item_Consumables.h"
#include "Item_Material.h"

using namespace itemDatas;
using namespace std;

class Inventory
{
protected:
	/// <summary>
	/// ������ ���� �κ��丮 ����
	/// </summary>
	vector<ItemBase*> equipable;

	/// <summary>
	/// ���� �κ��丮�� �� �ִ� �������� ����
	/// </summary>
	int equipable_CurrentInventoryCount;

	/// <summary>
	/// ���� �κ��丮 �κ��丮�� �ִ� �뷮
	/// </summary>
	int equipable_MaxInventoryCapacity;

	/// <summary>
	/// �Ҹ�ǰ���� ���� �κ��丮 ����
	/// </summary>
	vector<ItemBase*> consumables;

	/// <summary>
	/// �Ҹ�ǰ�� �κ��丮�� �� �ִ� �������� ����
	/// </summary>
	int consumables_CurrentInventoryCount;

	/// <summary>
	/// �Ҹ�ǰ�� �κ��丮 �ִ� ����
	/// </summary>
	int consumables_MaxInventoryCapacity;

	/// <summary>
	/// ���(��� ���� ����)�� ���� �κ��丮 ����
	/// </summary>
	vector<ItemBase*> materials;

	/// <summary>
	/// ��� ������ �κ��丮�� �� �ִ� �������� ����
	/// </summary>
	int materials_CurrentInventoryCount;

	/// <summary>
	/// ��� ������ �κ��丮 �ִ� ����
	/// </summary>
	int materials_MaxInventoryCapacity;

	/// <summary>
	/// ��
	/// </summary>
	int money;

	/// <summary>
	/// ������ �޴���
	/// </summary>
	ItemManager itemManager;

	int GetItemTypeById(int id);
public:
	/// <summary>
	/// �κ��丮 ������
	/// </summary>
	/// <param name="equipable_MaxInventoryCapacity"></param>
	/// <param name="consumables_MaxInventoryCapacity"></param>
	/// <param name="materials_MaxInventoryCapacity"></param>
	Inventory(int equipable_MaxInventoryCapacity, 
		int consumables_MaxInventoryCapacity, 
		int materials_MaxInventoryCapacity,
		ItemManager& itemManager);

	/// <summary>
	/// Ư�� �������� �ִ��� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <param name="id">������ id</param>
	/// <returns>������ 0, ������ �������� ������ ��ȯ�Ѵ�</returns>
	int CountItem(int id);


	/// <summary>
	/// ���� �����۸� �̰ɷ� ���� �� ���� ����
	/// </summary>
	/// <param name="weaponItme">���� ������ ��ü</param>
	/// <returns>ȹ�� �����ϰ�� true, ������ ��� false</returns>
	bool PushItem(ItemBase* weaponItme);

	/// <summary>
	/// �κ��丮���� ���� �������� �ִ��� Ȯ���ϰ� ���� ��� �߰��ϰ� 
	/// ���� ������ ��ȯ�Ѵ� �ϴ� �Լ�
	/// </summary>
	/// <param name="id">������ id</param>
	/// <param name="count">�߰��� ����</param>
	/// <returns>���� ����</returns>
	template<typename T>
	int AddItemAndReturnRemaining(int id, int count, vector<T> inventory);

	/// <summary>
	/// �κ��丮�� �������� ���� �ִ� �Լ�
	/// ���, ���� �ϰ�츸 �����ϴ�
	/// </summary>
	/// <param name="item">���� ������</param>
	int PushItem(int id, int count);

	/// <summary>
	/// ��� �ش��
	/// index�� �ش��ϴ� ���� �κ��丮���� �����ϰ� ��ȯ�Ѵ�
	/// </summary>
	/// <param name="id">���� ������ id</param>
	/// <returns>id�� �ش��ϴ� ������</returns>
	ItemBase* PopItem(int index);

	/// <summary>
	/// id�� �ش��ϴ� �������� ������ �Լ�
	/// ������ �����ٱ⺸�ٴ� ������ �Ҹ�ǰ�� ������� ���� ��ü�� ������ ������
	/// �̰� �� �ش��ϴ� �� ��ŭ ����������
	/// ���ʿ� count�� ������ �˻��ؼ� �����ű���
	/// </summary>
	/// <param name="id">���� ������ id</param>
	/// <returns>id�� �ش��ϴ� ������</returns>
	void PopItem(int id, int count);

	/// <summary>
	/// ���ĭ�� ���� á���� Ȯ���ϴ� �Լ�
	/// </summary>
	/// <returns>���� �������� true �ƴϸ� false</returns>
	bool isEquipableFull();

	/// <summary>
	/// ��� ���� �� �ִ��� Ȯ���ϴ� �Լ�
	/// </summary>
	/// <returns>true�� ���� �� ����, false�� ���� �� ����</returns>
	bool isCanDequip();

	/// <summary>
	/// �Һ�ĭ�� ���� á���� Ȯ���ϴ� �Լ�
	/// </summary>
	/// <returns>���� �������� true �ƴϸ� false</returns>
	bool isConsumablesFull();

	/// <summary>
	/// ���ĭ�� ���� ���ִ��� Ȯ���ϴ� �Լ�
	/// </summary>
	/// <returns>���� �������� true �ƴϸ� false</returns>
	bool isMaterialFull();

	/// <summary>
	/// �������� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>������</returns>
	int GetMoney();

	/// <summary>
	/// �������� �����ϴ� �Լ�
	/// </summary>
	/// <param name="delta"></param>
	/// <param name="isAdd"></param>
	void SetMoney(int delta, bool isAdd);

	/// <summary>
	/// �κ��丮 ������ ���ϱ�
	/// </summary>
	/// <returns></returns>
	int GetEquipableInventorySize();

	/// <summary>
	/// �κ��丮 ������ ���ϱ�
	/// </summary>
	/// <returns></returns>
	int GetConsumableInventorySize();

	/// <summary>
	/// �κ��丮 ������ ���ϱ�
	/// </summary>
	/// <returns></returns>
	int GetMaterialInventorySize();

	/// <summary>
	/// �ε����� ������� ��� �κ��丮�� �������� id�� �޴� �Լ�
	/// </summary>
	/// <returns></returns>
	int GetEquipableInventoryItemIdByIndex(int index);

	/// <summary>
	/// �ε����� ��� ������ ���� �˾Ƴ���
	/// </summary>
	/// <param name="index">�ε���</param>
	/// <returns>�ε����� �ش��ϴ� ����</returns>
	int GetEquipableInventoryItemPriceByIndex(int index);

	/// <summary>
	/// �ε����� ������� �Һ� �κ��丮�� �������� id�� �޴� �Լ�
	/// </summary>
	/// <returns></returns>
	int GetConsumableInventoryItemIdByIndex(int index);

	/// <summary>
	/// �ε����� ���� �˾Ƴ���
	/// </summary>
	/// <param name="index">�ε���</param>
	/// <returns>�ε����� �ش��ϴ� ����</returns>
	int GetConsumableInventoryItemPriceByIndex(int index);

	/// <summary>
	/// �ε����� ������� �Һ� �κ��丮�� �������� id�� �޴� �Լ�
	/// </summary>
	/// <returns></returns>
	int GetMaterialsInventoryItemIdByIndex(int index);


	/// <summary>
	/// �ε����� ���� �˾Ƴ���
	/// </summary>
	/// <param name="index">�ε���</param>
	/// <returns>�ε����� �ش��ϴ� ����</returns>
	int GetMaterialsInventoryItemPriceByIndex(int index);

	/// <summary>
	/// ���ĭ ���
	/// </summary>
	void PrintEquipableInventory();

	/// <summary>
	/// �Һ�ĭ ���
	/// </summary>
	void PrintConsumableInventory();

	/// <summary>
	/// ���ĭ ���
	/// </summary>
	void PrintMaterialInventory();
};

