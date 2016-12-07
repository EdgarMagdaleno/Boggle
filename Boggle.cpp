#include "Boggle.h"

#define alphabetSize 26

char board[4][4];

Boggle::Boggle() {
	board = {'\0'};
}

void Boggle::setBoard(char _board[4][4]) {
	board = _board;
}

char *solution() {
	char *words[200] = {nullptr};

	
}

~Boggle::Boggle() {

}