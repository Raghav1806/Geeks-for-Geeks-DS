// given a set of strings, find the longest common prefix

/*
Algorithm:

(1) Insert all the words one by one in the trie. After inserting we perform a walk on the trie.
(2) In this walk, go deeper until we find a node having more than 1 children(branching occurs) or 0 children (one of the string gets exhausted).

This is because the characters (nodes in trie) which are present in the longest common prefix must be the single child of its parent, i.e- there should not be a branching in any of these nodes.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

// alphabet size (# of symbols)
#define ALPHABET_SIZE 26

// converts key current characters into index, use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode{
	struct TrieNode *children[ALPHABET_SIZE];

	// isLeaf is true if the node represents end of a word
	bool isLeaf;
};

// returns new trie node (initialized to NULLs)
struct TrieNode *getNode(){
	struct TrieNode *pNode = new TrieNode;
	if(pNode){
		int i;
		pNode->isLeaf = false;

		for(i = 0; i < ALPHABET_SIZE; i++)
			pNode->children[i] = NULL;
	}
return pNode;
}

// if not present, insert key into trie
// if key is prefix of trie node, just mark leaf node
void insert(struct TrieNode *root, string key){
	int length = key.length();
	int index;

	struct TrieNode *pCrawl = root;

	for(int level = 0; level < length; level++){
		index = CHAR_TO_INDEX(key[level]);
		if(!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isLeaf = true;
}

// counts and returns the number of children of the current node
int countChildren(struct TrieNode *node, int *index){
	int count = 0;
	for(int i = 0; i < ALPHABET_SIZE; i++){
		if(node->children[i] != NULL){
			count++;
			*index = i;
		}
	}
	return count;
}

// perform a walk on the trie and return the longest common prefix string
string walkTrie(struct TrieNode *root){
	struct TrieNode *pCrawl = root;
	int index;
	string prefix;

	while(countChildren(pCrawl, &index) == 1 && pCrawl->isLeaf == false){
		pCrawl = pCrawl->children[index];
		prefix.push_back('a' + index);
	}

	return prefix;
}

// function to construct trie
void constructTrie(string arr[], int n, struct TrieNode *root){
	for(int i = 0; i < n; i++)
		insert(root, arr[i]);
	return;
}

// a function that returns the longest common prefix from the array of strings
string commonPrefix(string arr[], int n){
	struct TrieNode *root = getNode();
	constructTrie(arr, n, root);

	// perform a walk on the trie
	return walkTrie(root);
}

int main(){

    	string arr[] = {"geeksforgeeks", "geeks",
                    	"geek", "geezer"};
    	int n = sizeof (arr) / sizeof (arr[0]);
 
    	string ans = commonPrefix(arr, n);
 
    	if (ans.length())
        	cout << "The longest common prefix is "<<ans<<"\n";
    	else
        	cout << "There is no common prefix";
    return 0;
}

