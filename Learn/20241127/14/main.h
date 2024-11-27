#pragma once
#include <iostream>
/// <summary>
/// ½Å¹æ½Ä ½Ì±ÛÅæ
/// </summary>
template <typename T>
class Singleton_New {
private:
	Singleton_New() {
		std::cout << "½Ì±ÛÅæ ÀÎ½ºÅÏ½º »ý¼º" << std::endl;
	}

	Singleton_New(const Singleton_New&) = delete;				// º¹»ç ¹æÁö

	Singleton_New& operator=(const Singleton_New) = delete;		// ´ëÀÔ ¹æÁö

	~Singleton_New() {

	}

public:
	static Singleton_New& GetInstance() {
		static Singleton_New T;

		return T;
	}

	void Show() {
		std::cout << "½Ì±ÛÅæ" << std::endl;
	}
};

