#pragma once
#include <iostream>

template <typename T>
class Singleton
{
private:
	Singlteon() {
		std::cout << "½Ì±ÛÅæ ÀÎ½ºÅÏ½º »ý¼º" << std::endl;
	}

	Singlteon(const Singlteon&) = delete;				// º¹»ç ¹æÁö

	Singlteon& operator=(const Singlteon) = delete;		// ´ëÀÔ ¹æÁö

	~Singlteon() {

	}

public:
	static Singlteon& GetInstance() {
		static Singlteon T;

		return T;
	}

	void Show() {
		std::cout << "½Ì±ÛÅæ" << std::endl;
	}
};

