/*
�б�
	if
		���ǹ��̶�� �ϸ� ���α׷��� ���� �帧�� �����ϴµ� ���
		�־��� ������ ������ ���������� ���� �ڵ����� �����ϰ� �ȴ�
		if���� �ۼ��� ������ ������ �� ���� ���
		
		if (����1){
			����1 ��
		}
		else if(����2) {
			���� if���̵� else if���̵� �ݵ�� �־����
			���� �ִ� if��(����1,)�� ���� �� ����(����2) ��
		}
		else {
			���� if���� ������ ������ ���
		}

		// ���ϸ���ڴٰ� if 5��ø �ñر� ���� ����
		// ������ ���� �ӽ��� �̿��սô�
		// �ൿƮ�� �������..

*/

#include <iostream>

int main() {
	/*
	std::cout << "------if��------" << std::endl;

	if (true)
	{
		// if(����)�� ������ ���� ���
		std::cout << "���� if�� ��� ��!" << std::endl;
	}
	else if(true)
	{
		// ���� �ִ°�(������ ��� if(����))�� ������ �����̰� else if(����)�� ������ ���̸�
		std::cout << "���� else if�� ��� ��!" << std::endl;
	}
	else 
	{
		// �ٷ� ���� �ִ� �� �����̸�
		std::cout << "���� else�� ��� ��!" << std::endl;
	}

	int number;
	std::cout << std::endl << "----------������ �Է��غ���?-----------" << std::endl;

	std::cout << "������ �Է��ض� : ";
	std::cin >> number;		// �Է��ϱ�

	// ���� �Է¹��� ������ 0���� ũ�ٸ�
	if (number > 0) 
	{
		std::cout << "number�� �����" << std::endl;
	}
	else if(number < 0)
	{
		std::cout << "number�� ������" << std::endl;
	}
	else {
		std::cout << "number�� 0�̴�" << std::endl;
	}
	*/
	/*
	int score;

	std::cout << "������ �Է��� ���ƶ� : ";
	std::cin >> score;

	if (score >= 90) {
		std::cout << "A����" << std::endl;
	}
	else if (score >= 80) {
		std::cout << "B����" << std::endl;
	}
	else if (score >= 70) {
		std::cout << "C����" << std::endl;
	}
	else if (score >= 60) {
		std::cout << "D����" << std::endl;
	}
	else {
		std::cout << "F����" << std::endl;
	}
	*/

	// �ǽ�
	//	1. �Է��� �޴´�(��(��) ������ �Է� ����)
	//	2. 3~5�� �� ���
	//	3. 6~8�� ���� ���
	//	4. 9~11�� ���� ���
	//	5. �� �� �ܿ�
	
	int month;
	
	std::cout << "���� �Է����ּ��� : ";
	std::cin >> month;
	
	if ((1 <= month && month <= 2) || (month == 12)) {
			std::cout << "�ܿ�" << std::endl;
	}
	else if (3 <= month && month <= 5) {
		std::cout << "��" << std::endl;
	}
	else if (6 <= month && month <= 8) {
		std::cout << "����" << std::endl;
	}
	else if (9 <= month && month <= 11) {
		std::cout << "����" << std::endl;
	}
	else {
		std::cout << "12�޿� �´� ���� �Է��ϼ���" << std::endl;
	}


	
	/*
	// �׽�Ʈ ���̽�
	for (month = -1; month < 14; month++) {
		std::cout << month << "�޷� �Էµ� �����Դϴ�. " << std::endl;
		if ((0 < month && month < 3) || (month == 12)) {
			std::cout << "�ܿ�" << std::endl;
		}
		else if (2 < month && month < 6) {
			std::cout << "��" << std::endl;
		}
		else if (5 < month && month < 9) {
			std::cout << "����" << std::endl;
		}
		else if (8 < month && month < 12) {
			std::cout << "����" << std::endl;
		}
		else {
			std::cout << "12�޿� �´� ���� �Է��ϼ���" << std::endl;
		}
		std::cout << std::endl;
	}
	*/
	
	// ���� �Է��� ������ ��ȿ�ϰ� ��ȿ�� ���� ������ �հ��̶�� ������ 60�� �̻��̴�
	// 60�� �̻󿡼� ������ �����Ѵٸ�
	int input;

	std::cout << "���� �Է� : "; std::cin >> input;

	// ��ȿ�� �����ΰ�?
	if (0 <= input && input <= 100) {
		if (input >= 60) {
			std::cout << "�հ��Դϴ�" << std::endl;
			if (input >= 90) {
				std::cout << "A����" << std::endl;
			}
			else if (input >= 80) {
				std::cout << "B����" << std::endl;
			}
			else if (input >= 70) {
				std::cout << "C����" << std::endl;
			}
			else {
				std::cout << "D����" << std::endl;
			}
		}
		else {
			std::cout << "���հ��Դϴ�" << std::endl;
		}
	}
	else {
		std::cout << "��ȿ�� �������� �ƴմϴ�" << std::endl;
	}

	int inputNum;
	std::cin >> inputNum;
	if ((inputNum % 2) == 0) {
		// ¦���ϰ�� ����
	}
	else {

	}

	//char a[] = { '��' };
	
}