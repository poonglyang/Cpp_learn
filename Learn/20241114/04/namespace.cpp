/*
[namespace]
	�̸� �浹�� �����ϰ�, �ڵ��� ������ �� ��Ȯ�ϰ� �ϱ� ����
	�Ը� ū ������Ʈ������ ���� ���̺귯��, �ڵ� ����� �Բ� ���ȴ�
	������ �̸��� �Լ�, Ŭ����, ������ ������ �� �ִµ�, ���� �����̽��� �����Ͽ� �浹�� �����ϴµ� ������ ��Ȱ�� �Ѵ�
	Ư�� �̸��� ���ӽ����̽� �ȿ� �־� �������� �̸� ������ ������ش�.
	���õ� �Լ�, ����, Ŭ������ ���ӽ����̽� �ȿ� ��Ƶθ� ������ �ſ� �����ϴ�.

[�⺻ ����]
	namespace MyNameSpace {
		// ����, �Լ�, Ŭ���� ���� �� �� �ִ�.
	}

*/

#include <iostream> 

namespace MyNameSpace {
	int num = 5;
	
	void Print() {
		std::cout << "MynameSpace�� �Լ�" << std::endl;
	}
}

namespace A {
	int num = 1;
	namespace B {
		int num = 2;
	}
}

namespace Physics {
	// �浹 ����
	// �߷� ����

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
	// ���а� ���õ� ���� ����
}

using namespace std;

int main() {
	MyNameSpace::Print();
	std::cout << MyNameSpace::num << std::endl;

	std::cout << A::B::num << std::endl;
}