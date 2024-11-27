#include "Weapon.h"
#include "Player.h" 
Weapon::Weapon(const std::string& type)
	: type(type), player(nullptr)
{

}

Weapon::~Weapon()
{
	std::cout << "무기" << type << "삭제함" << std::endl;
}

void Weapon::Use() const
{
	std::cout << type << "무기!" << std::endl;
}
