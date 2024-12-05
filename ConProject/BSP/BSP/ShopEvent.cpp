#include "ShopEvent.h"

void ShopEvent::EventStart(Player* player)
{
	ShowSignboard(player);
}

ShopEvent::ShopEvent()
{
	itemManager = ItemManager();
	shopInventory = Inventory(10, 10, 1, itemManager);

	int equipmentSaleCount = Mathf::Random::Range(0, 4);
	int consumableSaleCount = Mathf::Random::Range(0, 4);

	for (int i = 0; i < equipmentSaleCount; i++) {
		ItemBase* tempItem = itemManager.GetEquipableItemByIndex(Mathf::Random::Range(0, itemManager.GetEquipVectorSize()));
		shopInventory.equipable.push_back(tempItem);
	}

	for (int i = 0; i < consumableSaleCount; i++) {
		ItemBase* tempItem = itemManager.GetConsumableItemByIndex(Mathf::Random::Range(0, itemManager.GetConsumableVectorSize()), 1+rand() % 5);
		shopInventory.consumables.push_back(tempItem);
	}
}

void ShopEvent::ShowSignboard(Player* player)
{
	system("cls");
	for (int i = 0; i < 60; i++) {

		for (int j = 0; j < 45; j++) {

			switch (signboard[i][j]) {

			case 0:
				std::cout << "  ";
				break;
			case 1:
				SetRGBColor(50, 50, 50);
				std::cout << "■";
				break;
			case 2:
				SetRGBColor(160, 160, 160);
				std::cout << "■";
				break;
			case 3:
				SetRGBColor(130, 130, 130);
				std::cout << "■";
				break;
			case 4:
				SetRGBColor(109, 109, 109);
				std::cout << "■";
				break;
			case 5:
				SetRGBColor(193, 111, 18);
				std::cout << "■";
				break;
			case 6:
				SetRGBColor(236, 134, 19);
				std::cout << "■";
				break;
			case 7:
				SetRGBColor(246, 221, 221);
				std::cout << "■";
				break;
			case 8:
				SetRGBColor(177, 8, 8);
				std::cout << "■";
				break;
			case 9:
				SetRGBColor(102, 56, 5);
				std::cout << "■";
				break;
			case 10:
				SetRGBColor(105, 7, 7);
				std::cout << "■";
				break;
			case 11:
				SetRGBColor(69, 37, 2);
				std::cout << "■";
				break;
			}

			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			// 텍스트 색상 리셋 (기본)
			printf("\033[0m");
		}
		std::cout << std::endl;

		
	}
	Sleep(2000);
	BuySellSelect(player);
}

void ShopEvent::BuySellSelect(Player* player)
{
	
	int input;
	bool isShopping = true;

	while (isShopping) {
		system("cls");
		for (int i = 0; i < 48; i++) {

			for (int j = 0; j < 70; j++) {

				switch (buySellPanel[i][j]) {

				case 0:
					std::cout << "  ";
					break;
				case 1:
					SetRGBColor(50, 50, 50);
					std::cout << "■";
					break;
				case 2:
					SetRGBColor(121, 85, 72);
					std::cout << "■";
					break;
				case 3:
					SetRGBColor(89, 64, 55);
					std::cout << "■";
					break;
				case 4:
					SetRGBColor(185, 185, 185);
					std::cout << "■";
					break;
				case 5:
					SetRGBColor(66, 35, 25);
					std::cout << "■";
					break;
				case 6:
					SetRGBColor(96, 125, 139);
					std::cout << "■";
					break;
				case 7:
					SetRGBColor(3, 169, 244);
					std::cout << "■";
					break;
				case 8:
					SetRGBColor(122, 120, 122);
					std::cout << "■";
					break;
				case 9:
					SetRGBColor(255, 255, 255);
					std::cout << "■";
					break;
				case 10:
					SetRGBColor(255, 193, 7);
					std::cout << "■";
					break;
				case 11:
					SetRGBColor(255, 5, 5);
					std::cout << "■";
					break;
				case 12:
					SetRGBColor(180, 47, 2);
					std::cout << "■";
					break;
				case 13:
					SetRGBColor(247, 162, 133);
					std::cout << "■";
					break;
				case 14:
					SetRGBColor(234, 158, 10);
					std::cout << "■";
					break;
				}

				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				// 텍스트 색상 리셋 (기본)
				printf("\033[0m");
			}
			std::cout << std::endl;
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 70; j++) {
				switch (buySellOutSeleteText[i][j])
				{
				case 0:
					std::cout << "  ";
					break;
				case 7:
					SetRGBColor(255, 255, 255);
					std::cout << "■";
					break;
				case 2:
					SetRGBColor(255, 255, 255);
					std::cout << "▶    [구매한다]\t    ■\t\t    [판매한다]\t\t    ■\t\t    [나간다]\t\t■";
					break;
				case 3:
					SetRGBColor(255, 255, 255);
					std::cout << "      [구매한다]\t    ■\t\t▶  [판매한다]\t\t    ■\t\t    [나간다]\t\t■";
					break;
				case 4:
					SetRGBColor(255, 255, 255);
					std::cout << "      [구매한다]\t    ■\t\t    [판매한다]\t\t    ■\t\t▶  [나간다]\t\t■";
					break;
				default:
					break;
				}
				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				// 텍스트 색상 리셋 (기본)
				printf("\033[0m");
			}
			std::cout << std::endl;
		}

		input = playHelper::getCommand();

		switch (input) {
		case 100:
		case 77:
			if (buySellOutSeleteText[3][4] == 2) {
				buySellOutSeleteText[3][4] = 3;
			}
			else if (buySellOutSeleteText[3][4] == 3) {
				buySellOutSeleteText[3][4] = 4;
			}
				
			break;
			
		case 97:
		case 75:
			if (buySellOutSeleteText[3][4] == 4) {
				buySellOutSeleteText[3][4] = 3;

			}
			else if (buySellOutSeleteText[3][4] == 3) {
				buySellOutSeleteText[3][4] = 2;

			}
			break;
			
		case 13:
			switch (buySellOutSeleteText[3][4])
			{
			case 2:
				BuyItem(player);
				break;
			case 3:
				SellItem(player);
				break;
			case 4:
				isShopping = false;
				break;
			default:
				break;
			}
		}
	}
}

void ShopEvent::BuyItem(Player* player)
{
	int input;
	bool wantBuy = true;
	int choiceIndex = 0;
	while (wantBuy) {
		system("cls");
		std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
		std::cout << std::endl<<"[아이템 구매]\t\t\t\t" << std::endl;
		std::cout << "[소지금 : " << player->inventory->GetMoney() << " G]" << std::endl;


		std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl << std::endl;
		// 인벤토리의 아이템 이름 출력
		if (!shopInventory.equipable.empty()) {
			for (int i = 0; i < shopInventory.equipable.size(); i++) {
				if (choiceIndex == i) {
					std::cout << "\t▶\t";
				}
				else {
					std::cout << "\t\t";
				}
				std::cout << shopInventory.equipable[i]->GetItemName() << "\t남은 수량 : "
					<< shopInventory.equipable[i]->GetItemCount() << "개\t가격 : " << shopInventory.equipable[i]->GetPrice() << "G" << std::endl;
			}
		}
		
		if (!shopInventory.consumables.empty()) {
			for (int i = 0; i < shopInventory.consumables.size(); i++) {
				if (choiceIndex - shopInventory.equipable.size() == i) {
					std::cout << "\t▶\t";
				}
				else {
					std::cout << "\t\t";
				}
				std::cout << shopInventory.consumables[i]->GetItemName() << "\t남은 수량 : "
					<< shopInventory.consumables[i]->GetItemCount() << "개\t가격 : " << shopInventory.consumables[i]->GetPrice() << "G" << std::endl;
			}
		}
		

		std::cout << std::endl;

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 31; j++) {
				switch (shopAction[i][j]) {
				case 0:
					std::cout << "  ";
					break;
				case 1:
					std::cout << "■";
					break;
				case 2:
					std::cout << "\t▶  [구매한다]\t      ■\t  [떠난다]\t    ■";
					break;
				case 3:
					std::cout << "\t   [구매한다]\t      ■       ▶  [떠난다]   \t    ■";
					break;
				case 7:
					std::cout << "\t  [← or Ａ]\t      ■\t [→ or Ｄ]\t    ■";
					break;

				}
			}
			std::cout << std::endl;
		}

		input = playHelper::getCommand();

		switch (input)
		{
		case 100:	// 오른쪽 화살표 or d
		case 77:
			shopAction[2][3] = 3;
			break;

			break;
		case 97:	// 왼쪾 화살표 or s
		case 75:
			shopAction[2][3] = 2;
			break;
		case 119:	// 위 또는 w
		case 72:
			if (choiceIndex - 1 >= 0) {
				--choiceIndex;
			}
			break;
		case 115:	// 아래 방향키 또는 s
		case 80:
			if (choiceIndex + 1 < shopInventory.equipable.size() + shopInventory.consumables.size()) {
				++choiceIndex;
			}
			break;
		case 13:	// 엔터
			if (shopAction[2][3] == 2) {
				if (!shopInventory.equipable.empty() && choiceIndex < shopInventory.equipable.size()) {
					// 인덱스가 장비고
					if (player->inventory->GetMoney() >= shopInventory.GetEquipableInventoryItemPriceByIndex(choiceIndex)) {
						// 돈이 충분하다면
						player->inventory->SetMoney(-shopInventory.GetEquipableInventoryItemPriceByIndex(choiceIndex),true);
						player->inventory->PushItem(shopInventory.PopItem(choiceIndex));
					}
					
				}
				else if (!shopInventory.consumables.empty()) {
					if (!shopInventory.equipable.empty()) {
						int tempIndex = choiceIndex - shopInventory.equipable.size();
						if (player->inventory->GetMoney() >= shopInventory.GetConsumableInventoryItemPriceByIndex(tempIndex)) {
							player->inventory->SetMoney(-shopInventory.GetConsumableInventoryItemPriceByIndex(tempIndex), true);
							player->inventory->
								PushItem(shopInventory.GetConsumableInventoryItemIdByIndex(tempIndex), 1);

							shopInventory.PopItem(shopInventory.GetConsumableInventoryItemIdByIndex(tempIndex), 1);
						}
					}
					else {
						if (player->inventory->GetMoney() >= shopInventory.GetConsumableInventoryItemPriceByIndex(choiceIndex)) {
							player->inventory->SetMoney(-shopInventory.GetConsumableInventoryItemPriceByIndex(choiceIndex), true);
							player->inventory->
								PushItem(shopInventory.GetConsumableInventoryItemIdByIndex(choiceIndex), 1);

							shopInventory.PopItem(shopInventory.GetConsumableInventoryItemIdByIndex(choiceIndex), 1);
						}
					}
				}
			}
			else if(shopAction[2][3] == 3) {
				wantBuy = false;
			}
			break;
		default:
			break;
		}

	}
}

void ShopEvent::SellItem(Player* player)
{
	int choiceIndex = 0;

	bool wantShowInventory = true;
	InventoryNum currentShowInventory = InventoryNum::Equip;
	std::vector<ItemBase*>* currentInventory = &player->inventory->equipable;

	switch (currentShowInventory)
	{
	case itemDatas::InventoryNum::Equip:
		currentInventory = &player->inventory->equipable;
		changeShowArr[2][3] = 2;
		sellAction[2][3] = 2;
		break;
	case itemDatas::InventoryNum::Consumable:
		currentInventory = &player->inventory->consumables;
		changeShowArr[2][3] = 3;
		sellAction[2][3] = 2;
		break;
	case itemDatas::InventoryNum::Material:
		changeShowArr[2][3] = 4;
		sellAction[2][3] = 2;
		currentInventory = &player->inventory->materials;
		break;
	default:
		break;
	}

	int input;
	while (wantShowInventory) {
		system("cls");
		std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
		std::cout << std::endl << "[아이템 판매]\t\t\t\t" << std::endl;
		std::cout << "[소지금 : " << player->inventory->GetMoney() << " G]" << std::endl;

		std::cout << std::endl;

		

		// 인벤토리 상단 부분 그리기
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 31; j++) {
				switch (changeShowArr[i][j]) {
				case 0:
					std::cout << "  ";
					break;
				case 1:
					std::cout << "■";
					break;
				case 2:
					std::cout << "[재료]\t■\t    [장비]\t    ■\t  [소비]    ■";
					break;
				case 3:
					std::cout << "[장비]\t■\t    [소비]\t    ■\t  [재료]    ■";
					break;
				case 4:
					std::cout << "[소비]\t■\t    [재료]\t    ■\t  [장비]    ■";
					break;
				case 5:
					std::cout << "Ｑ";
					break;
				case 6:
					std::cout << "Ｅ";
					break;
				}
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		// 인벤토리의 아이템 이름 출력
		for (int i = 0; i < currentInventory->size(); i++) {
			if (choiceIndex == i) {
				std::cout << "\t▶\t";
			}
			else {
				std::cout << "\t\t";
			}
			ItemBase* item = (*currentInventory)[i];
			std::cout << item->GetItemName() << std::endl;
		}

		std::cout << std::endl;
		std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;



		std::cout << std::endl;
		// 아이템 설명 출력
		if (!currentInventory->empty()) {

			ItemBase* item = (*currentInventory)[choiceIndex];
			std::cout << "\t이름\t\t" << item->GetItemName() << std::endl;
			std::cout << "\t갯수\t\t" << item->GetItemCount() << "개" << std::endl;
			std::cout << "\t가격\t\t" << item->GetPrice() << std::endl;

			std::cout << std::endl;
		}
		else {
			std::cout << "\t아이템이 없습니다" << std::endl;
		}


		std::cout << std::endl;

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 31; j++) {
				switch (sellAction[i][j]) {
				case 0:
					std::cout << "  ";
					break;
				case 1:
					std::cout << "■";
					break;
				case 2:
					std::cout << "\t▶  [판매한다]\t      ■\t  [나간다]\t    ■";
					break;
				case 3:
					std::cout << "\t   [판매한다]\t      ■       ▶  [나간다]   \t    ■";
					break;
				case 7:
					std::cout << "\t  [← or Ａ]\t      ■\t [→ or Ｄ]\t    ■";
					break;

				}
			}
			std::cout << std::endl;
		}

		input = playHelper::getCommand();

		switch (input)
		{
		case 100:	// 오른쪽 화살표 or d
		case 77:
			sellAction[2][3] = 3;
			break;
		case 97:	// 왼쪾 화살표 or s
		case 75:
			sellAction[2][3] = 2;
			break;
		case 119:	// 위 또는 w
		case 72:
			if (choiceIndex - 1 >= 0) {
				--choiceIndex;
			}
			break;
		case 115:	// 아래 방향키 또는 s
		case 80:
			if (choiceIndex + 1 < currentInventory->size()) {
				++choiceIndex;
			}
			break;
		case 113:	// q
			choiceIndex = 0;
			switch (currentShowInventory)
			{
			case itemDatas::InventoryNum::Equip:
				currentInventory = &player->inventory->materials;
				currentShowInventory = itemDatas::InventoryNum::Material;
				changeShowArr[2][3] = 4;
				break;
			case itemDatas::InventoryNum::Consumable:
				currentInventory = &player->inventory->equipable;
				currentShowInventory = itemDatas::InventoryNum::Equip;
				changeShowArr[2][3] = 2;
				break;
			case itemDatas::InventoryNum::Material:
				changeShowArr[2][3] = 3;
				currentInventory = &player->inventory->consumables;
				currentShowInventory = itemDatas::InventoryNum::Consumable;
				break;
			}
			break;
		case 101:	// e
			choiceIndex = 0;
			switch (currentShowInventory)
			{
			case itemDatas::InventoryNum::Equip:
				changeShowArr[2][3] = 3;
				currentInventory = &player->inventory->consumables;
				currentShowInventory = itemDatas::InventoryNum::Consumable;

				break;
			case itemDatas::InventoryNum::Consumable:
				currentInventory = &player->inventory->materials;
				currentShowInventory = itemDatas::InventoryNum::Material;
				changeShowArr[2][3] = 4;
				break;
			case itemDatas::InventoryNum::Material:
				currentInventory = &player->inventory->equipable;
				currentShowInventory = itemDatas::InventoryNum::Equip;
				changeShowArr[2][3] = 2;

				break;
			}
			break;
		case 13:	// 엔터
			if (!currentInventory->empty()) {
				switch (currentShowInventory)
				{
				case itemDatas::InventoryNum::Equip: {
					if (sellAction[2][3] == 2) {
						player->inventory->SetMoney(player->inventory->GetEquipableInventoryItemPriceByIndex(choiceIndex), true);
						ItemBase* popItem = player->inventory->PopItem(choiceIndex);
						delete popItem;
						popItem = nullptr;
						if (choiceIndex >= player->inventory->equipable.size()) {
							choiceIndex = player->inventory->equipable.size() - 1;
						}
					}
					else {
						wantShowInventory = false;
					}
					break;
				}
				case itemDatas::InventoryNum::Consumable: {
					
					if (sellAction[2][3] == 2) {
						player->inventory->SetMoney(player->inventory->GetConsumableInventoryItemPriceByIndex(choiceIndex), true);
						ItemBase* item = (*currentInventory)[choiceIndex];
						player->inventory->PopItem(item->GetItemId(), 1);;
						if (choiceIndex >= player->inventory->consumables.size()) {
							choiceIndex = 0;
						}
					}
					else {
						wantShowInventory = false;
					}
				}

				break;
				case itemDatas::InventoryNum::Material: {
					if (sellAction[2][3] == 2) {
						player->inventory->SetMoney(player->inventory->GetMaterialsInventoryItemPriceByIndex(choiceIndex), true);

						ItemBase* item = (*currentInventory)[choiceIndex];
						player->inventory->PopItem(item->GetItemId(), 1);
						if (choiceIndex >= player->inventory->materials.size()) {
							choiceIndex = 0;
						}
					}
					else {
						wantShowInventory = false;
					}
					
					break;
				}

				default:
					break;
				}
			}
			else {
				if (sellAction[2][3] == 3) {
					wantShowInventory = false;
				}
			}
			break;
		default:
			break;
		}

	}
}

void ShopEvent::EventUpdate()
{
	
}

void ShopEvent::EventEnd()
{
}

void ShopEvent::RenderEvent()
{
}
