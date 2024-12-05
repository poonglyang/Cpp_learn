#pragma once
#include <vector>
#include "Item_Equipable.h"
#include "Item_Consumables.h"
#include "Item_Material.h"

/// <summary>
/// 모든 아이템의 정보를 가지고 있는 클래스
/// 아이템을 추가할 경우 이 클래스에서 id에 맞는 것을 깊은복사해 가져온다
/// 플레이가 시작될 시 반드시 가지고 있는다.
/// 장비만이 기존 세이브 파일을 통해 새로 추가할 수 있다.
/// </summary>
class ItemManager
{
private:
	/// <summary>
	/// 장비류 아이템이 들어있는 백터
	/// </summary>
	std::vector<Item_Equipable> equipable_Items;

	/// <summary>
	/// 소비류 아이템이 들어있는 백터
	/// </summary>
	std::vector<Item_Consumables> consumables_Items;

	/// <summary>
	/// 재료 아이템이 들어있는 백터
	/// </summary>
	std::vector<Item_Material> material_Items;

	/// <summary>
	/// 절대 반환되면 안되는 아이템
	/// </summary>
	ItemBase* fuck;
public:
	/// <summary>
	/// 아이템 매니저의 생성자
	/// 여기서 이 콘솔에 들어갈 모든 아이템을 생성한다
	/// 언리얼로 들어가면 스크립터블 오브젝트로 만들 예정
	/// </summary>
	ItemManager();

	/// <summary>
	/// id를 바탕으로 id에 해당하는 아이템의 최대 중첩 갯수를 반환하는 함수
	/// </summary>
	/// <param name="id">아이템 id</param>
	/// <returns>최대 갯수</returns>
	int GetItemMaxCountById(int id);

	///// <summary>
	///// 아이템에 맞는 것을 돌려주는 함수
	///// 당근 빠따로 깊은 복사된 것이 돌려받아진다
	///// </summary>
	///// <typeparam name="T">ItemBase, Item_Equipable, Item_Consumables, Item_Material 중 하나</typeparam>
	///// <param name="id">아이템 id</param>
	///// <param name="count">갯수</param>
	///// <returns></returns>
	//template<typename T>
	//#if __cplusplus >= 202002L
	//requires std::is_base_of<ItemBase, T>::value
	//#endif
	//T GetItem(int id, int count)
	//{
	//	int itemType = id / 100000;
	//	int index = id - itemType * 100000 - 1;

	//	if (id < 100000) {
	//		T deepCopyItem = T(equipable_Items[index]);
	//		return deepCopyItem;
	//	}
	//	else if (id < 200000) {
	//		T deepCopyItem = T(consumables_Items[index]);
	//		deepCopyItem.SetItemCount(count, false);
	//		return deepCopyItem;
	//	}
	//	else if (id < 300000) {
	//		T deepCopyItem = T(material_Items[index]);
	//		deepCopyItem.SetItemCount(count, false);
	//		return deepCopyItem;
	//	}
	//	else {
	//		//제발 이거 출력되면 ㅈ됨
	//		return fuck;
	//	}
	//}
	
	Item_Equipable* GetEquipableItemByIndex(int index);

	Item_Equipable* GetEquipableItem(int id);

	Item_Consumables* GetConsumableItemByIndex(int index, int count);

	Item_Consumables* GetConsumableItem(int id, int count);

	Item_Material* GetMaterialItem(int id, int count);


	int GetEquipVectorSize();
	int GetConsumableVectorSize();
};

