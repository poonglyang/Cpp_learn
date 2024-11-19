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

	// cs에는 x가 없지만 
	std::cout << "cs에는 없는 x값 : " << cs.GetX() << std::endl
		<< "cs에는 없는 Y값을 가져오는 함수 : " << cs.GetY() << std::endl << std::endl;
}