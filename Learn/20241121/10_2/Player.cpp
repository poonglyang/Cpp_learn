#include "Player.h"

Player::Player(const std::string& n, const int h): Unit(n, h)
{
}
// �θ�Ŭ������ ���� �����Լ��� ������ ���� ������ ���� ��ü�� �ȵȴ�

void Player::Attack() const
{
	std::cout << name << "�� Į�� �ֵѷ���" << std::endl;
}

void Player::TakeDamage(const int damage)
{
	health -= damage;
	std::cout << health << std::endl;
}
