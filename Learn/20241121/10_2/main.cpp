/*
[추상화]
	

[추상 클래스]
	하나 이상의 순수 가상함수를 포함한 클래스라면 추상 클래스라고 정의한다
	추상 클래스는 인스턴스화 시킬 수 없다
	다른 클래스들이 상속 받아야 하는 기본 인터페이스나 기본 동작을 정의하는데 사용
	특정 함수들이 자식 클래스에 의해 구현되므로 강제한다. -> 반드시 해야함

[헤더 파일]
	헤더파일에서는 선언을 하고(구현되 되긴함) 헤더 파일에 맞는 cpp에서 구현한다

[virtual Function 과 Pure Virtual Function | 가상함수와 순수가상함수]
	1. 가상함수 (virtual Function)
		구현부를 포함할 수 있다
		파생클래스에서 재정의 하지 않아도 된다.
		가상함수 만으로는 추상클래스가 성립되지 않는다.
		클래스 인스턴스화가 가능하다

	2. 순수가상함수 (Pure Virtual Function)
		구현부가 없다
		파생클래스에서 반드시 재정의 해야한다.
		순수 가상함수가 하나라도 있으면 추상클래스가 성립 된다.
		인스턴스화가 불가능 하다.

[Upcasting과 DownCasting]
	Upcasting
		자식클래스의 객체를 부모 클래스 타입으로 변환한다
		안정성을 보장하며 명시적인 타입 변환이 필요 없다

	DownCasting
		부모 클래스 타입을 자식 클래스 타입으로 변환

*/

#include <iostream> 
#include "Player.h"

class Shape {
public :
	virtual void Draw() const {
		std::cout << "부모 클래스 shape" << std::endl;
	}

	virtual ~Shape() = default;
};

class Circle : public Shape {

public:
	void Draw() const  {
		std::cout << "자식 클래스 Circle" << std::endl;
	}

	void CircleFunction() {
		std::cout << "Circle 클래스의 맴버 함수 CircleFunction" << std::endl;
	}
};

class Rectangle : public Shape {

public:
	void Draw() const  {
		std::cout << "자식 클래스 Rectangle" << std::endl;
	}

	void RectangleFunction() {
		std::cout << "Rectangle 클래스의 맴버 함수 RectangleFunction" << std::endl;
	}
};

int main() {
#pragma region 추상클래스
	//Player* p = new Player("전사", 10);

	//p->Attack();
	//p->TakeDamage(10);

	//delete p;
	//p = nullptr;

	////Unit* u = new Unit("aa", 10);		// 순수 가상함수가 있기에 선언 불가하다
#pragma endregion

#pragma region 업케스팅, 다운캐스팅
	Shape* shape1 = nullptr;
	Shape* shape2 = nullptr;

	// 업케스팅 : 자식 클래스 객체를 부모 클래스 타입의 포인터
	shape1 = new Circle();	
	shape2 = new Rectangle();

	// 자식 클래스의 멤버들을 호출해준다 (부모에 있는 virtual을 빼면 부모 클래스의 Draw가 나온다)
	shape1->Draw();
	shape2->Draw();
	// 다운케스팅
	/*Circle* c = (Circle*)shape1;
	c->CircleFunction();*/

	Circle* c = dynamic_cast<Circle*>(shape1);	// 타입이 맞지 않으면 nullptr을 뱉음
	c->CircleFunction();	//자식 클래스 맴버 함수 호출
	
	Rectangle* r 
		= dynamic_cast<Rectangle*>(shape2);	// 가상함수를 가진 클래스에서만 사용 가능하다 (어느 하나라도 virtual이 필요하다)
	r->RectangleFunction();

	c->Draw();
	r->Draw();

#pragma endregion
}