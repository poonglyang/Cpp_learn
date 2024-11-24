#pragma once
#include <iostream>
#include <vector>

using namespace std;

class IState
{
protected:
#pragma region �÷��̾� ����
	/// <summary>
	/// hp
	/// </summary>
	float hp;

	/// <summary>
	/// �ִ� Hp
	/// </summary>
	float maxHp;

	/// <summary>
	/// mp
	/// </summary>
	float mp;

	/// <summary>
	/// �ִ� Mp
	/// </summary>
	float maxMp;

	/// <summary>
	/// ���ݷ�
	/// </summary>
	float atk;

	/// <summary>
	/// ũ��Ƽ�� Ȯ��
	/// </summary>
	float critialProbability;

	/// <summary>
	/// ũ��Ƽ�� ������ ����
	/// </summary>
	float critialDamage;

	/// <summary>
	/// ���� ���� %
	/// </summary>
	float defIgnore;
	
	/// <summary>
	/// ����
	/// </summary>
	float def;

	/// <summary>
	/// ���߷�
	/// </summary>
	float hit;

	/// <summary>
	/// ȸ�Ƿ�
	/// </summary>
	float avoid;

	/// <summary>
	/// ���� ���� Ȯ��
	/// </summary>
	float defenseProbability;

	/// <summary>
	/// �ൿ��
	/// </summary>
	float behaviorSpeed;

	/// <summary>
	/// ��Ҵ��� �׾����� Ȯ���ϴ� ����
	/// </summary>
	bool isAlive;
#pragma endregion
public:

	/// <summary>
	/// ������
	/// </summary>
	/// <param name="hp">hp</param>
	/// <param name="maxHp">�ִ� hp</param>
	/// <param name="mp">mp</param>
	/// <param name="maxMp">�ִ� mp</param>
	/// <param name="atk">���ݷ�</param>
	/// <param name="critialProbability">ũ��Ƽ�� Ȯ��</param>
	/// <param name="critialDamage">ũ��Ƽ�� ������ ����</param>
	/// <param name="defIgnore">���� ����</param>
	/// <param name="def">����</param>
	/// <param name="hit">���߷�</param>
	/// <param name="avoid">ȸ�Ƿ�</param>
	/// <param name="defenseProbability">���� ���� Ȯ��</param>
	/// <param name="behaviorSpeed">�ൿ��</param>
	IState(float hp, float maxHp, float mp, float maxMp, float atk, 
		float critialProbability, float critialDamage, float defIgnore, float def, float hit,
		float avoid, float defenseProbability, float behaviorSpeed);

	/// <summary>
	/// �÷��̾ �׾��� �� ����Ǵ� �Լ�
	/// </summary>
	virtual void Die();

	/// <summary>
	/// hp���� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>hp��</returns>
	float GetHp() const;

	/// <summary>
	/// hp���� �ٲٴ� �Լ�
	/// </summary>
	/// <param name="delta">���� �Ǵ� ���� ��</param>
	/// <param name="isAdd">true�� ����, false�� ����</param>
	virtual void SetHp(float delta, bool isAdd);

	/// <summary>
	/// �ִ� hp�� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>�ִ� hp��</returns>
	float GetMaxHp() const;

	/// <summary>
	/// �ִ� hp���� �ٲٴ� �Լ�
	/// </summary>
	/// <param name="delta">���� �Ǵ� ���� ��</param>
	/// <param name="isAdd">true�� ����, false�� ����</param>
	virtual void SetMaxHp(float delta, bool isAdd);

	/// <summary>
	/// mp���� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>mp��</returns>
	float GetMp() const;

	/// <summary>
	/// mp���� �ٲٴ� �Լ�
	/// </summary>
	/// <param name="delta">���� �Ǵ� ���� ��</param>
	/// <param name="isAdd">true�� ����, false�� ����</param>
	virtual void SetMp(float delta, bool isAdd);

	/// <summary>
	/// �ִ� mp���� �ٲٴ� �Լ�
	/// </summary>
	/// <returns></returns>
	float GetMaxMp() const;

	/// <summary>
	/// �ִ� mp���� �ٲٴ� �Լ�
	/// </summary>
	/// <param name="delta">���� �Ǵ� ���� ��</param>
	/// <param name="isAdd">true�� ����, false�� ����</param>
	virtual void SetMaxMp(float delta, bool isAdd);

	/// <summary>
	/// Atk���� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>Atk ��</returns>
	float GetAtk() const;

	/// <summary>
	/// atk ���� �ٲٴ� �Լ�
	/// </summary>
	/// <param name="delta">���� �Ǵ� ���� ��</param>
	/// <param name="isAdd">true�� ����, false�� ����</param>
	virtual void SetAtk(float delta, bool isAdd);

	/// <summary>
	/// ũ��Ƽ�� Ȯ�� ���� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>ũ��Ƽ�� Ȯ��</returns>
	float GetCritialProbability() const;

	/// <summary>
	/// ũ��Ƽ�� Ȯ�� ���� �ٲٴ� �Լ�
	/// </summary>
	/// <param name="delta">���� �Ǵ� ���� ��</param>
	/// <param name="isAdd">true�� ����, false�� ����</param>
	virtual void SetCritialProbability(float delta, bool isAdd);

	/// <summary>
	/// ũ��Ƽ�� ������ ���� ���� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>ũ��Ƽ�� ������ ����</returns>
	float GetCritialDamage() const;

	/// <summary>
	/// ũ��Ƽ�� ������ ���� ���� �ٲٴ� �Լ�
	/// </summary>
	/// <param name="delta">���� �Ǵ� ���� ��</param>
	/// <param name="isAdd">true�� ����, false�� ����</param>
	virtual void SetCritialDamage(float delta, bool isAdd);

	/// <summary>
	/// ���� ����(���� ����) ���� ��ȯ �ϴ� �Լ�
	/// </summary>
	/// <returns>���� ���� ��(���� ����)</returns>
	float GetDefIgnore() const;

	/// <summary>
	/// ���� ����(���� ����) ���� �ٲٴ� �Լ�
	/// </summary>
	/// <param name="delta">���� �Ǵ� ���� ��</param>
	/// <param name="isAdd">true�� ����, false�� ����</param>
	virtual void SetDefIgnore(float delta, bool isAdd);

	/// <summary>
	/// ������ ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>���� ��</returns>
	float GetDef() const;

	/// <summary>
	/// ���� ����(���� ����) ���� �ٲٴ� �Լ�
	/// </summary>
	/// <param name="delta">���� �Ǵ� ���� ��</param>
	/// <param name="isAdd">true�� ����, false�� ����</param>
	virtual void SetDef(float delta, bool isAdd);

	/// <summary>
	/// ���߷��� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>���߷�</returns>
	float GetHit() const;

	/// <summary>
	/// ���߷� ���� �ٲٴ� �Լ�
	/// </summary>
	/// <param name="delta">���� �Ǵ� ���� ��</param>
	/// <param name="isAdd">true�� ����, false�� ����</param>
	virtual void SetHit(float delta, bool isAdd);

	/// <summary>
	/// ȸ�Ƿ��� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>ȸ�Ƿ�</returns>
	float GetAvoid() const;

	/// <summary>
	/// ȸ�Ƿ� ���� �ٲٴ� �Լ�
	/// </summary>
	/// <param name="delta">���� �Ǵ� ���� ��</param>
	/// <param name="isAdd">true�� ����, false�� ����</param>
	virtual void SetAvoid(float delta, bool isAdd);

	/// <summary>
	/// ���� ���� Ȯ���� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>���� ���� Ȯ�� ��</returns>
	float GetDefenseProbability() const;

	/// <summary>
	/// ���� ���� Ȯ�� ���� �ٲٴ� �Լ�
	/// </summary>
	/// <param name="delta">���� �Ǵ� ���� ��</param>
	/// <param name="isAdd">true�� ����, false�� ����</param>
	virtual void SetDefenseProbability(float delta, bool isAdd);

	/// <summary>
	/// �ൿ���� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>�ൿ��</returns>
	float GetBehaviorSpeed() const;

	/// <summary>
	/// �ൿ�� ���� �ٲٴ� �Լ�
	/// </summary>
	/// <param name="delta">���� �Ǵ� ���� ��</param>
	/// <param name="isAdd">true�� ����, false�� ����</param>
	virtual void SetBehaviorSpeed(float delta, bool isAdd);

	void SetAllState(vector<float> state, bool isEquip);

	/// <summary>
	/// ����ִ��� ���θ� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns></returns>
	bool GetIsAlive() const;

	void PrintState();
};

