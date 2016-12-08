#include "Trie.h"

class Boggle {
	public:
		Boggle();
		~Boggle();
		void newGame();
		char board[4][4];
		char *words[200] = {nullptr};

	private:
		char *dictionaryBuffer = nullptr;
		Trie *dictionary = nullptr;
		Trie *solution = nullptr;
		char *searchWord(char word[], Trie *root);
		char *lineFeed = "\n";
		void createBoard();
		void readDictionary();
		void createTrie();
		void solve();
		char *insertWord(char word[], Trie *root);
		void depthFirstSearch(bool visited[4][4], int i, int j, char word[], int last, int &index);
};