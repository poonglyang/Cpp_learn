#include <iostream>

class ParentClass {
public:
	int x;
	int y;

	virtual int Calc() {
		std::cout << "ParentClass의 Calc" << std::endl;
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
		std::cout << "ChildClass의 Calc" << std::endl;
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

	std::cout << "부모의 Calc : " << ps.Calc() << std::endl;
	std::cout << "자식의 : " << cs.Calc() << std::endl;

	// cs에는 x가 없지만 
	std::cout << "cs에는 없는 x값 : " << cs.GetX() << std::endl
		<< "cs에는 없는 Y값을 가져오는 함수 : " << cs.GetY() << std::endl << std::endl;
}