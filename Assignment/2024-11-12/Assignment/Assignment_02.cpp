#include <iostream>

int main() {
	int count = 0;

	std::cout << "���� ���� �� �����Դϴ�" << std::endl;

	srand(time(NULL));	// �õ尪 ����

	while (count < 10) {
		int playerChoice = 0;
		
		while (playerChoice < 1 || 3 < playerChoice) {
			std::cout << "����(1), ����(2), ��(3)�� �Է����ּ��� : ";
			std::cin >> playerChoice;
			if (1 <= playerChoice && playerChoice <= 3) {
				// �÷��̾ �ùٸ� ���� �Է��� ������ �˻���
				break;
			}
			std::cout << "�ùٸ� ���� (����(1), ����(2), ��(3))�� �Է��ϼ���" << std::endl << std::endl;
		}
		
		int comChoice = rand() % 3 + 1;		// ��ǻ�� ���� 1, 2, 3 �� �ϳ��� �����ϰ� ��

		if (comChoice == playerChoice) {
			std::cout << "�����ϴ�" << std::endl;
		}
		else if (playerChoice - comChoice == 1 || playerChoice - comChoice == -2 ){
			std::cout << "�÷��̾� : " << playerChoice << ", ��ǻ�� : " << comChoice << " �̰���ϴ�" << std::endl;
		}
		else {
			std::cout << "�÷��̾� : " << playerChoice << ", ��ǻ�� : " << comChoice << " �����ϴ�" << std::endl;
		}
		std::cout << std::endl;

		count++;
	}
}