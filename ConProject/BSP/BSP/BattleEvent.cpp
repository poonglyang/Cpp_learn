#include "BattleEvent.h"

BattleEvent::BattleEvent()
{
	float hp = myMath::Mathf::Random::Range(30, 50);
	float mp = myMath::Mathf::Random::Range(20, 50);
	float atk = myMath::Mathf::Random::Range(3, 20);
	float critialProbability = 1 + myMath::Mathf::Random::Value();
	float critialDamage = 1.5f;
	float defIgnore = 0;
	float def = myMath::Mathf::Random::Range(4, 10);

	float hitArr[6] = { 0.7f, 0.75f, 0.8f, 0.85f, 0.9f, 0.95f };

	float hit = hitArr[rand() % 3];

	float avoidArr[7] = { 0.08f, 0.1f, 0.12f, 0.14f, 0.16f, 0.18f, 0.2f };

	float avoid = avoidArr[rand() % 3];

	monsterIndex = myMath::Mathf::Random::Range(0, monsterNames.size());

	monster = new Monster(
		hp, hp, mp, mp, atk, critialProbability, critialDamage, defIgnore,
		def, hit, avoid, 0.1f, 1, 
		monsterNames[monsterIndex]
	);

	for (int i = 9; i < 29; i++) {
		for (int j = 14; j < 34; j++) {
			switch (monsterIndex)
			{
			case playHelper::Slime:
				BattleImage[i][j] = monster->slime[i - 9][j - 14];
				break;
			case playHelper::Goblin:
				BattleImage[i][j] = monster->slime[i - 9][j - 14];
				break;
			case playHelper::Ork:
				BattleImage[i][j] = monster->slime[i - 9][j - 14];
				break;
			case playHelper::Skeleton:
				BattleImage[i][j] = monster->slime[i - 9][j - 14];
				break;
			case playHelper::Troll:
				BattleImage[i][j] = monster->slime[i - 9][j - 14];
				break;
			case playHelper::mimic:
				BattleImage[i][j] = monster->mimic[i - 9][j - 14];
				break;
			default:
				break;
			}
			
		}
	}
}

BattleEvent::BattleEvent(int index)
{
	monsterIndex = index;
	float hp = myMath::Mathf::Random::Range(30, 50);
	float mp = myMath::Mathf::Random::Range(20, 50);
	float atk = myMath::Mathf::Random::Range(3, 20);
	float critialProbability = 1 + myMath::Mathf::Random::Value();
	float critialDamage = 1.5f;
	float defIgnore = 0;
	float def = myMath::Mathf::Random::Range(4, 10);



	float hitArr[6] = { 0.7f, 0.75f, 0.8f, 0.85f, 0.9f, 0.95f };

	float hit = hitArr[rand() % 3];

	float avoidArr[7] = { 0.08f, 0.1f, 0.12f, 0.14f, 0.16f, 0.18f, 0.2f };

	float avoid = avoidArr[rand() % 3];

	monster = new Monster(
		hp, hp, mp, mp, atk, critialProbability, critialDamage, defIgnore,
		def, hit, avoid, 0.1f, 1,
		monsterNames[monsterIndex]
	);

	for (int i = 9; i < 29; i++) {
		for (int j = 14; j < 34; j++) {
			switch (monsterIndex)
			{
			case 0:
				BattleImage[i][j] = monster->slime[i - 9][j - 14];
				break;
			case 1:
				BattleImage[i][j] = monster->slime[i - 9][j - 14];
				break;
			case 2:
				BattleImage[i][j] = monster->slime[i - 9][j - 14];
				break;
			case 3:
				BattleImage[i][j] = monster->slime[i - 9][j - 14];
				break;
			case 4:
				BattleImage[i][j] = monster->slime[i - 9][j - 14];
				break;
			case 5:
				BattleImage[i][j] = monster->mimic[i - 9][j - 14];
				break;
			default:
				break;
			}

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

void BattleEvent::EventUpdate(Player* player)
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
				std::cout << monsterName[monsterIndex];
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
			case 71:
				SetRGBColor(50, 50, 50);
				std::cout << "■";
				break;
			case 72:
				SetRGBColor(106, 120, 163);
				std::cout << "■";
				break;
			case 73:
				SetRGBColor(201, 117, 88);
				std::cout << "■";
				break;
			case 74:
				SetRGBColor(119, 138, 177);
				std::cout << "■";
				break;
			case 75:
				SetRGBColor(150, 79, 66);
				std::cout << "■";
				break;
			case 76:
				SetRGBColor(211, 52, 69);
				std::cout << "■";
				break;
			case 77:
				SetRGBColor(255, 244, 164);
				std::cout << "■";
				break;
			case 78:
				SetRGBColor(150, 79, 66);
				std::cout << "■";
				break;
			case 79:
				SetRGBColor(232, 197, 131);
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

bool BattleEvent::UseItem(Player* player)
{
	bool isUse = false;
	bool wantShowInventory = true;
	int input;
	int choiceIndex = 0;
	while (wantShowInventory) {
		system("cls");
		std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
		std::cout << std::endl;

		// 인벤토리의 아이템 이름 출력
		for (int i = 0; i < player->inventory->consumables.size(); i++) {
			if (choiceIndex == i) {
				std::cout << "\t▶\t";
			}
			else {
				std::cout << "\t\t";
			}
			ItemBase* item = (player->inventory->consumables)[i];
			std::cout << item->GetItemName() << std::endl;
		}

		std::cout << std::endl;
		std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;



		std::cout << std::endl;
		// 아이템 설명 출력
		if (!player->inventory->consumables.empty()) {

			ItemBase* item = (player->inventory->consumables)[choiceIndex];
			std::cout << "\t이름\t\t" << item->GetItemName() << std::endl;
			std::cout << "\t갯수\t\t" << item->GetItemCount() << "개" << std::endl;
			std::cout << "\t가격\t\t" << item->GetPrice() << std::endl;
			std::cout << "\t설명\t\t" << item->GetItemExplain() << std::endl;

			std::cout << std::endl;
		}
		else {
			std::cout << "\t아이템이 없습니다" << std::endl;
		}


		std::cout << std::endl;

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 31; j++) {
				switch (inventoryAction[i][j]) {
				case 0:
					std::cout << "  ";
					break;
				case 1:
					std::cout << "■";
					break;
				case 4:
					std::cout << "\t▶  [사용한다]\t      ■\t  [나간다]\t    ■";
					break;
				case 5:
					std::cout << "\t   [사용한다]\t      ■       ▶  [나간다]   \t    ■";
					break;
				case 7:
					std::cout << "\t  [← or Ａ]\t      ■\t [→ or Ｄ]\t    ■";
					break;

				}
			}
			std::cout << std::endl;
		}

		input = playHelper::getCommand();

		switch (input)
		{
		case 100:	// 오른쪽 화살표 or d
		case 77:
			inventoryAction[2][3] = 5;
			break;
		case 97:	// 왼쪾 화살표 or s
		case 75:
			inventoryAction[2][3] = 4;
			break;
		case 119:	// 위 또는 w
		case 72:
			if (choiceIndex - 1 >= 0) {
				--choiceIndex;
			}
			break;
		case 115:	// 아래 방향키 또는 s
		case 80:
			if (choiceIndex + 1 < player->inventory->consumables.size()) {
				++choiceIndex;
			}
			break;
		case 13:	// 엔터
			if (!player->inventory->consumables.empty()) {
				ItemBase* item = (player->inventory->consumables)[choiceIndex];
				if (inventoryAction[2][3] == 4) {
					player->UseItem(choiceIndex);
					if (choiceIndex >= player->inventory->consumables.size()) {
						choiceIndex = 0;
					}
					wantShowInventory = false;
					isUse = true;
				}
				else {
					wantShowInventory = false;
				}
				break;
			}
			break;
		default:
			break;
		}

	}

	return isUse;
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

		case 13: {
			IState* playerIState = dynamic_cast<IState*>(player);
			IState* monsterIState = dynamic_cast<IState*>(monster);
			if (BattleText[3][4] == 2) {

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
				if (UseItem(player)) {
					RenderEvent();
					std::cout << std::endl << std::endl << "\t플레이어는 아이템을 사용했다" << std::endl;
					playHelper::getCommand();
					std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
					Attack(monsterIState, playerIState, false);

					
				}
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
			
		}

		if (player->GetHp() <= 0) {
			RenderEvent();
			std::cout << std::endl << std::endl << "\t플레이어가 사망하였다" << std::endl;
			std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
			playHelper::getCommand();
			battleEnd = true;
		}
		
		if (monster->GetHp() <= 0) {
			for (int i = 9; i < 13; i++) {
				for (int j = 14; j < 34; j++) {
					BattleImage[i][j] = 0;
				}
			}
			RenderEvent();
			Sleep(300);
			for (int i = 13; i < 17; i++) {
				for (int j = 14; j < 34; j++) {
					BattleImage[i][j] = 0;
				}
			}
			RenderEvent();
			Sleep(300);
			for (int i = 17; i < 21; i++) {
				for (int j = 14; j < 34; j++) {
					BattleImage[i][j] = 0;
				}
			}
			RenderEvent();
			Sleep(300);
			for (int i = 21; i < 25; i++) {
				for (int j = 14; j < 34; j++) {
					BattleImage[i][j] = 0;
				}
			}
			RenderEvent();
			Sleep(300);
			for (int i = 25; i < 29; i++) {
				for (int j = 14; j < 34; j++) {
					BattleImage[i][j] = 0;
				}
			}
			RenderEvent();
			Sleep(300);
			std::cout << std::endl << std::endl << monsterNames[monsterIndex] << "을 무찔렀다" << std::endl;

			int gold = 10 + rand() % 50;
			std::cout << gold << " 골드를 얻었다" << std::endl;
			player->inventory->SetMoney(gold, true);

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
		std::cout << std::endl << std::endl << "\t" << monsterNames[monsterIndex] << "의 공격!" << std::endl;
		std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
	}
	playHelper::getCommand();

	if (myMath::Mathf::Random::Value() < (attacker->GetHit() - target->GetAvoid())) {
		// 공격이 명중함
		float damage = CalcDamage(attacker, target, isPlayerAttack);
		RenderEvent();
		if (isPlayerAttack) {
			std::cout << std::endl << std::endl << "\t" << monsterNames[monsterIndex] << "은(는) " << damage << " 의 피해를 입었다" << std::endl;
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
			std::cout << std::endl << std::endl << "\t" << monsterNames[monsterIndex] << "은(는) 공격을 회피했다" << std::endl;
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

	if (myMath::Mathf::Random::Value() < attacker->GetCritialProbability()) {
		// 크리티컬이면
		RenderEvent();
		std::cout << std::endl << std::endl << "\t" << "크리티컬!!!!" << std::endl;
		std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
		damage*= attacker->GetCritialDamage();		// 크리 배율만큼 곱하기
		playHelper::getCommand();
	}
	

	float def = target->GetDef();					// 방어력 가져오고
	def *= (1 - attacker->GetDefIgnore());			// 방어력 무시 수치만큼 나눔(근데 속도때문에 곱함)

	if (myMath::Mathf::Random::Value() < target->GetDefenseProbability()) {
		// 방어자가 방어하면
		def *= 2;	// 방어력 2배 증가
		RenderEvent();
		if (isPlayerAttack) {
			std::cout << std::endl << std::endl << "\t" << monsterNames[monsterIndex] << "은(는) 가드를 올렸다" << std::endl;
			std::cout << std::endl << std::endl << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
		}
		else {
			std::cout << std::endl << std::endl << "\t" << "플레이어는 " << monsterNames[monsterIndex] << "의 공격을 방어했다" << std::endl;
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



