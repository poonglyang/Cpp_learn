#pragma once
#include<iostream>
#include "ItemData.h"
#include <vector>

using namespace itemDatas;
using namespace std;

class ItemBase
{
private:
#pragma region 아이템 베이스 관련 변수
	/// <summary>
	/// 아이템의 id
	/// </summary>
	int id;

	/// <summary>
	/// 아이템의 이름
	/// </summary>
	string name;

	/// <summary>
	/// 아이템 수량
	/// </summary>
	int count;

	/// <summary>
	/// 아이템 최대 수량
	/// </summary>
	int maxCount;

	/// <summary>
	/// 아이템 가격
	/// </summary>
	int price;

	/// <summary>
	/// 아이템 타입
	/// </summary>
	int itemType;

	/// <summary>
	/// 아이템 설명
	/// </summary>
	string explain;

#pragma endregion


public:
	
	/// <summary>
	/// 아이템 생성자
	/// </summary>
	/// <param name="id">이 아이템의 id</param>
	/// <param name="name">이 아이템의 이름</param>
	/// <param name="count">이 아이템의 갯수, 기본값 1</param>
	/// <param name="maxCount">이 아이템의 최대 크기</param>
	ItemBase(int id, const string& name, int count, int maxCount, int price, int itemType, const string& explain);

	virtual ~ItemBase();

	/// <summary>
	/// 아이템의 id를 반환하는 함수
	/// </summary>
	/// <returns>아이템의 id 값</returns>
	int GetItemId();

	/// <summary>
	/// 아이템의 이름을 반환하는 함수
	/// </summary>
	/// <returns>아이템 이름</returns>
	string GetItemName();

	/// <summary>
	/// 아이템의 갯수를 반환하는 함수
	/// </summary>
	/// <returns>아이템의 갯수</returns>
	int GetItemCount();

	/// <summary>
	/// 아이템 갯수를 증감하는 함수
	/// 아이템 증감 + 현재 아이템 < 아이템 최대 수량이면
	/// 아이템 증감 + 현재 아이템 - 아이템 최대 수량 반환
	/// </summary>
	/// <returns>아이템 초과분</returns>
	virtual int SetItemCount(int delta);

	/// <summary>
	/// 아이템의 최대 중첩 갯수를 반환하는 함수
	/// </summary>
	/// <returns>아이템 최대 중첩 갯수</returns>
	int GetItemMaxCount();

	/// <summary>
	/// 아이템의 가격을 반환하는 함수
	/// 만약 0 이외의 수가 반환 된 경우
	/// 같은 아이템인데 반환된 수 만큼 count가 있는 아이템을 만들어야한다
	/// </summary>
	/// <returns>가격</returns>
	int GetPrice();

	/// <summary>
	/// 아이템의 타입을 반환하는 함수
	/// </summary>
	/// <returns>아이템 타입</returns>
	int GetItemType();

	/// <summary>
	/// 아이템의 설명을 반환하는 함수
	/// </summary>
	/// <returns>아이템 설명 string</returns>
	string GetItemExplain();

	/// <summary>
	/// 아이템 정보를 출력하는 함수
	/// </summary>
	virtual void PrintItemInfo();
};

