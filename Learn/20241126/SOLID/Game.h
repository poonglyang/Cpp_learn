#pragma once

#include <iostream>

/*
해당 클래스에서 플레이어, 몬스터 데이터 관리. 전투, 출력 등등 다들어가 있다
- 데이터 관리, 전투로직 등을 바꿀려면 Game 클래스 전반에 걸쳐 코드를 수정해야 한다

// 만약 해당 클래스를 분리한다 하면
	Status클래스와 battleable클래스를 상속 받은 playerClass(Status(스탯), 이름, 살았는지 여부, battleable(공격, 방어 등 행동)
		플레이어와 관련된 기능
	
	Status클래스와 battleable클래스를 상속 받은 monsterClass(Status(스탯), 이름, 살았는지 여부, battleable(공격, 방어 등 행동)
		몬스터와 관련된 기능

	Battleable

	print 클래스
		두 클래스의 정보만 출력하는 클래스
*/

class Game
{
private:
	std::string playerName;
	std::string monsterName;
	int playerHealth;
	int monsterHealth;
	int playerAttack;
	int monsterAttack;
public:

	Game();

	void Start();
};

class Status {

};

class Monster : public Status {

};

class Player : public Status {

};

class BattleManager {

};