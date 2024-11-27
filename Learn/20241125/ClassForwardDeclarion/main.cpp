/*
[상호 참조 오류]
	클래스 끼리 서로 참조하기에 상호 참조 오류가 난다
	클래스 전방 선언을 하여 해결하자

	전방선언을 하여 컴파일러가 필요한 타이밍에만 찾을 수 있게 한다
*/

#include "Player.h"
#include "Weapon.h"

int main() {
	Weapon* sword = new Weapon("검");

	Player* player = new Player("김검사", sword);

	player->Attack();

	delete sword;
	sword = nullptr;

	delete player;
	player = nullptr;
}