#include <iostream>

using namespace std;

/// <summary>
/// 배열을 섞는 함수
/// </summary>
/// <param name="arr">섞을 배열</param>
void Shuffle(int arr[][52]);

/// <summary>
/// 카드 내용을 입력받아 맞게 출력하는 함수
/// </summary>
/// <param name="emblem">문양</param>
/// <param name="number">숫자</param>
void PrintCard(int emblem, int number);

int BetMoney(int currentMoney);

/// <summary>
/// 배열의 내용을 출력하는 함수
/// </summary>
/// <param name="arr">출력할 배열</param>
void PrintAllCards(int arr[][52]);



int main() {

	srand(time(0));
	int money = 10000;  // 가지고 있는 돈
	int cardArr[2][52];	// 카드를 담는 배열	

	/*
	다 만들고 나서 생각난건데
	그냥 1~52가 들어있는 배열 만들고
	13으로 나누어서 나온 몫으로 문양 판별하고
	4로 나누어 나온 나머지가 카드의 숫자라고 하면 되는거 아닌가?
	쩝..
	*/

	// 카드를 순서대로 생성
	for (int i = 0; i < 4; i++) {				// 0 : 다이아, 1 : 하트, 2 : 클로버, 3 : 스페이드
		for (int j = 0; j < 13; j++) {			// j : 1 ~ 13
			cardArr[0][i * 13 + j] = i;
			cardArr[1][i * 13 + j] = j + 1;
		}
	}

	PrintAllCards(cardArr);

	Shuffle(cardArr);	// 카드 섞기

	PrintAllCards(cardArr);

	for (int i = 0; i < sizeof(cardArr[1]) / sizeof(int) / 3; i++) {

		int cardList[3];
		int bet;

		cout << "딜러 : " << i + 1 << " 번째 게임 입니다" << endl;
		cout << "[딜러가 카드를 보여준다]" << endl;
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

		cout << "딜러 : 배팅... 해주십시오." << endl;

		bet = BetMoney(money);
		money -= bet;

		if (cardList[0] < cardList[2] && cardList[2] < cardList[1]) {
			cout << "축하합니다! 이겼습니다!" << endl;
			if (7 < rand() % 10) {
				cout << "말도 안돼! 잭팟! 배팅금의 8배를 획득하셨습니다!" << endl;
				money += bet * 6;
			}
			money += bet * 2;
		}
		else {
			cout << "지셨습니다 아쉽습니다" << endl;
		}

		if (money < 500) {
			cout << "[소지금이 다 떨어졌다.. 집에 가자]" << endl;
			return 0;
		}

		cout << endl << endl;
	}

	cout << "딜러 : 저희 카지노는 여기까지 그럼 안전한 귀가 되시길..";
}

void Shuffle(int arr[][52]) {

	for (int i = 0; i < 1000; i++) {
		int index1 = rand() % 52;		// 바꿀 인덱스 지정
		int index2 = rand() % 52;

		int tempEmblem;					// 카드 문양 임시 공간
		int tempNum;					// 카드 번호 임시 공간

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
		cout << "◆";
		break;
	case 1:
		cout << "♥";
		break;
	case 2:
		cout << "♣";
		break;
	case 3:
		cout << "♠";
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
		cout << "[현재 보유금 : " << currentMoney << ", 최소 배팅금 : 500] : ";
		cin >> bet;
		if (bet < 500) {
			cout << "딜러 : 최소 배팅 금액보다는 높게 배팅하셔야 합니다.\n배팅하기 : " << endl;
		}
		else if (bet > currentMoney) {
			cout << "[돈이 부족하다]\n배팅하기 : " << endl;
		}
		
	} while (bet > currentMoney || bet < 500);
	return bet;
}

void PrintAllCards(int arr[][52])
{
	// 그냥 한번 출력
	for (int i = 0; i < 52; i++) {
		switch (arr[0][i]) {
			cout << "문양 : ";
		case 0:
			cout << "◆";
			break;
		case 1:
			cout << "♥";
			break;
		case 2:
			cout << "♣";
			break;
		case 3:
			cout << "♠";
			break;
		}
		cout << ", 숫자 : " << arr[1][i] << endl;
	}
}
