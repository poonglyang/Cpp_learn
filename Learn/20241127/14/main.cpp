/*
[������ ����]
	�̱���
		���� �Ѱ��� �ν��Ͻ����� �㵵�� �����Ѵ�
		Ŭ������ ��ü�� ���� x
		
		���� :	�� ������ ���������� ������ ó�� ����
				���� �ν��Ͻ�
					-> ȿ������ ����

		���� : ������� �����



*/

#include <iostream>
#include "main.h"

/// <summary>
/// ���� �̱���
/// </summary>
class Singleton_Old {
private:
	static Singleton_Old* instance;


public:
	Singleton_Old() {
		
	}

	~Singleton_Old() {
		delete instance;
	}

	static Singleton_Old* GetInstance() {
		if (instance == nullptr) {
			instance = new Singleton_Old();
		}
		else return instance;
	}
};


int main() {
	/*Singleton_New& s1 = Singleton_New::GetInstance();

	s1.Show();

	goto a7;

	Singleton_New& s2 = Singleton_New::GetInstance();
	s2.Show();*/

	/*if (&s1 == &s2) {
		std::cout << "����" << std::endl;
	}*/

a7:
	std::cout << "�ǳ� �ٱ�" << std::endl;
}