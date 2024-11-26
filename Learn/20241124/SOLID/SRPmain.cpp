/*
S(Single Responsibility Princple SRP, ���� å�� ��Ģ)
	��Ŭ���� ���� �ϳ��� å�Ӹ� ������ �Ѵ�
	å���� ������ ������ �ǹ�
	� ������ �߻��� �Ǿ��ٸ� �ش� Ŭ������ �����ؾ� �ϴ� ������ ���� �ϳ��̴�.
	�ϳ��� Ŭ������ ����� �ϳ��� ��ɸ� �����ϵ��� �����ؾ� ��
*/

class Unit {

private:
	int Atk;
	int Def;
	int Hit;
	int Avoid;

public:
	void Attack();
	void Interaction_Buy();
	void Interaction_Sell();
};

class Status {
protected:
	int atk;
	int def;
	int hit;
	int avoid;

public:
	int GetAtk();
	void SetAtk();
	int GetAtk();
	void SetAvoid();
};

class Battle {
public:
	void Attack(Unit attacker, Unit target);
};

class Interaction {
public:
	void Buy();
};