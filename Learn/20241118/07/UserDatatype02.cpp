/*
������
	��� ���տ� �̸��� �ٿ��� ����ϴ� ������ Ÿ��
	�ڵ��� �������� ����
	�⺻������ int Ÿ������ ���ǵȴ�
	�ڵ����� 0���� �����Ͽ� 1�� �����Ѵ�
	��������� ���� ������ �� �ִ�.

// �� ��� (C++ 11����)
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
/// ���� ��� ������(C++ 11����)
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

// ���� Ÿ���� �������̴�?
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

	// ���� ��� ������
	//Location loc = Inven;	// ������ ��Ȯ�ϰ� �����ؾ��Ѵ�

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

	// �ǽ�
	// 1. ��ǥ�� ��Ÿ���� ����ü�� �����ض�
}