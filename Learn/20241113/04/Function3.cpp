/*
[�Լ� ���� �ε�]
	������ �Լ� �̸��� ����ؼ� �Ű������� Ÿ��, ����, �Ǵ� ������ �ٸ��� �����ϴ� ��
	����� ��Ȱ�� �ϴ� ���� �Լ��� ���� �� �� �Լ��� �ٸ� �̸��� �ο��ϴ� �� ��ſ� �����ε��� ����ϸ� 
	�ڵ��� �������� ���Ǹ� �ϳ��� �Լ��̸����� �پ��� ������ �Լ��� ȣ�� �����ϴ�

[�Լ� �����ε� ���� ����]
	1. �Լ� �̸��� �����ؾ� �Ѵ�
	2. ���� Ÿ���� �������� �ƴϴ�
	3. �Ű������� ������ Ÿ���� �ٸ��ų� ������ �޶�� �Ѵ�

üũ ����
	�Լ� �����ε��� �����ΰ���?
	�Լ� �����ε��� �������̵��� �������� �����ΰ���
	
*/



#include <iostream>

int Add(int a, int b) {
	return a + b;
}

float Add(float a, float b) {
	return a + b;
}

int Sub(int num1, int num2) {
	return num1 - num2;
}

float Sub(float num1, float num2) {
	return num1 - num2;
}

int Mul(int num1, int num2) {
	return num1 * num2;
}

float Mul(float num1, float num2) {
	return num1 * num2;
}

int Div(int num1, int num2) {
	return num1 / num2;
}

float Div(float num1, float num2) {
	return num1 / num2;
}

float SqExtend(float row, float col) {
	return row * col;
}

float CirExtend(float r) {
	return r * r * 3.14f;
}

int main() {
	std::cout << "�� ���� ��, " << Add(33.23f, 11.8f) << "   " << Add(3, 8) << std::endl;
	std::cout << "�� ���� ��, " << Sub(20.83f, 1.54f) << "   " << Sub(3, 8) << std::endl;
	std::cout << "�� ���� ��, " << Mul(20.83f, 1.54f) << "   " << Mul(3, 8) << std::endl;
	std::cout << "�� ���� ������, " << Div(20.83f, 1.54) << "   " << Div(3, 8) << std::endl;

	std::cout << "�簢���� ���� : " << SqExtend(20, 3) << std::endl;
	std::cout << "���� ���� : " << CirExtend(3.3f) << std::endl;


	/*
		1. ���ϱ�, ����, ���ϱ�, ������, �Լ� �����
			�����ε��� ����� Ȱ���� �������� �Ǽ����� ������
		2. �簢���� ���� ������ ����ϴ� �Լ��� ������

		3. 
	*/


}