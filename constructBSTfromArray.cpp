// Program to construct balanced BST from array

#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

void display(struct Node *root){
	if(root == NULL)
		return;
	display(root->left);
	cout<<root->data<<" ";
	display(root->right);
}

struct Node *newNode(int x){
	struct Node *newptr = new Node;
	newptr->data = x;
	newptr->left = NULL;
	newptr->right = NULL;
return newptr;
}

struct Node *inorder(struct Node *root, int x){
	struct Node *newptr = newNode(x);
	if(root == NULL)
		return newptr;
	if(x > root->data)
		root->right = inorder(root->right, x);
	else
		root->left = inorder(root->left, x);
return root;
}

struct Node *sortedArraytoBST(int A[], int start, int end){
	if(start > end)
		return NULL;
	int mid = (start+end)/2;
	struct Node *root = newNode(A[mid]);
	root->left = sortedArraytoBST(A, start, mid-1);
	root->right = sortedArraytoBST(A, mid+1, end);

return root;
}

int main(){
	struct Node *root = NULL;
	int size, i;
	cout<<"Enter the number of elements in array\n";
	cin>>size;
	int A[size];
	cout<<"Enter the elements\n";
	
	for(i=0; i<size; i++)
		cin>>A[i];

	sort(A, A+size);

	root = sortedArraytoBST(A, 0, size-1);

	cout<<"The inorder traversal of balanced BST is\n";
	display(root);
	
return 0;
}
