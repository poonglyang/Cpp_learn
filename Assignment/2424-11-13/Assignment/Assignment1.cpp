#include <iostream>

struct node {
	std::string name;
	int maxHp;
	int hp;
	int damage;
};

int Attack(node attacker, node target) {
	std::cout << attacker.name << "의 공격 " << target.name << "은(는) " << attacker.damage << "만큼 피해를 입었다" << std::endl;
	target.hp -= attacker.damage;
	std::cout << target.name << "의 hp : " << target.hp << std::endl;
	return target.hp;
}


int Attack(int type, int targetHp) {
	if (type == 1) {
		targetHp -= 20;
		std::cout << "고블린의 공격 20의 피해를 입었다. 현재 플레이어의 hp" << targetHp << std::endl;

	}
	else {
		targetHp -= 20;
		std::cout << "플레이어의 공격 고블린은 20의 피해를 입었다. 현재 고블린의 hp" << targetHp << std::endl;
	}

	return targetHp;
}


int main() {
	int playerHp = 100;
	int goblineHp = 50;

	while (playerHp > 0 && goblineHp > 0) {
		int attackTarget;
		std::cout << "공격할 대상을 선택하세요 (1. 플레이어, 2. 고블린) : ";
		std::cin >> attackTarget;

		switch (attackTarget) {
			case 1:
				playerHp = Attack(1, playerHp);
				break;
			case 2:
				goblineHp = Attack(2, goblineHp);
			default:
				std::cout << "당신은 아무것도 공격하지 않았다" << std::endl;
				break;
		}

	}
}


/*
int main() {

	node player = { "플레이어", 100, 100, 10 };
	node gobline = { "고블린", 50, 50, 3 };

	while (player.hp > 0 && gobline.hp > 0) {
		int attackTarget;
		std::cout << "공격할 대상을 선택하세요 (1. 플레이어, 2. 고블린) : ";
		std::cin >> attackTarget;

		switch (attackTarget) {
		case 1:
			player.hp = Attack(gobline, player);
			break;
		case 2:
			gobline.hp = Attack(player, gobline);
			break;
		default:
			std::cout << "당신은 아무것도 공격하지 않았다" << std::endl;
			break;
		}
	}
}
*/
