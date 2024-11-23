#pragma once
#include <iostream>
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
	vector<Item_Equipable> equipable_Items;
	vector<Item_Consumables> consumables_Items;
	vector<Item_Material> material_Items;

	ItemBase* fuck;
public:
	/// <summary>
	/// 아이템 매니저의 생성자
	/// 여기서 이 콘솔에 들어갈 모든 아이템을 생성한다
	/// 언리얼로 들어가면 스크립터블 오브젝트로 만들 예정
	/// </summary>
	ItemManager();


	template<typename T>
#if __cplusplus >= 202002L	// C++ 20 이후에만 있으므로
		requires std::is_base_of<ItemBase, T>::value	// T가 ItemBase이거나 상속 받은 것이여야 함을 말함
#endif
	T GetItem(int id, int count);
};

