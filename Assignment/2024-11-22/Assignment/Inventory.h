#pragma once
#include <iostream>
#include <vector>
#include "ItemBase.h"
#include "ItemData.h"
#include "ItemManager.h"
#include "Item_Equipable.h"
#include "Item_Consumables.h"
#include "Item_Material.h"

using namespace itemDatas;
using namespace std;

class Inventory
{
protected:
	/// <summary>
	/// 장비류가 들어가는 인벤토리 백터
	/// </summary>
	vector<ItemBase*> equipable;

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
	vector<ItemBase*> consumables;

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
	vector<ItemBase*> materials;

	/// <summary>
	/// 재료 아이템 인벤토리에 차 있는 아이템의 갯수
	/// </summary>
	int materials_CurrentInventoryCount;

	/// <summary>
	/// 재료 아이템 인벤토리 최대 공간
	/// </summary>
	int materials_MaxInventoryCapacity;

	/// <summary>
	/// 돈
	/// </summary>
	int money;

	/// <summary>
	/// 아이템 메니저
	/// </summary>
	ItemManager itemManager;

	int GetItemTypeById(int id);
public:
	/// <summary>
	/// 인벤토리 생성자
	/// </summary>
	/// <param name="equipable_MaxInventoryCapacity"></param>
	/// <param name="consumables_MaxInventoryCapacity"></param>
	/// <param name="materials_MaxInventoryCapacity"></param>
	Inventory(int equipable_MaxInventoryCapacity, 
		int consumables_MaxInventoryCapacity, 
		int materials_MaxInventoryCapacity,
		ItemManager& itemManager);

	/// <summary>
	/// 특정 아이템이 있는지 반환하는 함수
	/// </summary>
	/// <param name="id">아이템 id</param>
	/// <returns>없으면 0, 있으면 아이템의 갯수를 반환한다</returns>
	int CountItem(int id);


	/// <summary>
	/// 무기 아이템만 이걸로 받을 수 있음 제발
	/// </summary>
	/// <param name="weaponItme">무기 아이템 객체</param>
	/// <returns>획득 성공일경우 true, 실패일 경우 false</returns>
	bool PushItem(ItemBase* weaponItme);

	/// <summary>
	/// 인벤토리에서 같은 아이템이 있는지 확인하고 있을 경우 추가하고 
	/// 남은 갯수를 반환한다 하는 함수
	/// </summary>
	/// <param name="id">아이템 id</param>
	/// <param name="count">추가할 갯수</param>
	/// <returns>남은 갯수</returns>
	template<typename T>
	int AddItemAndReturnRemaining(int id, int count, vector<T> inventory);

	/// <summary>
	/// 인벤토리에 아이템을 집어 넣는 함수
	/// 장비, 잡탬 일경우만 가능하다
	/// </summary>
	/// <param name="item">넣을 아이템</param>
	int PushItem(int id, int count);

	/// <summary>
	/// 장비만 해당됨
	/// index에 해당하는 것을 인벤토리에서 삭제하고 반환한다
	/// </summary>
	/// <param name="id">꺼낼 아이템 id</param>
	/// <returns>id에 해당하는 아이템</returns>
	ItemBase* PopItem(int index);

	/// <summary>
	/// id에 해당하는 아이템을 꺼내는 함수
	/// 솔직히 꺼낸다기보다는 없에고 소모품과 재료탬은 존재 자체가 정해져 있으니
	/// 이거 후 해당하는 것 만큼 생성해주자
	/// 에초에 count를 이전에 검사해서 넣을거긴함
	/// </summary>
	/// <param name="id">꺼낼 아이템 id</param>
	/// <returns>id에 해당하는 아이템</returns>
	void PopItem(int id, int count);

	/// <summary>
	/// 장비칸이 가득 찼는지 확인하는 함수
	/// </summary>
	/// <returns>가득 차있으면 true 아니면 false</returns>
	bool isEquipableFull();

	/// <summary>
	/// 장비를 벗을 수 있는지 확인하는 함수
	/// </summary>
	/// <returns>true면 벗을 수 있음, false면 벗을 수 없음</returns>
	bool isCanDequip();

	/// <summary>
	/// 소비칸이 가득 찼는지 확인하는 함수
	/// </summary>
	/// <returns>가득 차있으면 true 아니면 false</returns>
	bool isConsumablesFull();

	/// <summary>
	/// 재료칸이 가득 차있는지 확인하는 함수
	/// </summary>
	/// <returns>가득 차있으면 true 아니면 false</returns>
	bool isMaterialFull();

	/// <summary>
	/// 소지금을 반환하는 함수
	/// </summary>
	/// <returns>소지금</returns>
	int GetMoney();

	/// <summary>
	/// 소지금을 설정하는 함수
	/// </summary>
	/// <param name="delta"></param>
	/// <param name="isAdd"></param>
	void SetMoney(int delta, bool isAdd);

	/// <summary>
	/// 인벤토리 사이즈 구하기
	/// </summary>
	/// <returns></returns>
	int GetEquipableInventorySize();

	/// <summary>
	/// 인벤토리 사이즈 구하기
	/// </summary>
	/// <returns></returns>
	int GetConsumableInventorySize();

	/// <summary>
	/// 인벤토리 사이즈 구하기
	/// </summary>
	/// <returns></returns>
	int GetMaterialInventorySize();

	/// <summary>
	/// 인덱스를 기반으로 장비 인벤토리의 아이템의 id를 받는 함수
	/// </summary>
	/// <returns></returns>
	int GetEquipableInventoryItemIdByIndex(int index);

	/// <summary>
	/// 인덱스로 장비 아이템 가격 알아내기
	/// </summary>
	/// <param name="index">인덱스</param>
	/// <returns>인덱스에 해당하는 가격</returns>
	int GetEquipableInventoryItemPriceByIndex(int index);

	/// <summary>
	/// 인덱스를 기반으로 소비 인벤토리의 아이템의 id를 받는 함수
	/// </summary>
	/// <returns></returns>
	int GetConsumableInventoryItemIdByIndex(int index);

	/// <summary>
	/// 인덱스로 가격 알아내기
	/// </summary>
	/// <param name="index">인덱스</param>
	/// <returns>인덱스에 해당하는 가격</returns>
	int GetConsumableInventoryItemPriceByIndex(int index);

	/// <summary>
	/// 인덱스를 기반으로 소비 인벤토리의 아이템의 id를 받는 함수
	/// </summary>
	/// <returns></returns>
	int GetMaterialsInventoryItemIdByIndex(int index);


	/// <summary>
	/// 인덱스로 가격 알아내기
	/// </summary>
	/// <param name="index">인덱스</param>
	/// <returns>인덱스에 해당하는 가격</returns>
	int GetMaterialsInventoryItemPriceByIndex(int index);

	/// <summary>
	/// 장비칸 출력
	/// </summary>
	void PrintEquipableInventory();

	/// <summary>
	/// 소비칸 출력
	/// </summary>
	void PrintConsumableInventory();

	/// <summary>
	/// 재료칸 출력
	/// </summary>
	void PrintMaterialInventory();
};

