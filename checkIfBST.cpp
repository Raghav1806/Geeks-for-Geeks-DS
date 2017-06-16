// Program to check if given tree is a BST or not.

#include <iostream>
#define MAX 1000
using namespace std;

int A[MAX];
int index = 0;

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

void printInorder(struct Node *root){
	if(root == NULL)
		return;
	printInorder(root->left);
	cout<<root->data<<" ";
	A[index] = root->data;
	index++;
	printInorder(root->right);
}

struct Node *insertBST(struct Node *root, int x){
	if(root == NULL)
		return newNode(x);
	else{
		if(root->data > x)
			root->left = insertBST(root->left, x);
		else
			root->right = insertBST(root->right, x);
	}
return root;
}

int main(){
	struct Node *root = NULL;
	root = insertBST(root, 10);
	insertBST(root, 20);
	insertBST(root, -9);
	insertBST(root, 100);
	int i, check;
	check = 1;
	printInorder(root);
	for(i=0; i<index-1; i++){
		if(A[i] > A[i+1]){
			check = 0;
			break;
		}
	}
if(check)
	cout<<"BST!\n";
else
	cout<<"Not BST!\n";
return 0;
}
