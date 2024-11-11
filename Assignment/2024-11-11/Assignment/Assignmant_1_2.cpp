#include <iostream>

int main() 
{
	// if문 버전입니다
	int num1, num2;

	std::cout << "입력받은 정수에 따라 덧셈 뺄셈을하는 프로그램입니다.\n첫 번째 정수를 입력해 주세요 : ";
	std::cin >> num1;

	std::cout << "\n두 번째 정수를 입력해 주세요 : ";
	std::cin >> num2;

	if (num1 > num2) {
		std::cout << num1 + num2 << std::endl;
	}
	else if (num1 < num2) {
		std::cout << num1 - num2 << std::endl;
	}
	else {
		std::cout << "같은 경우는 경우의 수에 없었습니다" << std::endl;
	}


}