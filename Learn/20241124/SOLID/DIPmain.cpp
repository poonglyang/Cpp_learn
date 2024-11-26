/*	
D(Depeondency Inversion Principle, DIP, 의존성 역전 원칙)
	상위 모듈이 하위 모듈에 의존하지 않도록 하고 추상화된 인터페이스에 의존하도록 해야한다는 원칙
	하위 모듈은 상위 모듈의 구현에 의존하면 안된다
	두 모듈이 추상화된 인터페이스를 통해 연결되어야 한다.

	구체적인 구현에 의존하지 않고 추상화에 의존하여 모듈간의 결합도를 줄임.
*/

/*
	상위 = 게임 캐릭터
	하위 - 무기 시스템

*/

#include <iostream>

using namespace std;

class Weapon {
public:
	virtual void Use() const= 0;
};

class Sword : public Weapon{
public:
	void Use() const override {
		cout << "칼휘두르기 " << endl;
	}
};

class Bow : public Weapon {
public:
	void Use() const override {
		cout << "활 쏘기" << endl;
	}
};

class Player {

private:
	Weapon* weapon;

public :
	Player(Weapon* weapon) : weapon(weapon) {}
	void Attack() {
		weapon->Use();
	}
};

int main() {
	Sword s;
	Bow b;


	Player playerSword(&s);
	playerSword.Attack();
}
