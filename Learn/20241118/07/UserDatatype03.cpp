/*
	�Ʒ��� ���� ���ð� ���� ��
	1. ������ ����� �Լ��� �����ض�
		�÷��̾ ����ġ�� �װ� Ư�� ����ġ �̻��̸� ������
	2. �ſ� ������ ���� �Լ� �����

*/



#include <iostream>

using namespace std;

enum class Job {
	Warrior, Mage, Archer
};

struct Character {
	std::string name;
	int hp;
	int power;
	int level;
	int exp;
	Job job;	// ����ü �ȿ� �������� ���Խ�ų �� �ִ�.

};

string GetName(Job j) {
	switch (j)
	{
	case Job::Warrior:
		return "������� �� ����";
	case Job::Mage:
		return "���� �� ������";
	case Job::Archer:
		return "��� ����";
	default:
		return "���� ���� ����";
	}
}

void LevelUp(Character ch) {
	ch.level++;
}

void Attack(Character attacker, Character target) {

}

int main() {
	Character p1 = { "������", 100, 10, 1, 0, Job::Warrior };
	Character p2 = { "�����", 100, 10, 2, 0, Job::Mage };
	Character p3 = { "��ü�", 100, 10, 3, 0, Job::Archer };

	cout << "�÷��̾�1 : " << p1.name << ", ���� : " << p1.level << ", ��Ȱ : " << GetName(p1.job) << endl;
	cout << "�÷��̾�1 : " << p2.name << ", ���� : " << p2.level << ", ��Ȱ : " << GetName(p2.job) << endl;
}