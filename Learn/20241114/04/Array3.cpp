#include <iostream>
#include <algorithm>

/*
2���� �迭�� �޸� ������ �����̴�

*/

int main() {
	//int arr[4][3];

	//arr[0][0] = 1;
	//arr[0][1] = 2;
	//arr[0][2] = 3;

	//arr[1][0] = 4;
	//arr[1][1] = 5;
	//arr[1][2] = 6;

	//arr[2][0] = 7;
	//arr[2][1] = 8;
	//arr[2][2] = 9;

	//arr[3][0] = 10;
	//arr[3][1] = 11;
	//arr[3][2] = 12;

	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		std::cout << arr[i][j] << "\t";
	//	}
	//	std::cout << std::endl;
	//}

	//std::cout << std::endl;

	//int arr2[4][3] = {
	//	{1,2,3},
	//	{4,5,6},
	//	{7,8,9},
	//	{10,11,12}
	//};

	//int arr3[4][3] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	//for (int i = 0; i < 4; i++) {
	//	for (int k = 0; k < 3; k++) {
	//		std::cout << arr3[i][k];
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << std::endl;

	//// 2�� �迭�� ����Ͽ�
	//// �� ����Ʈ���� ����� ��� �ִ�
	//// �� ������ 3���� ȣ�Ǹ� �����ϰ� 3������ �ִ�
	//// �� �� �� ȣ�� ������ ��� ����� �Է¹ް� ����Ʈ�� �� ����� ��� �ִ��� �������϶�

	//int apt[3][3];
	//int total = 0;

	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		std::cout << i + 1 << "�� " << i+1  << "0" << j+1 << "ȣ���� ����� ��� �ֳ���? : ";
	//		std::cin >> apt[i][j];
	//	}
	//}

	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		total += apt[i][j];
	//	}
	//}

	//std::cout << "����Ʈ���� �� " << total << "���� ��� �ֽ��ϴ�" << std::endl;


	char name[6] = "hello";
	// ��ǻ���� ���ڿ��� �������� ��Ÿ���� null�� �ڵ����� �߰��ϱ⿡ helloa�� outofrange�� ����

	std::cout << name << std::endl;

	char name1[] = { 'h','e','l','l','o','\0'};		// �̷��� ������ �ϸ� �ڵ����� null���ڰ� ���Ե��� �ʱ� ������ �ڰ� �̻��ϰ� ���
													// �������� null(\0)�� ������ �ȴ�

	std::cout << std::endl << std::endl << name1;

	for (int i = 0; i < 5; i++) {
		std::cout << name1[i];
	}

	std::cout << std::endl << std::endl;
	std::string s = "�̰� ��� �� ����";

	// const char* : ���ڿ��� ���� �ּҸ� ����Ų��
	const char* str = "hello";

	std::cout << str << std::endl;
	std::cout << &str << std::endl;
	std::cout << &str[0]  << std::endl;

	/*
	hello : 

	�ּ� :	1000, 1001, 1002, 1003, 1004, 1005
	�� :		h	  e	    l	  l		o	  \0
	
	
	*/

	const char* str3 = "abce";
	std::cout << &str3 << std::endl;

	str3 = "efgh";
	std::cout << &str3 << std::endl;


	const char* const str2 = "aaa";
	

	/*
	const char * a = "Hello" ��
		���ڿ��� ����� �޸� �ּҸ� ����Ű�� �����͸� ����
		������ ��ü�� ����� �ƴ����� ����Ű�� ����� ���

	const char ab[] = "ddd"�� �������� �����ΰ�


	
	
	*/
}