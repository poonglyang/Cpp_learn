#include <iostream>
#include <windows.h>
using namespace std;

void setcolor(unsigned short text, unsigned short back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void SetConsoleColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	SetConsoleTextAttribute(hConsole, color);         // 색상 변경
}

int main() {

	/*for (int i = 0; i < 72 + 51; i++) {
		cout << "■";
	}*/
	cout << endl << endl;

	const int arrsize = 3;

	/*int arr[arrsize][arrsize] = {
		{0,110,0},
		{111,115,112},
		{113,116,114}
	};
	*/
	int arr[arrsize][arrsize] = {
		{14,11,15},
		{0,16,0},
		{0,16,0},
	};
	/*int arr[arrsize][arrsize] = {
		{10,11,12},
		{0,13,0},
		{0,13,0},
	};*/

	cout << endl;

	int visArr[123][123] = {};

	/*for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			visArr[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			visArr[i][9+j] = arr[i][j];
		}
	}*/

	/*for (int i = 0; i < 123; i++) {
		for (int j = 0; j < 123; j++) {
			if (visArr[i][j] == 0) {
				cout << "  ";
			}
			else if (visArr[i][j] == 1) {
				SetConsoleColor(FOREGROUND_RED);
				cout << "■";
			}
			else if (visArr[i][j] == 2) {
				SetConsoleColor(FOREGROUND_GREEN);
				cout << "■";
			}
		}
	}*/

	for (int i = 0; i < arrsize; i++) {
		for (int j = 0; j < arrsize; j++) {
			if (arr[i][j] == 0) {
				cout << "  ";
			}
			else if (arr[i][j] == 1) {
				setcolor(15, 0);
				cout << "■";
			}
			else if (arr[i][j] == 2) {
				setcolor(7, 0);
				cout << "■";
			}
			else if (arr[i][j] == 110) {
				cout << "▲";
			}
			else if (arr[i][j] == 111) {
				cout << "↙";
			}
			else if (arr[i][j] == 112) {
				cout << "↘";
			}
			else if (arr[i][j] == 113)
			{
				cout << "| ";
			}
			else if (arr[i][j] == 114)
			{
				cout << " |";
			}
			else if (arr[i][j] == 115)
			{
				cout << "＄";
			}
			else if (arr[i][j] == 116)
			{
				cout << "┗";
			}
			else if (arr[i][j] == 10) {
				cout << "┖━";
			}
			else if (arr[i][j] == 11) {
				cout << "━";
			}
			else if (arr[i][j] == 12) {
				cout << "━┚";
			}
			else if (arr[i][j] == 13) {
				cout << "◇";
			}
			else if (arr[i][j] == 14) {
				cout << "⊂";
			}
			else if (arr[i][j] == 15) {
				cout << " ⊃";
			}
			else if (arr[i][j] == 16) {
				cout << "◆";
			}

		}
		cout << endl;
	}


}