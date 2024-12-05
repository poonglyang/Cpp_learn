#include "BattleEvent.h"

BattleEvent::BattleEvent()
{
	float hp = Mathf::Random::Range(30, 100);
	float mp = Mathf::Random::Range(20, 100);
	float atk = Mathf::Random::Range(3, 41);
	float critialProbability = 1 + Mathf::Random::Value();
	float critialDamage = 1.5f;
	float defIgnore = 0;
	float def = Mathf::Random::Range(4, 30);

	float hitArr[6] = { 0.7f, 0.75f, 0.8f, 0.85f, 0.9f, 0.95f };

	float hit = hitArr[rand() % 6];

	float avoidArr[7] = { 0.08f, 0.1f, 0.12f, 0.14f, 0.16f, 0.18f, 0.2f };

	float avoid = avoidArr[rand() % 7];

	monster = new Monster(
		hp, hp, mp, mp, atk, critialProbability, critialDamage, defIgnore,
		def, hit, avoid, 0.1f, 1, 
		monsterNames[Mathf::Random::Range(0, monsterNames.size())]
	);

	for (int i = 9; i < 29; i++) {
		for (int j = 14; j < 34; j++) {
			BattleImage[i][j] = monster->monsterImage1[i - 9][j - 14];
		}
	}
}

BattleEvent::~BattleEvent()
{
	delete monster;
	monster = nullptr;
}

void BattleEvent::EventStart(Player* player)
{
	BattleAction(player);
}

void BattleEvent::EventUpdate()
{
}

void BattleEvent::EventEnd()
{
}

void BattleEvent::RenderEvent()
{
	system("cls");
	for (int i = 0; i < 30; i++) {

		for (int j = 0; j < 50; j++) {

			switch (BattleImage[i][j]) {

			case 0:
				std::cout << "  ";
				break;
			case 1:
				SetRGBColor(255, 255, 255);
				std::cout << "■";
				break;
			case 2:
				SetRGBColor(255, 255, 255);
				std::cout << monsterName[0];
				break;
			case 3:
				SetRGBColor(255, 255, 255);
				std::cout << "  HP";
				break;
			case 4: {
				SetRGBColor(255, 0, 0);
				if (monster->GetHp() == 0) {
					std::cout << hpBar[0];
				}
				else {
					int barIndex = static_cast<int>(monster->GetHp() / monster->GetMaxHp() * 10);
					std::cout << hpBar[barIndex];
				}
				
			}
				break;
			case 21:
				SetRGBColor(50, 50, 50);
				std::cout << "■";
				break;
			case 22:
				SetRGBColor(255, 175, 163);
				std::cout << "■";
				break;
			case 23:
				SetRGBColor(255, 255, 163);
				std::cout << "■";
				break;
			case 24:
				SetRGBColor(249, 136, 163);
				std::cout << "■";
				break;
			case 25:
				SetRGBColor(230, 89, 105);
				std::cout << "■";
				break;
			case 26:
				SetRGBColor(172, 20, 75);
				std::cout << "■";
				break;

				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				// 텍스트 색상 리셋 (기본)
				printf("\033[0m");
			}

		}
		std::cout << std::endl;
	}
	
		
}



void BattleEvent::BattleAction(Player* player)
{
	int input;
	bool battleEnd = false;
	while (!battleEnd) {
		RenderEvent();

		for (int i = 0; i < 8; i++) {

			for (int j = 0; j < 50; j++) {

				switch (BattleText[i][j]) {

				case 0:
					std::cout << "  ";
					break;
				case 1:
					SetRGBColor(255, 255, 255);
					std::cout << "■";
					break;
				case 2:
					SetRGBColor(255, 255, 255);
					std::cout << "\t▶  [공격하기]\t\t\t■■\t\t    [아이템 사용]\t\t  ■";
					break;
				case 3:
					SetRGBColor(255, 255, 255);
					std::cout << "\t   [공격하기] \t\t\t■■\t\t▶    [아이템 사용]\t\t  ■";
					break;
					SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					// 텍스트 색상 리셋 (기본)
					printf("\033[0m");
				}
			}
			std::cout << std::endl;
		}


		input = playHelper::getCommand();

		switch (input) {
		case 100:	// 오른쪽 방향키 또는 a
		case 77:
			BattleText[3][4] = 3;
			break;

		case 97:	// 왼쪽 방향키 또는 d
		case 75:
			BattleText[3][4] = 2;
			break;

		case 13:
			if (BattleText[3][4] == 2) {
				IState* playerIState = dynamic_cast<IState*>(player);
				IState* monsterIState = dynamic_cast<IState*>(monster);
				if (player->GetBehaviorSpeed() >= monster->GetBehaviorSpeed()) {
					Attack(playerIState, monsterIState, true);
					Attack(monsterIState, playerIState, false);
				}
				else {
					Attack(monsterIState, playerIState, false);
					Attack(playerIState, monsterIState, true);
				}
			}
			else if (BattleText[3][4] == 3) {
				std::cout << "소모품을 사용하였습니다(구현해야함시발)" << std::endl;
			}

			RenderEvent();
			player->PrintPlayerInfo();

			playHelper::getCommand();
			
			RenderEvent();

			std::cout << std::endl << "몬스터 정보" << std::endl;
			monster->PrintState();

			playHelper::getCommand();
			break;
		}

		if (player->GetHp() <= 0) {
			RenderEvent();
			std::cout << std::endl << std::endl << "\t플레이어가 사망하였다" << std::endl;
			std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
			playHelper::getCommand();
			battleEnd = true;
		}
		
		if (monster->GetHp() <= 0) {
			RenderEvent();
			std::cout << std::endl << std::endl << monsterNames[0] << "을 무찔렀다" << std::endl;
			std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
			playHelper::getCommand();
			battleEnd = true;
		}

	}
}



void BattleEvent::Attack(IState* attacker, IState* target, bool isPlayerAttack)
{
	RenderEvent();

	if (isPlayerAttack) {
		std::cout << std::endl << std::endl << "\t플레이어의 공격!" << std::endl;
		std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
	}
	else {
		std::cout << std::endl << std::endl << "\t" << monsterNames[0] << "의 공격!" << std::endl;
		std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
	}
	playHelper::getCommand();

	if (Mathf::Random::Value() < (attacker->GetHit() - target->GetAvoid())) {
		// 공격이 명중함
		float damage = CalcDamage(attacker, target, isPlayerAttack);
		RenderEvent();
		if (isPlayerAttack) {
			std::cout << std::endl << std::endl << "\t" << monsterNames[0] << "은(는) " << damage << " 의 피해를 입었다" << std::endl;
			std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
		}
		else {
			std::cout << std::endl << std::endl << "\t" << "플레이어는 " << damage << " 의 피해를 입었다" << std::endl;
			std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
		}
		target->SetHp(-damage, true);
		playHelper::getCommand();
	}
	else {
		// 회피함
		RenderEvent();
		if (isPlayerAttack) {
			std::cout << std::endl << std::endl << "\t" << monsterNames[0] << "은(는) 공격을 회피했다" << std::endl;
			std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
		}
		else {
			std::cout << std::endl << std::endl << "\t" << "플레이어은(는) 공격을 회피했다" << std::endl;
			std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
		}
		playHelper::getCommand();
	}
}

float BattleEvent::CalcDamage(IState* attacker, IState* target, bool isPlayerAttack)
{
	float damage = attacker->GetAtk();

	if (Mathf::Random::Value() < attacker->GetCritialProbability()) {
		// 크리티컬이면
		RenderEvent();
		std::cout << std::endl << std::endl << "\t" << "크리티컬!!!!" << std::endl;
		std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
		damage*= attacker->GetCritialDamage();		// 크리 배율만큼 곱하기
		playHelper::getCommand();
	}
	

	float def = target->GetDef();					// 방어력 가져오고
	def *= (1 - attacker->GetDefIgnore());			// 방어력 무시 수치만큼 나눔(근데 속도때문에 곱함)

	if (Mathf::Random::Value() < target->GetDefenseProbability()) {
		// 방어자가 방어하면
		def *= 2;	// 방어력 2배 증가
		RenderEvent();
		if (isPlayerAttack) {
			std::cout << std::endl << std::endl << "\t" << monsterNames[0] << "은(는) 가드를 올렸다" << std::endl;
			std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
		}
		else {
			std::cout << std::endl << std::endl << "\t" << "플레이어는 " << monsterNames[0] << "의 공격을 방어했다" << std::endl;
			std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
		}
		playHelper::getCommand();
	}
	
	
	damage -= def;

	if (damage < 1) {
		return 1;
	}

	return damage;
}



