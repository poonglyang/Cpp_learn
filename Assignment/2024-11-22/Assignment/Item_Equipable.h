#pragma once
#include<iostream>
#include "ItemBase.h"
#include <vector>

using namespace std;
using namespace itemDatas;

class Item_Equipable : public ItemBase
{
private:
#pragma region 장비 아이템 추가 스탯 변수
	/// <summary>
	/// 장착 부위
	/// </summary>
	int equipSlot;

	/// <summary>
	/// 이 장비로 추가되는 hp
	/// </summary>
	float itemState_Hp;

	/// <summary>
	/// 이 장비로 추가되는 mp
	/// </summary>
	float itemState_Mp;

	/// <summary>
	/// 이 장비로 추가되는 공격력
	/// </summary>
	float itemState_Atk;

	/// <summary>
	/// 이 장비로 추가되는 크리티컬 확률
	/// </summary>
	float itemState_CriticalProbability;

	/// <summary>
	/// 이 장비로 추가되는 크리티컬 데미지 배율
	/// </summary>
	float itemState_CriticalDamage;

	/// <summary>
	/// 이 장비로 추가되는 방어력 관통(방어력 무시)
	/// </summary>
	float itemState_DefIgnore;
	
	/// <summary>
	/// 이 장비로 추가되는 방어력
	/// </summary>
	float itemState_Def;

	/// <summary>
	/// 이 장비로 추가되는 명중률
	/// </summary>
	float itemState_Hit;

	/// <summary>
	/// 이 장비로 추가되는 회피률
	/// </summary>
	float itemState_Avoid;

	/// <summary>
	/// 이 장비로 추가되는 방패 막기 확률
	/// </summary>
	float itemState_Defense_Probability;

	/// <summary>
	/// 행동력
	/// </summary>
	float itemState_BehaviorSpeed;

#pragma endregion
public:
	/// <summary>
	/// 장비 아이템 생성자, itemBase 생성자의 갯수, 최대 갯수는 1로 들어간다
	/// </summary>
	/// <param name="id">장비 아이템 id</param>
	/// <param name="name">장비 아이템 이름</param>
	/// <param name="price">장비 아이템 가격</param>
	/// <param name="itemType">장비 아이템 타입</param>
	/// <param name="hp">장착시 올라가는 hp</param>
	/// <param name="mp">장착시 올라가는 mp</param>
	/// <param name="atk">장착시 올라가는 atk</param>
	/// <param name="critialProbability">장착시 올라가는 크확</param>
	/// <param name="critialDamage">장착시 올라가는 크뎀증</param>
	/// <param name="defIgnore">장착시 올라가는 방무</param>
	/// <param name="def">장착시 올라가는 방어력</param>
	/// <param name="hit">장착시 올라가는 명중률</param>
	/// <param name="avoid">장착시 올라가는 회피률</param>
	/// <param name="defenseProbability">장착시 올라가는 방패 막기 확률</param>
	/// <param name="behaviorSpeed">장착시 올라가는 스피드</param>
	Item_Equipable(
		int id, const string& name, int price, int itemType, const string& explain, int equipSlot,
		float hp, float mp, float atk, float critialProbability,
		float critialDamage, float defIgnore, float def, float hit,
		float avoid, float defenseProbability, float behaviorSpeed);

	Item_Equipable(const Item_Equipable& other);

public:
	/// <summary>
	/// 아이템 스탯을 vector 형태로 반환하는 함수
	/// </summary>
	/// <returns>아이템 스텟이 들어있는 vector</returns>
	vector<float> GetItemState();

	/// <summary>
	/// 장착 슬롯을 반환하는 함수
	/// </summary>
	/// <returns>장착 슬롯</returns>
	int GetEquipSlot();

	/// <summary>
	/// 아이템 정보를 출력하는 함수
	/// </summary>
	void PrintItemInfo() override;
};

