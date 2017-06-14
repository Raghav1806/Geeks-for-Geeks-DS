// Convert a binary tree into mirror tree

/* 
Algorithm:
(1)  Call Mirror for left-subtree    i.e., Mirror(left-subtree)
(2)  Call Mirror for right-subtree  i.e., Mirror(right-subtree)
(3)  Swap left and right subtrees.
          temp = left-subtree
          left-subtree = right-subtree
          right-subtree = temp
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

void mirror(struct Node *root){
	if(root == NULL)
		return;
	else{
		struct Node *temp;
		mirror(root->left);
		mirror(root->right);

		// swap the pointers in this node
		temp = root->left;
		temp = root->right;
		root->right = temp;
	}
}

void inOrder(struct Node *root){
	if(root == NULL)
		return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

int main(){
	struct Node *root = newNode(1);
	root->left = newNode(2);
  	root->right = newNode(3);
  	root->left->left = newNode(4);
 	root->left->right = newNode(5);

cout<<"Inorder traversal of constructed tree is: ";
	inOrder(root);
	cout<<"\n";

	mirror(root);

	cout<<"Inorder traversal of mirror tree is: ";
	inOrder(root);
	cout<<"\n"; 
return 0;
}
