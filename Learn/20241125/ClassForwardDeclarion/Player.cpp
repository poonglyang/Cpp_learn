#include "Player.h"
Player::Player(const std::string& name, Weapon* weapon)
	:name(name), weapon(weapon)
{
}

Player::~Player()
{
	/*
	delete weapon;
	weapon = nullptr;*/

	std::cout << "플레이어 삭제함" << name << "삭제" << std::endl;
}

void Player::Attack()
{
	std::cout << "공격" << std::endl;
	if (weapon) {
		weapon->Use();

	}
}