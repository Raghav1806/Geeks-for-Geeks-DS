// You need to find the inorder successor and predecessor of a given key. In case the given key is not found in BST, then return the two values within which this key will lie.

#include <iostream>
using namespace std;

struct Node{
	int key;
	struct Node *left;
	struct Node *right;
};

// this function finds predecessor and successor of key in BST
void findPreSuc(struct Node *root, struct Node *&pre, struct Node *&suc, int key){
	if(root == NULL)
		return;

	// If key is present at root
	if(root->key == key){
		// maximum value in left subtree is predecessor
		if(root->left != NULL){
			struct Node *temp = root->left;
			while(temp->right)
				temp = temp->right;
				
			pre = temp;
		}	
		// minimum value in right subtree is successor
		if(root->right != NULL){
			struct Node *temp = root->right;
			while(temp->left)
				temp = temp->left;
			suc = temp;
		}
	return;
	}
	// If key is smaller than root's key, go to left subtree
	if(root->key > key){
		suc = root;
		findPreSuc(root->left, pre, suc, key);
	}
	else{	// go to right subtree
		pre = root;
		findPreSuc(root->right, pre, suc, key);
	}
}

struct Node *newNode(int x){
	struct Node *newptr = new Node;
	newptr->key = x;
	newptr->left = NULL;
	newptr->right = NULL;
return newptr;
}

struct Node *insert(struct Node *root, int key){
	if(root == NULL)
		return newNode(key);
	if(key < root->key)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}

int main(){
	int key = 65;
	struct Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
    	insert(root, 70);
    	insert(root, 60);
    	insert(root, 80);

	struct Node *pre = NULL;
	struct Node *suc = NULL;

	findPreSuc(root, pre, suc, key);
    	if (pre != NULL)
      		cout << "Predecessor is " << pre->key << endl;
    	else
      		cout << "No Predecessor";
 
    	if (suc != NULL)
      		cout << "Successor is " << suc->key;
    	else
     	 	cout << "No Successor";
 
return 0;
}
