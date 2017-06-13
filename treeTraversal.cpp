// Tree traversals: Inorder, Preorder and Postorder

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

// Bottom-up postorder traversal
void printPostOrder(struct Node *root){
	if(root == NULL)
		return;
	// recur on left subtree
	printPostOrder(root->left);

	// recur on right subtree
	printPostOrder(root->right);

	// now deal with the root
	cout<<root->data<<" ";
}

// Printing nodes inorder
void printInOrder(struct Node* root){
	if(root == NULL)
		return;
	// recur on left child
	printInOrder(root->left);

	// now deal with the root
	cout<<root->data<<" ";

	// recur on right child
	printInOrder(root->right);
}

// Printing nodes in preorder
void printPreOrder(struct Node *root){
	if(root == NULL)
		return;
	// Print data of node
	cout<<root->data<<" ";
	
	// recur on left subtree
	printPreOrder(root->left);

	// recur on right subtree
	printPreOrder(root->right);
}

int main(){
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout<<"Pre Order traversal:\n";
	printPreOrder(root);

	cout<<"\nIn Order traversal:\n";
	printInOrder(root);
	
	cout<<"\nPost Order traversal:\n";
	printPostOrder(root);
return 0;
}
