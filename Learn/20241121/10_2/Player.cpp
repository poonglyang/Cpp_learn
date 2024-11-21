#include "Player.h"

Player::Player(const std::string& n, const int h): Unit(n, h)
{
}
// 부모클래스의 순수 가상함수를 재정의 하지 않으면 실행 자체가 안된다

void Player::Attack() const
{
	std::cout << name << "는 칼을 휘둘렀다" << std::endl;
}

void Player::TakeDamage(const int damage)
{
	health -= damage;
	std::cout << health << std::endl;
}
