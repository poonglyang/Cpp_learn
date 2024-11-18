/*
	아래와 같은 예시가 있을 때
	1. 레벨업 기능을 함수로 구현해라
		플레이어가 경험치를 쌓고 특정 경험치 이상이면 레벨업
	2. 매우 간단한 공격 함수 만들기

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
	Job job;	// 구조체 안에 열거형을 포함시킬 수 있다.

};

string GetName(Job j) {
	switch (j)
	{
	case Job::Warrior:
		return "집행검을 든 전사";
	case Job::Mage:
		return "오브 든 마법사";
	case Job::Archer:
		return "양궁 선출";
	default:
		return "선택 하지 않음";
	}
}

void LevelUp(Character ch) {
	ch.level++;
}

void Attack(Character attacker, Character target) {

}

int main() {
	Character p1 = { "김전사", 100, 10, 1, 0, Job::Warrior };
	Character p2 = { "김법사", 100, 10, 2, 0, Job::Mage };
	Character p3 = { "김궁수", 100, 10, 3, 0, Job::Archer };

	cout << "플레이어1 : " << p1.name << ", 레벨 : " << p1.level << ", 역활 : " << GetName(p1.job) << endl;
	cout << "플레이어1 : " << p2.name << ", 레벨 : " << p2.level << ", 역활 : " << GetName(p2.job) << endl;
}