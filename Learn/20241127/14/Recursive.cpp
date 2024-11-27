/*
Recursive (재귀 함수)
	자기 자신을 호출하는 함수
	반드시 종료 조건이 있어야 한다 (기저 조건, 종료 조건)
	
	반복문의 경우 재귀보다 메모리를 적게 사용하지만
	복잡한 문제를 해결하기 어렵다
	예를 들어 반복 횟수를 모르는 경우 어떻게 할 것인가

	함수의 진행 상태는 스택 메모리에 저장된다
		-> 재귀호출이 너무 많이 일어나면 스택 오버플로우가 일어난다



*/

#include <iostream>

void Print(int i) {
	if (i < 10) {
		i++;
		Print(i);
		
	}
}

int Factorial(int n) {

	if (n <= 1) {
		return 1;
	}

	return n * Factorial(n - 1);
}
// 호출 단계
//	1. Factorial(4)에서 종료 조건 확인 후 return 4 * Factorial(3)
//	2. Factorial(3)에서 종료 조건 확인 후 return 3 * Factorial(2)
//	3. Factorial(2)에서 종료 조건 확인 후 return 2 * Factorial(1)
//	4. Factorial(1)에서 종료 조건이 충족 하므로 return 1
//	5. 3.에서 return 2 * 1
//	6. 2.에서 return 3 * (2 * 1)
//	7. 1.에서 return 4 * (3 * (2 * 1))를 한다

int main() {
	std::cout << Factorial(4) << std::endl;
}