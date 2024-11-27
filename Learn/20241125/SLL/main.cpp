#include <list>
#include <iostream>
#include "SLL.h"

int main() {
	SLL s;

	for (int i = 1; i <= 10; i++) {
		s.Insert(i);
	}

	s.Print();

	std::cout << std::endl << std::endl;

	s.Delete(1);
	s.Delete(5);
	s.Print();
}