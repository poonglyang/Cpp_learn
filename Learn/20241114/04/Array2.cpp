#include <iostream> 
#include <algorithm>

int main() {
	srand(time(0));

	int intArr1[10];

	// �ʱ�ȭ
	for (int i = 0; i < 10; i++) {
		intArr1[i] = i;
	}

	// ������
	std::cout << "���� ��" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << i << ", " << std::endl;
	}

	std::cout << std::endl;

	// ���ÿ� ������
	int dest, sour, temp;

	for (int i = 0; i < 1000; i++) {
		dest = rand() % 10;
		sour = rand() % 10;

		std::cout << std::endl << dest << ", " << sour << std::endl;

		temp = intArr1[dest];
		intArr1[dest] = intArr1[sour];
		intArr1[sour] = temp;
	}

	// ������
	std::cout << "���� ��" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout <<  i << " " << intArr1[i];
	}

	// �ζ� ��ȣ �����
	std::cout << std::endl;

	int lottoNumberArr[45];
	int lottoArr[6];

	for (int i = 0; i < 45; i++) {
		lottoNumberArr[i] = i + 1;
	}

	for (int i = 0; i < 777; i++) {
		dest = rand() % 45;
		sour = rand() % 45;

		temp = lottoNumberArr[dest];
		lottoNumberArr[dest] = lottoNumberArr[sour];
		lottoNumberArr[sour] = temp;
	}

	std::cout << "�̹��� �ζ� ��ȣ�� ";

	for (int i = 0; i < 6; i++) {
		lottoArr[i] = lottoNumberArr[i];
	}
	std::sort(lottoArr, lottoArr + 6);

	for (int i = 0; i < 6; i++) {
		std::cout << lottoArr[i] << ", ";
	}

	std::cout << "�Դϴ�!" << std::endl;

	// �ǽ�
	// 10���� �л� ������ �Է�. �迭�� �����ϰ� ������ ����� ���ض�
	std::cout << "\n�л��� ������ 10�� �Է��ϼ��� : ";

	int scores[10];
	int sum = 0;
	for (int i = 0; i < sizeof(scores) / sizeof(int); i++) {
		std::cin >> scores[i];
		sum += scores[i];
	}

	std::cout << "���� : " << sum << ", ��� : " << sum / (sizeof(scores) / sizeof(int)) << std::endl;

	
}