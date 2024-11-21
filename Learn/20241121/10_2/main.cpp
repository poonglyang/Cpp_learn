/*
[�߻�ȭ]
	

[�߻� Ŭ����]
	�ϳ� �̻��� ���� �����Լ��� ������ Ŭ������� �߻� Ŭ������� �����Ѵ�
	�߻� Ŭ������ �ν��Ͻ�ȭ ��ų �� ����
	�ٸ� Ŭ�������� ��� �޾ƾ� �ϴ� �⺻ �������̽��� �⺻ ������ �����ϴµ� ���
	Ư�� �Լ����� �ڽ� Ŭ������ ���� �����ǹǷ� �����Ѵ�. -> �ݵ�� �ؾ���

[��� ����]
	������Ͽ����� ������ �ϰ�(������ �Ǳ���) ��� ���Ͽ� �´� cpp���� �����Ѵ�

[virtual Function �� Pure Virtual Function | �����Լ��� ���������Լ�]
	1. �����Լ� (virtual Function)
		�����θ� ������ �� �ִ�
		�Ļ�Ŭ�������� ������ ���� �ʾƵ� �ȴ�.
		�����Լ� �����δ� �߻�Ŭ������ �������� �ʴ´�.
		Ŭ���� �ν��Ͻ�ȭ�� �����ϴ�

	2. ���������Լ� (Pure Virtual Function)
		�����ΰ� ����
		�Ļ�Ŭ�������� �ݵ�� ������ �ؾ��Ѵ�.
		���� �����Լ��� �ϳ��� ������ �߻�Ŭ������ ���� �ȴ�.
		�ν��Ͻ�ȭ�� �Ұ��� �ϴ�.

[Upcasting�� DownCasting]
	Upcasting
		�ڽ�Ŭ������ ��ü�� �θ� Ŭ���� Ÿ������ ��ȯ�Ѵ�
		�������� �����ϸ� ������� Ÿ�� ��ȯ�� �ʿ� ����

	DownCasting
		�θ� Ŭ���� Ÿ���� �ڽ� Ŭ���� Ÿ������ ��ȯ

*/

#include <iostream> 
#include "Player.h"

class Shape {
public :
	virtual void Draw() const {
		std::cout << "�θ� Ŭ���� shape" << std::endl;
	}

	virtual ~Shape() = default;
};

class Circle : public Shape {

public:
	void Draw() const  {
		std::cout << "�ڽ� Ŭ���� Circle" << std::endl;
	}

	void CircleFunction() {
		std::cout << "Circle Ŭ������ �ɹ� �Լ� CircleFunction" << std::endl;
	}
};

class Rectangle : public Shape {

public:
	void Draw() const  {
		std::cout << "�ڽ� Ŭ���� Rectangle" << std::endl;
	}

	void RectangleFunction() {
		std::cout << "Rectangle Ŭ������ �ɹ� �Լ� RectangleFunction" << std::endl;
	}
};

int main() {
#pragma region �߻�Ŭ����
	//Player* p = new Player("����", 10);

	//p->Attack();
	//p->TakeDamage(10);

	//delete p;
	//p = nullptr;

	////Unit* u = new Unit("aa", 10);		// ���� �����Լ��� �ֱ⿡ ���� �Ұ��ϴ�
#pragma endregion

#pragma region ���ɽ���, �ٿ�ĳ����
	Shape* shape1 = nullptr;
	Shape* shape2 = nullptr;

	// ���ɽ��� : �ڽ� Ŭ���� ��ü�� �θ� Ŭ���� Ÿ���� ������
	shape1 = new Circle();	
	shape2 = new Rectangle();

	// �ڽ� Ŭ������ ������� ȣ�����ش� (�θ� �ִ� virtual�� ���� �θ� Ŭ������ Draw�� ���´�)
	shape1->Draw();
	shape2->Draw();
	// �ٿ��ɽ���
	/*Circle* c = (Circle*)shape1;
	c->CircleFunction();*/

	Circle* c = dynamic_cast<Circle*>(shape1);	// Ÿ���� ���� ������ nullptr�� ����
	c->CircleFunction();	//�ڽ� Ŭ���� �ɹ� �Լ� ȣ��
	
	Rectangle* r 
		= dynamic_cast<Rectangle*>(shape2);	// �����Լ��� ���� Ŭ���������� ��� �����ϴ� (��� �ϳ��� virtual�� �ʿ��ϴ�)
	r->RectangleFunction();

	c->Draw();
	r->Draw();

#pragma endregion
}