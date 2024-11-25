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
	std::cout << "========�÷��̾� ����========" << std::endl;
	std::cout << "���ݷ�\t" << mAtk + addAtk << std::endl;
	std::cout << "����\t" << mDef + addDef << std::endl;
	std::cout << "============���============" << std::endl;
	std::cout << "����\t" << equippedWeapon.GetName() << std::endl;
	std::cout << "��\t" << equippedArmor.GetName() << std::endl;
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
