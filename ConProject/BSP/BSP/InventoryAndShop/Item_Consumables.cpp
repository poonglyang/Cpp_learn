#include "Item_Consumables.h"

Item_Consumables::Item_Consumables(int id, const std::string& name, int count, int maxCount, int price, int itemType, const std::string& explain
	,float hpHeal, float addMaxHp, float  mpHeal, float addMaxMp, float addAtk, float addDef)
	: ItemBase(id, name, count, maxCount, price, (int)itemDatas::ItemType::Consumables, explain), hpHeal(hpHeal), addMaxHp(addMaxHp), mpHeal(mpHeal), addMaxMp(addMaxMp), addAtk(addAtk), addDef(addDef)
{
	toCopy = 0;
}

Item_Consumables::Item_Consumables(const Item_Consumables& other)
	: ItemBase(other), hpHeal(other.hpHeal), addMaxHp(other.addMaxHp), mpHeal(other.mpHeal), addMaxMp(other.addMaxMp), addAtk(other.addAtk), addDef(other.addDef)
{
	toCopy = other.toCopy;
}

void Item_Consumables::OnUse()
{
	
}

std::vector<float> Item_Consumables::GetConsumableState()
{
	std::vector<float> returnVector;

	returnVector.push_back(hpHeal);
	returnVector.push_back(addMaxHp);
	returnVector.push_back(mpHeal);
	returnVector.push_back(addMaxMp);
	returnVector.push_back(addAtk);
	returnVector.push_back(addDef);

	return returnVector;
}

void Item_Consumables::PrintItemInfo()
{
	std::cout << "������������������������������������" << std::endl;

	std::cout << "\t" << name << std::endl << std::endl;

	std::cout << "\t" << explain << std::endl << std::endl;

	std::cout << "\t" << "���� : " << count << std::endl;
	std::cout << "\t" << "���� : " << price << "���" << std::endl;
	std::cout << "������������������������������������" << std::endl;
}
