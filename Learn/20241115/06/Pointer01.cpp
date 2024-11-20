/*
[Pointer]
	포인터는 주소를 저장하는 변수
	기존의 변수는 데이터를 저장하는데 반하여 포인터는 메모리 공간의 주소를 저장한다
	포인터 변수가 주소를 저장하려면 변수의 주소를 알아야 한다
	변수 이름 앞에 & 연산자를 붙이면 해당 변수의 시작주소를 반환한다
	포인터 변수가 저장하는 변수의 주소에 저장된 값을 참조하려면 * 연산자를 이용한다

[포인터 연산자]
	& : 특정한 데이터의 메모리상의 주소값을 알 수 있다.
	* : & 연산자가 어떠한 데이터의 주소값을 얻어내는 연산자라면 거꾸로 
		주소값에서 해당 주소값에 대응되는 데이터를 가져오는 연산자

[포인터 정의 방법]
	(포인터에 주소값이 저장되는 데이터형)* 포인터의 이름

*/

#include <iostream>

int main() {
	//int a = 2;	// 일반 변수
	//int* p;

	//p = &a;		// 초기화한 변수의 주소를 포인터 변수 p에 저장

	//a = 3;
	//std::cout << &a << std::endl;
	//std::cout << *p << std::endl;

	//std::cout << "포인터 변수 p의 주소 : " << &p << std::endl;

	//*p += 2;

	//std::cout << a << std::endl;

	int num = 10;
	int* p = &num;

	// 역참조
	int** pp;
	pp = &p;	// 포인터 변수 p의 주소를 저장한다

	//std::cout << pp << std::endl;
	//std::cout << p << std::endl;

	**pp = 1234;
	std::cout << "num의 주소 값" << &num << std::endl;
	std::cout << "pp의 값 : " << pp << std::endl;
	std::cout << "**pp의 주소 값 : " << &**pp << std::endl;
	std::cout << "**pp의 값 : " << **pp << std::endl;
	std::cout << "num의 값 : " << num << std::endl;

	int* ptr = nullptr;		// nummptr 널포인터(아무것도 가르키지 않는다)로 초기화 한다.
	delete ptr;

	int* ptr2 = new int(44);	// 동적 힙 영역에 메모리 할당 ptr2는 동적 할당된 메모리의 주소를 가리키고 있음
	std::cout << "동적 할당된 값 : " << *ptr2 << std::endl;
	delete ptr2;				// 할당 해제

	// 벵글린 포인터 : 메모리에서 이미 해제된 포인터를 가르키는 포인터
	std::cout << "해제후 prt2의 메모리 주소 " << ptr2 << std::endl;

	ptr2 = nullptr;
	std::cout << "nullptr후 prt2의 메모리 주소 " << ptr2 << std::endl;
}