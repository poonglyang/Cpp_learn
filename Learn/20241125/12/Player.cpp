#include "Player.h"
#include "Player.h"
#include "Player.h"

Player::Player()
{
	InitPlayer();
}



void Player::InitPlayer()
{
	mAtk = 10;
	mDef = 10;
}

void Player::ShowStatus()
{
	Item equippedArmor = mInventory.GetEquippedArmor();
	Item equippedWeapon = mInventory.GetEquippedArmor();

	int addAtk = equippedWeapon.GetAttribute();
	int addDef = equippedArmor.GetAttribute();
	std::cout << "========플레이어 스탯========" << std::endl;
	std::cout << "공격력\t" << mAtk + addAtk << std::endl;
	std::cout << "방어력\t" << mDef + addDef << std::endl;
	std::cout << "============장비============" << std::endl;
	std::cout << "무기\t" << equippedWeapon.GetName() << std::endl;
	std::cout << "방어구\t" << equippedArmor.GetName() << std::endl;
}

void Player::SellItem(const int itemNum, int& gold)
{
	mInventory.SellItem(itemNum, gold);
}

void Player::EquipItem(const int num)
{
	mInventory.EquipItem(num);
}

void Player::AddItemToInventory(const Item& item)
{
	mInventory.AddItem(item);
}

void Player::ShowInventory() const
{
	mInventory.ShowInventory();
}
