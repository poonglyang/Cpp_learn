#pragma once
#include <iostream>
/// <summary>
/// �Ź�� �̱���
/// </summary>
template <typename T>
class Singleton_New {
private:
	Singleton_New() {
		std::cout << "�̱��� �ν��Ͻ� ����" << std::endl;
	}

	Singleton_New(const Singleton_New&) = delete;				// ���� ����

	Singleton_New& operator=(const Singleton_New) = delete;		// ���� ����

	~Singleton_New() {

	}

public:
	static Singleton_New& GetInstance() {
		static Singleton_New T;

		return T;
	}

	void Show() {
		std::cout << "�̱���" << std::endl;
	}
};

