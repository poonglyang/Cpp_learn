#pragma once
#include "ItemBase.h"

using namespace itemDatas;

class Item_Consumables : public ItemBase
{
protected:
	int toCopy;

	float hpHeal;

	float addMaxHp;

	float mpHeal;

	float addMaxMp;

	float addAtk;

	float addDef;

	float addCritialProbability;

	float critialDamage;

	float defIgnore;

	float hit;

	float avoid;

	float defenseProbability;

	float behaviorSpeed;

public:
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="id">������ id</param>
	/// <param name="name">������ �̸�</param>
	/// <param name="count">������ ����</param>
	/// <param name="maxCount">������ �ִ� ũ��</param>
	/// <param name="price">������ ����</param>
	/// <param name="itemType">������ Ÿ��</param>
	/// <param name="explain">������ ����</param>
	Item_Consumables(int id, const std::string& name, int count, int maxCount, int price, int itemType, const std::string& explain,
		float hpHeal, float addMaxHp,float  mpHeal, float addMaxMp, float addAtk, float addDef, 
		float addCritialProbability, float critialDamage, float defIgnore, float hit, float avoid, float defenseProbability, float behaviorSpeed);

	Item_Consumables(const Item_Consumables& other);


	/// <summary>
	/// ����� �� ����� ȿ���ε� �̰Ŵ� ���߿� ���� �˾Ƽ� �����ϰ���
	/// ���ʿ� ���� ���뿡�� �̷��� ���ݾ�
	/// </summary>
	void OnUse();

	/// <summary>
	/// ������ ȸ���ϴ� ���� �������� �Լ�
	/// </summary>
	/// <returns>ȸ������ ����ִ� ����</returns>
	std::vector<float> GetConsumableState();

	void PrintItemInfo() override;
};

