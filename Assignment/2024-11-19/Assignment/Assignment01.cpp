/*
멤버 초기화 리스트를 활용하여 객체초기화를 하고 출력해보기
*/

#include <iostream>

class Class1 {
public:
	std::string str1;
	int num1;
	double double1;
	Class1(const std::string& str, const int num, const double dou) : str1(str), num1(num), double1(dou) {
	};
	
};

int main() {
	Class1* c1 = new Class1("문자열1", 50, 1.77245);

	std::cout << c1->str1 << ", " << c1->num1 << ", " << c1->double1;

	delete c1;
	c1 = nullptr;
}