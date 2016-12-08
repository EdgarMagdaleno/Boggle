#include <iostream>
#include <cstring>
#include <ctime>
#include "Boggle.h"

Boggle::Boggle() {
	readDictionary();
	createTrie();
}

void Boggle::newGame() {
	createBoard();
	solve();
}

void errorLog(std::string message, int exitCode) {
	std::cout << "ERROR: " << message << std::endl;
	exit(exitCode); 
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

char *Boggle::insertWord(char word[], Trie *root){
	Trie *current = root;

	// Iterate through all the letter in the word.
	for(int i = 0; word[i]; i++) {

		// Transform character to index in the alphabet.
		int letter = word[i] - 'a';

		if(current->children[letter] == nullptr) {
			current->children[letter] = new Trie();
		}

		current = current->children[letter];
	}

	// Set this Trie as the end of a word.
	current->word = word;
	return current->word;
}

void Boggle::createTrie() {
	std::cout << "Creating trie... ";
	dictionary = new Trie();

	char *word = strtok(dictionaryBuffer, "\n\t");
	int wordLength;

	// Read until we reach the end of the file.
	while(word != nullptr) {
		// We do not care about words smaller than 3 characters.
		if(strlen(word) > 2) insertWord(word, dictionary);

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

char *Boggle::searchWord(char word[], Trie *root) {
	Trie *current = root;

	for(int i = 0; word[i]; i++) {
		int letter = word[i] - 'a';
		if(current->children[letter] != nullptr) {
			current = current->children[letter];
		} else {
			return nullptr;
		}
	}

	return current->word;
}

// Will build a trie with all the words on the board.
void Boggle::depthFirstSearch(bool visited[4][4], int i, int j, char word[], int last, int &index) {

	// Set the current cell as visited.
	visited[i][j] = true;

	// Last character in the array is set to the current character in the board.
	word[last] = board[i][j];

	// Check if the current word is in the dictionary.
	char *isWord = searchWord(word, dictionary);
	if(isWord != nullptr) {
		// If the word has not already been found, add it to the trie.
		searchWord(word, solution);
		if(!searchWord(word, solution)) {
			insertWord(word, solution);

			// Add the word to the list of solutions, increment the current index by 1.
			words[index] = isWord;
			index++;
			words[index] = lineFeed;
			index++;
		}
	}

	// Search on the neighbors.
	for (int x = i - 1; x <= i + 1 && x < 4; x++) {
		for (int y = j - 1; y <= j + 1 && y < 4; y++) {
			if (x >= 0 && y >= 0 && !visited[x][y]) {

				// Indicate the last element in the word is the next one to the current.
				depthFirstSearch(visited, x, y, word, last + 1, index);
			}
		}
	}
 
	// Mark the last character as null terminated.
	word[last] = '\0';
	visited[i][j] = false;
}

void Boggle::solve() {
	solution = new Trie();

	// Set all characters on the board as not visited.
	bool visited[4][4] = {{false}};

	// Buffer used to search the current word in the dictionary.
	char currentWord[16];

	// Index used to keep track of the last place in the list.
	int index = 0;

	// Apply Depth-First Search to every character on the board.
	for(int x = 0; x < 4; x++) {
		for(int y = 0; y < 4; y++) {
			depthFirstSearch(visited, x, y, currentWord, 0, index);
		}
	}
}

// Prints a matrix, used for debugging purposes.
void print(char board[4][4]) {
	for(int x = 0; x < 4; x++) {
		for(int y = 0; y < 4; y++) {
			std::cout << board[x][y] << " ";
		}

		std::cout << std::endl;
	}
}