/*
������ ���� �Ⱓ�� ���� ����
	����Ǵ� ��ġ�� ���� ũ�� ���������� ���������� ������
	�޸𸮻� �����ϴ� �Ⱓ�� ������ �� �ִ� ������ ���� �������� �ִ�.

	1. ���� ����
		���������� �߰�ȣ ���� ����Ǵ� ������ ��� ��������
		Ȱ�� ���� : ������ ����� ��� �������� ��ȿ, ����� ������ �޸𸮿��� ������� ��

	2. ���� ����
		��� �ܺο��� ����, ���α׷� ��ü�� ���� ����
		���α׷� �� ��� �Լ����� ���� ����
		���α׷� ���� ���۽� �����ǰ� ���α׷��� ����Ǹ� �Ҹ�
		���������� �����϶�

	3. ��� ���� (const)
		������ �� ���� ���� 
		�������� ������ �ش�
		����� �ʱ�ȭ�� ����� �Ѵ�
		�Լ��� �Ű��������� �� �� �ִ�
		const int a �� const�� ���� ����

*/

#include <iostream>
int GlobalNum = 10;

void GlobalVariable() {
	std::cout << "���⼭�� ���� ���� " << GlobalNum << std::endl;
}

void LocalVariable() {
	int num = 1; 
	{
		num = 2;
		int num1 = 5;
	}
	
}

void MyFuncOne() {
	int myFuncOneNum = 10;
	myFuncOneNum++;
	std::cout << "�������� myFuncOneNum�� ������ : " << myFuncOneNum << std::endl;
}

void MyFuncTwo() {
	int num1 = 10;
	int num2 = 10;
	num1++;
	num2--;
	std::cout << "�������� num1 : " << num1 << "�������� num2 : " << num2 << std::endl;
}

int Add(int num1, int num2);

//int Sum(const int num1, int num2) {
//	//num1 = 5; //<- �ȵ� �Ű������� ���͵� const�� �� ������ �����ش�
//
//}

int Sum(int a, int b = 5, int c = 1) {
	return a + b + c;
}

int main() {
	std::cout << " " << GlobalNum << std::endl;

	GlobalVariable();

	MyFuncOne();

	MyFuncTwo();

	const int a = 1;	// ���� �Ұ�

	std::cout << Sum(1, 3, 5) << std::endl;
	
}

int Add(int num1, int num2)
{
	return num1 + num2;
	
}
