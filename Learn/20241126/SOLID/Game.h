#pragma once

#include <iostream>

/*
�ش� Ŭ�������� �÷��̾�, ���� ������ ����. ����, ��� ��� �ٵ� �ִ�
- ������ ����, �������� ���� �ٲܷ��� Game Ŭ���� ���ݿ� ���� �ڵ带 �����ؾ� �Ѵ�

// ���� �ش� Ŭ������ �и��Ѵ� �ϸ�
	StatusŬ������ battleableŬ������ ��� ���� playerClass(Status(����), �̸�, ��Ҵ��� ����, battleable(����, ��� �� �ൿ)
		�÷��̾�� ���õ� ���
	
	StatusŬ������ battleableŬ������ ��� ���� monsterClass(Status(����), �̸�, ��Ҵ��� ����, battleable(����, ��� �� �ൿ)
		���Ϳ� ���õ� ���

	Battleable

	print Ŭ����
		�� Ŭ������ ������ ����ϴ� Ŭ����
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