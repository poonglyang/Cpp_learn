/*
Get, Set을 활용하여 플레이어와 몬스터 전투게임 만들기 (채력, 공격력만 있음)
*/


#include <iostream> 
using namespace std;

class Entity {
protected :
	string name;
	float hp;
	float power;

	void Die() {
		cout << "]" << endl << name << "은 쓰러졌다" << endl;
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
			cout << "남은 hp : " << this->hp << "]" << endl;
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
	cout << attacker.GetName() << "의 공격" << endl;
	cout << "[" << target.GetName() << "은(는) " << attacker.GetPower() << "의 피해를 입었다.";
	target.SetHp(attacker.GetPower());
}

void Attack(Enemy& attacker, Player& target) {
	cout << attacker.GetName() << "의 공격" << endl;
	cout << "[" << target.GetName() << "은(는) " << attacker.GetPower() << "의 피해를 입었다.";
	target.SetHp(attacker.GetPower());
}

int main() {
	Player* player = new Player("플레이어", 50, 3000);
	Enemy* enemy = new Enemy("적", 10000, 5);

	srand(time(0));

	cout << enemy->GetName() << "이(가) 등장했다" << endl;
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