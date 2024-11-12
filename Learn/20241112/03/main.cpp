/*
for 문
	반복작업을 수행할 때 사용되는 제어문 중 하나
	반복횟수가 명확하거나 정밀한 제어가 필요할 때 유용
	while보다 기본적으로 많은 코드로 이루어져 있지만 임의의 횟수 만큼 반복을 수행하기에는 for문이 편리하다

	for (초기화, 반복 조건, 반복시 증감값) {
		반복 수행
	}

	초기화 : 루프가 시작될 때 처음 한번만 실행되는 부분 반복문에 사용될 변수 초기화
	조건 : 각 반복이 실행될 때마다 조건이 검사되며 조건이 참이면 루프를 발생
	증감 : 반복이 진행되고 지정된 값 만큼 증감한다
	
	실행 순서
		초기화 -> 반복 조건 -> 반복 수행 -> 증감 -> 반복 조건 -> 조건에 따라 반복 수행 or for문 종료

*/

#include <iostream>

int main() {
	/*
	for (int i = 0; i < 5; i++) {
		std::cout << i << "  ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 10; i > 0; i--) {
		std::cout << i << "  ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
	*/
	/*
	// 1부터 10까지 숫자중 5까지만 출력
	for (int i = 1; i < 11; i++) {
		if (i > 5) {
			break;
		}

		std::cout << i << "  ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
	*/
	/*
	// 1부터 10까지 홀수만 출력

	for (int i = 1; i < 11; i++) {
		if (i % 2 == 0)
			continue;

		std::cout << i << "  ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
	*/
	/*
	// 1부터 50까지 반복, 3의 배수나 5의 배수인지 검사하기
	for (int i = 1; i <= 50; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			std::cout << i << "는 3이나 5의 배수입니다" << std::endl;
		}
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
	*/

	/*
	for (int i = 1; i < 11; i += 2) {
		std::cout << i << "  ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
	*/
	/*
	int inputNum;
	std::cin >> inputNum;

	for (int i = 0; i < inputNum; i++) {
		std::cout << i << "  ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
	*/

	/*
	// 1부터 100까지 합 구하기

	int sum = 0;

	for (int i = 1; i <= 100; i++) {
		sum += i;
	}
	std::cout << sum << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	*/

	/*
	// 중첩 for

	for (int i = 0; i < 3; i++) {				// 밖 for
		for (int j = 1; j < 4; j++) {			// 안 for
			std::cout << i * 3 + j << "  ";
		}
		std::cout << std::endl;
	}
	*/

	/*
	// 2중 for문을 돌려 2단부터 9단까지 돌려라
	for (int i = 2; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			std::cout << i << " * " << j << " = " << i * j << std::endl;
		}
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
	*/

	// 2중 for문을 돌려 2단부터 9단까지 돌려라
	for (int i = 1; i < 10; i++) {
		for (int j = 2; j < 10; j++) {
			std::cout << j << "*" << i << "=" << j * i << "\t";
		}
		std::cout << std::endl;
	}

	/*
	// 내가 입력한 숫자가 양수인지 검사하는 프로그램을 만든다면?
	int numInputs;	// 내가 입력할 숫자의 갯수
	bool isPositive = true;		// 모든 숫자가 양수인지 여부를 판단

	std::cout << "입력할 숫자의 갯수 : ";
	std::cin >> numInputs;

	for (int i = 0; i < numInputs; i++) {
		int num;
		std::cout << "숫자 입력 : ";
		std::cin >> num;

		if (num <= 0) {
			isPositive = false;
		}
	}

	std::cout << "모든 숫자가 양수인지 여부 : " << isPositive << std::endl;
	*/

	std::cout << std::endl;
	std::cout << std::endl;

	// 별찍기
	int n = 5;
	
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= i; j++) 
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	// 위에거 x축 반전
	for (int i = 5; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	// y축 반전
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5-i; j++) {
			std::cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	// x, y 축 반전
	for (int i = 0; i <= 5; i++) {

		for (int j = 1; j <= i; j++) {
			std::cout << " ";
		}

		for (int j = 1; j <= 5 - i; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}