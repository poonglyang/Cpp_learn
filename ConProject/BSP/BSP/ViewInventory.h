#pragma once
#include <windows.h>
#include "Player.h"
#include "StructureHelper.h"

namespace InventoryView {

	static void ViewInventory(Player* player) {
		int changeShowArr[7][31] = {
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
			{1,0,0,2},
			{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
			{1,0,0,0,5,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,6,0,0,0,1},
			{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};

		int inventoryAction[7][31] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,2},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,7},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};

		int choiceIndex = 0;

		bool wantShowInventory = true;
		InventoryNum currentShowInventory = InventoryNum::Equip;
		std::vector<ItemBase*>* currentInventory = &player->inventory->equipable;

		switch (currentShowInventory)
		{
		case itemDatas::InventoryNum::Equip:
			currentInventory = &player->inventory->equipable;
			changeShowArr[2][3] = 2;
			inventoryAction[2][3] = 2;
			break;
		case itemDatas::InventoryNum::Consumable:
			currentInventory = &player->inventory->consumables;
			changeShowArr[2][3] = 3;
			inventoryAction[2][3] = 4;
			break;
		case itemDatas::InventoryNum::Material:
			changeShowArr[2][3] = 4;
			inventoryAction[2][3] = 6;
			currentInventory = &player->inventory->materials;
			break;
		default:
			break;
		}

		int input;
		while (wantShowInventory) {
			system("cls");
			std::cout << std::endl;

			// �κ��丮 ��� �κ� �׸���
			for (int i = 0; i < 7; i++) {				
				for (int j = 0; j < 31; j++) {
					switch (changeShowArr[i][j]) {
					case 0:
						std::cout << "  ";
						break;
					case 1:
						std::cout << "��";
						break;
					case 2:
						std::cout << "[���]\t��\t    [���]\t    ��\t  [�Һ�]    ��";
						break;
					case 3:
						std::cout << "[���]\t��\t    [�Һ�]\t    ��\t  [���]    ��";
						break;
					case 4:
						std::cout << "[�Һ�]\t��\t    [���]\t    ��\t  [���]    ��";
						break;
					case 5:
						std::cout << "��";
						break;
					case 6:
						std::cout << "��";
						break;
					}
				}
				std::cout << std::endl;
			}

			std::cout << std::endl;

			// �κ��丮�� ������ �̸� ���
			if (!currentInventory->empty()) {
				for (int i = 0; i < currentInventory->size(); i++) {
					if (choiceIndex == i) {
						std::cout << "\t��\t";
					}
					else {
						std::cout << "\t\t";
					}
					ItemBase* item = (*currentInventory)[i];
					std::cout << item->GetItemName() << std::endl;
				}
			}
			else {
				std::cout << "\t\t�������� �����ϴ�";
			}
			

			std::cout << std::endl;
			std::cout << "��������������������������������" << std::endl;

			

			std::cout << std::endl;
			// ������ ���� ���
			if (!currentInventory->empty()) {
				
				ItemBase* item = (*currentInventory)[choiceIndex];
				std::cout << "\t�̸�\t\t" << item->GetItemName() << std::endl;
				std::cout << "\t����\t\t" << item->GetItemCount() << "��" << std::endl;
				std::cout << "\t����\t\t" << item->GetPrice() << std::endl;
				std::cout << "\t����\t\t" << item->GetItemExplain() << std::endl;

				std::cout << std::endl;

				Item_Equipable* tempItem = dynamic_cast<Item_Equipable*>(item);

				if (tempItem != nullptr) {
					tempItem->PrintItemInfo();
				}
			}
			else {
				std::cout << "\t�������� �����ϴ�" << std::endl;
			}
			

			std::cout << std::endl;
			
			for (int i = 0; i < 7; i++) {
				for (int j = 0; j < 31; j++) {
					switch (inventoryAction[i][j]) {
					case 0:
						std::cout << "  ";
						break;
					case 1:
						std::cout << "��";
						break;
					case 2:
						std::cout << "\t��  [�����Ѵ�]\t      ��\t  [������]\t    ��";
						break;
					case 3:
						std::cout << "\t   [�����Ѵ�]\t      ��       ��  [������]   \t    ��";
						break;
					case 4:
						std::cout << "\t��  [����Ѵ�]\t      ��\t  [������]\t    ��";
						break;
					case 5:
						std::cout << "\t   [����Ѵ�]\t      ��       ��  [������]   \t    ��";
						break;
					case 6:
						std::cout << "\t   \t\t      ��       ��  [������]   \t    ��";
						break;
					case 7:
						std::cout << "\t  [�� or ��]\t      ��\t [�� or ��]\t    ��";
						break;

					}
				}
				std::cout << std::endl;
			}
			
			input = playHelper::getCommand();

			switch (input)
			{
			case 100:	// ������ ȭ��ǥ or d
			case 77: 
				switch (currentShowInventory)
				{
				case itemDatas::InventoryNum::Equip:
					inventoryAction[2][3] = 3;
					break;
				case itemDatas::InventoryNum::Consumable:
					inventoryAction[2][3] = 5;
					break;
				case itemDatas::InventoryNum::Material:
					inventoryAction[2][3] = 6;
					break;
				default:
					break;
				}

				break;
			case 97:	// �ަU ȭ��ǥ or s
			case 75: 
				switch (currentShowInventory)
				{
				case itemDatas::InventoryNum::Equip:
					inventoryAction[2][3] = 2;
					break;
				case itemDatas::InventoryNum::Consumable:
					inventoryAction[2][3] = 4;
					break;
				case itemDatas::InventoryNum::Material:
					inventoryAction[2][3] = 6;
					break;
				default:
					break;
				}
				break;
			case 119:	// �� �Ǵ� w
			case 72:
				if (choiceIndex - 1 >= 0) {
					--choiceIndex;
				}
				break;
			case 115:	// �Ʒ� ����Ű �Ǵ� s
			case 80:
				if (choiceIndex + 1 < currentInventory->size()) {
					++choiceIndex;
				}
				break;
			case 113:	// q
				switch (currentShowInventory)
				{
				case itemDatas::InventoryNum::Equip:
					currentInventory = &player->inventory->materials;
					currentShowInventory = itemDatas::InventoryNum::Material;
					changeShowArr[2][3] = 4;
					inventoryAction[2][3] = 6;
					
					break;
				case itemDatas::InventoryNum::Consumable:
					currentInventory = &player->inventory->equipable;
					currentShowInventory = itemDatas::InventoryNum::Equip;
					changeShowArr[2][3] = 2;
					inventoryAction[2][3] = 2;
					break;
				case itemDatas::InventoryNum::Material:
					changeShowArr[2][3] = 3;
					inventoryAction[2][3] = 4;
					currentInventory = &player->inventory->consumables;
					currentShowInventory = itemDatas::InventoryNum::Consumable;
					break;
				}
				break;
			case 101:	// e
				switch (currentShowInventory)
				{
				case itemDatas::InventoryNum::Equip:
					changeShowArr[2][3] = 3;
					inventoryAction[2][3] = 4;
					currentInventory = &player->inventory->consumables;
					currentShowInventory = itemDatas::InventoryNum::Consumable;
					
					break;
				case itemDatas::InventoryNum::Consumable:
					currentInventory = &player->inventory->materials;
					currentShowInventory = itemDatas::InventoryNum::Material;
					changeShowArr[2][3] = 4;
					inventoryAction[2][3] = 6;
					break;
				case itemDatas::InventoryNum::Material:
					currentInventory = &player->inventory->equipable;
					currentShowInventory = itemDatas::InventoryNum::Equip;
					changeShowArr[2][3] = 2;
					inventoryAction[2][3] = 2;
					
					break;
				}
				break;
			case 13:	// ����
				if (!currentInventory->empty()) {
					switch (currentShowInventory)
					{
					case itemDatas::InventoryNum::Equip: {
						if (inventoryAction[2][3] == 2) {
							player->EquipSelect(choiceIndex);
							choiceIndex = 0;
						}
						else {
							ItemBase* popItem = player->inventory->PopItem(choiceIndex);
							delete popItem;
							popItem = nullptr;
							if (choiceIndex >= player->inventory->equipable.size()) {
								choiceIndex = player->inventory->equipable.size() - 1;
							}
						}
						break;
					}
					case itemDatas::InventoryNum::Consumable: {
						ItemBase* item = (*currentInventory)[choiceIndex];
						if (inventoryAction[2][3] == 4) {
							player->UseItem(choiceIndex);
							if (choiceIndex >= player->inventory->consumables.size()) {
								choiceIndex = 0;
							}
							//std::cout << "��� �����ؾ��� �ù�" << std::endl;
						}
						else {
							ItemBase* item = (*currentInventory)[choiceIndex];
							player->inventory->PopItem(item->GetItemId(), 1);;
							if (choiceIndex >= player->inventory->consumables.size()) {
								choiceIndex = 0;
							}
						}
						break;
					}
					case itemDatas::InventoryNum::Material: {
						ItemBase* item = (*currentInventory)[choiceIndex];
						player->inventory->PopItem(item->GetItemId(), 1);
						if (choiceIndex >= player->inventory->materials.size()) {
							choiceIndex = 0;
						}
						break;
					}
						
					default:
						break;
					}
				}
				
				break;
			case 105:	// i Ű
				wantShowInventory = false;
				break;
			default:
				break;
			}

		}
	}

	static void ViewState(Player* player) {
		system("mode con: cols=50 lines=70");
		system("cls");
		player->PrintPlayerInfo();
		player->PrintEquip();
		playHelper::getCommand();
	}

	static void ViewEquip(Player* player) {
		player->PrintEquip();
	}

	
}



