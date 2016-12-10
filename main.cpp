#include <iostream>
#include "Boggle.h"
#include <QApplication>
#include "widget.h"

/*
	Boggle constructor loads the dictionary, creates a random board and solves it.
	Function newGame creates a random board and solves it.
	The solution is always stored at boggle->words.

	An example of how to print the board solution is shown below.
*/

int main(int argc, char *argv[]) {


	QApplication app(argc, argv);
	Widget w;
	
	Boggle *boggle = new Boggle();
	boggle->newGame();
	
	w.setLine("Boggle");
	w.show();

	return app.exec();
	

	/*for(int x = 0; x < 4; x++) {
		for(int y = 0; y < 4; y++) {
			std::cout << boggle->board[x][y] << " ";
		}

		std::cout << std::endl;
	}

	for(int i = 0; boggle->words[i]; i++) {
		std::cout << boggle->words[i];
    }*/
}
