#include "ItemManager.h"

ItemManager::ItemManager()
{
#pragma region ��� ������ �߰� �κ�
#pragma region �ʺ��ڿ� ��
	Item_Equipable equipable_Item = Item_Equipable(
		1, "�ʺ��ڿ� ��", 10, (int)itemDatas::ItemType::Equipable,
		"�˿� �� �Թ��� �ʺ��ڰ� ���� ���� ��",
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,
		20, 0, 7, 3, 5, 0, 0, 5, 0, 0, 10);
	
	equipable_Items.push_back(equipable_Item);

#pragma endregion �ʺ��ڿ� ��

#pragma region �ʺ��ڿ� ��հ�
	equipable_Item = Item_Equipable(
		2,		// ������ id
		"�ʺ��ڿ� ��հ�",		// ������ ����
		10,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"��հ˿� �� �Թ��� �ʺ��ڰ� ���� ���� ��հ�",		// ������ ����
		(int)itemDatas::EquipSlot::Weapon_Both,			// ������ ���� ����
		20,		// ������ �߰� hp
		0,		// ������ �߰� mp
		10,		// ������ �߰� atk
		1,		// ������ �߰� ũȮ
		5,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		0,		// ������ �߰� ����
		7,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		1		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion �ʺ��ڿ� ��հ�

#pragma region �ʺ��ڿ� �ܰ�
	equipable_Item = Item_Equipable(
		3,		// ������ id
		"�ʺ��ڿ� �ܰ�",		// ������ ����
		10,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"�ܰ˿� �� �Թ��� �ʺ��ڰ� ���� ���� ��հ�",		// ������ ����
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,	// ������ ���� ����
		10,		// ������ �߰� hp
		0,		// ������ �߰� mp
		3,		// ������ �߰� atk
		20,		// ������ �߰� ũȮ
		15,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		0,		// ������ �߰� ����
		10,		// ������ �߰� ���߷�
		5,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		20		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion �ʺ��ڿ� �ܰ�

#pragma region �ʺ��ڿ� â
	equipable_Item = Item_Equipable(
		4,		// ������ id
		"�ʺ��ڿ� â",		// ������ ����
		10,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"â�� �� �Թ��� �ʺ��ڰ� ���� ���� â",		// ������ ����
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,	// ������ ���� ����
		20,		// ������ �߰� hp
		0,		// ������ �߰� mp
		4,		// ������ �߰� atk
		10,		// ������ �߰� ũȮ
		10,		// ������ �߰� ũ����
		10,		// ������ �߰� �湫
		0,		// ������ �߰� ����
		7,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		12		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion �ʺ��ڿ� â

#pragma region �ʺ��ڿ� �б�
	equipable_Item = Item_Equipable(
		5,		// ������ id
		"�ʺ��ڿ� �б�",		// ������ ����
		10,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"�б⿡ �� �Թ��� �ʺ��ڰ� ���� ���� �б�",		// ������ ����
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,	// ������ ���� ����
		25,		// ������ �߰� hp
		0,		// ������ �߰� mp
		8,		// ������ �߰� atk
		3,		// ������ �߰� ũȮ
		3,		// ������ �߰� ũ����
		3,		// ������ �߰� �湫
		0,		// ������ �߰� ����
		3,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		5		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion �ʺ��ڿ� �б�

#pragma region �ʺ��ڿ� Ȱ
	equipable_Item = Item_Equipable(
		6,		// ������ id
		"�ʺ��ڿ� Ȱ",		// ������ ����
		10,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"Ȱ�� �� �Թ��� �ʺ��ڰ� ���� ���� Ȱ",		// ������ ����
		(int)itemDatas::EquipSlot::Weapon_Right,	// ������ ���� ����
		18,		// ������ �߰� hp
		0,		// ������ �߰� mp
		8,		// ������ �߰� atk
		10,		// ������ �߰� ũȮ
		10,		// ������ �߰� ũ����
		10,		// ������ �߰� �湫
		0,		// ������ �߰� ����
		15,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		4		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion �ʺ��ڿ� Ȱ

#pragma region �ʺ��ڿ� ����
	equipable_Item = Item_Equipable(
		7,		// ������ id
		"�ʺ��ڿ� ����",		// ������ ����
		10,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"�ʺ��ڰ� ���� ���� ����",		// ������ ����
		(int)itemDatas::EquipSlot::Weapon_Left,	// ������ ���� ����
		50,		// ������ �߰� hp
		0,		// ������ �߰� mp
		0,		// ������ �߰� atk
		0,		// ������ �߰� ũȮ
		0,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		20,		// ������ �߰� ����
		0,		// ������ �߰� ���߷�
		-5,		// ������ �߰� ȸ����
		10,		// ������ �߰� ���� ���� Ȯ��
		0		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion �ʺ��ڿ� ����

#pragma region �ʺ��ڿ� ������
	equipable_Item = Item_Equipable(
		7,		// ������ id
		"�ʺ��ڿ� ������",		// ������ ����
		10,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"������ �� �Թ��� �ʺ��ڰ� ���� ���� ������",		// ������ ����
		(int)itemDatas::EquipSlot::Weapon_Right,	// ������ ���� ����
		0,		// ������ �߰� hp
		50,		// ������ �߰� mp
		30,		// ������ �߰� atk
		0,		// ������ �߰� ũȮ
		0,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		-10,		// ������ �߰� ����
		0,		// ������ �߰� ���߷�
		-10,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		-10		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion �ʺ����� ������

#pragma region �ʺ��ڿ� ��ü �� �����
	equipable_Item = Item_Equipable(
		2, "��ü �� ������", 99999999, (int)itemDatas::ItemType::Equipable,
		"��ȭ�ô� �� ���������  �����Ǵ� �����\n\t�������ϴٰ� ������ ������ ���� �ɷ�ġ�� �ø���",
		(int)itemDatas::EquipSlot::Necklace,
		10000, 10000, 999, 999, 999, 999, 999, 999, 999, 999, 999);

	equipable_Items.push_back(equipable_Item);
#pragma endregion ������ �׳� �����ڿ� �����

#pragma endregion ��� ������ �߰� �κ�

#pragma region �Һ� ������ �߰� �κ�
#pragma region ���� hp ����
	Item_Consumables consumable = Item_Consumables (
		100001, "���� hp ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables, 
		"hp 50�� ��� ä���ݴϴ�", 50, 0,0,0,0,0);

	consumables_Items.push_back(consumable);
#pragma endregion ���� hp ����

#pragma region ���� mp ����
	consumable = Item_Consumables(
		100002, "���� mp ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"mp 50�� ��� ä���ݴϴ�",0,0,50,0,0,0);

	consumables_Items.push_back(consumable);
#pragma endregion ���� mp ����

#pragma region �ִ� ä�� ���� ����
	consumable = Item_Consumables(
		100003, "�ִ� ä�� ���� ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"�ִ�hp 30 �ø��ϴ�", 0, 30, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion �ִ� ä�� ���� ����

#pragma region �ִ� ���� ���� ����
	consumable = Item_Consumables(
		100004, "�ִ� ä�� ���� ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"�ִ�mp 30 �ø��ϴ�", 0, 0, 0, 30, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion �ִ� ���� ���� ����

#pragma region ���ݷ� ���� ����
	consumable = Item_Consumables(
		100005, "���ݷ� ���� ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"���ݷ��� 10 �ø��ϴ�", 0, 0, 0, 0, 10, 0);

	consumables_Items.push_back(consumable);
#pragma endregion ���ݷ� ���� ����

#pragma region ���� ���� ����
	consumable = Item_Consumables(
		100006, "���� ���� ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"������ 10 �ø��ϴ�", 0, 0, 0, 0, 0, 10);

	consumables_Items.push_back(consumable);
#pragma endregion ���� ���� ����

#pragma endregion

#pragma region ��� ������ �߰� �κ�
#pragma region ����
	Item_Material misc = Item_Material(
		300001, "����", 1, 30, 1, (int)itemDatas::ItemType::Materials, 
		"���� �ִٴ� ����");

	material_Items.push_back(misc);
#pragma endregion ����

#pragma region ������
	misc = Item_Material(
		300002, "������", 1, 30, 1, (int)itemDatas::ItemType::Materials, 
		"��𿡳� �����ٴϴ� ������");

	material_Items.push_back(misc);
#pragma endregion ������

#pragma region ����
	misc = Item_Material(
		300003, "����", 1, 30, 1, (int)itemDatas::ItemType::Materials, 
		"������ �������� ���� ����� ���");

	material_Items.push_back(misc);
#pragma endregion ����

#pragma endregion

	// ���� ��ȯ�Ǹ� �ȵǴ� ������
	fuck = new ItemBase(-999, "Error", 0, 0, 0, -999, "Error������ ���ʿ� ���� ��ü�� �Ұ�����");
}

int ItemManager::GetItemMaxCountById(int id)
{
	int itemType = id / 100000;
	int index = id - itemType * 100000 - 1;
	if (id < 100000) {
		return 1;
	}
	else if (id < 200000) {
		return consumables_Items[index].GetItemMaxCount();
	}
	else if (id < 300000) {
		return material_Items[index].GetItemMaxCount();
	}
	else {
		//���� �̰� ��µǸ� ����
		return 0;
	}
}

Item_Equipable* ItemManager::GetEquipableItem(int id)
{
	int itemType = id / 100000;
	int index = id - itemType * 100000 - 1;

	Item_Equipable* deepCopyItem = new Item_Equipable(equipable_Items[index]);

	return deepCopyItem;
}

Item_Consumables* ItemManager::GetConsumableItem(int id, int count)
{
	int itemType = id / 100000;
	int index = id - itemType * 100000 - 1;
	Item_Consumables* deepCopyItem = new Item_Consumables(consumables_Items[index]);
	deepCopyItem->SetItemCount(count, false);
	return deepCopyItem;
}

Item_Material* ItemManager::GetMaterialItem(int id, int count)
{
	int itemType = id / 100000;
	int index = id - itemType * 100000 - 1;
	Item_Material* deepCopyItem = new Item_Material(material_Items[index]);
	deepCopyItem->SetItemCount(count, false);
	return deepCopyItem;
}





