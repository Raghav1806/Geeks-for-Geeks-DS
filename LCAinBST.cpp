// Program to find lowest common ancestor of given two nodes in a BST
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

void inorder(struct Node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

struct Node *insertNode(struct Node *root, int x){
	struct Node *temp = newNode(x);
	if(root == NULL)
		root = temp;
	else{
		if(x > root->data)
			root->right = insertNode(root->right, x);
		else
			root->left = insertNode(root->left, x);
	}
return root;
}

struct Node *findLCA(struct Node *root, int n1, int n2){
	if(root == NULL)
		return root;
	// if both n1 and n2 are smaller than root, then LCA lies in left subtree
	if(root->data > n1 && root->data > n2)
		findLCA(root->left, n1, n2);
	// if both n1 and n2 are greater than root, then LCA lies in right subtree
	if(root->data < n1 && root->data < n2)
		findLCA(root->right, n1, n2);

return root;
}

int main(){
	struct Node *root = NULL;
	int size, num, n1, n2;
	cout<<"Enter the size of BST ";
	cin>>size;
	cout<<"Enter the contents of BST\n";
	while(size--){
		cin>>num;
		root = insertNode(root, num);
	}
	cout<<"The inorder traversal of BST is\n";
	inorder(root);
	cout<<"\n";

	cout<<"Enter the two numbers whose LCA is to be searched ";
	cin>>n1>>n2;
	struct Node *t = findLCA(root, n1, n2);
	cout<<"LCA is "<<t->data<<"\n";

return 0;
}
