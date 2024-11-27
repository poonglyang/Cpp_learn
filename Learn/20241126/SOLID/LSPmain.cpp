/*
L(Liskov Substiution Principle, LSP, �������� ġȯ ��Ģ)
	�ڽ� Ŭ������ �θ� Ŭ������ ����� ��ü�� �� �־�� �Ѵ�.
	���α׷����� �θ� Ŭ���� ��ü�� ���Ǵ� ��� �κп� �ڽ�Ŭ���� ��ü�� ��ü�ص� �������� ������ �ٲ��� �ʾƾ� �Ѵ�
	�������� ��ӱ����� �ڽ�Ŭ������ �θ�Ŭ�������� ���ǵ� �ൿ�� �����ϸ� �ȵȴ�
	�θ� Ŭ������ �����ͳ� ������ ���� �ڽ�Ŭ������ ����� �� ���� ������ �ȵ�.
*/

#include <iostream>
class Bird {
public :
	virtual void Fly() const {
		std::cout << "���� ���ư���" << std::endl;
	}
};

class Eagle : public Bird {
	void Fly() const override {
		std::cout << "�������� ���ư���" << std::endl;
	}
};

class Penguin1 : public Bird {
	void Fly() const override {
		throw "Ostriches cannot fly!";
	}
};

class Penguin2 : public Bird {
public:
	void Fly() const override {
		// ����� �� �� ������, '���� �Ұ�' �޽����� ����ϴ� ��, ����� ���õ� ��Ģ�� ����
		std::cout << "�ر��� �� �� ����." << std::endl;
	}
};




