#pragma once
#include <iostream>
#include <vector>
#include "ItemBase.h";
#include "ItemData.h"

using namespace itemDatas;
using namespace std;

class Inventory
{
protected:
	/// <summary>
	/// 장비류가 들어가는 인벤토리 백터
	/// </summary>
	vector<ItemBase> equipable;

	/// <summary>
	/// 장비류 인벤토리에 차 있는 아이템의 갯수
	/// </summary>
	int equipable_CurrentInventoryCount;

	/// <summary>
	/// 장비류 인벤토리 인벤토리의 최대 용량
	/// </summary>
	int equipable_MaxInventoryCapacity;

	/// <summary>
	/// 소모품류가 들어가는 인벤토리 백터
	/// </summary>
	vector<ItemBase> consumables;

	/// <summary>
	/// 소모품류 인벤토리에 차 있는 아이템의 갯수
	/// </summary>
	int consumables_CurrentInventoryCount;

	/// <summary>
	/// 소모품류 인벤토리 최대 공간
	/// </summary>
	int consumables_MaxInventoryCapacity;

	/// <summary>
	/// 재료(라고 쓰고 잡탬)이 들어가는 인벤토리 백터
	/// </summary>
	vector<ItemBase> materials;

	/// <summary>
	/// 재료 아이템 인벤토리에 차 있는 아이템의 갯수
	/// </summary>
	int materials_CurrentInventoryCount;

	/// <summary>
	/// 재료 아이템 인벤토리 최대 공간
	/// </summary>
	int materials_MaxInventoryCapacity;
public:
	/// <summary>
	/// 생성자
	/// </summary>
	Inventory();

	/// <summary>
	/// 인벤토리에 아이템을 집어 넣는 함수
	/// </summary>
	/// <param name="item">넣을 아이템</param>
	bool PushItem(ItemBase& item);

};

