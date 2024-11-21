#pragma once
#include "Bingo.h"

class AutoSelectBingo : public Bingo
{
public:
	AutoSelectBingo(int size);

	~AutoSelectBingo();

	int AutoSelect();
};

