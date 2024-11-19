#include <iostream>

class ParentClass {
public:
	int x;
	int y;

	int Calc() {
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
	int Calc() {
		return x - y;
	}

	int GetX() {
		return x;
	}
};


int main() {
	ChildClass cs;
	cs.SetXY(10, 5);

	// cs���� x�� ������ 
	std::cout << "cs���� ���� x�� : " << cs.GetX() << std::endl
		<< "cs���� ���� Y���� �������� �Լ� : " << cs.GetY() << std::endl << std::endl;
}