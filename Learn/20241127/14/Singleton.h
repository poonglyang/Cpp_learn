#pragma once
#include <iostream>

template <typename T>
class Singleton
{
private:
	Singlteon() {
		std::cout << "�̱��� �ν��Ͻ� ����" << std::endl;
	}

	Singlteon(const Singlteon&) = delete;				// ���� ����

	Singlteon& operator=(const Singlteon) = delete;		// ���� ����

	~Singlteon() {

	}

public:
	static Singlteon& GetInstance() {
		static Singlteon T;

		return T;
	}

	void Show() {
		std::cout << "�̱���" << std::endl;
	}
};

