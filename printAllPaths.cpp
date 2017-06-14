// Print all root to leaf paths of a binary tree

/*
Algorithm:
initialize: pathlen = 0, path[1000] 
// 1000 is some max limit for paths, it can change

// printPathsRecur traverses nodes of tree in preorder
printPathsRecur(tree, path[], pathlen)
   1) If node is not NULL then 
         a) push data to path array: 
                path[pathlen] = node->data.
         b) increment pathlen 
                pathlen++
   2) If node is a leaf node then print the path array.
   3) Else
        a) Call printPathsRecur for left subtree
                 printPathsRecur(node->left, path, pathLen)
        b) Call printPathsRecur for right subtree.
                printPathsRecur(node->right, path, pathLen)
*/

#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

void printArray(int A[], int len){
int i;
	for(i=0; i<len; i++)
		cout<<A[i];
	cout<<"\n";
}

void printPathsRecur(struct Node *root, int path[], int pathLen){
	if(root == NULL)
		return;
	path[pathLen] = root->data;
	pathLen++;

	// if it's a leaf, print the path that led there
	if(root->left == NULL && root->right == NULL){
		printArray(path, pathLen);
	}
	else{
	// try both subtrees
		printPathsRecur(root->left, path, pathLen);
		printPathsRecur(root->right, path, pathLen);
	}
}

void printPaths(struct Node *root){ 
	int path[1000];
	printPathsRecur(root, path, 0);
}

struct Node *newNode(int x){
	struct Node *newptr = new Node;
	newptr->data = x;
	newptr->left = NULL;
	newptr->right = NULL;
	return newptr;
}

int main(){
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printPaths(root);
return 0;
}
