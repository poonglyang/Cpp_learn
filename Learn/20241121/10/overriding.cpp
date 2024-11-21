/*
[overriding]
	자식 클래스가 부모 클래스의 메서드를 재정의하여 자신의 방식으로 동작하게 만드는 객체 지향 프로그래밍의 중요한 개념
	함수 이름, 매개변수가 부모클래스의 함수와 동일해야 함
	자식 클래스가 부모 클래스의 함수를 변경하거나 확장시킬 수 있다.

[virtual]
	부모 클래스의 함수에 붙이며, 해당 함수가 오버라이딩 가능함을 나타낸다


[override]
	자식 클래스에서 함수가
*/

#include <iostream>

/// <summary>
/// 자동차 클래스(부모 클래스)
/// </summary>
class Vehicle {
protected :
	std::string name;

public:
	Vehicle(const std::string& n) : name(n) {
		std::cout << "부모 클래스 생성자 호출" << std::endl;
	}

	virtual void Move() const {
		std::cout << name << "의 부모 클래스 함수 호출" << std::endl;
	}

	/// <summary>
	/// 소멸자, 자식클래스의 호출 되기 위해 virtual을 붙인다
	/// </summary>
	virtual ~Vehicle() {	// 부모 클래스에 virtual을 쓰지 않으면 자식 클래스의 소멸자가 해제되지 않는다
		std::cout << "부모 클래스 소멸자 호출" << std::endl;
	}

	/// <summary>
	/// 소멸자에서 아무것도 하지 않을 경우 default를 사용한다
	/// </summary>
	// virtual~Vehicle() = default;
};

class Car : public Vehicle {
public:
	Car(const std::string& n) : Vehicle(n) {
		std::cout << "자식 생성자(Car) 호출" << std::endl;
	}

	void Move() const override {
		
		std::cout << name << "의 자식 클래스 자동차 함수 호출" << std::endl;

	}

	void noOver() {
		std::cout << "테스트" << std::endl;
	}

	~Car() {
		std::cout << "자식 클래스 (car) 소멸자 호출" << std::endl;
	}
};

class Bike : public Vehicle {
public:
	Bike(const std::string& n) : Vehicle(n) {
		std::cout << "자식 생성자(Car) 호출" << std::endl;
	}

	void Move() const override {
		std::cout << name << "의 자식 클래스 오토바이 함수 호출" << std::endl;

	}

	~Bike() {
		std::cout << "자식 클래스 (Bike) 소멸자 호출" << std::endl;
	}
};

int main() {
	Vehicle* v;
	v = new Car("자동차");
	v->Move();

	delete v;
	v = nullptr;
}