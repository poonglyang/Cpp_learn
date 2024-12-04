#include "Player.h"

void Player::Equip(Item_Equipable*& slot, Item_Equipable* item)
{
	/*if (inventory->isCanDequip() && item == nullptr) {
		std::cout << "장비칸이 가득 차있어 장비를 벗을 수 없습니다" << std::endl;
	}
	else {
		
	}*/

	Item_Equipable* temp = slot;	// 슬롯의 것을 temp에 옮기고
	if (temp != nullptr) {			
		SetAllState(temp->GetItemState(), false);	// 스텟 다 빼고
		inventory->PushItem(dynamic_cast<ItemBase*>(temp));		// 인벤토리에 넣기
	}

	slot = item;
	SetAllState(item->GetItemState(), true);
}

void Player::Dequip(Item_Equipable*& slot)
{
	if (slot == nullptr) {
		std::cout << "장착된 장비가 없습니다" << std::endl;
	}
	else if (!inventory->isCanDequip()) {
		std::cout << "장비칸이 꽉 차 장비를 벗을 수 없습니다" << std::endl;
	}
	else {
		Item_Equipable* temp = slot;	// 슬롯의 것을 temp에 옮기고
		if (temp != nullptr) {
			SetAllState(temp->GetItemState(), false);	// 스텟 다 빼고
			inventory->PushItem(dynamic_cast<ItemBase*>(temp));		// 인벤토리에 넣기
		}

		slot = nullptr;
	}
	
}

Player::Player(float hp, float maxHp, float mp, float maxMp, float atk, float critialProbability, float critialDamage, float defIgnore, float def, float hit, float avoid, float defenseProbability, float behaviorSpeed, ItemManager& itemManager)
	: IState(hp, maxHp, mp, maxMp, atk, critialProbability, critialDamage, 
		defIgnore, def, hit, avoid, defenseProbability, behaviorSpeed)
{
	inventory = new Inventory(20, 20, 20, itemManager);

	rightHand = nullptr;
	leftHand = nullptr;
	helmet = nullptr;;
	armor_Top = nullptr;
	armor_Bottom = nullptr;
	gloves = nullptr;
	boots = nullptr;
	ring = nullptr;
	necklace = nullptr;
	belt = nullptr;
	bracelet = nullptr;
}

Item_Equipable* Player::GetPlayerRightHand() const
{
	return rightHand;
}



void Player::Dequip(int slot)
{
	switch (slot)
	{
	case (int)itemDatas::EquipSlot::Weapon_Both:
		std::cout << "미구현 상태입니다" << std::endl;
		break;
	case (int)itemDatas::EquipSlot::Weapon_Both_OneHand:
		break;
	case (int)itemDatas::EquipSlot::Weapon_Right:
		Dequip(rightHand);
		break;
	case (int)itemDatas::EquipSlot::Weapon_Left:
		Dequip(leftHand);
		break;
	case (int)itemDatas::EquipSlot::Armor_Top:
		Dequip(armor_Top);
		break;
	case (int)itemDatas::EquipSlot::Armor_Bottom:
		Dequip(armor_Bottom);
		break;
	case (int)itemDatas::EquipSlot::Helmet:
		Dequip(helmet);
		break;
	case (int)itemDatas::EquipSlot::Gloves:
		Dequip(gloves);
		break;
	case (int)itemDatas::EquipSlot::Boots:
		Dequip(boots);
		break;
	case (int)itemDatas::EquipSlot::Ring:
		Dequip(ring);
		break;
	case (int)itemDatas::EquipSlot::Necklace:
		Dequip(necklace);
		break;
	case (int)itemDatas::EquipSlot::Belt:
		Dequip(belt);
		break;
	case (int)itemDatas::EquipSlot::Bracelet:
		Dequip(bracelet);
		break;
	default:
		break;
	}
}

void Player::EquipSelect(int index)
{
	Item_Equipable* item = dynamic_cast<Item_Equipable*>(inventory->PopItem(index));
	int slot = item->GetEquipSlot();
	switch (slot)
	{
	case (int)itemDatas::EquipSlot::Weapon_Both:
		std::cout << "구현중입니다 죄송합니다";
		break;
	case (int)itemDatas::EquipSlot::Weapon_Both_OneHand:
		int selectHand;
		std::cout << "어느 손에 장착하시겠습니까? (1. 오른손, 2. 왼손) : ";
		std::cin >> selectHand;
		switch (selectHand)
		{
		case 1:
			Equip(rightHand, item);
			break;
		case 2:
			Equip(leftHand , item);
			break;
		default:
			std::cout << "장착에 실패하였습니다" << std::endl;
			break;
		}
		break;
	case (int)itemDatas::EquipSlot::Weapon_Right:
		Equip(rightHand, item);
		break;
	case (int)itemDatas::EquipSlot::Weapon_Left:
		Equip(leftHand, item);
		break;
	case (int)itemDatas::EquipSlot::Armor_Top:
		Equip(armor_Top, item);
		break;
	case (int)itemDatas::EquipSlot::Armor_Bottom:
		Equip(armor_Bottom, item);
		break;
	case (int)itemDatas::EquipSlot::Helmet:
		Equip(helmet, item);
		break;
	case (int)itemDatas::EquipSlot::Gloves:
		Equip(gloves, item);
		break;
	case (int)itemDatas::EquipSlot::Boots:
		Equip(boots, item);
		break;
	case (int)itemDatas::EquipSlot::Ring:
		Equip(ring, item);
		break;
	case (int)itemDatas::EquipSlot::Necklace:
		Equip(necklace, item);
		break;
	case (int)itemDatas::EquipSlot::Belt:
		Equip(belt, item);
		break;
	case (int)itemDatas::EquipSlot::Bracelet:
		Equip(bracelet, item);
		break;
	default:
		break;
	}

}

void Player::PrintPlayerInfo()
{
	std::cout << "[플레이어 스탯]" << std::endl;
	PrintState();
}

void Player::PrintEquip()
{
	std::cout << "[장비]" << std::endl;
	std::cout << "\t[오른손]\t" << std::endl;
	if (rightHand != nullptr) {
		rightHand->PrintItemInfo();
	}
	else {
		std::cout << "\t없음\t" << std::endl;
	}
	
	std::cout << "\t[왼손]\t" << std::endl;
	if (leftHand != nullptr) {
		leftHand->PrintItemInfo();
	}
	else {
		std::cout << "\t없음\t" << std::endl;
	}

	std::cout << "\t[머리]\t" << std::endl;
	if (helmet != nullptr) {
		helmet->PrintItemInfo();
	}
	else {
		std::cout << "\t없음\t" << std::endl;
	}

	std::cout << "\t[상의]\t" << std::endl;
	if (armor_Top != nullptr) {
		armor_Top->PrintItemInfo();
	}
	else {
		std::cout << "\t없음\t" << std::endl;
	}

	std::cout << "\t[하의]\t" << std::endl;
	if (armor_Bottom != nullptr) {
		armor_Bottom->PrintItemInfo();
	}
	else {
		std::cout << "\t없음\t" << std::endl;
	}

	std::cout << "\t[장갑]\t" << std::endl;
	if (gloves != nullptr) {
		gloves->PrintItemInfo();
	}
	else {
		std::cout << "\t없음\t" << std::endl;
	}

	std::cout << "\t[신발]\t" << std::endl;
	if (boots != nullptr) {
		boots->PrintItemInfo();
	}
	else {
		std::cout << "\t없음\t" << std::endl;
	}

	std::cout << "\t[반지]\t" << std::endl;
	if (ring != nullptr) {
		ring->PrintItemInfo();
	}
	else {
		std::cout << "\t없음\t" << std::endl;
	}

	std::cout << "\t[목걸이]\t" << std::endl;
	if (necklace != nullptr) {
		necklace->PrintItemInfo();
	}
	else {
		std::cout << "\t없음\t" << std::endl;
	}

	std::cout << "\t[벨트]\t" << std::endl;
	if (belt != nullptr) {
		belt->PrintItemInfo();
	}
	else {
		std::cout << "\t없음\t" << std::endl;
	}

	std::cout << "\t[팔찌]\t" << std::endl;
	if (bracelet != nullptr) {
		bracelet->PrintItemInfo();
	}
	else {
		std::cout << "\t없음\t" << std::endl;
	}

}


