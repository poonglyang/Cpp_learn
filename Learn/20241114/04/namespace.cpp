/*
[namespace]
	이름 충돌을 방지하고, 코드의 구조를 더 명확하게 하기 위함
	규모가 큰 프로젝트에서는 여러 라이브러리, 코드 모듈이 함께 사용된다
	동일한 이름의 함수, 클래스, 변수가 존재할 수 있는데, 네임 스페이스로 구분하여 충돌을 방지하는데 종요한 역활을 한다
	특정 이름을 네임스페이스 안에 넣어 독립적인 이름 공간을 만들어준다.
	관련된 함수, 변수, 클래스를 네임스페이스 안에 모아두면 관리가 매우 용이하다.

[기본 구조]
	namespace MyNameSpace {
		// 변수, 함수, 클래스 등이 들어갈 수 있다.
	}

*/

#include <iostream> 

namespace MyNameSpace {
	int num = 5;
	
	void Print() {
		std::cout << "MynameSpace의 함수" << std::endl;
	}
}

namespace A {
	int num = 1;
	namespace B {
		int num = 2;
	}
}

namespace Physics {
	// 충돌 관련
	// 중력 관련

}

namespace A {
	enum class MyEnumClass {

	};
}

namespace Graphics {
	void rander();

	class a {

	};
}

namespace Mathf {
	// 수학과 관련된 것을 쓴다
}

using namespace std;

int main() {
	MyNameSpace::Print();
	std::cout << MyNameSpace::num << std::endl;

	std::cout << A::B::num << std::endl;
}