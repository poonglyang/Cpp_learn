#pragma once
#include<iostream>
#include "ItemBase.h"
#include <vector>

using namespace std;
using namespace itemDatas;

class Item_Equipable : public ItemBase
{
private:
#pragma region ��� ������ �߰� ���� ����
	/// <summary>
	/// ���� ����
	/// </summary>
	int equipSlot;

	/// <summary>
	/// �� ���� �߰��Ǵ� hp
	/// </summary>
	float itemState_Hp;

	/// <summary>
	/// �� ���� �߰��Ǵ� mp
	/// </summary>
	float itemState_Mp;

	/// <summary>
	/// �� ���� �߰��Ǵ� ���ݷ�
	/// </summary>
	float itemState_Atk;

	/// <summary>
	/// �� ���� �߰��Ǵ� ũ��Ƽ�� Ȯ��
	/// </summary>
	float itemState_CriticalProbability;

	/// <summary>
	/// �� ���� �߰��Ǵ� ũ��Ƽ�� ������ ����
	/// </summary>
	float itemState_CriticalDamage;

	/// <summary>
	/// �� ���� �߰��Ǵ� ���� ����(���� ����)
	/// </summary>
	float itemState_DefIgnore;
	
	/// <summary>
	/// �� ���� �߰��Ǵ� ����
	/// </summary>
	float itemState_Def;

	/// <summary>
	/// �� ���� �߰��Ǵ� ���߷�
	/// </summary>
	float itemState_Hit;

	/// <summary>
	/// �� ���� �߰��Ǵ� ȸ�Ƿ�
	/// </summary>
	float itemState_Avoid;

	/// <summary>
	/// �� ���� �߰��Ǵ� ���� ���� Ȯ��
	/// </summary>
	float itemState_Defense_Probability;

	/// <summary>
	/// �ൿ��
	/// </summary>
	float itemState_BehaviorSpeed;

#pragma endregion
public:
	/// <summary>
	/// ��� ������ ������, itemBase �������� ����, �ִ� ������ 1�� ����
	/// </summary>
	/// <param name="id">��� ������ id</param>
	/// <param name="name">��� ������ �̸�</param>
	/// <param name="price">��� ������ ����</param>
	/// <param name="itemType">��� ������ Ÿ��</param>
	/// <param name="hp">������ �ö󰡴� hp</param>
	/// <param name="mp">������ �ö󰡴� mp</param>
	/// <param name="atk">������ �ö󰡴� atk</param>
	/// <param name="critialProbability">������ �ö󰡴� ũȮ</param>
	/// <param name="critialDamage">������ �ö󰡴� ũ����</param>
	/// <param name="defIgnore">������ �ö󰡴� �湫</param>
	/// <param name="def">������ �ö󰡴� ����</param>
	/// <param name="hit">������ �ö󰡴� ���߷�</param>
	/// <param name="avoid">������ �ö󰡴� ȸ�Ƿ�</param>
	/// <param name="defenseProbability">������ �ö󰡴� ���� ���� Ȯ��</param>
	/// <param name="behaviorSpeed">������ �ö󰡴� ���ǵ�</param>
	Item_Equipable(
		int id, const string& name, int price, int itemType, const string& explain, int equipSlot,
		float hp, float mp, float atk, float critialProbability,
		float critialDamage, float defIgnore, float def, float hit,
		float avoid, float defenseProbability, float behaviorSpeed);

	Item_Equipable(const Item_Equipable& other);

public:
	/// <summary>
	/// ������ ������ vector ���·� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>������ ������ ����ִ� vector</returns>
	vector<float> GetItemState();

	/// <summary>
	/// ���� ������ ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>���� ����</returns>
	int GetEquipSlot();

	/// <summary>
	/// ������ ������ ����ϴ� �Լ�
	/// </summary>
	void PrintItemInfo() override;
};

