#include <iostream>
#include <windows.h>
#include "Bingo.h"
using namespace std;

void PrintBingo(Bingo& b1, Bingo& b2) {

	cout << endl << "플레이어의 빙고" << endl;
	b1.PrintBingo();
	cout << "플레이어 빙고 카운트 : " << b1.CountBingo() << endl;

	cout << endl << "컴퓨터 빙고" << endl;
	b2.PrintBingo();
	cout << "컴퓨터 빙고 카운트 : " << b2.CountBingo() << endl;
}

int main() {
	int n;
	cout << "빙고 크기를 입력하세요. (ex. 5*5면 5입력) : ";
	cin >> n;

	srand(time(0));

	Bingo* playerBingo = new Bingo(n);
	playerBingo->FillBingo();

	Bingo* comBingo = new Bingo(n);
	comBingo->FillBingo();
	
	PrintBingo(*playerBingo, *comBingo);
	
	int select;
	int comSelect;
	while (playerBingo->CountBingo() < 3 && comBingo->CountBingo() < 3) {

		do
		{
			// 빙고에서 올바른 숫자가 선택될 때까지 반복해서 선택하는 반복문
			cout << "빙고에 선택할 숫자를 입력하세요. 0~" << (playerBingo->GetSize() * playerBingo->GetSize()) - 1 << " : ";
			cin >> select;
		} while (!playerBingo->SelectNum(select));
		
		comBingo->SelectNum(select);

		do {
			comSelect = rand() % (comBingo->GetSize() * comBingo->GetSize());
		} while (!comBingo->SelectNum(comSelect));
		
		playerBingo->SelectNum(comSelect);

		PrintBingo(*playerBingo, *comBingo);
	}

	
	
	delete playerBingo, comBingo;
	playerBingo = comBingo = nullptr;
}