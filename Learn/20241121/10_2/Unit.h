#pragma once
#include <iostream>
// 헤더 가드를 한번 살펴보자
class Unit {
protected:
	std::string name;
	int health;

public:
	Unit(const std::string& n, const int h);
	virtual ~Unit();

public:
	virtual void Attack() const = 0;			// = 0으로 하여 순수가상으로 표현
	virtual void TakeDamage(int damage) = 0;
};

