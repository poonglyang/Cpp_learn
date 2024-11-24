#pragma once
#include <iostream>
#include <vector>

using namespace std;

class IState
{
protected:
#pragma region 플레이어 스탯
	/// <summary>
	/// hp
	/// </summary>
	float hp;

	/// <summary>
	/// 최대 Hp
	/// </summary>
	float maxHp;

	/// <summary>
	/// mp
	/// </summary>
	float mp;

	/// <summary>
	/// 최대 Mp
	/// </summary>
	float maxMp;

	/// <summary>
	/// 공격력
	/// </summary>
	float atk;

	/// <summary>
	/// 크리티컬 확률
	/// </summary>
	float critialProbability;

	/// <summary>
	/// 크리티컬 데미지 배율
	/// </summary>
	float critialDamage;

	/// <summary>
	/// 방어력 무시 %
	/// </summary>
	float defIgnore;
	
	/// <summary>
	/// 방어력
	/// </summary>
	float def;

	/// <summary>
	/// 명중률
	/// </summary>
	float hit;

	/// <summary>
	/// 회피률
	/// </summary>
	float avoid;

	/// <summary>
	/// 방패 막기 확률
	/// </summary>
	float defenseProbability;

	/// <summary>
	/// 행동력
	/// </summary>
	float behaviorSpeed;

	/// <summary>
	/// 살았는지 죽었는지 확인하는 변수
	/// </summary>
	bool isAlive;
#pragma endregion
public:

	/// <summary>
	/// 생성자
	/// </summary>
	/// <param name="hp">hp</param>
	/// <param name="maxHp">최대 hp</param>
	/// <param name="mp">mp</param>
	/// <param name="maxMp">최대 mp</param>
	/// <param name="atk">공격력</param>
	/// <param name="critialProbability">크리티컬 확률</param>
	/// <param name="critialDamage">크리티컬 데미지 배율</param>
	/// <param name="defIgnore">방어력 무시</param>
	/// <param name="def">방어력</param>
	/// <param name="hit">명중률</param>
	/// <param name="avoid">회피률</param>
	/// <param name="defenseProbability">방패 막기 확률</param>
	/// <param name="behaviorSpeed">행동력</param>
	IState(float hp, float maxHp, float mp, float maxMp, float atk, 
		float critialProbability, float critialDamage, float defIgnore, float def, float hit,
		float avoid, float defenseProbability, float behaviorSpeed);

	/// <summary>
	/// 플레이어가 죽었을 때 실행되는 함수
	/// </summary>
	virtual void Die();

	/// <summary>
	/// hp값을 반환하는 함수
	/// </summary>
	/// <returns>hp값</returns>
	float GetHp() const;

	/// <summary>
	/// hp값을 바꾸는 함수
	/// </summary>
	/// <param name="delta">증감 또는 대입 값</param>
	/// <param name="isAdd">true면 증감, false면 대입</param>
	virtual void SetHp(float delta, bool isAdd);

	/// <summary>
	/// 최대 hp를 반환하는 함수
	/// </summary>
	/// <returns>최대 hp값</returns>
	float GetMaxHp() const;

	/// <summary>
	/// 최대 hp값을 바꾸는 함수
	/// </summary>
	/// <param name="delta">증감 또는 대입 값</param>
	/// <param name="isAdd">true면 증감, false면 대입</param>
	virtual void SetMaxHp(float delta, bool isAdd);

	/// <summary>
	/// mp값을 반환하는 함수
	/// </summary>
	/// <returns>mp값</returns>
	float GetMp() const;

	/// <summary>
	/// mp값을 바꾸는 함수
	/// </summary>
	/// <param name="delta">증감 또는 대입 값</param>
	/// <param name="isAdd">true면 증감, false면 대입</param>
	virtual void SetMp(float delta, bool isAdd);

	/// <summary>
	/// 최대 mp값을 바꾸는 함수
	/// </summary>
	/// <returns></returns>
	float GetMaxMp() const;

	/// <summary>
	/// 최대 mp값을 바꾸는 함수
	/// </summary>
	/// <param name="delta">증감 또는 대입 값</param>
	/// <param name="isAdd">true면 증감, false면 대입</param>
	virtual void SetMaxMp(float delta, bool isAdd);

	/// <summary>
	/// Atk값을 반환하는 함수
	/// </summary>
	/// <returns>Atk 값</returns>
	float GetAtk() const;

	/// <summary>
	/// atk 값을 바꾸는 함수
	/// </summary>
	/// <param name="delta">증감 또는 대입 값</param>
	/// <param name="isAdd">true면 증감, false면 대입</param>
	virtual void SetAtk(float delta, bool isAdd);

	/// <summary>
	/// 크리티컬 확률 값을 반환하는 함수
	/// </summary>
	/// <returns>크리티컬 확률</returns>
	float GetCritialProbability() const;

	/// <summary>
	/// 크리티컬 확률 값을 바꾸는 함수
	/// </summary>
	/// <param name="delta">증감 또는 대입 값</param>
	/// <param name="isAdd">true면 증감, false면 대입</param>
	virtual void SetCritialProbability(float delta, bool isAdd);

	/// <summary>
	/// 크리티컬 데미지 배율 값을 반환하는 함수
	/// </summary>
	/// <returns>크리티컬 데미지 배율</returns>
	float GetCritialDamage() const;

	/// <summary>
	/// 크리티컬 데미지 배율 값을 바꾸는 함수
	/// </summary>
	/// <param name="delta">증감 또는 대입 값</param>
	/// <param name="isAdd">true면 증감, false면 대입</param>
	virtual void SetCritialDamage(float delta, bool isAdd);

	/// <summary>
	/// 방어력 무시(방어력 관통) 값을 반환 하는 함수
	/// </summary>
	/// <returns>방어력 무시 값(방어력 관통)</returns>
	float GetDefIgnore() const;

	/// <summary>
	/// 방어력 무시(방어력 관통) 값을 바꾸는 함수
	/// </summary>
	/// <param name="delta">증감 또는 대입 값</param>
	/// <param name="isAdd">true면 증감, false면 대입</param>
	virtual void SetDefIgnore(float delta, bool isAdd);

	/// <summary>
	/// 방어력을 반환하는 함수
	/// </summary>
	/// <returns>방어력 값</returns>
	float GetDef() const;

	/// <summary>
	/// 방어력 무시(방어력 관통) 값을 바꾸는 함수
	/// </summary>
	/// <param name="delta">증감 또는 대입 값</param>
	/// <param name="isAdd">true면 증감, false면 대입</param>
	virtual void SetDef(float delta, bool isAdd);

	/// <summary>
	/// 명중률을 반환하는 함수
	/// </summary>
	/// <returns>명중률</returns>
	float GetHit() const;

	/// <summary>
	/// 명중률 값을 바꾸는 함수
	/// </summary>
	/// <param name="delta">증감 또는 대입 값</param>
	/// <param name="isAdd">true면 증감, false면 대입</param>
	virtual void SetHit(float delta, bool isAdd);

	/// <summary>
	/// 회피률을 반환하는 함수
	/// </summary>
	/// <returns>회피률</returns>
	float GetAvoid() const;

	/// <summary>
	/// 회피률 값을 바꾸는 함수
	/// </summary>
	/// <param name="delta">증감 또는 대입 값</param>
	/// <param name="isAdd">true면 증감, false면 대입</param>
	virtual void SetAvoid(float delta, bool isAdd);

	/// <summary>
	/// 방패 막기 확률을 반환하는 함수
	/// </summary>
	/// <returns>방패 막기 확률 값</returns>
	float GetDefenseProbability() const;

	/// <summary>
	/// 방패 막기 확률 값을 바꾸는 함수
	/// </summary>
	/// <param name="delta">증감 또는 대입 값</param>
	/// <param name="isAdd">true면 증감, false면 대입</param>
	virtual void SetDefenseProbability(float delta, bool isAdd);

	/// <summary>
	/// 행동력을 반환하는 함수
	/// </summary>
	/// <returns>행동력</returns>
	float GetBehaviorSpeed() const;

	/// <summary>
	/// 행동력 값을 바꾸는 함수
	/// </summary>
	/// <param name="delta">증감 또는 대입 값</param>
	/// <param name="isAdd">true면 증감, false면 대입</param>
	virtual void SetBehaviorSpeed(float delta, bool isAdd);

	void SetAllState(vector<float> state, bool isEquip);

	/// <summary>
	/// 살아있는지 여부를 반환하는 함수
	/// </summary>
	/// <returns></returns>
	bool GetIsAlive() const;

	void PrintState();
};

