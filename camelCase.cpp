/*
Algorithm:
The idea is to insert all dictionary keys into the Trie one by one. Here key refers to only Uppercase characters in original word in CamelCase notation. If we encounter the key for the first time, we need to mark the last node as leaf node and insert the complete word for that key into the vector associated with the leaf node. If we encounter a key that is already in the trie, we update the vector associated with the leaf node with current word. After all dictionary words are processed, we search for the pattern in the trie and print all words that matches the pattern.
*/

// program to print all words in the CamelCase dictionary that matches with a given pattern

#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

// Alphabet size (# of upper-case characters)
#define ALPHABET_SIZE 26

// a trie node
struct TrieNode{
	TrieNode *children[ALPHABET_SIZE];

	// isLeaf is true if the node represents end of a word
	bool isLeaf;

	// vector to store list of complete words in leaf node
	list<string> word;
};

// returns a new Trie node (initialized to NULLs)
TrieNode *getNewTrieNode(){
	struct TrieNode *pNode = new TrieNode;
	if(pNode){
		pNode->isLeaf = false;
		for(int i = 0; i < ALPHABET_SIZE; i++)
			pNode->children[i] = NULL;
	}
	return pNode;
}

// function to insert word into the trie
void insert(struct TrieNode *root, string word){
	int index;
	struct TrieNode *pCrawl = root;

	for(int level = 0; level < word.length(); level++){
		// consider only uppercase characters
		if(islower(word[level]))
			continue;

		// get current character position
		index = int(word[level]) - 'A';
		if(!pCrawl->children[index])
			pCrawl->children[index] = getNewTrieNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isLeaf = true;

	// push word into vector associated with leaf node
	(pCrawl->word).push_back(word);
}

// function to print all children of trie node root
void printAllWords(struct TrieNode *root){
	// if current node is leaf
	if(root->isLeaf){
		for(string str : root->word)
			cout<<str<<"\n";
	}

	// recurse for all children of root node
	for(int i = 0; i < ALPHABET_SIZE; i++){
		struct TrieNode *child = root->children[i];
		if(child)
			printAllWords(child);
	}
}

// search for pattern in Trie and print all words matching that pattern
bool search(struct TrieNode *root, string pattern){
	int index;
	struct TrieNode *pCrawl = root;

	for(int level = 0; level < pattern.length(); level++){
		index = int(pattern[level]) - 'A';
		// invalid pattern
		if(!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	// print all words matching that pattern
	printAllWords(pCrawl);

return true;
}

// main function to print all words in the CamelCase dictionary that matches with a given pattern
void findAllWords(vector<string> dict, string pattern){
	// construct trie root node
	struct TrieNode *root = getNewTrieNode();

	// construct trie from given dict
	for(string word : dict)
		insert(root, word);

	// search for pattern in trie
	if(!search(root, pattern))
		cout<<"No match found\n";
}

int main(){

    	// dictionary of words where each word follows
    	// CamelCase notation
    	vector<string> dict = {
        	"Hi", "Hello", "HelloWorld", "HiTech", "HiGeek",
       	 	"HiTechWorld", "HiTechCity", "HiTechLab"
    	};
 
    	// pattern consisting of uppercase characters only
    	string pattern = "HT";
 
    	findAllWords(dict, pattern);

return 0;
}
