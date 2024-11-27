#include "Game.h"

Game::Game()
{
	mShop = new Shop();
	mPlayer = new Player();
	mGold = 100000;
	mLocation = GameEnums::Location::LOCATION_SHOP;
	mSelect = 0;
}

Game::~Game()
{
	delete mShop;
	mShop = nullptr;
	delete mPlayer;
	mPlayer = nullptr;
}

void Game::SetLocation(GameEnums::Location location)
{
	mLocation = location;
}

void Game::StartGame()
{
	bool isStart = true;
	while (true) {
		switch (mLocation)
		{
		case GameEnums::Location::LOCATION_SHOP:
			SetShopPage();
			break;
		case GameEnums::Location::LOCATION_SELL_INVENTORY:
			SetSellInventorypage();
			break;
		case GameEnums::Location::LOCATION_INVENTORY:
			SetInventoryPage();
			break;
		default:
			std::cout << "길을 잃었다";
			isStart = false;
			break;
		}
	}
}

void Game::SetShopPage()
{
	int select;
	std::cout << "상점에 온걸 환영해." << std::endl;
	std::cout << "아이템 종류 선택 (1. 방어구, 2. 무기) : ";
	std::cin >> select;

	GameEnums::ItemType itemType;

	if (select == 1) {
		itemType = GameEnums::ItemType::ITEM_ARMOR;
	}
	else if (select == 2) {
		itemType = GameEnums::ItemType::ITEM_WEAPON;
	}
	else {
		std::cout << "잘못된 선택" << std::endl;
		return;
	}

	DisplayShopItems(itemType);

	std::cout << "구매할 아이템 번호를 입력해라 : ";
	int num;
	std::cin >> num;

	BuyItemFromShop(itemType, num);

	SetLocation(GameEnums::Location::LOCATION_INVENTORY);
}

void Game::SetInventoryPage()
{
	std::cout << "인벤토리 보기" << std::endl;
	DisplayPlayerStatus();
	mPlayer->ShowInventory();
	std::cout << "상점은 1, 장착은 2, 판매는 3 : ";
	int choice;
	std::cin >> choice;

	if (choice == 1) {
		SetLocation(GameEnums::Location::LOCATION_SHOP);
	}
	else if (choice == 2) {
		std::cout << "장착할 아이템 번호 입력 : ";
		int itemNum;
		std::cin >> itemNum;
		EquipItemToPlayer(itemNum);

	}
	else if (choice == 3) {
		SetLocation(GameEnums::Location::LOCATION_SELL_INVENTORY);
	}
	else {
		
	}
}

void Game::SetSellInventorypage()
{
	std::cout << "판매할 아이템을 선택해라 : ";
	int itemNum;
	std::cin >> itemNum;

	mPlayer->SellItem(itemNum, mGold);
	mPlayer->ShowInventory();
}

void Game::DisplayShopItems(GameEnums::ItemType itemKind)
{
	mShop->DisplayItems(itemKind);
}

void Game::BuyItemFromShop(GameEnums::ItemType itemKind, int num)
{
	Item* boughtItem = mShop->BuyItem(itemKind, num - 1, mGold);
	if (boughtItem != nullptr) {
		std::cout << "아이템 구매 성공" << std::endl;
		mPlayer->AddItemToInventory(*boughtItem);
		std::cout << "구매한 아이템 - " << boughtItem->GetName() << std::endl;

		mGold -= boughtItem->GetPrice();

		std::cout << "남은 금액 : " << mGold << "골드" << std::endl;
	}
	std::cout << "아이템 구매 불가" << std::endl;
		
}

void Game::EquipItemToPlayer(const int num)
{
	mPlayer->EquipItem(num);
}

void Game::DisplayPlayerStatus()
{
	mPlayer->ShowStatus();
}
