#pragma once
#include <iostream> 
using namespace std;
class Bingo
{
protected :
	int size;

	int bingoCount;

	int** bingoArr;

	void shuffle(int* arr);

public:
	Bingo(int size);

	virtual ~Bingo();

	int GetSize();

	int GetBingoCount();

	void FillBingo(int n);

	void FillBingo(int arr[]);

	void FillBingo();

	bool SelectNum(int num);

	int CountBingo();
	
	void PrintBingo();
};

