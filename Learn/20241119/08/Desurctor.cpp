/*
�Ҹ���
	��ü�� �Ҹ�� �� �ڵ����� ȣ��Ǵ� �Լ�
	�Ű����� ����
	��ȯ�� ����
	�����ε� �Ұ�


*/


#include <iostream>

class MyClass
{
public:
	// ������
	MyClass(int size);

	// �Ҹ���
	~MyClass();

private:
	int* data;
};

MyClass::MyClass(int size)
{
	data = new int[size];
	std::cout << "������" << std::endl;
}

MyClass::~MyClass()
{
	delete[] data;							// �迭�� ��� delete[]�� �������Ѵ�
	data = nullptr;
	std::cout << "�Ҹ���" << std::endl;
}

class ParentClass {
protected:
	int x;
	int y;

};

class ChildClass {

};

int main() {
	MyClass* m = new MyClass(10);
	//m->~MyClass();


	delete m;
	m = nullptr;
}
