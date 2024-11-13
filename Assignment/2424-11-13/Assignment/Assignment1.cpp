#include <iostream>

struct node {
	std::string name;
	int maxHp;
	int hp;
	int damage;
};

int Attack(node attacker, node target) {
	std::cout << attacker.name << "�� ���� " << target.name << "��(��) " << attacker.damage << "��ŭ ���ظ� �Ծ���" << std::endl;
	target.hp -= attacker.damage;
	std::cout << target.name << "�� hp : " << target.hp << std::endl;
	return target.hp;
}


int Attack(int type, int targetHp) {
	if (type == 1) {
		targetHp -= 20;
		std::cout << "����� ���� 20�� ���ظ� �Ծ���. ���� �÷��̾��� hp" << targetHp << std::endl;

	}
	else {
		targetHp -= 20;
		std::cout << "�÷��̾��� ���� ����� 20�� ���ظ� �Ծ���. ���� ����� hp" << targetHp << std::endl;
	}

	return targetHp;
}


int main() {
	int playerHp = 100;
	int goblineHp = 50;

	while (playerHp > 0 && goblineHp > 0) {
		int attackTarget;
		std::cout << "������ ����� �����ϼ��� (1. �÷��̾�, 2. ���) : ";
		std::cin >> attackTarget;

		switch (attackTarget) {
			case 1:
				playerHp = Attack(1, playerHp);
				break;
			case 2:
				goblineHp = Attack(2, goblineHp);
			default:
				std::cout << "����� �ƹ��͵� �������� �ʾҴ�" << std::endl;
				break;
		}

	}
}


/*
int main() {

	node player = { "�÷��̾�", 100, 100, 10 };
	node gobline = { "���", 50, 50, 3 };

	while (player.hp > 0 && gobline.hp > 0) {
		int attackTarget;
		std::cout << "������ ����� �����ϼ��� (1. �÷��̾�, 2. ���) : ";
		std::cin >> attackTarget;

		switch (attackTarget) {
		case 1:
			player.hp = Attack(gobline, player);
			break;
		case 2:
			gobline.hp = Attack(player, gobline);
			break;
		default:
			std::cout << "����� �ƹ��͵� �������� �ʾҴ�" << std::endl;
			break;
		}
	}
}
*/
