#include <iostream>

int main() {
	int game;
	std::cout << "�����ϴ� ������ ����ּ���\n(1. ������ġ 2. �ݿ����Ƽ, 3. ���ҵ�) : ";
	std::cin >> game;

	if (1 <= game && game <= 3) {
		int character;
		if (game <= 1) {
			std::cout << "ĳ���͸� ����ּ���\n(1. D.va 2. �ɼ��� 3. �ֳ� 4. �޸��� 5. ���� 76) : ";
			std::cin >> character;
			if (1 <= character && character <= 5) {
				if (character >= 5) {
					std::cout << "���� 76 ������ �����Ѵ�" << std::endl;
				}
				else if (character >= 4) {
					std::cout << "�ǻ簡 �Խ��ϴ�" << std::endl;
				}
				else if (character >= 3) {
					std::cout << "�ֳ�, ���� �Ϸ�" << std::endl;
				}
				else if (character >= 2) {
					std::cout << "���̸��� ��..�ƴ� �ɼ���" << std::endl;
				}
				else {
					std::cout << "����� ��Ƽ� D.va" << std::endl;
				}
			}
			else {
				std::cout << "��Ͽ� �ִ� ĳ���͸� ����ּ���" << std::endl;
			}
		}
		else if (game <= 2) {
			std::cout << "ų��Ʈ���� ����ּ���\n(1. UAV 2. ���׹̻��� 3. ���� ���� 4. �ǽ� 5. MGB) : ";
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
				std::cout << "��Ͽ� �ִ� ĳ���͸� ����ּ���" << std::endl;
			}
		}
		else {
			std::cout << "ĳ���͸� ����ּ���\n(1. ���̺� 2. ��� 3. �ֵ� 4. �ƶ� 5. ��Ÿ��) : ";
			std::cin >> character;
			if (1 <= character && character <= 5) {
				if (character >= 5) {
					std::cout << "....." << std::endl;
				}
				else if (character >= 4) {
					std::cout << "������ �ʳ׿�?" << std::endl;
				}
				else if (character >= 3) {
					std::cout << "ȣ�� ���̽�" << std::endl;
				}
				else if (character >= 2) {
					std::cout << "��.. Ȥ�� ȭ����?" << std::endl;
				}
				else {
					std::cout << "�̰� �� �Ƿ��̴�" << std::endl;
				}
			}
			else {
				std::cout << "��Ͽ� �ִ� ĳ���͸� ����ּ���" << std::endl;
			}
		}
	}
	else {
		std::cout << "��Ͽ� �ִ� ������ ����ּ���" << std::endl;
	}


}