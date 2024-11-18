/*
	아래와 같은 예시가 있을 때
	1. 레벨업 기능을 함수로 구현해라
		플레이어가 경험치를 쌓고 특정 경험치 이상이면 레벨업
	2. 매우 간단한 공격 함수 만들기

*/

#include <iostream>

enum class Job {
	None = 0,
	Warrior, 
	Mage, 
	Archer
};

/// <summary>
/// 적의 정보를 가지고 있는 구조체
/// 이름, hp, 공격력, 레벨
/// </summary>
struct Enemy {
	std::string name;
	int hp;
	int power;
	int exp;
};

/// <summary>
/// 캐릭터의 정보를 담고 있는 구조체
/// 이름, hp, 최대 채력, 공격력, 레벨, 경험치, 최대경험치, 직업
/// </summary>
struct Character {
	std::string name;	// 이름
	int hp;				// hp
	int maxHp;			// 최대 채력
	int power;			// 공격력
	int level;			// 레벨
	int exp;			// 경험치
	int maxExp;			// 최대 경험치
	Job job;			// 직업

};

/// <summary>
/// 직업을 설명해주는 함수
/// </summary>
/// <param name="j">선택한 직업</param>
/// <returns>직업 설명문</returns>
std::string GetName(Job j);

/// <summary>
/// 직업을 선택하는 함수
/// </summary>
/// <param name="player">플레이어 정보가 담긴 구조체의 주소</param>
void SelectCharacterJob(Character& player);

/// <summary>
/// 적을 만드는 함수
/// </summary>
/// <param name="enemy">적의 정보가 담긴 구조체의 주소</param>
Enemy makeEnemy();

void LevelUp(Character& ch);

void Attack(Character& attacker, Enemy& target);

void Attack(Enemy& attacker, Character& target);

int main() {
	srand(time(0));
	Character player = {"", 100, 100, 5, 1, 0, 10, Job::None};
	std::cout << "캐릭터 이름을 지정해주세요 : ";
	std::cin >> player.name;

	SelectCharacterJob(player);

	for (int i = 0; i < 10; i++) {
		Enemy enemy = makeEnemy();
		std::cout << enemy.name << "이 나타났다" << std::endl;
		while (player.hp > 0 && enemy.hp > 0) {
			std::cout << player.name << "의 채력 : " << player.hp << ", " << enemy.name << "의 채력 : " << enemy.hp << std::endl;
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
		return "집행검을 든 전사";
	case Job::Mage:
		return "오브 든 마법사";
	case Job::Archer:
		return "양궁 선수 출신 궁수";
	default:
		return "선택 하지 않음";
	}
}

void SelectCharacterJob(Character& player) {
	std::string job;
	std::string jobs[3] = { "전사", "마법사", "궁수" };

	do {
		std::cout << "직업을 선택해 주세요\n[전사 || 마법사 || 궁수]" << std::endl;
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
			std::cout << "직업 명을 입력하거나 숫자로 입력해주세요 (ex. 전사, 1)" << std::endl;
		}
	} while (true);

	std::cout << GetName(player.job) << std::endl;

}

Enemy makeEnemy()
{
	Enemy enemy;
	switch (rand() % 4) {
	case 0:
		enemy = {"슬라임", 10, 2, 5};
		return enemy;
	case 1:
		enemy = { "고블린", 25, 3, 10};
		return enemy;
	case 2:
		enemy = { "스네이크", 15, 7, 20};
		return enemy;
	case 3:
		enemy = { "오크", 50, 10, 100};
		return enemy;
	default :
		enemy = { "Error", 999, 999, 999};
		return enemy;
	}
}

void LevelUp(Character& ch) {
	std::cout << "레벨업!" << std::endl;
	ch.exp -= ch.maxExp;	// 최대 경험치 만큼 exp 빼기
	ch.maxExp *= 1.5;			// 경험치 통 증가
	ch.level++;				// 레벨 1 상승
	ch.maxHp *=1.2;			// 최대 채력 증가	
	ch.hp = ch.maxHp;		// hp 회복
	ch.power *= 1.5;		// 공격력 증가

	if (ch.exp >= ch.maxExp) {	// 레벨업 과정을 해도 경험치가 경험치통보다 높다면
		LevelUp(ch);		// 레벨업
	}

}

void Attack(Character& attacker, Enemy& target) 
{
	std::cout << attacker.name << "의 공격\n" << target.name << "은 " << attacker.power << "만큼 피해를 입었다." << std::endl;
	target.hp -= attacker.power;

	if (target.hp <= 0) {
		// 적의 hp가 0 이하일 경우 
		std::cout << target.name << "를 쓰려트렸다. 경험치 " << target.exp << "획득" << std::endl;
		attacker.exp += target.exp;					// 경험치 획득

		if (attacker.exp >= attacker.maxExp) {
			// 얻은 경험치가 최대 경험치보다 클 경우
			LevelUp(attacker);	// 레벨업
		}
	}
	else {
		std::cout << target.name << "의 채력 : " << target.hp << std::endl;
		Attack(target, attacker);
	}
}

void Attack(Enemy& attacker, Character& target)
{
	std::cout << attacker.name << "의 공격\n" << target.name << "은 " << attacker.power << "만큼 피해를 입었다." << std::endl;
	target.hp -= attacker.power;
	if (target.hp <= 0) {
		// 적의 hp가 0 이하일 경우 
		std::cout << target.name << "는 강대한 " << target.name << "의 공격을 버티지 못했다" << std::endl;
		std::cout << "게임 오버" << std::endl;
		
	}
	else {
		std::cout << target.name << "의 채력 : " << target.hp << std::endl;
		Attack(target, attacker);
	}
}
