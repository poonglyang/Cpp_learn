/*
[����ȯ]
	������ ���� �� ������ Ÿ�Կ��� �ٸ� ������ Ÿ������ ��ȯ�ϴ� �۾�.

	1. �Ͻ���(������) ����ȯ
		�����Ϸ��� �ڵ����� �ڷ����� ��ȯ
		�ַ� ���� �ڷ����� ū �ڷ������� ��ȯ
		ū �ڷ����� ���� �ڷ������� ��ȯ�� ���������� ������ �ս��� �߻��� ���ɼ��� ����


	2. ����� ����ȯ
		����ڰ� ���� ����ȯ�� �Ѵ�

		a. C ��Ÿ�� ����� ����ȯ
			���������� �����ϴ�
			��ȣ �ȿ� ���ϴ� ������ Ÿ���� ����Ͽ� ������ ���� ��ȯ
			(type)value
				(type)	: ��ȯ �Ϸ��� ������ Ÿ��
				value	: ��ȯ ���
			������, �⺻��, ����� ���� Ÿ�� �� ���� ��� ������ Ÿ�Կ� ���� ���� �����ϴ�
			C++ ����ȯ ��Ŀ� ���ؼ� � ��ȯ�� �̷�������� ��Ȯ���� ���� �� �ִ�
			�߸��� ����ȯ���� ���� ��Ÿ�� ������ ������ �ս��� �߻��� �� �ִ�
			
		b. C++ ����� ����ȯ
			����ȯ�� �� �����ϰ� ��Ȯ�ϰ� �ϱ� ���� ĳ��Ʈ �����ڸ� ����

			1. static_cast
				������ Ÿ�ӿ� Ÿ���� ��ȯ�ϴµ� ���. 
				�ַ� �⺻ Ÿ�� ���� ��ȯ�� ���.
				�����Ϸ��� ��ȯ�� �������� �˻��ϱ� ������ �߸��� ��ȯ�� ������ �� �ִ�
				UpCasting ���� ����ϱ� �Ѵ�.
				������ ��� �������� Ÿ�� ��ȯ�� ȥ���� �� �� ���� �� ��������� �����°� �������� ������ �� �� �ִ�.
				
			2. dynamic_cast
				��Ÿ�ӿ� Ÿ�� ��ȯ�� ����
				�ַ� DownCasting�� ����Ѵ�
				�������� �����ϸ� Ÿ���� ���� �ʴ´ٸ� nullptr�� ��ȯ��Ų��
				RTTI(Runtime Type Information) ������� �۵��Ѵ�

			3. const_cast
				��ü�� ������� �����ϰų� �߰��� ��

			4. reinterpret_cast
				�ſ� ���������� �� �� ����ϸ� ����� ������ �ʷ��� �� �ִ�.



*/

#include <iostream>

using namespace std;

int main() {
#pragma region �Ͻ��� ����ȯ
	cout << "�Ͻ��� ����ȯ" << endl;
	int num1 = 10;
	double double1 = num1;	// int -> double�� ����ȯ

	cout << double1 << endl << endl;

#pragma endregion

#pragma region ����� ����ȯ (C)
	cout << "����� ����ȯ (C)" << endl;

	int num2 = 10;
	float float1 = (float)num2;	// int -> float

	double double2 = 3.14;
	int num3 = (int)double2;

	cout << "float�� ����ȯ �� : " << float1 << ", double���� int�� ����ȯ �Ǿ� �Ҽ��� ���� ���ư� : " << num3 << endl;

	// ������ Ÿ�� ����ȯ
	int num4 = 40;
	void* ptr = (void*)&num4;
	int* intPtr = (int*)ptr;

	cout << endl;
#pragma endregion

#pragma region ����� ����ȯ (C++)
	cout << "����� ����ȯ C++" << endl;

	int num5 = 10;
	double double3 = static_cast<double>(num5);	// num5�� double���·� ĳ���� �ϰڴ�

	cout << double3 << endl;


	double double4 = 3.14;
	//char* charPtr = static_cast<char*>(double4);	// �̷������� �ȵȴٴ� ���� ������ �����ش�
#pragma endregion

	
}