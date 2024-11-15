/*
* [포인터]
*	포인터 변수에 +,-
*	포인터 연산을 할 때 자료형의 크기에 비례하여 증가하거나 감소 한다

[대입]
	한 포인터가 다른 포인터와 동일한 메모리 주소를 가리키도록 한다.
	같은 메모리 주소를 가리키는 것은 위험하다
	포인터의 타입은 일치해야 한다
	여러 포인터가 동일한 메모리 주소를 가리키면 메모리 해제를 할 때 문제가 발생할 수 있다.

[포인터의 타입]
	포인터에는 왜 타입이 있을까?
	만약에 포인터라는 타입이 있다면
	int a;
	int* p;
	Pointer(라는 타입이 있다고 할 때)* p;
	p = &a;
	
	p는 a의 주소값이 저장되어 있음.
	문제는 a가 메모리에서 차지하는 모든 주소들의 위치가 들어가 있는게 아니라
	시작 주소만 들어가 있다.

	즉, 컴퓨터가 메모리에서 얼마만큼 읽어 들여야 할지 알 방법이 없다.

*/

#include <iostream>

using namespace std;

int main() {
	int a;
	int* pa = &a;
	
	cout << "pa의 값 : " << pa << endl;

	cout << (pa + 1) << endl;
	cout << (pa++) << endl;
	cout << (pa - 1) << endl;

	cout << endl << endl;

	int num = 10;
	int* pA = &num;		// num의 주소가 들어간다
	int* pB = pA;		// pA의 값(num의 주소)이 들어간다

	cout << *pA << endl;
	cout << *pB << endl;

	cout << endl << endl;

	int intA = 10;
	int* pIntA = &intA;
	// double* dp = pIntA;		// 다른 타입의 포인터는 대입 연산이 안된다.

	cout << endl << endl;

	double testFloat;
	double* pTF = &testFloat;
	cout << pTF << endl;
	cout << (pTF + 1) << endl;


}