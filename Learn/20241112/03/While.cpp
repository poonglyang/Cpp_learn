/*
[while]
	������ ��(true)�� ���� Ư�� �ڵ带 �ݺ� �����ϱ� ���� �ݺ���
	������ ������ �� ������ ��� �ݺ��ȴ�.
	�Ϲ������� �ݺ�Ƚ���� �̸� �������� �ʾҰų� Ư�� ������ ������ ������ �ݺ��ؾ��ϴ� ��� ���

	���� ������ �־�� ���� ����

[do-while]
	������ ������ ���ο� ������� �ڵ� ����� �ּ� �ѹ��� �����ؾ� �� �� ���
	

do {
	// ������ �ڵ�
} while(true) -> do ����� ����� �Ŀ� ���� ��. ������ ���̸� �ڵ� ��� �ٽ� ���� �����̸� ����

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
	// 1. while���� �̿��� �Է��� ���ڸ�ŭ ���
	/*
	int n;
	std::cout << "���� �Է� : ";
	std::cin >> n;

	int count = 0;

	while (count < n) {
		std::cout << "���" << std::endl;
		count++;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	*/
	// 2. ������ �Է��� ��� �ް� �Է� ���� ���ڴ� �����Ͽ� ���Ѵ�. 0�� �Է��ϸ� ��� ���ڸ� ���ϰ� �����Ѵ�.
	/*
	int inputNum;
	int total = 0;

	while (true) {
		std::cout << "���� �Է�(�����Ϸ��� 0�Է�) : ";
		std::cin >> inputNum;
		if (inputNum == 0)
			break;
		
		total += inputNum;
	}

	std::cout << total << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	*/

	// do while�� while() {} �� �ٸ��� ����� ���� �����Ű�� ������ Ȯ���ϱ� ������ �ּ� 1�� ��µȴ�
	/*
	int inputNum = 0;
	int total = 0;

	do {
		std::cout << "0���� ū ���� �Է��϶� : ";
		std::cin >> inputNum;
		total += inputNum;
	} while (inputNum > 0);
	*/
	
	srand(time(NULL));		// �õ� ���� ������ �ִ� �Լ�

	int random1 = rand();	// ������ �����ϴ� �Լ� // �õ尪�� ���α׷� ������ �� �����Ǿ� ���� ���� ���´�
	random1 = rand() % 3;	// 0,1,2 �� �ϳ��� ��ȯ
	std::cout << random1 << std::endl;

	


}