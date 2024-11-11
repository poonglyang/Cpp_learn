#include <iostream>

int main() {
	int game;
	std::cout << "좋아하는 게임을 골라주세요\n(1. 오버워치 2. 콜오브듀티, 3. 엘소드) : ";
	std::cin >> game;

	if (1 <= game && game <= 3) {
		int character;
		if (game <= 1) {
			std::cout << "캐릭터를 골라주세요\n(1. D.va 2. 케서디 3. 주노 4. 메르시 5. 솔져 76) : ";
			std::cin >> character;
			if (1 <= character && character <= 5) {
				if (character >= 5) {
					std::cout << "솔져 76 작전을 시작한다" << std::endl;
				}
				else if (character >= 4) {
					std::cout << "의사가 왔습니다" << std::endl;
				}
				else if (character >= 3) {
					std::cout << "주노, 착륙 완료" << std::endl;
				}
				else if (character >= 2) {
					std::cout << "내이름은 멕..아니 케서디" << std::endl;
				}
				else {
					std::cout << "사랑을 담아서 D.va" << std::endl;
				}
			}
			else {
				std::cout << "목록에 있는 캐릭터를 골라주세요" << std::endl;
			}
		}
		else if (game <= 2) {
			std::cout << "킬스트릭를 골라주세요\n(1. UAV 2. 순항미사일 3. 정밀 공습 4. 건쉽 5. MGB) : ";
			std::cin >> character;
			if (1 <= character && character <= 5) {
				if (character >= 5) {
					std::cout << "26627 Tactical Nuke inbound" << std::endl;
				}
				else if (character >= 4) {
					std::cout << "Rhino 2-1 arrving on station, fire contril is yours" << std::endl;
				}
				else if (character >= 3) {
					std::cout << "This is Phoenix 3, good copy, strike inbound" << std::endl;
				}
				else if (character >= 2) {
					std::cout << "This is Falcon 3-0, Cruise Missile away" << std::endl;
				}
				else {
					std::cout << "UAV entering the A.O" << std::endl;
				}
			}
			else {
				std::cout << "목록에 있는 캐릭터를 골라주세요" << std::endl;
			}
		}
		else {
			std::cout << "캐릭터를 골라주세요\n(1. 레이븐 2. 라비 3. 애드 4. 아라 5. 리타아) : ";
			std::cin >> character;
			if (1 <= character && character <= 5) {
				if (character >= 5) {
					std::cout << "....." << std::endl;
				}
				else if (character >= 4) {
					std::cout << "나쁘지 않네요?" << std::endl;
				}
				else if (character >= 3) {
					std::cout << "호오 나이스" << std::endl;
				}
				else if (character >= 2) {
					std::cout << "음.. 혹시 화났어?" << std::endl;
				}
				else {
					std::cout << "이게 내 실력이다" << std::endl;
				}
			}
			else {
				std::cout << "목록에 있는 캐릭터를 골라주세요" << std::endl;
			}
		}
	}
	else {
		std::cout << "목록에 있는 게임을 골라주세요" << std::endl;
	}


}