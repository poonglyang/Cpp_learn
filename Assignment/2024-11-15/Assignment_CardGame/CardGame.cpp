#include <iostream>

using namespace std;

/// <summary>
/// �迭�� ���� �Լ�
/// </summary>
/// <param name="arr">���� �迭</param>
void Shuffle(int arr[][52]);

/// <summary>
/// ī�� ������ �Է¹޾� �°� ����ϴ� �Լ�
/// </summary>
/// <param name="emblem">����</param>
/// <param name="number">����</param>
void PrintCard(int emblem, int number);

int BetMoney(int currentMoney);

/// <summary>
/// �迭�� ������ ����ϴ� �Լ�
/// </summary>
/// <param name="arr">����� �迭</param>
void PrintAllCards(int arr[][52]);



int main() {

	srand(time(0));
	int money = 10000;  // ������ �ִ� ��
	int cardArr[2][52];	// ī�带 ��� �迭	

	/*
	�� ����� ���� �������ǵ�
	�׳� 1~52�� ����ִ� �迭 �����
	13���� ����� ���� ������ ���� �Ǻ��ϰ�
	4�� ������ ���� �������� ī���� ���ڶ�� �ϸ� �Ǵ°� �ƴѰ�?
	��..
	*/

	// ī�带 ������� ����
	for (int i = 0; i < 4; i++) {				// 0 : ���̾�, 1 : ��Ʈ, 2 : Ŭ�ι�, 3 : �����̵�
		for (int j = 0; j < 13; j++) {			// j : 1 ~ 13
			cardArr[0][i * 13 + j] = i;
			cardArr[1][i * 13 + j] = j + 1;
		}
	}

	PrintAllCards(cardArr);

	Shuffle(cardArr);	// ī�� ����

	PrintAllCards(cardArr);

	for (int i = 0; i < sizeof(cardArr[1]) / sizeof(int) / 3; i++) {

		int cardList[3];
		int bet;

		cout << "���� : " << i + 1 << " ��° ���� �Դϴ�" << endl;
		cout << "[������ ī�带 �����ش�]" << endl;
		cout << "=======["; 
		for (int j = 0; j < 3; j++) {
			cardList[j] = cardArr[1][i * 3 + j];
			PrintCard(cardArr[0][i * 3 + j], cardArr[1][i * 3 + j]);
			cout << "  ";
		}
		cout << "]=======" << endl << endl;

		if (cardList[0] > cardList[1]) {
			int temp = cardList[0];
			cardList[0] = cardList[1];
			cardList[1] = temp;
		}

		//cout << endl << cardList[0] << "  " << cardList[1] << "  " << cardList[2] << endl;
		//cout << (cardList[0] < cardList[2]) << " " << (cardList[2] < cardList[1]) << endl;

		cout << "���� : ����... ���ֽʽÿ�." << endl;

		bet = BetMoney(money);
		money -= bet;

		if (cardList[0] < cardList[2] && cardList[2] < cardList[1]) {
			cout << "�����մϴ�! �̰���ϴ�!" << endl;
			if (7 < rand() % 10) {
				cout << "���� �ȵ�! ����! ���ñ��� 8�踦 ȹ���ϼ̽��ϴ�!" << endl;
				money += bet * 6;
			}
			money += bet * 2;
		}
		else {
			cout << "���̽��ϴ� �ƽ����ϴ�" << endl;
		}

		if (money < 500) {
			cout << "[�������� �� ��������.. ���� ����]" << endl;
			return 0;
		}

		cout << endl << endl;
	}

	cout << "���� : ���� ī����� ������� �׷� ������ �Ͱ� �ǽñ�..";
}

void Shuffle(int arr[][52]) {

	for (int i = 0; i < 1000; i++) {
		int index1 = rand() % 52;		// �ٲ� �ε��� ����
		int index2 = rand() % 52;

		int tempEmblem;					// ī�� ���� �ӽ� ����
		int tempNum;					// ī�� ��ȣ �ӽ� ����

		tempEmblem = arr[0][index1];
		tempNum = arr[1][index1];

		arr[0][index1] = arr[0][index2];
		arr[1][index1] = arr[1][index2];

		arr[0][index2] = tempEmblem;
		arr[1][index2] = tempNum;
	}
}

void PrintCard(int emblem, int number)
{
	switch (emblem) {
	case 0:
		cout << "��";
		break;
	case 1:
		cout << "��";
		break;
	case 2:
		cout << "��";
		break;
	case 3:
		cout << "��";
		break;
	}

	switch (number) {
	case 1:
		cout << "A";
		break;
	case 11:
		cout << "J";
		break;
	case 12:
		cout << "Q";
		break;
	case 13:
		cout << "K";
		break;
	default:
		cout << number;
	}
}

int BetMoney(int currentMoney)
{	
	int bet;
	do {
		cout << "[���� ������ : " << currentMoney << ", �ּ� ���ñ� : 500] : ";
		cin >> bet;
		if (bet < 500) {
			cout << "���� : �ּ� ���� �ݾ׺��ٴ� ���� �����ϼž� �մϴ�.\n�����ϱ� : " << endl;
		}
		else if (bet > currentMoney) {
			cout << "[���� �����ϴ�]\n�����ϱ� : " << endl;
		}
		
	} while (bet > currentMoney || bet < 500);
	return bet;
}

void PrintAllCards(int arr[][52])
{
	// �׳� �ѹ� ���
	for (int i = 0; i < 52; i++) {
		switch (arr[0][i]) {
			cout << "���� : ";
		case 0:
			cout << "��";
			break;
		case 1:
			cout << "��";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		}
		cout << ", ���� : " << arr[1][i] << endl;
	}
}
