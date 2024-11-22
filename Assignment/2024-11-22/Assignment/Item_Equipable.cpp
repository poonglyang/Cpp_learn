#include "Item_Equipable.h"

Item_Equipable::Item_Equipable(int id, const string& name, int itemType, 
	int equipSlot, float hp, float mp, float atk, float critialProbability,
	float critialDamage, float defIgnore, float def, float hit, float avoid,
	float defenseProbability, float behaviorSpeed)
	: ItemBase(id, name, 1, 1, itemType),
	itemState_Hp(hp), itemState_Mp(mp), itemState_Atk(atk),
	itemState_CriticalProbability(critialProbability),
	itemState_CriticalDamage(critialDamage), itemState_DefIgnore(defIgnore),
	itemState_Def(def), itemState_Hit(hit), itemState_Avoid(avoid), 
	itemState_Defense_Probability(defenseProbability), itemState_BehaviorSpeed(behaviorSpeed)
{
	// ������ ����...
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
	cout << "�����������������������" << endl;
	cout << "\t" << this->GetItemName() << endl << endl;

	vector<string> itemEquipSlot = {
		"���",
		"������",
		"�޼�",
		"�Ӹ�",
		"����",
		"����",
		"�尩",
		"�Ź�"
	};

	cout << "\t" << "��� ������" << endl << endl;
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



	cout << "�����������������������" << endl;


}
