#include "Bingo.h"

/// <summary>
/// �迭�� �����ִ� �Լ�
/// </summary>
/// <param name="arr">���� �迭</param>
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
/// ������ ������, �������� �����ϰ� ũ�⸦ ä��
/// </summary>
/// <param name="size">�������� ũ��</param>
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
/// ������ ũ�⸦ ��ȯ�ϴ� �Լ�
/// </summary>
/// <returns>������ ũ��</returns>
int Bingo::GetSize()
{
	return size;
}

int Bingo::GetBingoCount()
{
	return bingoCount;
}

/// <summary>
/// ���ڸ� �ϳ��� �����ͼ� ä������ ���� �ڸ��� ä��� �Լ�
/// </summary>
/// <param name="n">ä�� ����</param>
void Bingo::FillBingo(int n)
{
	if ( n < 0 && n > size * size -1) {
		cout << "[���� ���� ���� �Է��ϼ̽��ϴ�]" << endl;
		return;
	}

	for (int col = 0; col < size; col++) {
		// ����
		for (int row = 0; row < size; row++) {
			// ����
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
/// ���� ä��� �Լ�
/// </summary>
/// <param name="arr">ä�� ������ �� �迭</param>
void Bingo::FillBingo(int arr[])
{
	//if (sizeof(*arr) / sizeof(int) != size * size) {
	//	// ���� �������� ũ��� �迭�� ũ�Ⱑ �ٸ��ٸ� (�������� �� ä�� �� ���ٸ�)
	//	exit;
	//}
	for (int col = 0; col < size; col++) {
		// ����
		for (int row = 0; row < size; row++) {
			// ����
			bingoArr[col][row] = arr[col * size + row];
		}
	}
	
}

/// <summary>
/// �ڵ����� ���� ä��� �Լ�
/// </summary>
void Bingo::FillBingo()
{
	int* arr = new int[size * size];			// size * size ũ���� �迭�� ����
	
	for (int i = 0; i < size * size; i++) {
		arr[i] = i;								// �迭 0���� size * size -1 ��ŭ ä��
	}

	shuffle(arr);			// �迭 ����

	for (int col = 0; col < size; col++) {
		// ����
		for (int row = 0; row < size; row++) {
			// ����
			bingoArr[col][row] = arr[col * size + row];		// ���� �迭�� �־���
		}
	}
}


/// <summary>
/// �Ű������� ���� ���ڸ� ������ ã�� ���ڰ� ������ -1�� �ٲٴ� �Լ�
/// </summary>
/// <param name="num">ã�� ����</param>
/// <returns>ã�� ���ڰ� ������ true ������ false</returns>
bool Bingo::SelectNum(int num)
{
	for (int col = 0; col < size; col++) {
		// ����
		for (int row = 0; row < size; row++) {
			// ����
			if (bingoArr[col][row] == num) {
				bingoArr[col][row] = -1;
				return true;
			}
		}
	}
	return false;
}

/// <summary>
/// ������ ������ ���� �Լ�
/// </summary>
/// <returns>������ ����</returns>
int Bingo::CountBingo()
{
	int bingoCount = 0;

	bool isBingo = true;

	// ���� ���� �˻�
	for (int col = 0; col < size; col++) {
		// ����
		isBingo = true;
		for (int row = 0; row < size; row++) {
			// ����
			if (bingoArr[col][row] != -1) {
				isBingo = false;
				break;
			}
		}
		if (isBingo) {
			bingoCount++;
		}
	}

	// ���� ���� �˻�
	for (int row = 0; row < size; row++) {
		// ����
		bool isBingo = true;
		for (int col = 0; col < size; col++) {
			// ����
			if (bingoArr[col][row] != -1) {
				isBingo = false;
				break;
			}
		}
		if (isBingo) {
			bingoCount++;
		}
	}

	// �»�� -> ���ϴ� �밢�� �˻�
	isBingo = true;
	for (int i = 0; i < size; i++) {
		// ����
		if (bingoArr[i][i] != -1) {
			isBingo = false;
			break;
		}
	}
	if (isBingo) {
		bingoCount++;
	}

	// ���� -> ���ϴ� �밢�� �˻�
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

	//cout << "���� ���� : " << bingoCount << endl;

	this->bingoCount = bingoCount;

	return bingoCount;
}

/// <summary>
/// ���� ����ϴ� �Լ�
/// </summary>
void Bingo::PrintBingo()
{
	for (int col = 0; col < size; col++) {
		// ����
		for (int row = 0; row < size; row++) {
			// ����
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
