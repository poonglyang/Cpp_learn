/*
생성자 맴버 초기화 리스트
	맴버 변수가 생성자 본문 안에서 초기화 되는 것이 
	아니라 본문이 실행 되기 전에 초기화 한다

	생성자 매개변수 뒤에 삽입됨. 콜론 : 으로 시작한 다음 초기화 할 각 변수를 쉼표로 구분함

[Getter, Setter]
	맴버 변수를 private로 선언하고 외부에서 직접적인 접근을 차단.
	객체의 데이터를 보호하고 외부와의 인터페이스 제공

	1. Getter
		읽기 전용으로 맴버 변수의 값을 반환함
		const를 함수 뒤에 붙여 맴버 변수의 변경을 방지하고

	2. Setter
		맴버 변수의 값을 설정
*/


#include <iostream>

using namespace std;

class Exam {
public:
	const int num;

	int& score;

	/*Exam() {					// 이건 안됨
		this->num = num;
		this->score = score
	}*/ 
	Exam(int num, int score) : num(num), score(score) {}	// 상수와 참조는 반드시 이런식으로 초기화 해야한다
};

class Monster {
public :
	string mName;
	int mAtk;
	int mHealth;

	Monster(const string& monsterName, int monsterAtk, int monsterHealth) 
		:mName(monsterName), mAtk(monsterAtk), mHealth(monsterHealth)
	{
		// 여기서 초기화 할 필요가 없다
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
	Monster* m = new Monster("고블린", 10, 20);

	Person p;
	p.SetName("피곤해");
	p.SetAge(10);

	cout << p.GetName() << ", " << p.GetAge() << endl;
}