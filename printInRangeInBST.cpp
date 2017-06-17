// Program to print numbers in given range in BST
#include <iostream>
using namespace std;
int a, b;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

void inorder(struct Node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	if(a <= root->data && root->data <= b)
		cout<<root->data<<" ";
	inorder(root->right);
}

struct Node *newNode(int x){
	struct Node *newptr = new Node;
	newptr->data = x;
	newptr->left = NULL;
	newptr->right = NULL;
return newptr;
}

struct Node *insertNode(struct Node *root, int x){
	if(root == NULL)
		return newNode(x);
	else{
		if(x < root->data)
			root->left = insertNode(root->left, x);
		else
			root->right = insertNode(root->right, x);
	}
return root;
}

int main(){
	struct Node *root = NULL;
	int num, num1, num2, size;
	cout<<"Enter the size of BST\n";
	cin>>size;
	cout<<"Enter the elements of BST\n";
	while(size--){
		cin>>num;
		root = insertNode(root, num);
	}
	cout<<"Enter the range of numbers\n";
	cin>>a>>b;
	cout<<"The inorder traversal of BST of numbers in required range is\n";
	inorder(root);
return 0;
}
