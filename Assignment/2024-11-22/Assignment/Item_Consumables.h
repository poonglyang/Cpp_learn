#pragma once
#include "ItemBase.h"
#include<iostream>

using namespace std;
using namespace itemDatas;

class Item_Consumables : public ItemBase
{
protected:
	int toCopy;

public:
	/// <summary>
	/// 생성자
	/// </summary>
	/// <param name="id">아이템 id</param>
	/// <param name="name">아이템 이름</param>
	/// <param name="count">아이탬 갯수</param>
	/// <param name="maxCount">아이템 최대 크기</param>
	/// <param name="price">아이템 가격</param>
	/// <param name="itemType">아이템 타입</param>
	/// <param name="explain">아이템 설명</param>
	Item_Consumables(int id, const string& name, int count, int maxCount, int price, int itemType, const string& explain);

	Item_Consumables(const Item_Consumables& other);


	/// <summary>
	/// 사용할 때 적용될 효과인데 이거는 나중에 내가 알아서 구현하겠지
	/// 에초에 과제 내용에는 이런거 없잖아
	/// </summary>
	void OnUse();

	void PrintItemInfo() override;
};

