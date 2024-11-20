/*
���
	


*/

#include <iostream>

using namespace std;

class Character {
private:
	

public:
	string name;
	int health;

	Character(const string& n, const int h) : name(n), health(h) {
		cout << "�θ� Ŭ���� character ������ ȣ�� " << endl;
	}

	void Attack() {
		cout << "����" << endl;
	}

	void TakeDamage(const int damage) {
		health -= damage;
		cout << name << "�� " << damage << "��ŭ �������� �Ծ���. ���� ä�� " << damage << endl;
	}

	virtual void Skill() {

	}
};

class Warrior : public Character{
private:
	int stamina;
public:
	// �θ�Ŭ������ �����ڰ� �ʱ�ȭ �ǰ� �ڽ� Ŭ������ �����ڰ� �ʱ�ȭ �Ǿ�� �Ѵ�
	Warrior(const string& n, const int h, const int s) : Character(n, h), stamina(s) {
		cout << "�ڽ� Ŭ���� Warrior ������ ȣ��" << endl;
	}	

	int GetStamina() {
		return stamina;
	}

	void Skill() {
		cout << "�� �ֵθ���" << endl;
	}
};


class Maze : public Character{
private:
	int mana;
public:
	Maze(const string& n, const int h, const int m) : Character(n, h), mana(m) {
		cout << "�ڽ� Ŭ���� Warrior ������ ȣ��" << endl;
	}

	int GetMana() {
		return mana;
	}

	void Skill() override {
		cout << "������ ��" << endl;
	}
};

int main() {
	Warrior* w = new Warrior("������", 100, 30);		// main �Լ����� ���޵� "������"�� const�̱� ������ �����ڿ��� const�� �ٿ��� �Ѵ�

	w->Skill();
	w->Attack();

	Maze* m = new Maze("�����", 100, 30);
	m->Skill();
	m->Attack();

	
}