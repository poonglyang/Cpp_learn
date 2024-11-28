/*
열거형
	상수 집합에 이름을 붙여서 사용하는 데이터 타입
	코드의 가독성을 높임
	기본적으로 int 타입으로 정의된다
	자동으로 0부터 시작하여 1씩 증가한다
	명시적으로 값을 지정할 수 있다.

// 구 방식 (C++ 11이전)
enum ColorEnum{
	Red,		// 0
	Green,		// 1
	Black,		// 2
};


*/

#include <iostream>

enum ColorEnum{
	Red,		// 0
	Green,		// 1
	Black,		// 2
};

enum Direction {
	Left = 1,	// 1
	Right,		// 2
	Up = 4,		// 4
	Down,		// 5
	Front,		// 6
	Back,		// 7
};

/// <summary>
/// 범위 기반 열거형(C++ 11이후)
/// </summary>
enum class Location
{
	Inven,
	Town,
	Shop
};

enum class Character {
	Knight = 1,
	Mage,
	Archer,
	None
};

// 리턴 타입이 열거형이다?
Character GetCharacter(int n) {
	switch (n) {
	case 1: return Character::Knight;
	case 2: return Character::Mage;
	case 3: return Character::Archer;
	default: return Character::None;
	}
}


int main() {
	ColorEnum a = Red;
	ColorEnum b = 2;

	/*std::cout << ColorEnum::Red << std::endl;
	std::cout << ColorEnum::Green << std::endl;
	std::cout << ColorEnum::Black << std::endl<< std::endl;

	std::cout << Direction::Down << std::endl;*/

	std::cout << a << std::endl;

	// 범위 기반 열거형
	//Location loc = Inven;	// 범위를 명확하게 지정해야한다

	Location loc = Location::Town;

	int dirSelect;
	std::cin >> dirSelect;

	switch (dirSelect) {
	case Direction::Left:
		break;
	case Direction::Right:
		break;
	case Direction::Up:
		break;
	case Direction::Down:
		break;
	}

	int characterSelect;
	std::cin >> characterSelect;

	Character selectedCharacter = static_cast<Character>(characterSelect);

	switch (selectedCharacter) {
	case Character::Knight:
		break;
	case Character::Mage:
		break;
	case Character::Archer:
		break;
	default:
		break;
	}

	// 실습
	// 1. 좌표를 나타내는 구조체를 정의해라
}