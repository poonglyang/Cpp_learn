#include <iostream>

int main() 
{
	// if�� �����Դϴ�
	int num1, num2;

	std::cout << "�Է¹��� ������ ���� ���� �������ϴ� ���α׷��Դϴ�.\nù ��° ������ �Է��� �ּ��� : ";
	std::cin >> num1;

	std::cout << "\n�� ��° ������ �Է��� �ּ��� : ";
	std::cin >> num2;

	if (num1 > num2) {
		std::cout << num1 + num2 << std::endl;
	}
	else if (num1 < num2) {
		std::cout << num1 - num2 << std::endl;
	}
	else {
		std::cout << "���� ���� ����� ���� �������ϴ�" << std::endl;
	}


}