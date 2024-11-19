/*
������ �ɹ� �ʱ�ȭ ����Ʈ
	�ɹ� ������ ������ ���� �ȿ��� �ʱ�ȭ �Ǵ� ���� 
	�ƴ϶� ������ ���� �Ǳ� ���� �ʱ�ȭ �Ѵ�

	������ �Ű����� �ڿ� ���Ե�. �ݷ� : ���� ������ ���� �ʱ�ȭ �� �� ������ ��ǥ�� ������

[Getter, Setter]
	�ɹ� ������ private�� �����ϰ� �ܺο��� �������� ������ ����.
	��ü�� �����͸� ��ȣ�ϰ� �ܺο��� �������̽� ����

	1. Getter
		�б� �������� �ɹ� ������ ���� ��ȯ��
		const�� �Լ� �ڿ� �ٿ� �ɹ� ������ ������ �����ϰ�

	2. Setter
		�ɹ� ������ ���� ����
*/


#include <iostream>

using namespace std;

class Exam {
public:
	const int num;

	int& score;

	/*Exam() {					// �̰� �ȵ�
		this->num = num;
		this->score = score
	}*/ 
	Exam(int num, int score) : num(num), score(score) {}	// ����� ������ �ݵ�� �̷������� �ʱ�ȭ �ؾ��Ѵ�
};

class Monster {
public :
	string mName;
	int mAtk;
	int mHealth;

	Monster(const string& monsterName, int monsterAtk, int monsterHealth) 
		:mName(monsterName), mAtk(monsterAtk), mHealth(monsterHealth)
	{
		// ���⼭ �ʱ�ȭ �� �ʿ䰡 ����
	}
};

class Person {
private:
	string name;
	
	int age;

public:

	string GetName() const {
		return name;
	}

	void SetName(const string& name) {
		this->name = name;
	}

	int GetAge() const {
		return age;
	}

	void SetAge(int age) {
		this->age = age;
	}
};


int main() {
	Monster* m = new Monster("���", 10, 20);

	Person p;
	p.SetName("�ǰ���");
	p.SetAge(10);

	cout << p.GetName() << ", " << p.GetAge() << endl;
}