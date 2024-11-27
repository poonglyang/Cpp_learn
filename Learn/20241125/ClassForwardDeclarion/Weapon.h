#pragma once
//#include "Player.h"	// ��ȣ ���� ������ �ذ��� ����
#include <iostream>

class Player;			// Ŭ���� ���漱���� ������
						// cpp���� include�� �ؾ��Ѵ�
						// ���縸 �˷��ֱ⿡ �ӵ����� �������� ���� �� �ֵ�


class Weapon
{
private:
	std::string name;
	Player* player;
	std::string type;
public:
	Weapon(const std::string& type);
	~Weapon();

	void Use() const;



};

