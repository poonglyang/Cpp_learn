#include "Player.h"

void Player::Equip(Item_Equipable*& slot, Item_Equipable* item)
{
	/*if (inventory->isCanDequip() && item == nullptr) {
		cout << "���ĭ�� ���� ���־� ��� ���� �� �����ϴ�" << endl;
	}
	else {
		
	}*/

	Item_Equipable* temp = slot;	// ������ ���� temp�� �ű��
	if (temp != nullptr) {			
		SetAllState(temp->GetItemState(), false);	// ���� �� ����
		inventory->PushItem(dynamic_cast<ItemBase*>(temp));		// �κ��丮�� �ֱ�
	}

	slot = item;
	SetAllState(item->GetItemState(), true);
}

void Player::Dequip(Item_Equipable*& slot)
{
	if (slot == nullptr) {
		cout << "������ ��� �����ϴ�" << endl;
	}
	else if (!inventory->isCanDequip()) {
		cout << "���ĭ�� �� �� ��� ���� �� �����ϴ�" << endl;
	}
	else {
		Item_Equipable* temp = slot;	// ������ ���� temp�� �ű��
		if (temp != nullptr) {
			SetAllState(temp->GetItemState(), false);	// ���� �� ����
			inventory->PushItem(dynamic_cast<ItemBase*>(temp));		// �κ��丮�� �ֱ�
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
		cout << "�̱��� �����Դϴ�" << endl;
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
		cout << "�������Դϴ� �˼��մϴ�";
		break;
	case (int)itemDatas::EquipSlot::Weapon_Both_OneHand:
		int selectHand;
		cout << "��� �տ� �����Ͻðڽ��ϱ�? (1. ������, 2. �޼�) : ";
		cin >> selectHand;
		switch (selectHand)
		{
		case 1:
			Equip(rightHand, item);
			break;
		case 2:
			Equip(leftHand , item);
			break;
		default:
			cout << "������ �����Ͽ����ϴ�" << endl;
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
	cout << "[�÷��̾� ����]" << endl;
	PrintState();
}

void Player::PrintEquip()
{
	cout << "[���]" << endl;
	cout << "\t[������]\t" << endl;
	if (rightHand != nullptr) {
		rightHand->PrintItemInfo();
	}
	else {
		cout << "\t����\t" << endl;
	}
	
	cout << "\t[�޼�]\t" << endl;
	if (leftHand != nullptr) {
		leftHand->PrintItemInfo();
	}
	else {
		cout << "\t����\t" << endl;
	}

	cout << "\t[�Ӹ�]\t" << endl;
	if (helmet != nullptr) {
		helmet->PrintItemInfo();
	}
	else {
		cout << "\t����\t" << endl;
	}

	cout << "\t[����]\t" << endl;
	if (armor_Top != nullptr) {
		armor_Top->PrintItemInfo();
	}
	else {
		cout << "\t����\t" << endl;
	}

	cout << "\t[����]\t" << endl;
	if (armor_Bottom != nullptr) {
		armor_Bottom->PrintItemInfo();
	}
	else {
		cout << "\t����\t" << endl;
	}

	cout << "\t[�尩]\t" << endl;
	if (gloves != nullptr) {
		gloves->PrintItemInfo();
	}
	else {
		cout << "\t����\t" << endl;
	}

	cout << "\t[�Ź�]\t" << endl;
	if (boots != nullptr) {
		boots->PrintItemInfo();
	}
	else {
		cout << "\t����\t" << endl;
	}

	cout << "\t[����]\t" << endl;
	if (ring != nullptr) {
		ring->PrintItemInfo();
	}
	else {
		cout << "\t����\t" << endl;
	}

	cout << "\t[�����]\t" << endl;
	if (necklace != nullptr) {
		necklace->PrintItemInfo();
	}
	else {
		cout << "\t����\t" << endl;
	}

	cout << "\t[��Ʈ]\t" << endl;
	if (belt != nullptr) {
		belt->PrintItemInfo();
	}
	else {
		cout << "\t����\t" << endl;
	}

	cout << "\t[����]\t" << endl;
	if (bracelet != nullptr) {
		bracelet->PrintItemInfo();
	}
	else {
		cout << "\t����\t" << endl;
	}

}


