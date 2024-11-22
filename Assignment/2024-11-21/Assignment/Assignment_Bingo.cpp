#include <iostream>
#include <windows.h>
#include "Bingo.h"
using namespace std;

void PrintBingo(Bingo& b1, Bingo& b2) {

	cout << endl << "�÷��̾��� ����" << endl;
	b1.PrintBingo();
	cout << "�÷��̾� ���� ī��Ʈ : " << b1.CountBingo() << endl;

	cout << endl << "��ǻ�� ����" << endl;
	b2.PrintBingo();
	cout << "��ǻ�� ���� ī��Ʈ : " << b2.CountBingo() << endl;
}

int main() {
	int n;
	cout << "���� ũ�⸦ �Է��ϼ���. (ex. 5*5�� 5�Է�) : ";
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
			// ������ �ùٸ� ���ڰ� ���õ� ������ �ݺ��ؼ� �����ϴ� �ݺ���
			cout << "���� ������ ���ڸ� �Է��ϼ���. 0~" << (playerBingo->GetSize() * playerBingo->GetSize()) - 1 << " : ";
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