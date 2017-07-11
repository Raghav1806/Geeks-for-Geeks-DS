// The task is to implement search query for the phone directory. The search query on a string ‘str’ displays all the contacts which prefix as ‘str’.

/* 
Examples:
Input : contacts [] = {“gforgeeks” , “geeksquiz” }
        Query String = “gekk”

Output : Suggestions based on "g" are 
         geeksquiz
         gforgeeks

         Suggestions based on "ge" are 
         geeksquiz

         No Results Found for "gek" 

         No Results Found for "gekk" 
*/

#include <iostream>
#include <map>
#include <cstring>
using namespace std;

struct TrieNode{
	// each trie node contains a map 'child' where each alphabet points to a trie node. We can also use a fixed size array of size 256
	map<char, TrieNode*> child;

	// isLast is true if the node represents end of a string
	bool isLast;

	// default constructor
	TrieNode(){
		// initialize all the trie nodes with NULL
		for(char i = 'a'; i <= 'z'; i++)
			child[i] = NULL;

		isLast = false;
	}
};

// making root NULL for ease so that it doesn't have to be passed to all functions
struct TrieNode *root = NULL;

// insert a contact into the trie
void insert(string s){
	int len = s.length();

	// 'itr' is used to iterate trie nodes
	struct TrieNode *itr = root;
	for(int i = 0; i < len; i++){
		// check if the s[i] is already present in trie
		TrieNode *nextNode = itr->child[s[i]];
		if(nextNode == NULL){
			// if not found then create a new trienode
			nextNode = new TrieNode();
		
			// insert into the map
			itr->child[s[i]] = nextNode;
		}

		// move the iterator ('itr'), to point to next trie node
		itr = nextNode;

		// if its the last character of the string 's' then mark 'isLast' as true
		if(i == len-1)
			itr->isLast = true;
	}
}

// this function displays all dictionary words going through current node. String 'prefix' represents string corresponding to the path from root to curNode
void displayContactsUtil(struct TrieNode *curNode, string prefix){
	// check if the string 'prefix' ends at this node, if yes, then display the string found so far
	if(curNode->isLast)
		cout<<prefix<<"\n";

	// find all the adjacent nodes to the current node and then display the string found so far
	for(char i = 'a'; i <= 'z'; i++){
		struct TrieNode *nextNode = curNode->child[i];
		if(nextNode != NULL)
			displayContactsUtil(nextNode, prefix+(char)i);
	}
}

// display suggestions after every character enter by the user for a given query string 'str'
void displayContacts(string str){
	TrieNode *prevNode = root;

	string prefix = "";
	int len = str.length();

	// display the contact list for string formed after entering every character
	int i;
	for(i = 0; i < len; i++){
		// 'prefix' stores the string formed so far
		prefix += (char)str[i];

		// get the last character entered
		char lastChar = prefix[i];

		// find the node corresponding to the last character of 'prefix' which is pointed by prevNode of the trie
		struct TrieNode *curNode = prevNode->child[lastChar];

		// if nothing is found, then break the loop as no more prefixes are going to be present
		if(curNode == NULL){
			cout<<"No results found for "<<prefix<<"\n";
			i++;
			break;	
		}

		// if present in trie then display all the contacts with given prefix
		cout<<"Suggestions based on "<<prefix<<" are\n";
		displayContactsUtil(curNode, prefix);
		
		// change prevnode for next prefix
		prevNode = curNode;
	}

	// once search fails for a prefix, we print  "Not results found" for all remaining characters of current query string "str"
	for(; i<len; i++){
		prefix += (char)str[i];
		cout<<"No results found for\n"<<prefix<<"\n";
	}
}

// insert all the contacts into the trie
void insertIntoTrie(string contacts[], int n){
	// initialize root node
	root = new TrieNode();

	// insert each contact into the trie
	for(int i = 0; i < n; i++)
		insert(contacts[i]);
}

int main(){

    	// Contact list of the User
    	string contacts[] = {"gforgeeks" , "geeksquiz"};
 
    	// Size of the Contact List
    	int n = sizeof(contacts)/sizeof(string);
 
    	// Insert all the Contacts into Trie
    	insertIntoTrie(contacts, n);
 
    	string query = "gekk";
 
    	// Note that the user will enter 'g' then 'e', so
    	// first display all the strings with prefix as 'g'
    	// and then all the strings with prefix as 'ge'
    	displayContacts(query);
 
return 0;
}
