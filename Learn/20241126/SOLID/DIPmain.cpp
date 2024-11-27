/*	
D(Depeondency Inversion Principle, DIP, ������ ���� ��Ģ)
	���� ����� ���� ��⿡ �������� �ʵ��� �ϰ� �߻�ȭ�� �������̽��� �����ϵ��� �ؾ��Ѵٴ� ��Ģ
	���� ����� ���� ����� ������ �����ϸ� �ȵȴ�
	�� ����� �߻�ȭ�� �������̽��� ���� ����Ǿ�� �Ѵ�.

	��ü���� ������ �������� �ʰ� �߻�ȭ�� �����Ͽ� ��Ⱓ�� ���յ��� ����.
*/

/*
	���� = ���� ĳ����
	���� - ���� �ý���

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
		cout << "Į�ֵθ��� " << endl;
	}
};

class Bow : public Weapon {
public:
	void Use() const override {
		cout << "Ȱ ���" << endl;
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
