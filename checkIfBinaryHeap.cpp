// Program to check if a binary tree is Max-Heap
/*
Binary tree need to fulfill following two conditions for being a heap –

(1) It should be a complete tree (i.e. all levels except last should be full).
(2) Every node’s value should be greater than or equal to its child node (considering max-heap).

Algorithm:

(1) Every Node can have 2 children, 0 child (last level nodes) or 1 child (there can be at most one such node).
(2) If Node has No child then it’s a leaf node and return true (Base case)
(3) If Node has one child (it must be left child because it is a complete tree) then we need to compare this node with its single child only.
(4) If Node has both child then check heap property at Node and recur for both subtrees.
*/

#include <iostream>
using namespace std;

struct Node{
	int key;
	struct Node *left;
	struct Node *right;
};

struct Node *newNode(int k){
	struct Node *newNode = new Node;
	newNode->key = k;
	newNode->left = NULL;
	newNode->right = NULL;
return newNode;
}

// this function counts the number of nodes in binary tree
int countNodes(struct Node *root){
	if(root == NULL)
		return 0;
	return(1 + countNodes(root->left) + countNodes(root->right));
}

// program to check if the binary tree is complete or not
bool isComplete(struct Node *root, int index, int numberNodes){
	// an empty tree is complete
	if(root == NULL)
		return true;

	// if index assigned to current node is more than number of nodes in tree, then tree is not complete
	if(index >= numberNodes)
		return false;

	// recur for left and right subtrees
	return (isComplete(root->left, 2*index + 1, numberNodes) && isComplete(root->right, 2*index + 2, numberNodes));
}

// this function checks the heap property in tree
bool isHeap(struct Node *root){
	// single node satisfies property
	if(root->left == NULL && root->right == NULL)
		return true;

	// node will be in second last level
	if(root->right == NULL){
		// check heap property at node
		// no recursive call, because no need to check last level
		return (root->key >= root->left->key);
	}
	else{
		// check heap property at node and recursively check heap property at left and right subtree
		if(root->key >= root->left->key && root->key >= root->right->key)
			return ((isHeap(root->left)) && (isHeap(root->right)));
		else
			return false;
	}
}

// function to check binary tree is a heap or not
bool checkIfHeap(struct Node *root){
	int nodeCount = countNodes(root);
	int index = 0;

	if(isComplete(root, index, nodeCount) && isHeap(root))
		return true;
return false;
}

int main(){
	struct Node* root = NULL;
    	root = newNode(10);
    	root->left = newNode(9);
    	root->right = newNode(8);
    	root->left->left = newNode(7);
    	root->left->right = newNode(6);
    	root->right->left = newNode(5);
    	root->right->right = newNode(4);
    	root->left->left->left = newNode(3);
    	root->left->left->right = newNode(2);
    	root->left->right->left = newNode(1);
 
    if (isHeap(root))
        cout<<"Given binary tree is a Heap\n";
    else
        cout<<"Given binary tree is not a Heap\n";

return 0;
}
