// Program to count number of nodes in a binary tree

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

int getLeafCount(struct Node *root){
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return 1;
	else
		return getLeafCount(root->left) + getLeafCount(root->right);
}

int main(){
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout<<"Leaf count = "<<getLeafCount(root)<<"\n";
return 0;
}
