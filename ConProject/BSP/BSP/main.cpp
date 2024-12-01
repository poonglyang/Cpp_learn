#include <iostream>
#include "Game.h"
int main() {
	srand(time(0));
	Game g = Game(5);
	g.GameStart();
}