#pragma once
#include <iostream>
#include "IState.h"
#include "Inventory.h"

using namespace std;
using namespace itemDatas;

class Player : public IState
{
protected:

#pragma region 장비 장착
	/// <summary>
	/// 플레이어 오른손 장비
	/// </summary>
	Item_Equipable* rightHand;

	/// <summary>
	/// 플레이어 왼손 장비
	/// </summary>
	Item_Equipable* leftHand;

	/// <summary>
	/// 플레이어 헬멧
	/// </summary>
	Item_Equipable* helmet;

	/// <summary>
	/// 플레이어 상의
	/// </summary>
	Item_Equipable* armor_Top;

	/// <summary>
	/// 플레이어 하의
	/// </summary>
	Item_Equipable* armor_Bottom;

	/// <summary>
	/// 플레이어 장갑
	/// </summary>
	Item_Equipable* gloves;

	/// <summary>
	/// 플레이어 신발
	/// </summary>
	Item_Equipable* boots;

	/// <summary>
	/// 플레이어 반지
	/// </summary>
	Item_Equipable* ring;

	/// <summary>
	/// 플레이어 목걸이
	/// </summary>
	Item_Equipable* necklace;

	/// <summary>
	/// 플레이어 벨트
	/// </summary>
	Item_Equipable* belt;

	/// <summary>
	/// 플레이어 팔찌
	/// </summary>
	Item_Equipable* bracelet;
#pragma endregion

	void Equip(Item_Equipable*& slot, Item_Equipable* item);

	void Dequip(Item_Equipable*& slot);

public:
	/// <summary>
	/// 플레이어 인벤토리
	/// </summary>
	Inventory* inventory;

	Player(float hp, float maxHp, float mp, float maxMp, float atk,
		float critialProbability, float critialDamage, float defIgnore, float def, float hit,
		float avoid, float defenseProbability, float behaviorSpeed, ItemManager& itemManager);

	/// <summary>
	/// 플레이어의 오른손 장비를 반환하는 함수
	/// </summary>
	/// <returns>오른손 장비</returns>
	Item_Equipable* GetPlayerRightHand() const;

	void Dequip(int slot);

	void EquipSelect(int index);

	void PrintPlayerInfo();

	void PrintEquip();
};

