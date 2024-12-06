#include "Item_Consumables.h"

Item_Consumables::Item_Consumables(int id, const std::string& name, int count, int maxCount, int price, int itemType, const std::string& explain
	,float hpHeal, float addMaxHp, float  mpHeal, float addMaxMp, float addAtk, float addDef, float addCritialProbability, float critialDamage, float defIgnore, float hit, float avoid, float defenseProbability, float behaviorSpeed)
	: ItemBase(id, name, count, maxCount, price, (int)itemDatas::ItemType::Consumables, explain), hpHeal(hpHeal), addMaxHp(addMaxHp), mpHeal(mpHeal), addMaxMp(addMaxMp), addAtk(addAtk), addDef(addDef),
	addCritialProbability(addCritialProbability), critialDamage(critialDamage), defIgnore(defIgnore), hit(hit), avoid(avoid), defenseProbability(defenseProbability) , behaviorSpeed(behaviorSpeed)
{
	toCopy = 0;
}

Item_Consumables::Item_Consumables(const Item_Consumables& other)
	: ItemBase(other), hpHeal(other.hpHeal), addMaxHp(other.addMaxHp), mpHeal(other.mpHeal), addMaxMp(other.addMaxMp), addAtk(other.addAtk), addDef(other.addDef), addCritialProbability(other.addCritialProbability), critialDamage(other.critialDamage), defIgnore(other.defIgnore), hit(other.hit), avoid(other.avoid), defenseProbability(other.defenseProbability), behaviorSpeed(other.behaviorSpeed)
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
	returnVector.push_back(addCritialProbability);
	returnVector.push_back(critialDamage);
	returnVector.push_back(defIgnore);
	returnVector.push_back(addDef);
	returnVector.push_back(hit);
	returnVector.push_back(avoid);
	returnVector.push_back(defenseProbability);
	returnVector.push_back(behaviorSpeed);

	return returnVector;
}

void Item_Consumables::PrintItemInfo()
{
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;

	std::cout << "\t" << name << std::endl << std::endl;

	std::cout << "\t" << explain << std::endl << std::endl;

	std::cout << "\t" << "수량 : " << count << std::endl;
	std::cout << "\t" << "가격 : " << price << "골드" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
}
