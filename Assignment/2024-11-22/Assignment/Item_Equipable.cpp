#include "Item_Equipable.h"

Item_Equipable::Item_Equipable(int id, const string& name, int price, int itemType, const string& explain,
	int equipSlot, float hp, float mp, float atk, float critialProbability,
	float critialDamage, float defIgnore, float def, float hit, float avoid,
	float defenseProbability, float behaviorSpeed)
	: ItemBase(id, name, 1, 1, price, itemType, explain), equipSlot(equipSlot),
	itemState_Hp(hp), itemState_Mp(mp), itemState_Atk(atk),
	itemState_CriticalProbability(critialProbability),
	itemState_CriticalDamage(critialDamage), itemState_DefIgnore(defIgnore),
	itemState_Def(def), itemState_Hit(hit), itemState_Avoid(avoid), 
	itemState_Defense_Probability(defenseProbability), itemState_BehaviorSpeed(behaviorSpeed)
{
	// ������ ����...
}

Item_Equipable::Item_Equipable(const Item_Equipable& other)
	: ItemBase(other.id, other.name, other.count, other.maxCount, other.price, other.itemType, other.explain)
{
	this->equipSlot = other.equipSlot;
	this->itemState_Hp = other.itemState_Hp;
	this->itemState_Mp = other.itemState_Mp;
	this->itemState_Atk = other.itemState_Atk;
	this->itemState_CriticalProbability = other.itemState_CriticalProbability;
	this->itemState_CriticalDamage = other.itemState_CriticalDamage;
	this->itemState_DefIgnore = other.itemState_DefIgnore;
	this->itemState_Def = other.itemState_Def;
	this->itemState_Hit = other.itemState_Hit;
	this->itemState_Avoid = other.itemState_Avoid;
	this->itemState_Defense_Probability = other.itemState_Defense_Probability;
	this->itemState_BehaviorSpeed = other.itemState_BehaviorSpeed;
}

vector<float> Item_Equipable::GetItemState()
{
	vector<float> itemStateV = {
		itemState_Hp, itemState_Mp, itemState_Atk, itemState_CriticalProbability,
		itemState_CriticalDamage, itemState_DefIgnore, itemState_Def, itemState_Hit,
		itemState_Avoid, itemState_Defense_Probability, itemState_BehaviorSpeed
	};

	return itemStateV;
}

int Item_Equipable::GetEquipSlot()
{
	return equipSlot;
}

void Item_Equipable::PrintItemInfo()
{
	cout << "������������������������������������" << endl;
	cout << "\t" << name << endl << endl;

	vector<string> itemEquipSlot = {
		"���", "�� �� ���(��� ���� ����)", "������ ���", "�޼� ���",
		"�Ӹ�", "����", "����", "�尩", "�Ź�",
		"����", "�����", "��Ʈ", "����"
	};

	cout << "\t" << itemEquipSlot[equipSlot] << endl;

	cout << endl << endl;
	cout << "\t" << "������ ����" << endl;

	vector<float> itemStateV = GetItemState();

	vector<string> itemStateInfo = {
		"Hp\t\t",
		"Mp\t\t",
		"���ݷ�\t\t",
		"ũ��Ƽ�� Ȯ��\t",
		"ũ��Ƽ�� ������\t",
		"���� ����\t",
		"����\t\t",
		"���߷�\t\t",
		"ȸ����\t\t",
		"���и��� Ȯ��\t",
		"�ൿ��\t\t"
	};

	int index = 0;
	for (const float& state : itemStateV) {
		if (state != 0) {
			cout << "\t" << itemStateInfo[index] << state << endl;
		}
		index++;
	}

	cout << endl << "\t" << explain << endl;

	cout << endl << "\t���� : " << price << "���" << endl;

	cout << "������������������������������������" << endl;


}
