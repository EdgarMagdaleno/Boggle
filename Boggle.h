#define alphabetSize 26

#include "Trie.h"

class Boggle {
	public:
		Boggle();
		~Boggle();
		void newGame();
		char board[4][4];
		char *words[200] = {nullptr};

	private:
		char lineFeed = '\n';
		char *dictionaryBuffer = nullptr;
		Trie *dictionary = nullptr;
		Trie *solution = nullptr;
		void createBoard();
		void readDictionary();
		void createTrie();
		void solve();
		void depthFirstSearch(bool visited[4][4], int i, int j, char *word, int last, int &index);
};