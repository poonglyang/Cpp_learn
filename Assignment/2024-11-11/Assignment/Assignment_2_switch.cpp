#include <iostream>

int main() {
	int game;
	std::cout << "�����ϴ� ������ ����ּ���\n(1. ������ġ 2. �ݿ����Ƽ, 3. ���ҵ�) : ";
	std::cin >> game;

	switch (game)
	{
		int character;

	case 1:
		std::cout << "ĳ���͸� ����ּ���\n(1. D.va 2. �ɼ��� 3. �ֳ� 4. �޸��� 5. ���� 76) : ";
		std::cin >> character;
		switch (character)
		{
		case 1:
			std::cout << "����� ��Ƽ� D.va" << std::endl;
			break;
		case 2:
			std::cout << "���̸��� ��..�ƴ� �ɼ���" << std::endl;
			break;
		case 3:
			std::cout << "�ֳ�, ���� �Ϸ�" << std::endl;
			break;
		case 4:
			std::cout << "�ǻ簡 �Խ��ϴ�" << std::endl;
			break;
		case 5:
			std::cout << "���� 76 ������ �����Ѵ�" << std::endl;
			break;
		default:
			std::cout << "��Ͽ� �ִ� ĳ���͸� ����ּ���" << std::endl;
			break;
		}
		break;
	case 2:
		std::cout << "ų��Ʈ���� ����ּ���\n(1. UAV 2. ���׹̻��� 3. ���� ���� 4. �ǽ� 5. MGB) : ";
		std::cin >> character;
		switch (character)
		{
		case 1:
			std::cout << "UAV entering the A.O" << std::endl;
			break;
		case 2:
			std::cout << "This is Falcon 3-0, Cruise Missile away" << std::endl;
			break;
		case 3:
			std::cout << "This is Phoenix 3, good copy, strike inbound" << std::endl;
			break;
		case 4:
			std::cout << "Rhino 2-1 arrving on station, fire contril is yours" << std::endl;
			break;
		case 5:
			std::cout << "26627.. Tactical Nuke inbound" << std::endl;
			break;
		default:
			std::cout << "��Ͽ� �ִ� ĳ���͸� ����ּ���" << std::endl;
			break;
		}
		break;
	case 3:
		std::cout << "ĳ���͸� ����ּ���\n(1. ���̺� 2. ��� 3. �ֵ� 4. �ƶ� 5. ��Ÿ��) : ";
		std::cin >> character;
		switch (character)
		{
		case 1:
			std::cout << "�̰� �� �Ƿ��̴�" << std::endl;
			break;
		case 2:
			std::cout << "��.. Ȥ�� ȭ����?" << std::endl;
			break;
		case 3:
			std::cout << "ȣ�� ���̽�" << std::endl;
			break;
		case 4:
			std::cout << "������ �ʳ׿�?" << std::endl;
			break;
		case 5:
			std::cout << "....." << std::endl;
			break;
		default:
			std::cout << "��Ͽ� �ִ� ĳ���͸� ����ּ���" << std::endl;
			break;
		}
		break;
	default:
		std::cout << "��Ͽ� �ִ� ������ ����ּ���" << std::endl;
		break;
	}
}