/*
변수의 존재 기간과 접근 범위
	선언되는 위치에 따라 크게 전역변수와 지역변수로 나뉜다
	메모리상에 존재하는 기간과 접근할 수 있는 범위에 대한 차이점이 있다.

	1. 지역 변수
		지역변수는 중괄호 내에 선언되는 변수는 모두 지역변수
		활동 영역 : 변수가 선언된 블록 내에서만 유효, 블록이 끝나면 메모리에서 사라지게 됨

	2. 전역 변수
		블록 외부에서 정의, 프로그램 전체에 접근 가능
		프로그램 내 모든 함수에서 접근 가능
		프로그램 실행 시작시 생성되고 프로그램이 종료되면 소멸
		전역변수는 지양하라

	3. 상수 변수 (const)
		변경할 수 없는 변수 
		안전성을 보장해 준다
		선언시 초기화를 해줘야 한다
		함수의 매개변수에도 쓸 수 있다
		const int a 등 const가 붙은 변수

*/

#include <iostream>
int GlobalNum = 10;

void GlobalVariable() {
	std::cout << "여기서도 접근 가능 " << GlobalNum << std::endl;
}

void LocalVariable() {
	int num = 1; 
	{
		num = 2;
		int num1 = 5;
	}
	
}

void MyFuncOne() {
	int myFuncOneNum = 10;
	myFuncOneNum++;
	std::cout << "지역변수 myFuncOneNum의 데이터 : " << myFuncOneNum << std::endl;
}

void MyFuncTwo() {
	int num1 = 10;
	int num2 = 10;
	num1++;
	num2--;
	std::cout << "지역변수 num1 : " << num1 << "지역변수 num2 : " << num2 << std::endl;
}

int Add(int num1, int num2);

//int Sum(const int num1, int num2) {
//	//num1 = 5; //<- 안됨 매개변수로 들어와도 const는 값 변경을 막아준다
//
//}

int Sum(int a, int b = 5, int c = 1) {
	return a + b + c;
}

int main() {
	std::cout << " " << GlobalNum << std::endl;

	GlobalVariable();

	MyFuncOne();

	MyFuncTwo();

	const int a = 1;	// 변경 불가

	std::cout << Sum(1, 3, 5) << std::endl;
	
}

int Add(int num1, int num2)
{
	return num1 + num2;
	
}
