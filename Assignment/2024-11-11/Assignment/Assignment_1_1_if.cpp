#include <iostream>

int main() {
	// if문 버전입니다
	int num1, num2;

	std::cout << "사칙연산 프로그램입니다.\n첫 번째 정수를 입력해 주세요 : ";
	std::cin >> num1;

	std::cout << "\n두 번째 정수를 입력해 주세요 : ";
	std::cin >> num2;

	char sign;
	std::cout << "\n사칙연산 기호를 입력하세요\n(더하기 : '+', 빼기 : '-', 곱하기 : '*', 나누기 : '/' : ";
	std::cin >> sign;

	if (sign == '+') {
		std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
	}
	else if (sign == '-') {
		std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
	}
	else if (sign == '*') {
		std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
	}
	else if (sign == '/') {
		std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
	}
	else {
		std::cout << "올바른 기호를 입력해 주세요" << std::endl;
	}
}