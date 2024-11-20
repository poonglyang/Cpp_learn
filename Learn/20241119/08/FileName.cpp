#include <iostream>

class ParentClass {
public:
	int x;
	int y;

	virtual int Calc() {
		std::cout << "ParentClass�� Calc" << std::endl;
		return x + y;
	}

	void SetXY(int x, int y) {
		this->x = x;
		this->y = y;
	}

	int GetY() {
		return y;
	}
};

class ChildClass : public ParentClass {
public:
	int Calc() override {
		std::cout << "ChildClass�� Calc" << std::endl;
		return x - y;
	}

	int GetX() {
		return x;
	}
};


int main() {
	ChildClass cs;
	cs.SetXY(10, 5);

	ParentClass ps;
	ps.SetXY(10, 5);

	std::cout << "�θ��� Calc : " << ps.Calc() << std::endl;
	std::cout << "�ڽ��� : " << cs.Calc() << std::endl;

	// cs���� x�� ������ 
	std::cout << "cs���� ���� x�� : " << cs.GetX() << std::endl
		<< "cs���� ���� Y���� �������� �Լ� : " << cs.GetY() << std::endl << std::endl;
}