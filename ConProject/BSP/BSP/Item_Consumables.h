#pragma once
#include "ItemBase.h"

using namespace itemDatas;

class Item_Consumables : public ItemBase
{
protected:
	int toCopy;

	float hpHeal;

	float addMaxHp;

	float mpHeal;

	float addMaxMp;

	float addAtk;

	float addDef;

	float addCritialProbability;

	float critialDamage;

	float defIgnore;

	float hit;

	float avoid;

	float defenseProbability;

	float behaviorSpeed;

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
	Item_Consumables(int id, const std::string& name, int count, int maxCount, int price, int itemType, const std::string& explain,
		float hpHeal, float addMaxHp,float  mpHeal, float addMaxMp, float addAtk, float addDef, 
		float addCritialProbability, float critialDamage, float defIgnore, float hit, float avoid, float defenseProbability, float behaviorSpeed);

	Item_Consumables(const Item_Consumables& other);


	/// <summary>
	/// 사용할 때 적용될 효과인데 이거는 나중에 내가 알아서 구현하겠지
	/// 에초에 과제 내용에는 이런거 없잖아
	/// </summary>
	void OnUse();

	/// <summary>
	/// 포션이 회복하는 양을 가져오는 함수
	/// </summary>
	/// <returns>회복량이 들어있는 백터</returns>
	std::vector<float> GetConsumableState();

	void PrintItemInfo() override;
};

