#include "Trie.h"
#include <iostream>

Trie::Trie() {
	for(int i = 0; i < alphabetSize; i++) {
		children[i] = nullptr;
	}

	word = nullptr;
}

void Trie::add(char *word) {
	Trie *current= this;

	// Iterate through all the letter in the word.
	for(int i = 0; word[i]; i++) {

		// Transform character to index in the alphabet.
		int letter = word[i] - 'a';

		// If letter is a Q, ignore the next letter as it is a U.
		if(letter == 16) i++;

		if(current->children[letter] == nullptr) {
			current->children[letter] = new Trie();
		}

		current = current->children[letter];
	}

	// Point word to dictionary buffer.
	current->word = word;
}

char *Trie::contains(char *word) {
	Trie *current = this;

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
