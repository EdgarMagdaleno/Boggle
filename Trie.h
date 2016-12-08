class Trie {
	public:
		Trie *children[26];
		char *word;

		Trie() {
			for(int i = 0; i < 26; i++) {
				children[i] = nullptr;
			}

			word = nullptr;
		}
};