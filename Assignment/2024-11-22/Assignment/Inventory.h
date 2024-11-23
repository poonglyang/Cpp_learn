#pragma once
#include <iostream>
#include <vector>
#include "ItemBase.h";
#include "ItemData.h"

using namespace itemDatas;
using namespace std;

class Inventory
{
protected:
	/// <summary>
	/// ������ ���� �κ��丮 ����
	/// </summary>
	vector<ItemBase> equipable;

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
	vector<ItemBase> consumables;

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
	vector<ItemBase> materials;

	/// <summary>
	/// ��� ������ �κ��丮�� �� �ִ� �������� ����
	/// </summary>
	int materials_CurrentInventoryCount;

	/// <summary>
	/// ��� ������ �κ��丮 �ִ� ����
	/// </summary>
	int materials_MaxInventoryCapacity;
public:
	/// <summary>
	/// ������
	/// </summary>
	Inventory();

	/// <summary>
	/// �κ��丮�� �������� ���� �ִ� �Լ�
	/// </summary>
	/// <param name="item">���� ������</param>
	bool PushItem(ItemBase& item);

};

