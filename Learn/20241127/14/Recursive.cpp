/*
Recursive (��� �Լ�)
	�ڱ� �ڽ��� ȣ���ϴ� �Լ�
	�ݵ�� ���� ������ �־�� �Ѵ� (���� ����, ���� ����)
	
	�ݺ����� ��� ��ͺ��� �޸𸮸� ���� ���������
	������ ������ �ذ��ϱ� ��ƴ�
	���� ��� �ݺ� Ƚ���� �𸣴� ��� ��� �� ���ΰ�

	�Լ��� ���� ���´� ���� �޸𸮿� ����ȴ�
		-> ���ȣ���� �ʹ� ���� �Ͼ�� ���� �����÷ο찡 �Ͼ��



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
// ȣ�� �ܰ�
//	1. Factorial(4)���� ���� ���� Ȯ�� �� return 4 * Factorial(3)
//	2. Factorial(3)���� ���� ���� Ȯ�� �� return 3 * Factorial(2)
//	3. Factorial(2)���� ���� ���� Ȯ�� �� return 2 * Factorial(1)
//	4. Factorial(1)���� ���� ������ ���� �ϹǷ� return 1
//	5. 3.���� return 2 * 1
//	6. 2.���� return 3 * (2 * 1)
//	7. 1.���� return 4 * (3 * (2 * 1))�� �Ѵ�

int main() {
	std::cout << Factorial(4) << std::endl;
}