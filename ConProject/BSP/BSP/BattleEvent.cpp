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
				std::cout << "��";
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
				std::cout << "��";
				break;
			case 22:
				SetRGBColor(255, 175, 163);
				std::cout << "��";
				break;
			case 23:
				SetRGBColor(255, 255, 163);
				std::cout << "��";
				break;
			case 24:
				SetRGBColor(249, 136, 163);
				std::cout << "��";
				break;
			case 25:
				SetRGBColor(230, 89, 105);
				std::cout << "��";
				break;
			case 26:
				SetRGBColor(172, 20, 75);
				std::cout << "��";
				break;

				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				// �ؽ�Ʈ ���� ���� (�⺻)
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
					std::cout << "��";
					break;
				case 2:
					SetRGBColor(255, 255, 255);
					std::cout << "\t��  [�����ϱ�]\t\t\t���\t\t    [������ ���]\t\t  ��";
					break;
				case 3:
					SetRGBColor(255, 255, 255);
					std::cout << "\t   [�����ϱ�] \t\t\t���\t\t��    [������ ���]\t\t  ��";
					break;
					SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					// �ؽ�Ʈ ���� ���� (�⺻)
					printf("\033[0m");
				}
			}
			std::cout << std::endl;
		}


		input = playHelper::getCommand();

		switch (input) {
		case 100:	// ������ ����Ű �Ǵ� a
		case 77:
			BattleText[3][4] = 3;
			break;

		case 97:	// ���� ����Ű �Ǵ� d
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
				std::cout << "�Ҹ�ǰ�� ����Ͽ����ϴ�(�����ؾ��Խù�)" << std::endl;
			}

			RenderEvent();
			player->PrintPlayerInfo();

			playHelper::getCommand();
			
			RenderEvent();

			std::cout << std::endl << "���� ����" << std::endl;
			monster->PrintState();

			playHelper::getCommand();
			break;
		}

		if (player->GetHp() <= 0) {
			RenderEvent();
			std::cout << std::endl << std::endl << "\t�÷��̾ ����Ͽ���" << std::endl;
			std::cout << std::endl << std::endl << "���������������������������������������������������";
			playHelper::getCommand();
			battleEnd = true;
		}
		
		if (monster->GetHp() <= 0) {
			RenderEvent();
			std::cout << std::endl << std::endl << monsterNames[0] << "�� ���񷶴�" << std::endl;
			std::cout << std::endl << std::endl << "���������������������������������������������������";
			playHelper::getCommand();
			battleEnd = true;
		}

	}
}



void BattleEvent::Attack(IState* attacker, IState* target, bool isPlayerAttack)
{
	RenderEvent();

	if (isPlayerAttack) {
		std::cout << std::endl << std::endl << "\t�÷��̾��� ����!" << std::endl;
		std::cout << std::endl << std::endl << "���������������������������������������������������";
	}
	else {
		std::cout << std::endl << std::endl << "\t" << monsterNames[0] << "�� ����!" << std::endl;
		std::cout << std::endl << std::endl << "���������������������������������������������������";
	}
	playHelper::getCommand();

	if (Mathf::Random::Value() < (attacker->GetHit() - target->GetAvoid())) {
		// ������ ������
		float damage = CalcDamage(attacker, target, isPlayerAttack);
		RenderEvent();
		if (isPlayerAttack) {
			std::cout << std::endl << std::endl << "\t" << monsterNames[0] << "��(��) " << damage << " �� ���ظ� �Ծ���" << std::endl;
			std::cout << std::endl << std::endl << "���������������������������������������������������";
		}
		else {
			std::cout << std::endl << std::endl << "\t" << "�÷��̾�� " << damage << " �� ���ظ� �Ծ���" << std::endl;
			std::cout << std::endl << std::endl << "���������������������������������������������������";
		}
		target->SetHp(-damage, true);
		playHelper::getCommand();
	}
	else {
		// ȸ����
		RenderEvent();
		if (isPlayerAttack) {
			std::cout << std::endl << std::endl << "\t" << monsterNames[0] << "��(��) ������ ȸ���ߴ�" << std::endl;
			std::cout << std::endl << std::endl << "���������������������������������������������������";
		}
		else {
			std::cout << std::endl << std::endl << "\t" << "�÷��̾���(��) ������ ȸ���ߴ�" << std::endl;
			std::cout << std::endl << std::endl << "���������������������������������������������������";
		}
		playHelper::getCommand();
	}
}

float BattleEvent::CalcDamage(IState* attacker, IState* target, bool isPlayerAttack)
{
	float damage = attacker->GetAtk();

	if (Mathf::Random::Value() < attacker->GetCritialProbability()) {
		// ũ��Ƽ���̸�
		RenderEvent();
		std::cout << std::endl << std::endl << "\t" << "ũ��Ƽ��!!!!" << std::endl;
		std::cout << std::endl << std::endl << "���������������������������������������������������";
		damage*= attacker->GetCritialDamage();		// ũ�� ������ŭ ���ϱ�
		playHelper::getCommand();
	}
	

	float def = target->GetDef();					// ���� ��������
	def *= (1 - attacker->GetDefIgnore());			// ���� ���� ��ġ��ŭ ����(�ٵ� �ӵ������� ����)

	if (Mathf::Random::Value() < target->GetDefenseProbability()) {
		// ����ڰ� ����ϸ�
		def *= 2;	// ���� 2�� ����
		RenderEvent();
		if (isPlayerAttack) {
			std::cout << std::endl << std::endl << "\t" << monsterNames[0] << "��(��) ���带 �÷ȴ�" << std::endl;
			std::cout << std::endl << std::endl << "���������������������������������������������������";
		}
		else {
			std::cout << std::endl << std::endl << "\t" << "�÷��̾�� " << monsterNames[0] << "�� ������ ����ߴ�" << std::endl;
			std::cout << std::endl << std::endl << "���������������������������������������������������";
		}
		playHelper::getCommand();
	}
	
	
	damage -= def;

	if (damage < 1) {
		return 1;
	}

	return damage;
}



