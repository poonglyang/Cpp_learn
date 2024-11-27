/*
S(Single Responsibility Princple SRP, 단일 책임 원칙)
	한클래스 내에 하나의 책임만 가져야 한다
	책임은 변경의 이유를 의미
	어떤 변경이 발생이 되었다면 해당 클래스의 변경해야 하는 이유는 오직 하나이다.
	하나의 클래스나 모듈이 하나의 기능만 수행하도록 설계해야 함
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