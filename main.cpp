#include <iostream>
#include "Boggle.h"

int main() {
	Boggle *boggle = new Boggle();

	boggle->newGame();

	for(int x = 0; x < 4; x++) {
		for(int y = 0; y < 4; y++) {
			std::cout << boggle->board[x][y] << " ";
		}

		std::cout << std::endl;
	}

	for(int i = 0; boggle->words[i]; i++) {
		std::cout << boggle->words[i];
	}
}