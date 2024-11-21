/*
[overriding]
	�ڽ� Ŭ������ �θ� Ŭ������ �޼��带 �������Ͽ� �ڽ��� ������� �����ϰ� ����� ��ü ���� ���α׷����� �߿��� ����
	�Լ� �̸�, �Ű������� �θ�Ŭ������ �Լ��� �����ؾ� ��
	�ڽ� Ŭ������ �θ� Ŭ������ �Լ��� �����ϰų� Ȯ���ų �� �ִ�.

[virtual]
	�θ� Ŭ������ �Լ��� ���̸�, �ش� �Լ��� �������̵� �������� ��Ÿ����


[override]
	�ڽ� Ŭ�������� �Լ���
*/

#include <iostream>

/// <summary>
/// �ڵ��� Ŭ����(�θ� Ŭ����)
/// </summary>
class Vehicle {
protected :
	std::string name;

public:
	Vehicle(const std::string& n) : name(n) {
		std::cout << "�θ� Ŭ���� ������ ȣ��" << std::endl;
	}

	virtual void Move() const {
		std::cout << name << "�� �θ� Ŭ���� �Լ� ȣ��" << std::endl;
	}

	/// <summary>
	/// �Ҹ���, �ڽ�Ŭ������ ȣ�� �Ǳ� ���� virtual�� ���δ�
	/// </summary>
	virtual ~Vehicle() {	// �θ� Ŭ������ virtual�� ���� ������ �ڽ� Ŭ������ �Ҹ��ڰ� �������� �ʴ´�
		std::cout << "�θ� Ŭ���� �Ҹ��� ȣ��" << std::endl;
	}

	/// <summary>
	/// �Ҹ��ڿ��� �ƹ��͵� ���� ���� ��� default�� ����Ѵ�
	/// </summary>
	// virtual~Vehicle() = default;
};

class Car : public Vehicle {
public:
	Car(const std::string& n) : Vehicle(n) {
		std::cout << "�ڽ� ������(Car) ȣ��" << std::endl;
	}

	void Move() const override {
		
		std::cout << name << "�� �ڽ� Ŭ���� �ڵ��� �Լ� ȣ��" << std::endl;

	}

	void noOver() {
		std::cout << "�׽�Ʈ" << std::endl;
	}

	~Car() {
		std::cout << "�ڽ� Ŭ���� (car) �Ҹ��� ȣ��" << std::endl;
	}
};

class Bike : public Vehicle {
public:
	Bike(const std::string& n) : Vehicle(n) {
		std::cout << "�ڽ� ������(Car) ȣ��" << std::endl;
	}

	void Move() const override {
		std::cout << name << "�� �ڽ� Ŭ���� ������� �Լ� ȣ��" << std::endl;

	}

	~Bike() {
		std::cout << "�ڽ� Ŭ���� (Bike) �Ҹ��� ȣ��" << std::endl;
	}
};

int main() {
	Vehicle* v;
	v = new Car("�ڵ���");
	v->Move();

	delete v;
	v = nullptr;
}