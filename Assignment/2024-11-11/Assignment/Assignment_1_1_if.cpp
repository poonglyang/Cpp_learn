#include <iostream>

int main() {
	// if�� �����Դϴ�
	int num1, num2;

	std::cout << "��Ģ���� ���α׷��Դϴ�.\nù ��° ������ �Է��� �ּ��� : ";
	std::cin >> num1;

	std::cout << "\n�� ��° ������ �Է��� �ּ��� : ";
	std::cin >> num2;

	char sign;
	std::cout << "\n��Ģ���� ��ȣ�� �Է��ϼ���\n(���ϱ� : '+', ���� : '-', ���ϱ� : '*', ������ : '/' : ";
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
		std::cout << "�ùٸ� ��ȣ�� �Է��� �ּ���" << std::endl;
	}
}