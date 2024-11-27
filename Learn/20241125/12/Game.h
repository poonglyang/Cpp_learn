#pragma once
#include <iostream>
#include "Player.h"
#include "Shop.h"
#include "GameEnum.h"
class Game
{
private:
	Shop* mShop;
	Player* mPlayer;
	GameEnums::Location mLocation;
	int mGold;
	int mSelect;

public:
	Game();
	~Game();

	void SetLocation(GameEnums::Location location);

	void StartGame();

	void SetShopPage();

	void SetInventoryPage();

	void SetSellInventorypage();

	void DisplayShopItems(GameEnums::ItemType itemKind);

	void BuyItemFromShop(GameEnums::ItemType itemKind, int num);
	
	void EquipItemToPlayer(const int num);

	void DisplayPlayerStatus();

};

