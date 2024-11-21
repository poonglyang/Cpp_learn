#pragma once

#include "Unit.h"

class Player : Unit
{
public:
	Player(const std::string& n, const int h);
	void Attack() const override;
	void TakeDamage(const int damage) override;
};

