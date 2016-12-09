#include <iostream>
#include <cstring>
#include <ctime>
#include "Boggle.h"

void errorLog(std::string message, int exitCode) {
	std::cout << "ERROR: " << message << std::endl;
	exit(exitCode); 
}

Boggle::Boggle() {
	readDictionary();
	createTrie();
}

void Boggle::newGame() {
	createBoard();
	solve();
}

void Boggle::createBoard() {
	// Time seed.
	std::srand(std::time(0));

	// Fill the board with random characters.
	for(int x = 0; x < 4; x++) {
		for(int y = 0; y < 4; y++) {
			board[x][y] = 'a' + std::rand() % 26;
		}
	}
}

void Boggle::createTrie() {
	std::cout << "Creating trie... ";
	dictionary = new Trie();

	char *word = strtok(dictionaryBuffer, "\n\t");

	// Read until we reach the end of the file.
	while(word != nullptr) {
		dictionary->add(word);

		// Source is only specified at the start, otherwise, it will loop.
		word = strtok(nullptr, "\n\t");
	}

	std::cout << "Done.\n";
}

void Boggle::readDictionary() {
	std::cout << "Reading dictionary... ";

	// Open file.
	FILE *file = fopen("dictionary.txt", "r");
	if(file == nullptr) errorLog("Could not open dictionary.", 0);

	// Get the fileSize.
	fseek(file, 0, SEEK_END);
	long fileSize = ftell(file);
	rewind(file);

	// Put the file into memory.
	dictionaryBuffer = (char *) malloc(sizeof(char) *fileSize);
	if(dictionaryBuffer == nullptr) errorLog("Memory allocation failed.", 1);

	// Check for differences between file size and buffer size.
	if(fileSize != fread(dictionaryBuffer, 1, fileSize, file)) errorLog("Dictionary size and buffer size differ.", 2);

	// Close the file as we do not need it anymore.
	fclose(file);
	std::cout << "Done.\n";
}

// Will build a trie with all the words on the board.
void Boggle::depthFirstSearch(bool visited[4][4], int i, int j, char *currentWord, int currentWordIndex, int &solutionIndex) {

	// Set the current cell as visited.
	visited[i][j] = true;

	// Last character in the array is set to the current character in the board.
	currentWord[currentWordIndex] = board[i][j];

	// Check if the current word is in the dictionary.
	char *isWord = dictionary->contains(currentWord);

	// If the word has not already been found, add it to the trie.
	if(isWord && !solution->contains(currentWord)) {
		solution->add(currentWord);

		words[solutionIndex] = isWord;
		solutionIndex++;

		words[solutionIndex] = &lineFeed;
		solutionIndex++;
	}

	// Search on the neighbors.
	for (int x = i - 1; x <= i + 1 && x < 4; x++) {
		for (int y = j - 1; y <= j + 1 && y < 4; y++) {
			if (x >= 0 && y >= 0 && !visited[x][y]) {
				depthFirstSearch(visited, x, y, currentWord, currentWordIndex + 1, solutionIndex);
			}
		}
	}
 
	// Mark the last character as null terminated.
	currentWord[currentWordIndex] = '\0';
	visited[i][j] = false;
}

void Boggle::solve() {
	solution = new Trie();

	// Set all characters on the board as not visited.
	bool visited[4][4] = {{false}};

	// Buffer used to search the current word in the dictionary.
	char currentWord[16];

	// Index used to keep track of the last place in the solution list.
	int solutionIndex = 0;

	// Apply Depth-First Search to every character on the board.
	for(int x = 0; x < 4; x++) {
		for(int y = 0; y < 4; y++) {
			depthFirstSearch(visited, x, y, currentWord, 0, solutionIndex);
		}
	}
}