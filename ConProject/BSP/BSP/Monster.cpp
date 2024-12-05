#include "Monster.h"

Monster::Monster() 
	: IState(1,1,1,1,1,1,1,1,1,1,1,1,1), name("������ ������ �ӽ�")
{
	
}

Monster::Monster(float hp, float maxHp, float mp, float maxMp, float atk, float critialProbability, float critialDamage, float defIgnore, float def, float hit, float avoid, float defenseProbability, float behaviorSpeed, const std::string& name)
	: IState(hp, maxHp, mp, maxMp, atk, critialProbability, critialDamage,
		defIgnore, def, hit, avoid, defenseProbability, behaviorSpeed), name(name)
{

}

std::string Monster::GetName()
{
	return name;
}
