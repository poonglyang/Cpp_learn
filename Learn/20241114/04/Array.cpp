/*
[�迭]
	������ Ÿ���� ���� ���� ���������� ������ �� �ִ� ������ ����
	�޸𸮿��� �������� ������ ������ �� ��Ҵ� �ε����� ���� ������ �� �ִ�.
	�迭�� ���� �� �� ������ ũ�⸦ ������ �� ����.
	�迭�� ��� ��Ҵ� ������ ������ Ÿ���� ������ �Ѵ�.
	���ӵ� ������ ����Ǳ� ������ ��ҿ� ���� �ε��� ������ �ſ� ������.

[����]
	�ڷ��� �迭[�迭 ����];


*/


#include <iostream>
#include <list>
#include <vector>
int main() {
	// 1. ũ�⸦ ����ϰ� �ʱ�ȭ
	int intArr[4] = { 1,2,3,4 };

	// 2. �迭�� ũ�⸦ �����ϰ� �ʱ�ȭ
	int intArr2[] = { 1,2,3 };	// ũ�⸦ �˾Ƽ� 3���� ����

	// 3. ũ�⸦ ��������� �����ϰ� �Ϻ� ��Ҹ� �ʱ�ȭ
	int intArr3[5] = { 1,2,3 };	// �������� 0���� �ʱ�ȭ

	// 4. ��� ��Ҹ� �ʱ�ȭ ���� ������ �⺻������ �ʱ�ȭ �� (0)
	int intArr4[5] = {};	// ���� �ʱ�ȭ
	
	std::cout << intArr[0] << std::endl;

	for (int i = 0; i < sizeof(intArr) / sizeof(int); i++) {
		std::cout << intArr[i];
	}
	std::cout << std::endl;

	int numbers[5] = { 10,20,30,40,50 };

	for (int i = 0; i < 5; i++) {
		std::cout << "�� �ε����� �����Ͽ� ��� : " << i << " : " << numbers[i] << std::endl;
	}

	std::cout << std::endl;

	std::cout << "�迭 intArr[0]�� �ּ� : " << intArr << std::endl;		// �迭�� ���� �ּҰ� ���� (�迭�� ���� �ּҴ� �迭�� 0��° �ּҿ� ����)
	std::cout << "�迭 intArr[0]�� �ּ� : " << &intArr[0] << std::endl;	// �迭[0]�� �ּҰ� ����
	std::cout << "�迭 intArr[1]�� �ּ� : " << &intArr[1] << std::endl;	// �迭[1]�� �ּҰ� ����
	std::cout << "�迭 intArr[1]�� �ּ� : " << &intArr[2] << std::endl;	// �迭[2]�� �ּҰ� ����
	std::cout << "�迭 intArr[1]�� �ּ� : " << &intArr[3] << std::endl;	// �迭[3]�� �ּҰ� ����
	// �ּ� ���� ���� ���������� 4byte�� �����ϴ� ���� Ȯ���� �� �ִ� -> �������� ������ ����ȴ�

	std::cout << std::endl;

	// �迭�� ����� ���ڸ� ã�ƺ��ô�
	int intArr5[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int select;
	bool isFind = false;
	std::cin >> select;

	// �Է°� ó���� �����ض�
	for (int i = 0; i < 10; i++) {
		if (intArr5[i] == select) {
			isFind = true;
			std::cout << "�ε��� : " << i << "�� �ֽ��ϴ�. ";
			break;
		}
	}

	if (isFind) {
		std::cout << "ã��" << std::endl;
	}
	else {
		std::cout << "����" << std::endl;
	}

	// �迭�� ����� ��� ����� ���� ���Ͻÿ�

	int intArr6[] = { 1,2,3,4,5 };

	int sum = 0;
	for (int i = 0; i < sizeof(intArr6) / sizeof(int); i++) {
		sum += intArr6[i];
	}
	std::cout << "\n\n�հ� : " << sum << std::endl;


}