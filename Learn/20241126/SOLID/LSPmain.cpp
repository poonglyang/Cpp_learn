/*
L(Liskov Substiution Principle, LSP, 리스코프 치환 원칙)
	자식 클래스는 부모 클래스의 기능을 대체할 수 있어야 한다.
	프로그램에서 부모 클래스 객체가 사용되는 모든 부분에 자식클래스 객체를 대체해도 논리적으로 동작이 바뀌지 않아야 한다
	안정적인 상속구조와 자식클래스는 부모클래스에서 정의된 행동을 위반하면 안된다
	부모 클래스의 포인터나 참조를 통해 자식클래스를 사용할 때 논리가 꺠지면 안됨.
*/

#include <iostream>
class Bird {
public :
	virtual void Fly() const {
		std::cout << "새는 날아간다" << std::endl;
	}
};

class Eagle : public Bird {
	void Fly() const override {
		std::cout << "독수리가 날아간다" << std::endl;
	}
};

class Penguin1 : public Bird {
	void Fly() const override {
		throw "Ostriches cannot fly!";
	}
};

class Penguin2 : public Bird {
public:
	void Fly() const override {
		// 펭귄은 날 수 없지만, '비행 불가' 메시지를 출력하는 등, 비행과 관련된 규칙을 유지
		std::cout << "팽귄은 날 수 없다." << std::endl;
	}
};




