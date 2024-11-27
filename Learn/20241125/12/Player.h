#pragma once
#include <iostream>
#include "Unit.h"
#include "Inventory.h"

class Player : public Unit
{

private:
	Inventory mInventory;


public:
	Player();
	~Player();

	void InitPlayer();
		
	void ShowStatus();

	/// <summary>
	/// 인벤토리 클래스에서 함수를 가져오자
	/// </summary>
	/// <param name="itemNum"></param>
	/// <param name="gold"></param>
	void SellItem(const int itemNum, int& gold);

	/// <summary>
	/// 인벤토리 클래스에서 아이템을 가져오자
	/// </summary>
	/// <param name="num"></param>
	void EquipItem(const int num);

	/// <summary>
	/// 인벤토리에서 가져오기
	/// </summary>
	void AddItemToInventory(const Item& item);

	/// <summary>
	/// 인벤토리에서 가져오기
	/// </summary>
	void ShowInventory() const;
};

