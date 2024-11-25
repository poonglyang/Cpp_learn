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
	/// �κ��丮 Ŭ�������� �Լ��� ��������
	/// </summary>
	/// <param name="itemNum"></param>
	/// <param name="gold"></param>
	void SellItem(const int itemNum, int& gold);

	/// <summary>
	/// �κ��丮 Ŭ�������� �������� ��������
	/// </summary>
	/// <param name="num"></param>
	void EquipItem(const int num);

	/// <summary>
	/// �κ��丮���� ��������
	/// </summary>
	void AddItemToInventory(const Item& item);

	/// <summary>
	/// �κ��丮���� ��������
	/// </summary>
	void ShowInventory() const;
};

