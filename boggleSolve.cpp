#include <iostream>
#include <cstring>
#include <stack>
#include <ctime>

#define alphabetSize 26

struct Trie {
	Trie *children[alphabetSize];
	char *word;

	Trie() {
		for(int i = 0; i < alphabetSize; i++) {
			children[i] = nullptr;
		}

		word = nullptr;
	}
};

struct Node {
	char *character;
	Node *next;

	Node() : next(nullptr), character(nullptr) {};
	Node(char *newCharacter) : next(nullptr), character(newCharacter) {};
};

struct Stack {
	Node *top;

	char *pop() {
		char *topElement = top->character;
		top = top->next;
		return top->character;
	}

	void push(char *newCharacter) {
		Node *current = top;

		while(current != nullptr) {
			current = current->next;
		}

		current = new Node(newCharacter);
	}
};

void errorLog(std::string message, int exitCode) {
	std::cout << "ERROR: " << message << std::endl;
	exit(exitCode); 
}

void createBoard(char board[4][4]) {
	// Time seed.
	std::srand(std::time(0));

	// Fill the board with random characters.
	for(int x = 0; x < 4; x++) {
		for(int y = 0; y < 4; y++) {
			board[x][y] = 'a' + std::rand() % 26;
		}
	}
}

char *insertWord(char word[], Trie *root){
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

Trie *createTrie(char *dictionary) {
	std::cout << "Creating trie... ";

	Trie *root = new Trie();
	char *word = strtok(dictionary, "\n\t");
	int wordLength;

	// Read until we reach the end of the file.
	while(word != nullptr) {
		// We do not care about words smaller than 3 characters.
		if(strlen(word) > 2) insertWord(word, root);

		// Source is only specified at the start, otherwise, it will loop.
		word = strtok(nullptr, "\n\t");
	}

	std::cout << "Done.\n";
	return root;
}

char *readDictionary() {
	std::cout << "Reading dictionary... ";

	// Open file.
	FILE *file = fopen("dictionary.txt", "r");
	if(file == nullptr) errorLog("Could not open dictionary.", 0);

	// Get the fileSize.
	fseek(file, 0, SEEK_END);
	long fileSize = ftell(file);
	rewind(file);

	// Put the file into memory.
	char *buffer = (char *) malloc(sizeof(char) *fileSize);
	if(buffer == nullptr) errorLog("Memory allocation failed.", 1);

	// Check for differences between file size and buffer size.
	if(fileSize != fread(buffer, 1, fileSize, file)) errorLog("Dictionary size and buffer size differ.", 2);

	// Close the file as we do not need it anymore.
	fclose(file);

	std::cout << "Done.\n";
	return buffer;
}

char *searchWord(char word[], Trie *root) {
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

// Will build a trie with all the words in the board.
void depthFirstSearch(char board[4][4], bool visited[4][4], int i, int j, char word[], int last, Trie *dictionary, Trie *solution, char *found[200], int &index) {

	// Set the current cell as visited.
	visited[i][j] = true;

	// Last character in the array is set to the current character in the board.
	word[last] = board[i][j];

	// Check if the current word is in the dictionary.
	char *isWord = searchWord(word, dictionary);
	if(isWord) {

		// If the word has not already been found, add it to the trie.
		if(!searchWord(word, solution)) {
			insertWord(word, solution);

			// Add the word to the list of solutions, increment the current index by 1.
			found[index] = isWord;
			index++;
		}
	}

	// Search on the neighbors.
	for (int x = i - 1; x <= i + 1 && x < 4; x++) {
		for (int y = j - 1; y <= j + 1 && y < 4; y++) {
			if (x >= 0 && y >= 0 && !visited[x][y]) {

				// Indicate the last element in the word is the next one to the current.
				depthFirstSearch(board, visited, x, y, word, last + 1, dictionary, solution, found, index);
			}
		}
	}
 
	// Mark the last character as null terminated.
	word[last] = '\0';
	visited[i][j] = false;
}

void solve(char board[4][4], Trie *dictionary, char *found[200]) {
	Trie *solution = new Trie();

	// Set all characters on the board as not visited.
	bool visited[4][4] = {{false}};

	// Buffer used to search the current word in the dictionary.
	char currentWord[16];

	// Index used to keep track of the last place in the list.
	int index = 0;

	// Apply Depth-First Search to every character on the board.
	for(int x = 0; x < 4; x++) {
		for(int y = 0; y < 4; y++) {
			depthFirstSearch(board, visited, x, y, currentWord, 0, dictionary, solution, found, index);
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

int main() {
	// Save time of start up.
	clock_t t = clock();

	// Create a new board
	char board[4][4];
	createBoard(board);

	// Debugging.
	print(board);

	// Put the dictionary into memory.
	char *dictionaryBuffer = readDictionary();

	// Create the trie with the dictionary in memory.
	Trie *dictionary = createTrie(dictionaryBuffer);

	// Create a list of pointer which will adress the words in the board.
	char *words[200] = {nullptr};

	// Fill the list.
	solve(board, dictionary, words);

	// Print the list.
	for(int i = 0; words[i]; i++) {
		std::cout << words[i] << std::endl;
	}

	// Calculate and print runtime.
	t = clock() - t;
	std::cout << "\nRuntime: " << ((float) t) / CLOCKS_PER_SEC << " seconds.";
	return 0;
}