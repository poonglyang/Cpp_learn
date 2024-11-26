/*
I(Interface Segregation Principle, ISP, 인터페이스 분리 원칙)
	클라이언트는 사용하지 않는 매서드에 의존하지 않아야 하는 원칙
	인터페이스는 사용자의 필요에 맞게 작고 구체적 설계. 클라이언트가 불필요한 기능에 의존하지 않도록
	특정 클라이언트가 필요로 하는 기능만을 제공하는 인터페이스를 설계

*/

#include <iostream>
using namespace std;

class Animal {
public:
	virtual void Eat() = 0;
	virtual void Sleep() = 0;
};

class Mammalia : public Animal {
	virtual void Swiming() = 0;
};

class Bird : public Animal {
public :
	virtual void Fly() = 0;
};

class Dog : public Mammalia {
public:
	void Eat() override {
		cout << "우걱" << endl;
	}

	void Sleep() override
	{	
		cout << "잘 수 있음" << endl;
	}

	/*void Fly() override {
		cout << "날수 없잖아" << endl;
	}*/

	void Swiming() override
	{
		cout << "수영하기" << endl;
	}
};