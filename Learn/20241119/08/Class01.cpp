/*
Class
	��ü ���� ���α׷���, ���� ���� ���α׷���
	��ü ���� ���α׷����� �츮�� ��� �ִ� ���� ���谡 ��ü��� �����Ǿ� �ִ� ��ó�� ����Ʈ��� ��ü�� �����ϴ� ���

	���� ���迡���� ���� ��ü�� �����ϰ� ��ü ��������� ������ ����� �����ϸ鼭
	�ٸ� ��ü��� ��ȣ�ۿ��� �Ѵ�.

Class�� �⺻ ����
	1. Ŭ���� ����
		Ŭ������ class Ű����� ����

	2. ��� ����
		Ŭ���� ���ο� ���ǵ� ������ ��ü�� ����(�Ӽ�)�� ����

	3. �ɹ� �Լ�
		Ŭ���� ���ο� ����ǰ� ����, ��ü�� ������ ����

��ü�� �����ΰ�
	Ŭ������ ��ü�� �����ϴ� Ʋ�̳� ���赵.
	��ü�� ���赵�� ������� ��üȭ�� ��Ų��.

���� ���� ������
	public : ���� ���� ����
	private : Ŭ���� ���ο����� ��� (�ɹ� ����)
	protected : �ڽŰ� ��� ���迡 �ִ� �͵鸸 ���� ����

���� �Ҵ�� ���� �Ҵ�
	���� �Ҵ�
		������ ������ �޸� ũ�Ⱑ ������
		����
		���α׷��� ���� �� ������ �ڵ��� ������
		ũ�⸦ �̸� �����ؾ� �ϹǷ� �������� �������� �޸� ������ �����ǹǷ� ��ȿ������ ���� �ִ�.
	���� �Ҵ�
		��Ÿ�� ���߿� �޸𸮸� �Ҵ���
		��
		ũ�⸦ �����ϰ� ������ �� ������ ��Ÿ�� �� �ʿ��� ��ŭ �޸𸮸� �Ҵ�
		���� �����ؾ��ϱ� ������ �޸� ���� ���輺�� �ִ�
		���� �Ҵ� �� �ݵ�� �����ؾ� �Ѵ�
		ũ�⸦ �̸� �� �� ���ų� ���� �߿� ����� ���ɼ��� �ִ� ���

*/

#include <iostream>
using namespace std;

class test {
	// �ɹ� ����
	int num1;
	int num2;

	// ��� -> �ɹ� �Լ�
	void add() {

	}

};

class Circle {

	float radius;

	string color;

public:
	Circle(float radius, string color) {
		this->radius = radius;
		this->color = color;
	}

	float calcArea() {
		return pow(radius, 2) * 3.14;
	}

	float GetRadius() {
		return radius;
	}

	string GetColor() {
		return color;
	}

};

class Student {
private:

public :
	Student();
	~Student();
	void Print();
};

Student::Student()
{

}

Student::~Student()
{

}

void Student::Print()
{

}

int main() {
	// ���� �Ҵ�
	Circle c = Circle(3, "red");

	cout << "���� ������ : " << c.GetRadius() << ", ���� ���� : " << c.calcArea() << endl;

	// ���� �Ҵ�
	Circle* c2 = new Circle(1.5, "blue");
	cout << "���� ������ : " << c2->GetRadius() << ", ���� ���� : " << c2->calcArea() << endl;

	free(c2);
}


