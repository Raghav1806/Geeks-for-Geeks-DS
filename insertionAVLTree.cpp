// program to insert a node in AVL tree

#include <iostream>
using namespace std;

struct Node{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};

int max(int a, int b){
	if(a > b)
		return a;
	else
		return b;
}

int height(struct Node *N){
	if(N == NULL)
		return 0;
	else
		return N->height;
}

struct Node *newNode(int key){
	struct Node *newptr = new Node;
	newptr->key = key;
	newptr->left = NULL;
	newptr->right = NULL;
	newptr->height = 1;

return newptr;
}

// A function to right rotate subtree rooted with y
struct Node *rightRotate(struct Node *y){
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// perform rotation
	x->right = y;
	y->left = T2;

	// update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// return new root
	return x;
}

// a function to left rotate subtree rooted with x
struct Node *leftRotate(struct Node *x){
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// perform rotation
	y->left = x;
	x->right = T2;

	// update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// return new root
	return y;
}

// get balance factor of node N
int getBalance(struct Node *N){
	if(N == NULL)
		return 0;

	else
		return height(N->left) - height(N->right);
}

// recursive function to insert key in subtree rooted with node and returns new root of subtree
struct Node *insert(struct Node *node, int key){

	// perform normal BST insertion
	if(node == NULL)
		return newNode(key);

	if(key < node->key)
		node->left = insert(node->left, key);
	else if(key > node->key)
		node->right = insert(node->right, key);
	else
		// equal keys are not allowed in BST
		return node;

	// update height of this ancestor node
	node->height = 1 + max(height(node->left), height(node->right));

	// get the balance factor of this ancestor node to check whether this node became unbalanced
	int balance = getBalance(node);

	// if this node becomes unbalanced, then there are 4 cases

	// left left case
	if(balance > 1 && key < node->left->key)
		return rightRotate(node);

	// right right case
	if(balance < -1 && key > node->right->key)
		return leftRotate(node);

	// left right case
	if(balance > 1 && key > node->left->key){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// right left case
	if(balance < -1 && key < node->right->key){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;
}

void preOrder(struct Node *root){
	if(root != NULL){
		cout<<root->key<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main(){
  	
	struct Node *root = NULL;
 
  	root = insert(root, 10);
  	root = insert(root, 20);
  	root = insert(root, 30);
  	root = insert(root, 40);
  	root = insert(root, 50);
  	root = insert(root, 25);
 
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  	cout<<"Preorder traversal of the constructed AVL tree is \n";
  	preOrder(root);
 
return 0;
}

