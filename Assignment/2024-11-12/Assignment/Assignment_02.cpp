#include <iostream>

int main() {
	int count = 0;

	std::cout << "가위 바위 보 게임입니다" << std::endl;

	srand(time(NULL));	// 시드값 변경

	while (count < 10) {
		int playerChoice = 0;
		
		while (playerChoice < 1 || 3 < playerChoice) {
			std::cout << "가위(1), 바위(2), 보(3)를 입력해주세요 : ";
			std::cin >> playerChoice;
			if (1 <= playerChoice && playerChoice <= 3) {
				// 플레이어가 올바른 값을 입력할 때가지 검사함
				break;
			}
			std::cout << "올바른 숫자 (가위(1), 바위(2), 보(3))를 입력하세요" << std::endl << std::endl;
		}
		
		int comChoice = rand() % 3 + 1;		// 컴퓨터 역시 1, 2, 3 중 하나만 선택하게 함

		if (comChoice == playerChoice) {
			std::cout << "비겼습니다" << std::endl;
		}
		else if (playerChoice - comChoice == 1 || playerChoice - comChoice == -2 ){
			std::cout << "플레이어 : " << playerChoice << ", 컴퓨터 : " << comChoice << " 이겼습니다" << std::endl;
		}
		else {
			std::cout << "플레이어 : " << playerChoice << ", 컴퓨터 : " << comChoice << " 졌습니다" << std::endl;
		}
		std::cout << std::endl;

		count++;
	}
}