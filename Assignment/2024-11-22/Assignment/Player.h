#pragma once
#include <iostream>
#include "IState.h"
#include "Inventory.h"

using namespace std;
using namespace itemDatas;

class Player : public IState
{
protected:

#pragma region ��� ����
	/// <summary>
	/// �÷��̾� ������ ���
	/// </summary>
	Item_Equipable* rightHand;

	/// <summary>
	/// �÷��̾� �޼� ���
	/// </summary>
	Item_Equipable* leftHand;

	/// <summary>
	/// �÷��̾� ���
	/// </summary>
	Item_Equipable* helmet;

	/// <summary>
	/// �÷��̾� ����
	/// </summary>
	Item_Equipable* armor_Top;

	/// <summary>
	/// �÷��̾� ����
	/// </summary>
	Item_Equipable* armor_Bottom;

	/// <summary>
	/// �÷��̾� �尩
	/// </summary>
	Item_Equipable* gloves;

	/// <summary>
	/// �÷��̾� �Ź�
	/// </summary>
	Item_Equipable* boots;

	/// <summary>
	/// �÷��̾� ����
	/// </summary>
	Item_Equipable* ring;

	/// <summary>
	/// �÷��̾� �����
	/// </summary>
	Item_Equipable* necklace;

	/// <summary>
	/// �÷��̾� ��Ʈ
	/// </summary>
	Item_Equipable* belt;

	/// <summary>
	/// �÷��̾� ����
	/// </summary>
	Item_Equipable* bracelet;
#pragma endregion

	void Equip(Item_Equipable*& slot, Item_Equipable* item);

	void Dequip(Item_Equipable*& slot);

public:
	/// <summary>
	/// �÷��̾� �κ��丮
	/// </summary>
	Inventory* inventory;

	Player(float hp, float maxHp, float mp, float maxMp, float atk,
		float critialProbability, float critialDamage, float defIgnore, float def, float hit,
		float avoid, float defenseProbability, float behaviorSpeed, ItemManager& itemManager);

	/// <summary>
	/// �÷��̾��� ������ ��� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>������ ���</returns>
	Item_Equipable* GetPlayerRightHand() const;

	void Dequip(int slot);

	void EquipSelect(int index);

	void PrintPlayerInfo();

	void PrintEquip();
};

