// program to delete a node from AVL tree

#include <iostream>
#include <cstdlib>
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

// function to right rotate subtree rooted with y
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

// function to left rotate subtree rooted with x
struct Node *leftRotate(struct Node *x){
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// perform a rotation
	y->left = x;
	x->right = T2;

	// update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// return new root
	return y;
}

// return balance factor of Node N
int getBalance(struct Node *N){
	if(N == NULL)
		return 0;
	else
		return height(N->left) - height(N->right);
}

struct Node *insert(struct Node *node, int key){
	// perform normal BST insertion
	if(node == NULL)
		return newNode(key);

	if(key < node->key)
		node->left = insert(node->left, key);
	else if(key > node->key)
		node->right = insert(node->right, key);
	// equal keys are not allowed
	else
		return node;

	// update height of this ancestor node
	node->height = 1 + max(height(node->left), height(node->right));

	// get balanced factor of this ancestor node to check whether this node became unbalanced
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

	// return the unchanged node pointer
	return node;
}

// function to find minimum key
struct Node *minValueNode(struct Node *root){
	struct Node *current = root;
	
	// loop down to leftmost leaf
	while(current->left != NULL)
		current = current->left;
return current; 
}

// recursive function to delete a node with given key from subtree with given root. It returns root of modified subtree
struct Node *deleteNode(struct Node *root, int key){
	// perform standard BST delete
	if(root == NULL)
		return root;

	// if the key to be deleted is smaller than the root's key, then it lies in left subtree
	if(key < root->key)
		root->left = deleteNode(root->left, key);

	// if the key to be deleted is greater than the root's key, then it lies in right subtree
	else if(key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then this is the node to be deleted
	else{
		// node with only one child or no child
		if((root->left == NULL) || (root->right == NULL)){
			struct Node *temp = root->left ? root->left : root->right;

			// no child case
			if(temp == NULL){
				temp = root;
				root = NULL;
			}
			else	// one child case
			*root = *temp;	// copy the contents of non empty child
			free(temp);
		}
		else{
			// node with two children: get the inorder successor (smallest in right subtree)
			struct Node *temp = minValueNode(root->right);

			// copy the inorder successor's data 
			root->key = temp->key;

			// delete the inorder successor
			root->right = deleteNode(root->right, temp->key);
		}
	}

	// if the tree had only one node then return
	if(root == NULL)
		return root;

	// update height of current node
	root->height = 1 + max(height(root->left), height(root->right));

	// get the balance factor of this node
	int balance = getBalance(root);

	// if the node becomes unbalanced, then there are 4 cases

	// left left case
	if(balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// left right case
	if(balance > 1 && getBalance(root->left) < 0){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// right right case
	if(balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// right left case
	if(balance < -1 && getBalance(root->right) > 0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

return root;
}

void preOrder(struct Node *root){
	if(root != NULL){
		cout<<root->key;
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main(){
  
	struct Node *root = NULL;
 
    	root = insert(root, 9);
    	root = insert(root, 5);
    	root = insert(root, 10);
    	root = insert(root, 0);
    	root = insert(root, 6);
    	root = insert(root, 11);
    	root = insert(root, -1);
    	root = insert(root, 1);
    	root = insert(root, 2);
 
    /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */
 
    	cout<<"Preorder traversal of the constructed AVL tree i\n";
    	preOrder(root);
 	root = deleteNode(root, 10);
 
    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */
 
    	cout<<"\nPreorder traversal after deletion of 10 \n";
    	preOrder(root);
 
return 0;
}
