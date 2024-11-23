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

bool IState::GetIsAlive() const
{
	return isAlive;
}


