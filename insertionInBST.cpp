#include <iostream>
using namespace std;

struct Node{
	int key;
	struct Node *left;
	struct Node *right;
};

struct Node *newNode(int x){
	struct Node *newptr = new Node;
	newptr->key = x;
	newptr->left = NULL;
	newptr->right = NULL;
return newptr;
}

// function for inorder traversal of BST
void inorder(struct Node *root){
	if(root != NULL){
		inorder(root->left);
		cout<<root->key<<"\n";
		inorder(root->right);
	}
}

// function for inserting a new node in BST
struct Node *insert(struct Node *root, int x){
	// If tree is empty, return a new node	
	if(root == NULL)
		return newNode(x);

	// otherwise, recur down the tree
	if(x <= root->key)
		root->left = insert(root->left, x);
	else if(x >= root->key)
		root->right = insert(root->right, x);
return root;
}

int main(){
	struct Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
inorder(root);
return 0;
}
