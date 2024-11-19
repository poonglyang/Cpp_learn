/*
소멸자
	객체가 소멸될 때 자동으로 호출되는 함수
	매개변수 없음
	반환값 없음
	오버로딩 불가


*/


#include <iostream>

class MyClass
{
public:
	// 생성자
	MyClass(int size);

	// 소멸자
	~MyClass();

private:
	int* data;
};

MyClass::MyClass(int size)
{
	data = new int[size];
	std::cout << "생성자" << std::endl;
}

MyClass::~MyClass()
{
	delete[] data;							// 배열일 경우 delete[]로 지워야한다
	data = nullptr;
	std::cout << "소멸자" << std::endl;
}

class ParentClass {
protected:
	int x;
	int y;

};

class ChildClass {

};

int main() {
	MyClass* m = new MyClass(10);
	//m->~MyClass();


	delete m;
	m = nullptr;
}
