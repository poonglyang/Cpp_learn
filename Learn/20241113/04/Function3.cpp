/*
[함수 오버 로딩]
	동일한 함수 이름을 사용해서 매개변수의 타입, 갯수, 또는 순서를 다르게 정의하는 것
	비슷한 역활을 하는 여러 함수가 있으 때 각 함수에 다른 이름을 부여하는 것 대신에 오버로딩을 사용하면 
	코드의 가독성이 향상되며 하나의 함수이름으로 다양한 형태의 함수를 호출 가능하다

[함수 오버로딩 성립 조건]
	1. 함수 이름이 동일해야 한다
	2. 리턴 타입은 고려대상이 아니다
	3. 매개변수의 데이터 타입이 다르거나 갯수가 달라야 한다

체크 사항
	함수 오버로딩은 무었인가요?
	함수 오버로딩과 오버라이딩의 차이점은 무엇인가요
	
*/



#include <iostream>

int Add(int a, int b) {
	return a + b;
}

float Add(float a, float b) {
	return a + b;
}

int Sub(int num1, int num2) {
	return num1 - num2;
}

float Sub(float num1, float num2) {
	return num1 - num2;
}

int Mul(int num1, int num2) {
	return num1 * num2;
}

float Mul(float num1, float num2) {
	return num1 * num2;
}

int Div(int num1, int num2) {
	return num1 / num2;
}

float Div(float num1, float num2) {
	return num1 / num2;
}

float SqExtend(float row, float col) {
	return row * col;
}

float CirExtend(float r) {
	return r * r * 3.14f;
}

int main() {
	std::cout << "두 수의 합, " << Add(33.23f, 11.8f) << "   " << Add(3, 8) << std::endl;
	std::cout << "두 수의 차, " << Sub(20.83f, 1.54f) << "   " << Sub(3, 8) << std::endl;
	std::cout << "두 수의 곱, " << Mul(20.83f, 1.54f) << "   " << Mul(3, 8) << std::endl;
	std::cout << "두 수의 나누기, " << Div(20.83f, 1.54) << "   " << Div(3, 8) << std::endl;

	std::cout << "사각형의 넓이 : " << SqExtend(20, 3) << std::endl;
	std::cout << "원의 넓이 : " << CirExtend(3.3f) << std::endl;


	/*
		1. 더하기, 빼기, 곱하기, 나누기, 함수 만들기
			오버로딩의 기능을 활용해 정수형과 실수형을 만들어라
		2. 사각형과 원의 면적을 계산하는 함수를 만들어라

		3. 
	*/


}