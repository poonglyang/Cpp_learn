/*
��� �ʱ�ȭ ����Ʈ�� Ȱ���Ͽ� ��ü�ʱ�ȭ�� �ϰ� ����غ���
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
	Class1* c1 = new Class1("���ڿ�1", 50, 1.77245);

	std::cout << c1->str1 << ", " << c1->num1 << ", " << c1->double1;

	delete c1;
	c1 = nullptr;
}