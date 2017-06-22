// program to print vertical order of a given binary tree

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node{
	int key;
	struct Node *left;
	struct Node *right;
};

struct Node *newNode(int x){
	struct Node *newptr = new Node;
	newptr->key = x;
	newptr->left = NULL;
	newptr->right = NULL;
return newptr;
}

// utility function to store vertical order in map 'm'
// hd (initialized 0) is horizontal distance of current node from root
void getVerticalOrder(struct Node *root, int hd, map<int, vector<int> > &m){
	if(root == NULL)
		return;

	// store current node in map 'm'
	m[hd].push_back(root->key);

	// store nodes in left subtree
	getVerticalOrder(root->left, hd-1, m);

	// store nodes in right subtree
	getVerticalOrder(root->right, hd+1, m);
}

void printVerticalOrder(struct Node *root){
	map< int, vector<int> > m;
	int hd = 0;
	int i;
	getVerticalOrder(root, hd, m);

	// traverse the map and print nodes at every hd
	map< int, vector<int> > :: iterator it;
	for(it = m.begin(); it != m.end(); it++){
		for(i = 0; i < it->second.size(); i++)
			cout<<it->second[i]<<" ";
	cout<<"\n";
	}
}

int main(){
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
    	root->left->left = newNode(4);
    	root->left->right = newNode(5);
    	root->right->left = newNode(6);
    	root->right->right = newNode(7);
    	root->right->left->right = newNode(8);
    	root->right->right->right = newNode(9);
    	cout << "Vertical order traversal is \n";
    	printVerticalOrder(root);
return 0;
}
