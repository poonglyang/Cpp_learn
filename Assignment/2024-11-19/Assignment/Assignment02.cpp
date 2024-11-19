/*
Get, Set�� Ȱ���Ͽ� �÷��̾�� ���� �������� ����� (ä��, ���ݷ¸� ����)
*/


#include <iostream> 
using namespace std;

class Entity {
protected :
	string name;
	float hp;
	float power;

	void Die() {
		cout << "]" << endl << name << "�� ��������" << endl;
	}

public :
	Entity(const string& name, float hp, float power) :name(name), hp(hp), power(power) {}

	~Entity() {
	}

	string GetName() {
		return name;
	}

	void SetName(string name) {
		this->name = name;
	}

	float GetHp() {
		return hp;
	}

	void SetHp(float hp) {
		if (this->hp - hp <= 0) {
			this->hp = 0;
			this->Die();
		}
		else {
			this->hp -= hp;
			cout << "���� hp : " << this->hp << "]" << endl;
		}
	}

	float GetPower() {
		return power;
	}

	void SetPower(float power) {
		this->power = power;
	}
};

class Player : public Entity {

public:
	Player(const string& name, float hp, float power) : Entity(name, hp, power) {
		
	}
};

class Enemy : public Entity {

public:
	Enemy(const string& name, float hp, float power) : Entity(name, hp, power) {

	}
};

void Attack(Player& attacker, Enemy& target) {
	cout << attacker.GetName() << "�� ����" << endl;
	cout << "[" << target.GetName() << "��(��) " << attacker.GetPower() << "�� ���ظ� �Ծ���.";
	target.SetHp(attacker.GetPower());
}

void Attack(Enemy& attacker, Player& target) {
	cout << attacker.GetName() << "�� ����" << endl;
	cout << "[" << target.GetName() << "��(��) " << attacker.GetPower() << "�� ���ظ� �Ծ���.";
	target.SetHp(attacker.GetPower());
}

int main() {
	Player* player = new Player("�÷��̾�", 50, 3000);
	Enemy* enemy = new Enemy("��", 10000, 5);

	srand(time(0));

	cout << enemy->GetName() << "��(��) �����ߴ�" << endl;
	while (player->GetHp() > 0 && enemy->GetHp() > 0) {
		if (rand() % 3 < 2) {
			Attack(*player, *enemy);
			Attack(*enemy, *player);
		}
		else {
			Attack(*enemy, *player);
			Attack(*player, *enemy);
		}
	}

	delete player;
	player = nullptr;
	delete enemy;
	enemy = nullptr;

}