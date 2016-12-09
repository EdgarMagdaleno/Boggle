class Trie {
	public:
		Trie *children[alphabetSize];
		char *word;

		Trie() {
			for(int i = 0; i < alphabetSize; i++) {
				children[i] = nullptr;
			}

			word = nullptr;
		}
};