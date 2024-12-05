#include "IState.h"
#include "ItemManager.h"
#include <vector>;

#pragma once
class Monster : public IState
{
private:
	

	std::string name;

public:
	int monsterImage1[20][20] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,21,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,21,21,21,21,21,22,21,0,0,0,0},
		{0,0,0,0,0,0,0,21,21,22,22,24,24,24,23,21,0,0,0,0},
		{0,0,0,0,0,0,21,22,23,23,24,25,25,24,22,21,0,0,0,0},
		{0,0,0,0,0,21,22,23,23,22,24,24,25,25,24,22,21,0,0,0},
		{0,0,0,0,21,22,22,23,23,22,24,24,24,25,25,24,22,21,0,0},
		{0,0,0,0,21,22,22,22,22,24,24,24,24,25,25,24,22,21,0,0},
		{0,0,0,0,21,22,23,21,24,24,24,21,24,25,25,25,24,21,0,0},
		{0,0,0,0,21,22,24,21,24,24,24,21,24,25,25,25,24,21,0,0},
		{0,0,0,0,21,22,24,24,24,24,24,24,24,25,25,25,25,21,0,0},
		{0,0,0,0,0,21,25,26,26,26,26,26,26,26,26,25,21,0,0,0},
		{0,0,0,0,0,0,21,21,26,26,26,26,26,26,21,21,0,0,0,0},
		{0,0,0,0,0,0,0,0,21,21,21,21,21,21,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};

	Monster();

	Monster(float hp, float maxHp, float mp, float maxMp, float atk,
		float critialProbability, float critialDamage, float defIgnore, float def, float hit,
		float avoid, float defenseProbability, float behaviorSpeed, const std::string& name);

	std::string GetName();

};

