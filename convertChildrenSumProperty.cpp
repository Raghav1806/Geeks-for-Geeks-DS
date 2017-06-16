// Given an arbitrary binary tree, convert it to a binary tree that holds Children Sum Property. You can only increment data values in any node (You cannot change structure of tree and cannot decrement value of any node). 

/*
Algorithm:
Traverse given tree in post order to convert it, i.e., first change left and right children to hold the children sum property then change the parent node.

Let difference between node’s data and children sum be diff.

     diff = node’s children sum - node’s data  

If diff is 0 then nothing needs to be done.

If diff > 0 (node’s data is smaller than node’s children sum) increment the node’s data by diff.

If diff < 0 (node’s data is greater than the node's children sum) then increment one child’s data. We can choose to increment either left or right child if they both are not NULL. Let us always first increment the left child. Incrementing a child changes the subtree’s children sum property so we need to change left subtree also. So we recursively increment the left child. If left child is empty then we recursively call increment() for right child. Let us run the algorithm for the given example. First convert the left subtree (increment 7 to 8). 
*/

#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *newNode(int x){
	struct Node *newptr = new Node;
	newptr->data = x;
	newptr->left = NULL;
	newptr->right = NULL;
	return newptr;
}

// function used to increment sub tree by diff
void increment(struct Node *root, int diff){
	// if left child is not NULL then increment it
	if(root->left != NULL){
		root->left->data = root->left->data + diff;
	// recursively call to fix the descendants of node->left
		increment(root->left, diff);	
	}	
	else if(root->right != NULL){
		root->right->data = root->right->data + diff;
		increment(root->right, diff);
	}
}

void printInorder(struct Node *root){
	if(root == NULL)
		return;

	printInorder(root->left);

	cout<<root->data<<" ";

	printInorder(root->right);
}

void convertTree(struct Node *root){
int leftData = 0;
int rightData = 0;
int diff;

	if(root == NULL || (root->left == NULL && root->right == NULL))
		return;
	else{
		convertTree(root->left);
		convertTree(root->right);

		if(root->left != NULL)
			leftData = root->left->data;

		if(root->right != NULL)
			rightData = root->right->data;

		diff = leftData + rightData - root->data;

		if(diff > 0)
			root->data = root->data + diff;
		if(diff < 0)
			increment(root, -diff);
	}
}

int main()
{
  struct Node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);
 
  cout<<"Inorder Traversal before conversion ";
  printInorder(root);
  cout<<"\n";
 
  convertTree(root);
 
  cout<<"Inorder Traversal after conversion ";
  printInorder(root);
  cout<<"\n";
  return 0;
}


