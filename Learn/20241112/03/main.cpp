/*
for ��
	�ݺ��۾��� ������ �� ���Ǵ� ��� �� �ϳ�
	�ݺ�Ƚ���� ��Ȯ�ϰų� ������ ��� �ʿ��� �� ����
	while���� �⺻������ ���� �ڵ�� �̷���� ������ ������ Ƚ�� ��ŭ �ݺ��� �����ϱ⿡�� for���� ���ϴ�

	for (�ʱ�ȭ, �ݺ� ����, �ݺ��� ������) {
		�ݺ� ����
	}

	�ʱ�ȭ : ������ ���۵� �� ó�� �ѹ��� ����Ǵ� �κ� �ݺ����� ���� ���� �ʱ�ȭ
	���� : �� �ݺ��� ����� ������ ������ �˻�Ǹ� ������ ���̸� ������ �߻�
	���� : �ݺ��� ����ǰ� ������ �� ��ŭ �����Ѵ�
	
	���� ����
		�ʱ�ȭ -> �ݺ� ���� -> �ݺ� ���� -> ���� -> �ݺ� ���� -> ���ǿ� ���� �ݺ� ���� or for�� ����

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
	// 1���� 10���� ������ 5������ ���
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
	// 1���� 10���� Ȧ���� ���

	for (int i = 1; i < 11; i++) {
		if (i % 2 == 0)
			continue;

		std::cout << i << "  ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
	*/
	/*
	// 1���� 50���� �ݺ�, 3�� ����� 5�� ������� �˻��ϱ�
	for (int i = 1; i <= 50; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			std::cout << i << "�� 3�̳� 5�� ����Դϴ�" << std::endl;
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
	// 1���� 100���� �� ���ϱ�

	int sum = 0;

	for (int i = 1; i <= 100; i++) {
		sum += i;
	}
	std::cout << sum << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	*/

	/*
	// ��ø for

	for (int i = 0; i < 3; i++) {				// �� for
		for (int j = 1; j < 4; j++) {			// �� for
			std::cout << i * 3 + j << "  ";
		}
		std::cout << std::endl;
	}
	*/

	/*
	// 2�� for���� ���� 2�ܺ��� 9�ܱ��� ������
	for (int i = 2; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			std::cout << i << " * " << j << " = " << i * j << std::endl;
		}
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
	*/

	// 2�� for���� ���� 2�ܺ��� 9�ܱ��� ������
	for (int i = 1; i < 10; i++) {
		for (int j = 2; j < 10; j++) {
			std::cout << j << "*" << i << "=" << j * i << "\t";
		}
		std::cout << std::endl;
	}

	/*
	// ���� �Է��� ���ڰ� ������� �˻��ϴ� ���α׷��� ����ٸ�?
	int numInputs;	// ���� �Է��� ������ ����
	bool isPositive = true;		// ��� ���ڰ� ������� ���θ� �Ǵ�

	std::cout << "�Է��� ������ ���� : ";
	std::cin >> numInputs;

	for (int i = 0; i < numInputs; i++) {
		int num;
		std::cout << "���� �Է� : ";
		std::cin >> num;

		if (num <= 0) {
			isPositive = false;
		}
	}

	std::cout << "��� ���ڰ� ������� ���� : " << isPositive << std::endl;
	*/

	std::cout << std::endl;
	std::cout << std::endl;

	// �����
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

	// ������ x�� ����
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

	// y�� ����
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

	// x, y �� ����
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