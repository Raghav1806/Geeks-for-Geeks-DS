// Postorder traversal of tree is used because, before deleting the parent node we should delete children nodes first.

#include <iostream>
#include <cstdlib>
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

void _deleteTree(struct Node *root){
	if(root == NULL)
		return;
	// first delete both subtrees
	_deleteTree(root->left);
	_deleteTree(root->right);

	// then delete the node
	cout<<"Deleting node: "<<root->data<<"\n";
	free(root);
}

// Delete a tree and sets the root as NULL
void deleteTree(struct Node **root){
	_deleteTree(*root);
	*root = NULL;
}

int main(){
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	deleteTree(&root);
	cout<<"Tree deleted\n";

return 0;
}
