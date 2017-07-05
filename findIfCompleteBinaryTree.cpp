// program to check whether a binary tree is a complete tree or not
/*
A complete binary tree is a binary tree whose all levels except the last level are completely filled and all the leaves in the last level are all to the left side.

Algorithm:

(1) Calculate the number of nodes (count) in the binary tree.
(2) Start recursion of the binary tree from the root node of the binary tree with index (i) being set as 0 and the number of nodes in the binary (count).
(3) If the current node under examination is NULL, then the tree is a complete binary tree. Return true.
(4) If index (i) of the current node is greater than or equal to the number of nodes in the binary tree (count) i.e. (i>= count), then the tree is not a complete binary. Return false.
(5) Recursively check the left and right sub-trees of the binary tree for same condition. For the left sub-tree use the index as (2*i + 1) while for the right sub-tree use the index as (2*i + 2).
*/

#include <iostream>
using namespace std;

struct Node{
	int key;
	struct Node *left;
	struct Node *right;
};

struct Node *newNode(int k){
	struct Node *newptr = new Node;
	newptr->key = k;
	newptr->left = NULL;
	newptr->right = NULL;
return newptr;
}

// this function counts the number of nodes in a binary tree
int countNodes(struct Node *root){
	if(root == NULL)
		return 0;

	return
		(1 + countNodes(root->left) + countNodes(root->right));
}

// this function checks if the binary tree is complete or not
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

int main(){
	struct Node *root = NULL;
	root = newNode(1);
	root->left = newNode(2);
    	root->right = newNode(3);
    	root->left->left = newNode(4);
    	root->left->right = newNode(5);
    	root->right->right = newNode(6);

	int nodeCount = countNodes(root);
	int index = 0;

	if(isComplete(root, index, nodeCount))
		cout<<"The binary tree is complete\n";
	else
		cout<<"The binary tree is not complete\n";
return 0;
}
