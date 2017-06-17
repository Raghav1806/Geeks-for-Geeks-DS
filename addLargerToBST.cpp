// Given a Binary Search Tree (BST), modify it so that all greater values in the given BST are added to every node.

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

void displayInorder(struct Node *root){
	if(root == NULL)
		return;
	displayInorder(root->left);
	cout<<root->data<<" ";
	displayInorder(root->right);
}

struct Node *insertNode(struct Node *root, int x){
	struct Node *newptr = newNode(x);
	if(root == NULL)
		return newptr;
	if(x > root->data)
		root->right = insertNode(root->right, x);
	else
		root->left = insertNode(root->left, x);
return root;
}

void modifyBSTUtil(struct Node *root, int *sum){
	// Base case
	if(root == NULL)
		return;
	// Recur for right subtree
	modifyBSTUtil(root->right, sum);

	// Now *sum has sum of nodes in right subtree, add root->data to sum and update root->data
	*sum = *sum + root->data;
	root->data = *sum;

	// Recur for left subtree
	modifyBSTUtil(root->left, sum);
}

void modifyBST(struct Node *root){
	int sum = 0;
	modifyBSTUtil(root, &sum);
}

int main(){
	struct Node *root = NULL;
	int num, size;
	cout<<"Enter the number of elements in BST\n";
	cin>>size;
	cout<<"Enter the elements of BST\n";
	while(size--){
		cin>>num;
		root = insertNode(root, num);
	}
	cout<<"Inorder traversal of original BST is\n";
	displayInorder(root);

	modifyBST(root);

	cout<<"\nInorder traversal of modified BST is\n";
	displayInorder(root);
return 0;
}
