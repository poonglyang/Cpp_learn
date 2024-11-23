#pragma once
#include <iostream>
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
	vector<Item_Equipable> equipable_Items;
	vector<Item_Consumables> consumables_Items;
	vector<Item_Material> material_Items;

	ItemBase* fuck;
public:
	/// <summary>
	/// ������ �Ŵ����� ������
	/// ���⼭ �� �ֿܼ� �� ��� �������� �����Ѵ�
	/// �𸮾�� ���� ��ũ���ͺ� ������Ʈ�� ���� ����
	/// </summary>
	ItemManager();


	template<typename T>
#if __cplusplus >= 202002L	// C++ 20 ���Ŀ��� �����Ƿ�
		requires std::is_base_of<ItemBase, T>::value	// T�� ItemBase�̰ų� ��� ���� ���̿��� ���� ����
#endif
	T GetItem(int id, int count);
};

