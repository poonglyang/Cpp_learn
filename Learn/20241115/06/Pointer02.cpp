/*
* [������]
*	������ ������ +,-
*	������ ������ �� �� �ڷ����� ũ�⿡ ����Ͽ� �����ϰų� ���� �Ѵ�

[����]
	�� �����Ͱ� �ٸ� �����Ϳ� ������ �޸� �ּҸ� ����Ű���� �Ѵ�.
	���� �޸� �ּҸ� ����Ű�� ���� �����ϴ�
	�������� Ÿ���� ��ġ�ؾ� �Ѵ�
	���� �����Ͱ� ������ �޸� �ּҸ� ����Ű�� �޸� ������ �� �� ������ �߻��� �� �ִ�.

[�������� Ÿ��]
	�����Ϳ��� �� Ÿ���� ������?
	���࿡ �����Ͷ�� Ÿ���� �ִٸ�
	int a;
	int* p;
	Pointer(��� Ÿ���� �ִٰ� �� ��)* p;
	p = &a;
	
	p�� a�� �ּҰ��� ����Ǿ� ����.
	������ a�� �޸𸮿��� �����ϴ� ��� �ּҵ��� ��ġ�� �� �ִ°� �ƴ϶�
	���� �ּҸ� �� �ִ�.

	��, ��ǻ�Ͱ� �޸𸮿��� �󸶸�ŭ �о� �鿩�� ���� �� ����� ����.

*/

#include <iostream>

using namespace std;

int main() {
	int a;
	int* pa = &a;
	
	cout << "pa�� �� : " << pa << endl;

	cout << (pa + 1) << endl;
	cout << (pa++) << endl;
	cout << (pa - 1) << endl;

	cout << endl << endl;

	int num = 10;
	int* pA = &num;		// num�� �ּҰ� ����
	int* pB = pA;		// pA�� ��(num�� �ּ�)�� ����

	cout << *pA << endl;
	cout << *pB << endl;

	cout << endl << endl;

	int intA = 10;
	int* pIntA = &intA;
	// double* dp = pIntA;		// �ٸ� Ÿ���� �����ʹ� ���� ������ �ȵȴ�.

	cout << endl << endl;

	double testFloat;
	double* pTF = &testFloat;
	cout << pTF << endl;
	cout << (pTF + 1) << endl;


}