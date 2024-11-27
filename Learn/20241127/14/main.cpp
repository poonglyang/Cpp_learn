/*
[디자인 패턴]
	싱글톤
		오직 한개의 인스턴스만을 담도록 보장한다
		클래스의 객체가 복사 x
		
		장점 :	한 곳에서 전역적으로 가져와 처리 가능
				단일 인스턴스
					-> 효율적인 관리

		단점 : 디버깅이 힘들다



*/

#include <iostream>
#include "main.h"

/// <summary>
/// 구식 싱글톤
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
		std::cout << "같음" << std::endl;
	}*/

a7:
	std::cout << "건너 뛰기" << std::endl;
}