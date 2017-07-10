// Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another. 

/*
Example:
Input: arr[] = {"zebra", "dog", "duck", "dove"}
Output: dog, dov, du, z
Explanation: dog => dog
             dove = dov 
             duck = du
             z   => zebra 

Input: arr[] =  {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
Output: geeksf, geeksg, geeksq}
*/

/*
Algorithm:
1) Construct a Trie of all words. Also maintain frequency of every node (Here frequency is number of times node is visited during insertion). Time complexity of this step is O(N) where N is total number of characters in all words.

2) Now, for every word, we find the character nearest to the root with frequency as 1. The prefix of the word is path from root to this character. To do this, we can traverse Trie starting from root. For every node being traversed, we check its frequency. If frequency is one, we print all characters from root to this node and don’t traverse down this node. Time complexity if this step also is O(N) where N is total number of characters in all words. 
*/

// program to print all prefixes that uniquely represent words.

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAX 256

// maximum length of an input word
#define MAX_WORD_LEN 500

// Trie Node
struct trieNode{
	struct trieNode *child[MAX];
	int freq;	// to store frequency
};

// function to create a new trie node
struct trieNode *newTrieNode(){
	struct trieNode *newNode = new trieNode;
	newNode->freq = 1;
	for(int i = 0; i < MAX; i++)
		newNode->child[i] = NULL;
	return newNode;
}

// method to insert a new string into trie
void insert(struct trieNode *root, string str){
	// length of string
	int len = str.length();
	struct trieNode *pCrawl = root;

	// traversing over the length of given str
	for(int level = 0; level < len; level++){
		// get index of child node from current character in str	
		int index = str[level];

		// create a new child if not exist already
		if(!pCrawl -> child[index])
			pCrawl->child[index] = newTrieNode();
		else
			pCrawl->child[index]->freq++;

		// move to the child
		pCrawl = pCrawl->child[index];
	}
}

// this function prints unique prefix for every word stored in trie. 
// prefixes one by one are stored in prefix[]. 'ind' is current index of prefix[]
void findPrefixesUtil(struct trieNode *root, char prefix[], int ind){
	// corner case
	if(root == NULL)
		return;

	// base case
	if(root->freq == 1){
		prefix[ind] = '\0';
		cout<<prefix<<" ";
		return;
	}

	for(int i = 0; i < MAX; i++){
		if(root->child[i] != NULL){
			prefix[ind] = i;
			findPrefixesUtil(root->child[i], prefix, ind+1); 
		}
	}
}

// function to print all prefixes that uniquely represent all words in arr[0..n-1]
void findPrefixes(string arr[], int n){
	// construct a trie of all words
	struct trieNode *root = newTrieNode();
	root->freq = 0;
	for(int i = 0; i < n; i++)
		insert(root, arr[i]);

	// create an array to store all prefixes
	char prefix[MAX_WORD_LEN];
	
	// print all prefixes using trie traversal
	findPrefixesUtil(root, prefix, 0);
}

int main(){

    	string arr[] = {"zebra", "dog", "duck", "dove"};
    	int n = sizeof(arr)/sizeof(arr[0]);
    	findPrefixes(arr, n);

return 0;
}
