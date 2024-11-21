#include "Bingo.h"

/// <summary>
/// 배열을 섞어주는 함수
/// </summary>
/// <param name="arr">섞을 배열</param>
void Bingo::shuffle(int* arr)
{
	int index1_col, index1_row;
	int index2_col, index2_row, temp;

	for (int i = 0; i < 1000; i++) {
		index1_col = rand() % size;
		index1_row = rand() % size;
		index2_col = rand() % size;
		index2_row = rand() % size;

		temp = arr[index1_col * size + index1_row];
		arr[index1_col * size + index1_row] = arr[index2_col * size + index2_row];
		arr[index2_col * size + index2_row] = temp;
	}

}

/// <summary>
/// 빙고의 생성자, 빙고판을 생성하고 크기를 채움
/// </summary>
/// <param name="size">빙고판의 크기</param>
Bingo::Bingo(int size)
{
	this->size = size;

	bingoArr = new int*[size];

	bingoCount = 0;

	for (int i = 0; i < size; i++) {
		bingoArr[i] = new int[size];
	}
}

Bingo::~Bingo()
{
	for (int i = 0; i < size; i++) {
		delete[] bingoArr[i];  
	}

	delete[] bingoArr;
}

/// <summary>
/// 빙고의 크기를 반환하는 함수
/// </summary>
/// <returns>빙고의 크기</returns>
int Bingo::GetSize()
{
	return size;
}

int Bingo::GetBingoCount()
{
	return bingoCount;
}

/// <summary>
/// 숫자를 하나씩 가져와서 채워지지 않은 자리에 채우는 함수
/// </summary>
/// <param name="n">채울 숫자</param>
void Bingo::FillBingo(int n)
{
	if ( n < 0 && n > size * size -1) {
		cout << "[범위 밖의 값을 입력하셨습니다]" << endl;
		return;
	}

	for (int col = 0; col < size; col++) {
		// 세로
		for (int row = 0; row < size; row++) {
			// 가로
			if (-1 <= bingoArr[col][row] && bingoArr[col][row] < size * size) {
				continue;
			}
			else {
				bingoArr[col][row] = n;
				return;
			}
		}
		cout << endl;
	}
}

/// <summary>
/// 빙고를 채우는 함수
/// </summary>
/// <param name="arr">채울 값들이 들어간 배열</param>
void Bingo::FillBingo(int arr[])
{
	//if (sizeof(*arr) / sizeof(int) != size * size) {
	//	// 만약 빙고판의 크기와 배열의 크기가 다르다면 (빙고판을 다 채울 수 없다면)
	//	exit;
	//}
	for (int col = 0; col < size; col++) {
		// 세로
		for (int row = 0; row < size; row++) {
			// 가로
			bingoArr[col][row] = arr[col * size + row];
		}
	}
	
}

/// <summary>
/// 자동으로 빙고를 채우는 함수
/// </summary>
void Bingo::FillBingo()
{
	int* arr = new int[size * size];			// size * size 크기의 배열을 만듦
	
	for (int i = 0; i < size * size; i++) {
		arr[i] = i;								// 배열 0부터 size * size -1 만큼 채움
	}

	shuffle(arr);			// 배열 섞기

	for (int col = 0; col < size; col++) {
		// 세로
		for (int row = 0; row < size; row++) {
			// 가로
			bingoArr[col][row] = arr[col * size + row];		// 섞인 배열을 넣어줌
		}
	}
}


/// <summary>
/// 매개변수로 받은 숫자를 빙고에서 찾고 숫자가 있으면 -1로 바꾸는 함수
/// </summary>
/// <param name="num">찾을 숫자</param>
/// <returns>찾는 숫자가 있으면 true 없으면 false</returns>
bool Bingo::SelectNum(int num)
{
	for (int col = 0; col < size; col++) {
		// 세로
		for (int row = 0; row < size; row++) {
			// 가로
			if (bingoArr[col][row] == num) {
				bingoArr[col][row] = -1;
				return true;
			}
		}
	}
	return false;
}

/// <summary>
/// 빙고의 개수를 새는 함수
/// </summary>
/// <returns>빙고의 갯수</returns>
int Bingo::CountBingo()
{
	int bingoCount = 0;

	bool isBingo = true;

	// 가로 빙고 검사
	for (int col = 0; col < size; col++) {
		// 세로
		isBingo = true;
		for (int row = 0; row < size; row++) {
			// 가로
			if (bingoArr[col][row] != -1) {
				isBingo = false;
				break;
			}
		}
		if (isBingo) {
			bingoCount++;
		}
	}

	// 세로 빙고 검사
	for (int row = 0; row < size; row++) {
		// 가로
		bool isBingo = true;
		for (int col = 0; col < size; col++) {
			// 세로
			if (bingoArr[col][row] != -1) {
				isBingo = false;
				break;
			}
		}
		if (isBingo) {
			bingoCount++;
		}
	}

	// 좌상단 -> 우하단 대각선 검사
	isBingo = true;
	for (int i = 0; i < size; i++) {
		// 세로
		if (bingoArr[i][i] != -1) {
			isBingo = false;
			break;
		}
	}
	if (isBingo) {
		bingoCount++;
	}

	// 우상단 -> 좌하단 대각선 검사
	isBingo = true;
	for (int i = 0; i < size; i++) {
		if (bingoArr[i][size - i - 1] != -1) {
			isBingo = false;
			break;
		}
	}
	if (isBingo) {
		bingoCount++;
	}

	//cout << "빙고 갯수 : " << bingoCount << endl;

	this->bingoCount = bingoCount;

	return bingoCount;
}

/// <summary>
/// 빙고를 출력하는 함수
/// </summary>
void Bingo::PrintBingo()
{
	for (int col = 0; col < size; col++) {
		// 세로
		for (int row = 0; row < size; row++) {
			// 가로
			if (-1 <= bingoArr[col][row] && bingoArr[col][row] < size * size) {
				if (bingoArr[col][row] == -1) {
					cout << "#\t";
				}
				else {
					cout << bingoArr[col][row] << "\t";
				}
			}
			else {
				cout << "*\t";
			}
		}
		cout << endl;
	}
	cout << endl;
}
