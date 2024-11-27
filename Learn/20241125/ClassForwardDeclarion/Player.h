#pragma once
#include <iostream>
#include "Weapon.h"
class Player
{
private:
	std::string name;
	Weapon* weapon;
	
public:
	Player(const std::string& name, Weapon* weapon);
	
	~Player();

	void Attack();
};

