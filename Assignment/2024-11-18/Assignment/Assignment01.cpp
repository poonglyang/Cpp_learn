/*
	�Ʒ��� ���� ���ð� ���� ��
	1. ������ ����� �Լ��� �����ض�
		�÷��̾ ����ġ�� �װ� Ư�� ����ġ �̻��̸� ������
	2. �ſ� ������ ���� �Լ� �����

*/

#include <iostream>

enum class Job {
	None = 0,
	Warrior, 
	Mage, 
	Archer
};

/// <summary>
/// ���� ������ ������ �ִ� ����ü
/// �̸�, hp, ���ݷ�, ����
/// </summary>
struct Enemy {
	std::string name;
	int hp;
	int power;
	int exp;
};

/// <summary>
/// ĳ������ ������ ��� �ִ� ����ü
/// �̸�, hp, �ִ� ä��, ���ݷ�, ����, ����ġ, �ִ����ġ, ����
/// </summary>
struct Character {
	std::string name;	// �̸�
	int hp;				// hp
	int maxHp;			// �ִ� ä��
	int power;			// ���ݷ�
	int level;			// ����
	int exp;			// ����ġ
	int maxExp;			// �ִ� ����ġ
	Job job;			// ����

};

/// <summary>
/// ������ �������ִ� �Լ�
/// </summary>
/// <param name="j">������ ����</param>
/// <returns>���� ����</returns>
std::string GetName(Job j);

/// <summary>
/// ������ �����ϴ� �Լ�
/// </summary>
/// <param name="player">�÷��̾� ������ ��� ����ü�� �ּ�</param>
void SelectCharacterJob(Character& player);

/// <summary>
/// ���� ����� �Լ�
/// </summary>
/// <param name="enemy">���� ������ ��� ����ü�� �ּ�</param>
Enemy makeEnemy();

void LevelUp(Character& ch);

void Attack(Character& attacker, Enemy& target);

void Attack(Enemy& attacker, Character& target);

int main() {
	srand(time(0));
	Character player = {"", 100, 100, 5, 1, 0, 10, Job::None};
	std::cout << "ĳ���� �̸��� �������ּ��� : ";
	std::cin >> player.name;

	SelectCharacterJob(player);

	for (int i = 0; i < 10; i++) {
		Enemy enemy = makeEnemy();
		std::cout << enemy.name << "�� ��Ÿ����" << std::endl;
		while (player.hp > 0 && enemy.hp > 0) {
			std::cout << player.name << "�� ä�� : " << player.hp << ", " << enemy.name << "�� ä�� : " << enemy.hp << std::endl;
			switch (rand() % 2) {
			case 0:
				Attack(player, enemy);
				break;
			case 1:
				Attack(enemy, player);
				break;
			default:
				Attack(player, enemy);
				break;
			}
		}

		if (player.hp <= 0) {
			break;
		}
	}

}

std::string GetName(Job j) {
	std::cout << (int)j << std::endl;
	switch (j)
	{
	case Job::Warrior:
		return "������� �� ����";
	case Job::Mage:
		return "���� �� ������";
	case Job::Archer:
		return "��� ���� ��� �ü�";
	default:
		return "���� ���� ����";
	}
}

void SelectCharacterJob(Character& player) {
	std::string job;
	std::string jobs[3] = { "����", "������", "�ü�" };

	do {
		std::cout << "������ ������ �ּ���\n[���� || ������ || �ü�]" << std::endl;
		std::cin >> job;
		if (jobs[0] == job || "1" == job) {
			player.job = Job::Warrior;
			break;
		}
		else if (jobs[1] == job || "2" == job) {
			player.job = Job::Mage;
			break;
		}
		else if (jobs[2] == job || "3" == job) {
			player.job = Job::Archer;
			break;
		}
		else {
			std::cout << "���� ���� �Է��ϰų� ���ڷ� �Է����ּ��� (ex. ����, 1)" << std::endl;
		}
	} while (true);

	std::cout << GetName(player.job) << std::endl;

}

Enemy makeEnemy()
{
	Enemy enemy;
	switch (rand() % 4) {
	case 0:
		enemy = {"������", 10, 2, 5};
		return enemy;
	case 1:
		enemy = { "���", 25, 3, 10};
		return enemy;
	case 2:
		enemy = { "������ũ", 15, 7, 20};
		return enemy;
	case 3:
		enemy = { "��ũ", 50, 10, 100};
		return enemy;
	default :
		enemy = { "Error", 999, 999, 999};
		return enemy;
	}
}

void LevelUp(Character& ch) {
	std::cout << "������!" << std::endl;
	ch.exp -= ch.maxExp;	// �ִ� ����ġ ��ŭ exp ����
	ch.maxExp *= 1.5;			// ����ġ �� ����
	ch.level++;				// ���� 1 ���
	ch.maxHp *=1.2;			// �ִ� ä�� ����	
	ch.hp = ch.maxHp;		// hp ȸ��
	ch.power *= 1.5;		// ���ݷ� ����

	if (ch.exp >= ch.maxExp) {	// ������ ������ �ص� ����ġ�� ����ġ�뺸�� ���ٸ�
		LevelUp(ch);		// ������
	}

}

void Attack(Character& attacker, Enemy& target) 
{
	std::cout << attacker.name << "�� ����\n" << target.name << "�� " << attacker.power << "��ŭ ���ظ� �Ծ���." << std::endl;
	target.hp -= attacker.power;

	if (target.hp <= 0) {
		// ���� hp�� 0 ������ ��� 
		std::cout << target.name << "�� ����Ʈ�ȴ�. ����ġ " << target.exp << "ȹ��" << std::endl;
		attacker.exp += target.exp;					// ����ġ ȹ��

		if (attacker.exp >= attacker.maxExp) {
			// ���� ����ġ�� �ִ� ����ġ���� Ŭ ���
			LevelUp(attacker);	// ������
		}
	}
	else {
		std::cout << target.name << "�� ä�� : " << target.hp << std::endl;
		Attack(target, attacker);
	}
}

void Attack(Enemy& attacker, Character& target)
{
	std::cout << attacker.name << "�� ����\n" << target.name << "�� " << attacker.power << "��ŭ ���ظ� �Ծ���." << std::endl;
	target.hp -= attacker.power;
	if (target.hp <= 0) {
		// ���� hp�� 0 ������ ��� 
		std::cout << target.name << "�� ������ " << target.name << "�� ������ ��Ƽ�� ���ߴ�" << std::endl;
		std::cout << "���� ����" << std::endl;
		
	}
	else {
		std::cout << target.name << "�� ä�� : " << target.hp << std::endl;
		Attack(target, attacker);
	}
}
