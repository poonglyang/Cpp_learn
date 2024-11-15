/*
[callbyValue]
	


[callbyReference]


*와 &의 전달방식
	* : 변수의 메모리 주소를 전달. 함수 내부에서 포인터를 통해 값을 수정
		함수 호출시 변수의 주소를 명시적으로 전달
	& : 변수의 별칭을 전달하며 함수 내부에서 직접 값을 수정
		함수 호출시 변수의 참조를 암시작으로 전달
*/

class A {
public:
	

	A() {

	}
};

#include <iostream>
using namespace std;

/// <summary>
/// 매개변수의 값을 10으로 바꾸는 함수
/// </summary>
/// <param name="n">함수의 인수를 전달할 때, 
/// 인수의 값이 복사되어 함수의 매개변수로 전달한다
/// 함수 내부에서 매개변수를 변경해도, 호출한 함수의 실제 인수는 변하지 않는다
/// 
/// 매개변수 n이 실제로 전달된 변수의 값을 복사받는다.
/// 따라서 함수 내에서 매개변수를 변경해도 main의 값은 변경되지 않는다
/// </param>
void Value(int n);

/// <summary>
/// 매개변수의 값을 20으로 바꾸는 함수
/// </summary>
/// <param name="n">함수 호출시 인수로 변수의 주소를 전달하는 방식,
/// 함수가 매개변수로 받은 포인터를 통해 실제 인수의 값을 직접 수정할 수 있다
/// 함수 내부에서 매개변수의 값을 변경하면, 호출한 함수의 실제 인수도 변경된다
/// 값을 복사하는 대신 주소를 전달하므로 메모리와 성능적인 측면에서 더 좋다
/// 
/// 포인터로 주소와 변수를 전달한다
/// 포인터를 통해 원래 변수가 저장된 메모리 위치에 직접 접근하여 값을 수정할 수 있다
/// </param>
void Address(int* n);

/// <summary>
/// 매개변수의 값을
/// </summary>
/// <param name="n">c++에서 지원하는 것, 함수 호출시 인수로 변수의 참조(별명)를 전달한다
/// 함수가 해당 참조를 통해 실제 인수에 접근하여 값을 수정할 수 있다
/// 참조를 사용하면 메모리 주소를 직접 다루지 않아도 되기 때문에 안전하다
/// 
/// 
/// </param>
void Reference(int& n);


/// <summary>
/// 전달된 두 변수의 값을 변화한다. 실제로 호출한 함수의 값은 변경되지 않는다
/// </summary>
/// <param name="a">변수 1</param>
/// <param name="b">변수 2</param>
void Swap(int a, int b);

/// <summary>
/// 주소를 사용하여 변수를 직접 변경한다. 변수의 주소를 전달받아 그 주소의 값을 바꾸므로, 실제 변수의 값이 변경된다.
/// </summary>
/// <param name="a">변수 1</param>
/// <param name="b">변수 2</param>
void SwapAddress(int* a, int* b);

/// <summary>
/// 참조를 사용하여 값을 직접 변경. 변수의 참조를 받아서 변수를 직접 바꾸는 방식으로 값에 의한 것처럼 간단하지만 실제 변수가 변경된다.
/// </summary>
/// <param name="a">변수 1</param>
/// <param name="b">변수 2</param>
void SwapReference(int& a, int& b);

int main() {

	int num = 300;
	cout << "num의 주소값 : " << &num << "과 num의 값 : " << num << endl;
	cout << "=============================================" << endl;
	Value(num);		// 매개변수 n에게 num을 복사하여 전달
	cout << "Value 함수 실행 뒤 main의 n : " << num << endl;
	cout << "=============================================" << endl;
	Address(&num);	// 매개변수 n에게 num의 주소 형태로 전달
	cout << "Address 함수 실행 뒤 main의 n : " << num << endl;
	cout << "=============================================" << endl;
	Reference(num);	// 
	cout << "Reference 함수 실행 뒤 main의 n : " << num << endl;
	cout << "=============================================" << endl;
	cout << "=============================================" << endl;

	int a = 3000, b = 1;
	cout << "함수 호출 전 a : " << a << ", b : " << b << endl;
	Swap(a, b);
	cout << "함수 호출 후 a : " << a << ", b : " << b << endl;
	cout << "=============================================" << endl;

	a = 3000, b = 1;
	cout << "함수 호출 전 a : " << a << ", b : " << b << endl;
	SwapAddress(&a, &b);
	cout << "함수 호출 후 a : " << a << ", b : " << b << endl;
	cout << "=============================================" << endl;

	a = 3000, b = 1;
	cout << "함수 호출 전 a : " << a << ", b : " << b << endl;
	SwapReference(a, b);
	cout << "함수 호출 후 a : " << a << ", b : " << b << endl;
	cout << "=============================================" << endl;



}


void Value(int n) {
	cout << "n의 주소값 : " << &n << "과 n의 값 : " << n << endl;
	n = 10;
	cout << "Value 함수 내에서의 매개변수 n : " << n << endl;
}

void Address(int* n) {
	cout << "n의 주소값 : " << &n << "과 n의 값 : " << n << endl;
	*n = 20;
	cout << "Address 함수 내에서의 매개변수 n : " << *n << endl;
}

void Reference(int& n) {
	cout << "n의 주소값 : " << &n << "과 n의 값 : " << n << endl;
	n = 30;
	cout << "Reference 함수 내에서의 매개변수 n : " << n << endl;
}

void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SwapAddress(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SwapReference(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
