/*
상속
	


*/

#include <iostream>

using namespace std;

class Character {
private:
	

public:
	string name;
	int health;

	Character(const string& n, const int h) : name(n), health(h) {
		cout << "부모 클래스 character 생성자 호출 " << endl;
	}

	void Attack() {
		cout << "공격" << endl;
	}

	void TakeDamage(const int damage) {
		health -= damage;
		cout << name << "이 " << damage << "만큼 데미지를 먹었다. 남은 채력 " << damage << endl;
	}

	virtual void Skill() {

	}
};

class Warrior : public Character{
private:
	int stamina;
public:
	// 부모클래스의 생성자가 초기화 되고 자식 클래스의 생성자가 초기화 되어야 한다
	Warrior(const string& n, const int h, const int s) : Character(n, h), stamina(s) {
		cout << "자식 클래스 Warrior 생성자 호출" << endl;
	}	

	int GetStamina() {
		return stamina;
	}

	void Skill() {
		cout << "검 휘두르기" << endl;
	}
};


class Maze : public Character{
private:
	int mana;
public:
	Maze(const string& n, const int h, const int m) : Character(n, h), mana(m) {
		cout << "자식 클래스 Warrior 생성자 호출" << endl;
	}

	int GetMana() {
		return mana;
	}

	void Skill() override {
		cout << "에너지 볼" << endl;
	}
};

int main() {
	Warrior* w = new Warrior("김전사", 100, 30);		// main 함수에서 전달된 "김전사"는 const이기 때문에 생성자에도 const를 붙여야 한다

	w->Skill();
	w->Attack();

	Maze* m = new Maze("김법사", 100, 30);
	m->Skill();
	m->Attack();

	
}