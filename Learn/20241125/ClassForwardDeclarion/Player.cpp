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

	std::cout << "�÷��̾� ������" << name << "����" << std::endl;
}

void Player::Attack()
{
	std::cout << "����" << std::endl;
	if (weapon) {
		weapon->Use();

	}
}