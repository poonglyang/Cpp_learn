#include "IState.h"

IState::IState(float hp, float maxHp, float mp, float maxMp, float atk, 
	float critialProbability, float critialDamage, float defIgnore, float def, 
	float hit, float avoid, float defenseProbability, float behaviorSpeed)
	: hp(hp), maxHp(maxHp), mp(mp), maxMp(maxMp), atk(atk), critialProbability(critialProbability),
	critialDamage(critialDamage), defIgnore(defIgnore), def(def), hit(hit), avoid(avoid),
	defenseProbability(defenseProbability),	behaviorSpeed(behaviorSpeed)
{
	isAlive = true;
}

void IState::Die()
{
	isAlive = false;
}

float IState::GetHp() const
{
	return hp;
}

void IState::SetHp(float delta, bool isAdd)
{
	if (isAdd) {
		hp += delta;
	}
	else {
		hp = delta;
	}

	if (hp > maxHp) {
		hp = maxHp;
	}
	else if (hp < 0) {
		hp = 0;
		Die();
	}
	
}

float IState::GetMaxHp() const
{
	return maxHp;
}

void IState::SetMaxHp(float delta, bool isAdd)
{
	if (isAdd) {
		maxHp += delta;
	}
	else {
		maxHp = delta;
	}

	if (maxHp < hp) {
		SetHp(maxHp, false);
	}
}

float IState::GetMp() const
{
	return mp;
}

void IState::SetMp(float delta, bool isAdd)
{
	if (isAdd) {
		mp += delta;
	}
	else {
		mp = delta;
	}

	if (mp > maxMp) {
		mp = maxMp;
	}
}

float IState::GetMaxMp() const
{
	return maxMp;
}

void IState::SetMaxMp(float delta, bool isAdd)
{
	if (isAdd) {
		maxMp += delta;
	}
	else {
		maxMp = delta;
	}

	if (maxMp < mp) {
		SetMp(maxMp, false);
	}
}

float IState::GetAtk() const
{
	return atk;
}

void IState::SetAtk(float delta, bool isAdd)
{
	if (isAdd) {
		atk += delta;
	}
	else {
		atk = delta;
	}
}

float IState::GetCritialProbability() const
{
	return critialProbability;
}

void IState::SetCritialProbability(float delta, bool isAdd)
{
	if (isAdd) {
		critialProbability += delta;
	}
	else {
		critialProbability = delta;
	}
}

float IState::GetCritialDamage() const
{
	return critialDamage;
}

void IState::SetCritialDamage(float delta, bool isAdd)
{
	if (isAdd) {
		critialDamage += delta;
	}
	else {
		critialDamage = delta;
	}
}

float IState::GetDefIgnore() const
{
	return defIgnore;
}

void IState::SetDefIgnore(float delta, bool isAdd)
{
	if (isAdd) {
		defIgnore += delta;
	}
	else {
		defIgnore = delta;
	}
}

float IState::GetDef() const
{
	return def;
}

void IState::SetDef(float delta, bool isAdd)
{
	if (isAdd) {
		def += delta;
	}
	else {
		def = delta;
	}
}

float IState::GetHit() const
{
	return hit;
}

void IState::SetHit(float delta, bool isAdd)
{
	if (isAdd) {
		hit += delta;
	}
	else {
		hit = delta;
	}
}

float IState::GetAvoid() const
{
	return avoid;
}

void IState::SetAvoid(float delta, bool isAdd)
{
	if (isAdd) {
		avoid += delta;
	}
	else {
		avoid = delta;
	}
}

float IState::GetDefenseProbability() const
{
	return defenseProbability;
}

void IState::SetDefenseProbability(float delta, bool isAdd)
{
	if (isAdd) {
		defenseProbability += delta;
	}
	else {
		defenseProbability = delta;
	}
}

float IState::GetBehaviorSpeed() const
{
	return behaviorSpeed;
}

void IState::SetBehaviorSpeed(float delta, bool isAdd)
{
	if (isAdd) {
		behaviorSpeed += delta;
	}
	else {
		behaviorSpeed = delta;
	}
}

void IState::SetAllState(std::vector<float> state, bool isEquip)
{
	/*std::vector<float> itemStateV = {
		itemState_Hp, itemState_Mp, itemState_Atk, itemState_CriticalProbability,
		itemState_CriticalDamage, itemState_DefIgnore, itemState_Def, itemState_Hit,
		itemState_Avoid, itemState_Defense_Probability, itemState_BehaviorSpeed
	};*/
	int equip = 1;
	if (isEquip) {
		equip = 1;
	}
	else {
		equip = -1;
	}

	maxHp += state[0] * equip;
	maxMp += state[1] * equip;
	atk += state[2] * equip;
	critialProbability += state[3] * equip;
	critialDamage += state[4] * equip;
	defIgnore += state[5] * equip;;
	def += state[6] * equip;
	hit += state[7] * equip;
	avoid += state[8] * equip;
	defenseProbability += state[9] * equip;
	behaviorSpeed += state[10] * equip;

}

bool IState::GetIsAlive() const
{
	return isAlive;
}

void IState::PrintState()
{
	std::cout << "HP\t\t\t" << hp << "/" << maxHp << std::endl;
	std::cout << "MP\t\t\t" << mp << "/" << maxMp << std::endl;
	std::cout << "공격력\t\t\t" << atk << std::endl;
	std::cout << "방어력\t\t\t" << def << std::endl;
	std::cout << "크리티컬 확률\t\t" << critialProbability << "%" << std::endl;
	std::cout << "크리티컬 데미지 배율\t" << critialDamage << "%" << std::endl;
	std::cout << "방어력 무시(%)\t\t" << defIgnore << std::endl;
	std::cout << "명중률\t\t\t" << hit << "%" << std::endl;
	std::cout << "회피율\t\t\t" << avoid << "%" << std::endl;
	std::cout << "방패 막기 확률\t\t" << defenseProbability << "%" << std::endl;
	std::cout << "행동력\t\t\t" << behaviorSpeed << std::endl;
}


