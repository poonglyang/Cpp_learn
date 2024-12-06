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

#pragma region �ʺ��ڿ� �ܰ�
	equipable_Item = Item_Equipable(
		2,		// ������ id
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
		3,		// ������ id
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
		4,		// ������ id
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
		5,		// ������ id
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
		6,		// ������ id
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

#pragma region ö �ܰ�
	equipable_Item = Item_Equipable(
		8,		// ������ id
		"ö �ܰ�",		// ������ ����
		50,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"������ ö�� ���� �ܰ�",		// ������ ����
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,			// ������ ���� ����
		50,		// ������ �߰� hp
		10,		// ������ �߰� mp
		30,		// ������ �߰� atk
		30,		// ������ �߰� ũȮ
		15,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		0,		// ������ �߰� ����
		20,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		1		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion �ʺ��ڿ� ��հ�

#pragma region ö �Ѽհ�
	equipable_Item = Item_Equipable(
		9,		// ������ id
		"ö �Ѽհ�",		// ������ ����
		50,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"�� ���� ö�� ���� �ܰ�",		// ������ ����
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,			// ������ ���� ����
		80,		// ������ �߰� hp
		0,		// ������ �߰� mp
		50,		// ������ �߰� atk
		20,		// ������ �߰� ũȮ
		10,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		0,		// ������ �߰� ����
		15,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		1		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion ö �Ѽհ�

#pragma region ö â
	equipable_Item = Item_Equipable(
		10,		// ������ id
		"ö â",		// ������ ����
		50,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"�� ���� ö�� ���� â",		// ������ ����
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,			// ������ ���� ����
		70,		// ������ �߰� hp
		0,		// ������ �߰� mp
		40,		// ������ �߰� atk
		35,		// ������ �߰� ũȮ
		22,		// ������ �߰� ũ����
		10,		// ������ �߰� �湫
		0,		// ������ �߰� ����
		70,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		1		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion ö â

#pragma region ���� ����
	equipable_Item = Item_Equipable(
		11,		// ������ id
		"���� ����",		// ������ ����
		10,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"������ ���� ����",		// ������ ����
		(int)itemDatas::EquipSlot::Armor_Top,			// ������ ���� ����
		100,		// ������ �߰� hp
		0,		// ������ �߰� mp
		0,		// ������ �߰� atk
		0,		// ������ �߰� ũȮ
		0,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		10,		// ������ �߰� ����
		0,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		1		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion ���� ����

#pragma region ö ����
	equipable_Item = Item_Equipable(
		12,		// ������ id
		"ö ����",		// ������ ����
		50,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"�� ���� ö�� ���� ����",		// ������ ����
		(int)itemDatas::EquipSlot::Armor_Top,			// ������ ���� ����
		200,		// ������ �߰� hp
		0,		// ������ �߰� mp
		0,		// ������ �߰� atk
		0,		// ������ �߰� ũȮ
		0,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		50,		// ������ �߰� ����
		0,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		1		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion ö ����

#pragma region ���� ����
	equipable_Item = Item_Equipable(
		13,		// ������ id
		"���� ����",		// ������ ����
		10,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"������ ���� ����",		// ������ ����
		(int)itemDatas::EquipSlot::Armor_Bottom,			// ������ ���� ����
		80,		// ������ �߰� hp
		0,		// ������ �߰� mp
		0,		// ������ �߰� atk
		0,		// ������ �߰� ũȮ
		0,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		8,		// ������ �߰� ����
		0,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		1		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion ���� ����

#pragma region ö ����
	equipable_Item = Item_Equipable(
		14,		// ������ id
		"���� ����",		// ������ ����
		50,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"�� ���� ö�� ���� ����",		// ������ ����
		(int)itemDatas::EquipSlot::Armor_Bottom,			// ������ ���� ����
		160,		// ������ �߰� hp
		0,		// ������ �߰� mp
		0,		// ������ �߰� atk
		0,		// ������ �߰� ũȮ
		0,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		20,		// ������ �߰� ����
		0,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		1		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion ö ����


#pragma region ���� ���
	equipable_Item = Item_Equipable(
		15,		// ������ id
		"���� ���",		// ������ ����
		10,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"������ ���� ���",		// ������ ����
		(int)itemDatas::EquipSlot::Helmet,			// ������ ���� ����
		30,		// ������ �߰� hp
		0,		// ������ �߰� mp
		0,		// ������ �߰� atk
		0,		// ������ �߰� ũȮ
		0,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		10,		// ������ �߰� ����
		0,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		1		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion ���� ���

#pragma region ö ���
	equipable_Item = Item_Equipable(
		16,		// ������ id
		"ö ���",		// ������ ����
		50,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"�� ���� ö�� ���� ���",		// ������ ����
		(int)itemDatas::EquipSlot::Helmet,			// ������ ���� ����
		65,		// ������ �߰� hp
		0,		// ������ �߰� mp
		0,		// ������ �߰� atk
		0,		// ������ �߰� ũȮ
		0,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		33,		// ������ �߰� ����
		0,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		1		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion ö ���

#pragma region ä���� ����
	equipable_Item = Item_Equipable(
		17,		// ������ id
		"ä���� ����",		// ������ ����
		200,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"ä���� ���� �÷��ִ� ����",		// ������ ����
		(int)itemDatas::EquipSlot::Ring,			// ������ ���� ����
		500,		// ������ �߰� hp
		0,		// ������ �߰� mp
		0,		// ������ �߰� atk
		0,		// ������ �߰� ũȮ
		0,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		0,		// ������ �߰� ����
		0,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		1		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion ä���� ����

#pragma region ������ ����
	equipable_Item = Item_Equipable(
		18,		// ������ id
		"������ ����",		// ������ ����
		200,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"������ ���� �÷��ִ� ����",		// ������ ����
		(int)itemDatas::EquipSlot::Ring,			// ������ ���� ����
		0,		// ������ �߰� hp
		500,		// ������ �߰� mp
		0,		// ������ �߰� atk
		0,		// ������ �߰� ũȮ
		0,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		0,		// ������ �߰� ����
		0,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		1		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion ������ ����

#pragma region ���ݷ��� ����
	equipable_Item = Item_Equipable(
		19,		// ������ id
		"���ݷ��� ����",		// ������ ����
		300,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"���ݷ��� ���� �÷��ִ� ����",		// ������ ����
		(int)itemDatas::EquipSlot::Ring,			// ������ ���� ����
		0,		// ������ �߰� hp
		0,		// ������ �߰� mp
		200,		// ������ �߰� atk
		0,		// ������ �߰� ũȮ
		0,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		0,		// ������ �߰� ����
		0,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		1		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion ���ݷ��� ����

#pragma region �������� ����
	equipable_Item = Item_Equipable(
		20,		// ������ id
		"�������� ����",		// ������ ����
		150,		// ����
		(int)itemDatas::ItemType::Equipable,			// ������ Ÿ��
		"���� �ɷ�ġ�� ���� �÷��ִ� ������",		// ������ ����
		(int)itemDatas::EquipSlot::Ring,			// ������ ���� ����
		100,		// ������ �߰� hp
		100,		// ������ �߰� mp
		50,		// ������ �߰� atk
		0,		// ������ �߰� ũȮ
		20,		// ������ �߰� ũ����
		0,		// ������ �߰� �湫
		70,		// ������ �߰� ����
		0,		// ������ �߰� ���߷�
		0,		// ������ �߰� ȸ����
		0,		// ������ �߰� ���� ���� Ȯ��
		1		// ������ �߰� �ൿ��
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion �������� ����

#pragma region ��ü �� �����
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
		"hp 50�� ��� ä���ݴϴ�", 50, 0,0,0,0,0,0,0,0,0,0,0,0);

	consumables_Items.push_back(consumable);
#pragma endregion ���� hp ����

#pragma region ���� mp ����
	consumable = Item_Consumables(
		100002, "���� mp ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"mp 50�� ��� ä���ݴϴ�",0,0,50,0,0,0, 0, 0, 0, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion ���� mp ����

#pragma region �ִ� ä�� ���� ����
	consumable = Item_Consumables(
		100003, "�ִ� ä�� ���� ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"�ִ�hp 30 �ø��ϴ�", 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion �ִ� ä�� ���� ����

#pragma region �ִ� ���� ���� ����
	consumable = Item_Consumables(
		100004, "�ִ� ���� ���� ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"�ִ�mp 30 �ø��ϴ�", 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion �ִ� ���� ���� ����

#pragma region ���ݷ� ���� ����
	consumable = Item_Consumables(
		100005, "���ݷ� ���� ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"���ݷ��� 10 �ø��ϴ�", 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion ���ݷ� ���� ����

#pragma region ���� ���� ����
	consumable = Item_Consumables(
		100006, "���� ���� ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"������ 10 �ø��ϴ�", 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion ���� ���� ����

#pragma region ���� ���� ���� ����
	consumable = Item_Consumables(
		100007, "���� ���� ���� ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"������ 5% �� �����մϴ�", 0, 0, 0, 0, 0, 0, 0, 0, 0.05f, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion ���� ���� ���� ����

#pragma region ���߷� ���� ����
	consumable = Item_Consumables(
		100008, "���߷� ���� ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"���߷��� 7% �� ����մϴ�", 0,0,0,0,0,0,0,0,0,0.07f,0,0,0);

	consumables_Items.push_back(consumable);
#pragma endregion ���߷� ���� ����

#pragma region ũ��Ƽ�� Ȯ�� ���� ����
	consumable = Item_Consumables(
		100009, "ũ��Ƽ�� Ȯ�� ���� ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"ũ��Ƽ�� Ȯ���� 7% �� ����մϴ�", 0, 0, 0, 0, 0, 0, 0.07f, 0, 0, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion ũ��Ƽ�� Ȯ�� ���� ����

#pragma region ũ��Ƽ�� ������ ���� ����
	consumable = Item_Consumables(
		100010, "ũ��Ƽ�� ������ ���� ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"ũ��Ƽ�� �������� 10% �� ����մϴ�", 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion ũ��Ƽ�� ������ ���� ����

#pragma region ȸ�� Ȯ�� ���� ����
	consumable = Item_Consumables(
		100011, "ȸ�� Ȯ�� ���� ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"ȸ�� Ȯ���� 5% �� ����մϴ�", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.05f, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion ȸ�� Ȯ�� ���� ����

#pragma region ��� Ȯ�� ���� ����
	consumable = Item_Consumables(
		100012, "��� Ȯ�� ���� ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"��� Ȯ���� 5% �� ����մϴ�", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.05f, 0);

	consumables_Items.push_back(consumable);
#pragma endregion ��� Ȯ�� ���� ����

#pragma region �ൿ�� ���� ����
	consumable = Item_Consumables(
		100013, "�ൿ�� ���� ����", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"�ൿ���� 1% �����մϴ�", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);

	consumables_Items.push_back(consumable);
#pragma endregion �ൿ�� Ȯ�� ���� ����

#pragma endregion

#pragma region ��� ������ �߰� �κ�
#pragma region ����
	Item_Material misc = Item_Material(
		200001, "����", 1, 30, 1, (int)itemDatas::ItemType::Materials, 
		"���� �ִٴ� ����");

	material_Items.push_back(misc);
#pragma endregion ����

#pragma region ������
	misc = Item_Material(
		200002, "������", 1, 30, 2, (int)itemDatas::ItemType::Materials, 
		"��𿡳� �����ٴϴ� ������");

	material_Items.push_back(misc);
#pragma endregion ������

#pragma region ����
	misc = Item_Material(
		200003, "����", 1, 30, 5, (int)itemDatas::ItemType::Materials, 
		"������ �������� ���� ����� ���");

	material_Items.push_back(misc);
#pragma endregion ����

#pragma region ��ö
	misc = Item_Material(
		200004, "��ö", 1, 30, 3, (int)itemDatas::ItemType::Materials,
		"�Ҽ����� ���� ���� ö");

	material_Items.push_back(misc);
#pragma endregion ��ö

#pragma region ö��
	misc = Item_Material(
		200005, "ö��", 1, 30, 15, (int)itemDatas::ItemType::Materials,
		"ö�� �� ��");

	material_Items.push_back(misc);
#pragma endregion ö��

#pragma region ���
	misc = Item_Material(
		200006, "���", 1, 30, 8, (int)itemDatas::ItemType::Materials,
		"���ݼ��� ���̴� ����");

	material_Items.push_back(misc);
#pragma endregion ���

#pragma region ����
	misc = Item_Material(
		200007, "����", 1, 30, 7, (int)itemDatas::ItemType::Materials,
		"��ü �� ���� ����");

	material_Items.push_back(misc);
#pragma endregion ����

#pragma region ����
	misc = Item_Material(
		200008, "����", 1, 30, 30, (int)itemDatas::ItemType::Materials,
		"������ ���� ���� ��");

	material_Items.push_back(misc);
#pragma endregion ����

#pragma region ���� ��ũ
	misc = Item_Material(
		200009, "���� ��ũ", 1, 30, 22, (int)itemDatas::ItemType::Materials,
		"���� �帴�ϰ� ���̴� ��ũ");

	material_Items.push_back(misc);
#pragma endregion ���� ��ũ

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

Item_Equipable* ItemManager::GetEquipableItemByIndex(int index)
{
	Item_Equipable* deepCopyItem = new Item_Equipable(equipable_Items[index]);
	return deepCopyItem;
}

Item_Equipable* ItemManager::GetEquipableItem(int id)
{
	int itemType = id / 100000;
	int index = id - itemType * 100000 - 1;

	Item_Equipable* deepCopyItem = new Item_Equipable(equipable_Items[index]);

	return deepCopyItem;
}

Item_Consumables* ItemManager::GetConsumableItemByIndex(int index, int count)
{
	Item_Consumables* deepCopyItem = new Item_Consumables(consumables_Items[index]);
	deepCopyItem->SetItemCount(count, false);
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

int ItemManager::GetRandomItemId()
{
	std::vector<int> tempV;

	for (Item_Consumables item : consumables_Items) {
		tempV.push_back(item.GetItemId());
	}

	for (Item_Material item : material_Items) {
		tempV.push_back(item.GetItemId());
	}

	

	return tempV[myMath::Mathf::Random::Range(0, tempV.size())];
}

int ItemManager::GetEquipVectorSize()
{
	return equipable_Items.size();;
}

int ItemManager::GetConsumableVectorSize()
{
	return consumables_Items.size();
}





