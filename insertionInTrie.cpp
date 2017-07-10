#include <iostream>
#include <cstring>
using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// converts key current character into index 
// use only 'a' through 'z' in lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode{
	struct TrieNode *children[ALPHABET_SIZE];

	// isLeaf is true if the node represents end of a word
	bool isLeaf;
};

// returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void){
	struct TrieNode *pNode = NULL;
	pNode = new TrieNode;

	if(pNode){
		int i;
		pNode->isLeaf = false;
		for(i=0; i<ALPHABET_SIZE; i++)
			pNode->children[i] = NULL;
	}
return pNode;
}

// if not present, insert key into trie
// if key is prefix of trie node, just mark leaf node
void insert(struct TrieNode *root, const char *key){
	int level;
	int length = strlen(key);
	int index;

	struct TrieNode *pCrawl = root;
	for(level = 0; level < length; level++){
		index = CHAR_TO_INDEX(key[level]);
		if(!pCrawl->children[index])
			pCrawl->children[index] = getNode();
		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isLeaf = true;
}

// returns true if key is present in trie, else false
bool search(struct TrieNode *root, const char *key){
	int level;
	int length = strlen(key);
	int index;
	struct TrieNode *pCrawl = root;

	for(level = 0; level < length; level++){
		index = CHAR_TO_INDEX(key[level]);

		if(!pCrawl->children[index])
			return false;
		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->isLeaf);
} 

int main(){

    	// Input keys (use only 'a' through 'z' and lower case)
    	char keys[][8] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their"};
 
    	char output[][32] = {"Not present in trie", "Present in trie"};
 
 
    	struct TrieNode *root = getNode();
 
    	// Construct trie
    	int i;
    	for (i = 0; i < ARRAY_SIZE(keys); i++)
        	insert(root, keys[i]);
 
    	// Search for different keys
    	cout<<"the "<<output[search(root, "the")];
    	cout<<"\n these "<<output[search(root, "these")];
    	cout<<"\n their"<<output[search(root, "their")];
    	cout<<"\n thaw"<<output[search(root, "thaw")];
 
return 0;
}
