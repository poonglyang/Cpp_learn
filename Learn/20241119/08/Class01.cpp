/*
Class
	객체 지향 프로그래밍, 절차 지향 프로그래밍
	객체 지향 프로그래밍은 우리가 살고 있는 실제 세계가 객체들로 구성되어 있는 것처럼 소프트웨어도 객체로 구성하는 방법

	실제 세계에서는 많은 객체가 존재하고 객체 나름대로의 고유한 기능을 수행하면서
	다른 객체들과 상호작용을 한다.

Class의 기본 구조
	1. 클래스 정의
		클래스는 class 키워드로 정의

	2. 멤버 변수
		클래스 내부에 정의된 변수로 객체의 상태(속성)를 저장

	3. 맴버 함수
		클래스 내부에 선언되고 구현, 객체의 동작을 정의

객체란 무엇인가
	클래스는 객체를 정의하는 틀이나 설계도.
	객체는 설계도를 기반으로 실체화를 시킨다.

접근 제어 지시자
	public : 자유 참조 가능
	private : 클래스 내부에서만 허용 (맴버 변수)
	protected : 자신과 상속 관계에 있는 것들만 접근 가능

정적 할당과 동적 할당
	정적 할당
		컴파일 시점에 메모리 크기가 결정됨
		스택
		프로그램이 종료 될 때까지 자동을 관리됨
		크기를 미리 지정해야 하므로 유연성이 떨어지고 메모리 공간이 고정되므로 비효율적일 수도 있다.
	동적 할당
		런타임 도중에 메모리를 할당함
		힙
		크기를 유연하게 조절할 수 있으며 런타임 중 필요한 만큼 메모리를 할당
		직접 관리해야하기 때문에 메모리 누수 위험성이 있다
		동적 할당 후 반드시 해제해야 한다
		크기를 미리 알 수 없거나 실행 중에 변경될 가능성이 있는 경우

*/

#include <iostream>
using namespace std;

class test {
	// 맴버 변수
	int num1;
	int num2;

	// 기능 -> 맴버 함수
	void add() {

	}

};

class Circle {

	float radius;

	string color;

public:
	Circle(float radius, string color) {
		this->radius = radius;
		this->color = color;
	}

	float calcArea() {
		return pow(radius, 2) * 3.14;
	}

	float GetRadius() {
		return radius;
	}

	string GetColor() {
		return color;
	}

};

class Student {
private:

public :
	Student();
	~Student();
	void Print();
};

Student::Student()
{

}

Student::~Student()
{

}

void Student::Print()
{

}

int main() {
	// 정적 할당
	Circle c = Circle(3, "red");

	cout << "원의 반지름 : " << c.GetRadius() << ", 원의 넓이 : " << c.calcArea() << endl;

	// 동적 할당
	Circle* c2 = new Circle(1.5, "blue");
	cout << "원의 반지름 : " << c2->GetRadius() << ", 원의 넓이 : " << c2->calcArea() << endl;

	free(c2);
}


