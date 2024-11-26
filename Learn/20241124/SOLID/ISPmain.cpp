/*
I(Interface Segregation Principle, ISP, �������̽� �и� ��Ģ)
	Ŭ���̾�Ʈ�� ������� �ʴ� �ż��忡 �������� �ʾƾ� �ϴ� ��Ģ
	�������̽��� ������� �ʿ信 �°� �۰� ��ü�� ����. Ŭ���̾�Ʈ�� ���ʿ��� ��ɿ� �������� �ʵ���
	Ư�� Ŭ���̾�Ʈ�� �ʿ�� �ϴ� ��ɸ��� �����ϴ� �������̽��� ����

*/

#include <iostream>
using namespace std;

class Animal {
public:
	virtual void Eat() = 0;
	virtual void Sleep() = 0;
};

class Mammalia : public Animal {
	virtual void Swiming() = 0;
};

class Bird : public Animal {
public :
	virtual void Fly() = 0;
};

class Dog : public Mammalia {
public:
	void Eat() override {
		cout << "���" << endl;
	}

	void Sleep() override
	{	
		cout << "�� �� ����" << endl;
	}

	/*void Fly() override {
		cout << "���� ���ݾ�" << endl;
	}*/

	void Swiming() override
	{
		cout << "�����ϱ�" << endl;
	}
};