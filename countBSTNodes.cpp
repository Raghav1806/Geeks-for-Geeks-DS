// Given a Binary Search Tree (BST) and a range, count number of nodes that lie in the given range.

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

void display(struct Node *root){
	if(root == NULL)
		return;
	display(root->left);
	cout<<root->data<<" ";
	display(root->right);
}

struct Node *insert(struct Node *root, int x){
	if(root == NULL)
		return newNode(x);
	if(root->data > x)
		root->left = insert(root->left, x);
	else
		root->right = insert(root->right, x);
return root;
}

// Returns count of nodes in BST in range [low, high]
int getCount(struct Node *root, int low, int high){
	if(root == NULL)
		return 0;
	if(root->data == high && root->data == low)
		return 1;

	// if current node is in range, then include it in count and recur for left and right children
	if(root->data <= high && root->data >= low)
		return 1 + getCount(root->left, low, high) + getCount(root->right, low, high);

	// If current node is smaller than low, then recur for right child
	else if(root->data < low)
		return getCount(root->right, low, high);
	else
		return getCount(root->left, low, high);
}

int main(){
	struct Node *root = NULL;
	int size, num, low, high;
	cout<<"Enter the number of elements of BST\n";
	cin>>size;
	cout<<"Enter the elements of BST\n";
	while(size--){
		cin>>num;
		root = insert(root, num);
	}

	cout<<"Inorder traversal is\n";
	display(root);

	cout<<"\nEnter the desired range limits\n";
	cin>>low>>high;

	cout<<"Count of nodes is "<<getCount(root, low, high)<<"\n";

return 0;
}
