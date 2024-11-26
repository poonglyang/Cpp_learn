/*
[static]
	���������� �� ���� �ܺο��� ����� �� ���� ������ ���ο����� ����� �� ����
	�Լ� ������ ����� static ������ �Լ��� ������ ���� �ִ�(�����ֱ⸦ �Լ��� �������� �ʴ´�)

[extern]
	�ܺο� �ִ� ���������� ����� �� ����


*/

#include <iostream>

extern int GlovalValue;

extern int staticGValue;

/*
	Ŭ���������� static ������ �Լ�
		Ŭ���� static�� ����� ������ �ش� Ŭ������ ��� �ν��Ͻ����� �����ȴ�
		�ν��Ͻ����� �������� ���Ǵ� ����
		Ŭ������ �ν��Ͻ��� ��� ������ �����ϴ�

		1. Ŭ���� ���� �ɹ� ����
			��� Ŭ���� �ν��Ͻ��� �����ϴ� ����
			Ŭ������ ��� �ν��Ͻ��� �ش� ������ ���� ����
			�ϳ��� �ν��Ͻ����� ������ �����ϴ� �ٸ� �ν��Ͻ������� �ݿ� �ȴ�
			Ŭ���� �ۿ��� �ʱ�ȭ�� ���ش�

		2. Ŭ���� ���� �ɹ� �Լ�
			Ŭ������ �ν��Ͻ� ���� ȣ���� �� �ִ� �Լ�
			���� �ɹ��Լ��� Ŭ������ ���� �ɹ��������� ���� ����
			�ν��Ͻ� �ɹ� ������ �Լ����� ���� �Ұ�

*/
extern class CountClass
{
private:
	int num;
	static int count;

	// C++ 17�̻���ʹ� inline�� �տ� ���̸� �ʱ�ȭ �����ϴ�
	inline static int count2 = 200;


public:
	CountClass() {
		count++;
	}


	static int GetCount() {
		return count;
	}

	void Print() {
		std::cout << "����Ʈ �Լ�" << std::endl;
	}

	static int Sum(int a, int b) {
		count = 1;	// ���� �ɹ� �����̱⿡ ��� ����
		// num = 2;	// static�� ���� �ɹ������̱⿡ �Ұ�

		GetCount();	// ���� �ɹ� �Լ��̱⿡ ����
		//Print();	// �Ϲ� �ɹ� �Լ��̱⿡ �Ұ���

	}
};

int CountClass::count = 0;	// Ŭ���� �ۿ��� �ʱ�ȭ�� ���ش�

/*
	�Լ������� static����
*/
void Count() {
	static int count = 0;				// �� �ѹ��� �ʱ�ȭ �ȴ�
	count++;
	std::cout << count << std::endl;
}



int main() {

	std::cout << GlovalValue << std::endl;

	std::cout << GlovalValue << std::endl;

	//std::cout << staticGValue << std::endl;
	GlovalValue = 10;
	//std::cout << staticGValue << std::endl;
	
	Count();
	Count();

	CountClass c1;
	CountClass c2;
	CountClass c3;

	
	std::cout << CountClass::GetCount() << std::endl; // �ν��Ͻ� ���� ���� ���� ��ɾ�� ��ȯ �����ϴ�
}