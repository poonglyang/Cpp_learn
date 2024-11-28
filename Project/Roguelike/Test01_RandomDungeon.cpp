#include <iostream>
#include "PDGA.h"

using namespace std;

int main() {
	PDGA map = PDGA(1, 10, 10, 30, 30);
	map.PrintDungeon();
}