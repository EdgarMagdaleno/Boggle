#define alphabetSize 26

class Trie {
	public:
		Trie();
		Trie *children[alphabetSize];
		char *word;
		void add(char *word);
		char *contains(char *word);
};