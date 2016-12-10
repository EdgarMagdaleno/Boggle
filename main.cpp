#include <iostream>
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
	
	w.setLine("Boggle");
	w.show();

	return app.exec();
}
