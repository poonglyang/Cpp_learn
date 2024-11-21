#pragma once
#include <iostream>
// ��� ���带 �ѹ� ���캸��
class Unit {
protected:
	std::string name;
	int health;

public:
	Unit(const std::string& n, const int h);
	virtual ~Unit();

public:
	virtual void Attack() const = 0;			// = 0���� �Ͽ� ������������ ǥ��
	virtual void TakeDamage(int damage) = 0;
};

