/*
[��ȣ ���� ����]
	Ŭ���� ���� ���� �����ϱ⿡ ��ȣ ���� ������ ����
	Ŭ���� ���� ������ �Ͽ� �ذ�����

	���漱���� �Ͽ� �����Ϸ��� �ʿ��� Ÿ�ֿ̹��� ã�� �� �ְ� �Ѵ�
*/

#include "Player.h"
#include "Weapon.h"

int main() {
	Weapon* sword = new Weapon("��");

	Player* player = new Player("��˻�", sword);

	player->Attack();

	delete sword;
	sword = nullptr;

	delete player;
	player = nullptr;
}