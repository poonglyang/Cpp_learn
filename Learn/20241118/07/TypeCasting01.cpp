/*
[형변환]
	변수나 값을 한 데이터 타입에서 다른 데이터 타입으로 변환하는 작업.

	1. 암시적(묵시적) 형변환
		컴파일러가 자동으로 자료형을 변환
		주로 작은 자료형이 큰 자료형으로 변환
		큰 자료형을 작은 자료형으로 변환은 가능하지만 데이터 손실이 발생할 가능성이 있음


	2. 명시적 형변환
		사용자가 직접 형변환을 한다

		a. C 스타일 명시적 형변환
			문법적으로 간단하다
			괄호 안에 원하는 데이터 타입을 명시하여 변수가 값을 변환
			(type)value
				(type)	: 변환 하려는 데이터 타입
				value	: 변환 대상
			포인터, 기본형, 사용자 정의 타입 등 거의 모든 데이터 타입에 대해 적용 가능하다
			C++ 형변환 방식에 비해서 어떤 변환이 이루어지는지 명확하지 않을 수 있다
			잘못된 형변환으로 인해 런타임 오류나 데이터 손실이 발생할 수 있다
			
		b. C++ 명시적 형변환
			형변환을 더 안전하고 명확하게 하기 위해 캐스트 연산자를 제공

			1. static_cast
				컴파일 타임에 타입을 변환하는데 사용. 
				주로 기본 타입 간의 변환에 사용.
				컴파일러가 변환이 가능한지 검사하기 때문에 잘못된 변환을 방지할 수 있다
				UpCasting 때도 사용하긴 한다.
				복잡한 상속 구조에서 타입 변환이 혼동을 줄 수 있을 때 명시적으로 붙히는게 가독성에 도움이 될 수 있다.
				
			2. dynamic_cast
				런타임에 타입 변환을 수행
				주로 DownCasting에 사용한다
				안정성을 보장하며 타입이 맞지 않는다면 nullptr을 반환시킨다
				RTTI(Runtime Type Information) 기반으로 작동한다

			3. const_cast
				객체에 상수성을 제거하거나 추가할 때

			4. reinterpret_cast
				매우 강력하지만 잘 못 사용하면 상당한 위험을 초래할 수 있다.



*/

#include <iostream>

using namespace std;

int main() {
#pragma region 암시적 형변환
	cout << "암시적 형변환" << endl;
	int num1 = 10;
	double double1 = num1;	// int -> double로 형변환

	cout << double1 << endl << endl;

#pragma endregion

#pragma region 명시적 형변환 (C)
	cout << "명시적 형변환 (C)" << endl;

	int num2 = 10;
	float float1 = (float)num2;	// int -> float

	double double2 = 3.14;
	int num3 = (int)double2;

	cout << "float로 형변환 됨 : " << float1 << ", double에서 int로 형변환 되어 소숫점 밑이 날아감 : " << num3 << endl;

	// 포인터 타입 형변환
	int num4 = 40;
	void* ptr = (void*)&num4;
	int* intPtr = (int*)ptr;

	cout << endl;
#pragma endregion

#pragma region 명시적 형변환 (C++)
	cout << "명시적 형변환 C++" << endl;

	int num5 = 10;
	double double3 = static_cast<double>(num5);	// num5를 double형태로 캐스팅 하겠다

	cout << double3 << endl;


	double double4 = 3.14;
	//char* charPtr = static_cast<char*>(double4);	// 이런식으로 안된다는 것을 에러롤 보여준다
#pragma endregion

	
}