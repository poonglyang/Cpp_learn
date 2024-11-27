#pragma once
//#include "Player.h"	// 상호 참조 오류를 해결을 위해
#include <iostream>

class Player;			// 클래스 전방선언을 했으니
						// cpp에서 include를 해야한다
						// 존재만 알려주기에 속도적인 순서에서 좋을 수 있따


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

