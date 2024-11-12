#include <iostream>

int main() {
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
		for (int j = 1; j <= 5 - i; j++) {
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