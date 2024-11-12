/*
[while]
	조건이 참(true)인 동안 특정 코드를 반복 실행하기 위한 반복문
	조건이 거짓이 될 때까지 계속 반복된다.
	일반적으로 반복횟수가 미리 정해지지 않았거나 특정 조건을 만족할 때까지 반복해야하는 경우 사용

	종료 조건이 있어야 종료 가능

[do-while]
	조건이 참인지 여부와 관계없이 코드 블록을 최소 한번은 실행해야 할 때 사용
	

do {
	// 실행할 코드
} while(true) -> do 블록이 실행된 후에 조건 평가. 조건이 참이면 코드 블록 다시 실행 거짓이면 종료

*/

#include <iostream>
int main() {
	/*
	int num = 0;

	while (num < 10) {
		num++;
		std::cout << num << std::endl;
	}

	int sum = 0;
	int num1 = 0;

	while (true) {
		sum += num1;
	
		if (sum > 5000) {
			break;
		}

		num1 ++;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	*/
	// 1. while문을 이용한 입력한 숫자만큼 출력
	/*
	int n;
	std::cout << "숫자 입력 : ";
	std::cin >> n;

	int count = 0;

	while (count < n) {
		std::cout << "출력" << std::endl;
		count++;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	*/
	// 2. 정수로 입력을 계속 받고 입력 받은 숫자는 누적하여 더한다. 0을 입력하면 모든 숫자를 더하고 종료한다.
	/*
	int inputNum;
	int total = 0;

	while (true) {
		std::cout << "숫자 입력(종료하려면 0입력) : ";
		std::cin >> inputNum;
		if (inputNum == 0)
			break;
		
		total += inputNum;
	}

	std::cout << total << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	*/

	// do while은 while() {} 과 다르게 블록을 먼저 실행시키고 조건을 확인하기 때문에 최소 1번 출력된다
	/*
	int inputNum = 0;
	int total = 0;

	do {
		std::cout << "0보다 큰 수를 입력하라 : ";
		std::cin >> inputNum;
		total += inputNum;
	} while (inputNum > 0);
	*/
	
	srand(time(NULL));		// 시드 값을 설정해 주는 함수

	int random1 = rand();	// 난수를 생성하는 함수 // 시드값은 프로그램 시작할 때 고정되어 같은 값이 나온다
	random1 = rand() % 3;	// 0,1,2 중 하나를 반환
	std::cout << random1 << std::endl;

	


}