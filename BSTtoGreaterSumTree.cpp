// Given a BST, transform it into greater sum tree where each node contains sum of all nodes greater than that node.

/*

Algorithm:
By leveraging the fact that the tree is a BST, we can find an O(n) solution. The idea is to traverse BST in reverse inorder. Reverse inorder traversal of a BST gives us keys in decreasing order. Before visiting a node, we visit all greater nodes of that node. While traversing we keep track of sum of keys which is the sum of all the keys greater than the key of current node. 

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

// Recursive function to transform BST to sum tree
// This function traverses tree in reverse order so that we have visited all greater key nodes of the currently visited nodes.
void transformTreeUtil(struct Node *root, int *sum){
	if(root == NULL)		
		return;
	// recur for right subtree
	transformTreeUtil(root->right, sum);

	// update sum
	*sum = *sum + root->data;
	
	// store old sum in current node
	root->data = *sum - root->data;

	// recur for left subtree
	transformTreeUtil(root->left, sum);
}

void transformTree(struct Node *root){
	int sum = 0;
	transformTreeUtil(root, &sum);
}

void printInorder(struct Node *root){
	if(root == NULL)
		return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

int main()
{
    	struct Node *root = newNode(11);
    	root->left = newNode(2);
    	root->right = newNode(29);
    	root->left->left = newNode(1);
    	root->left->right = newNode(7);
    	root->right->left = newNode(15);
    	root->right->right = newNode(40);
    	root->right->right->left = newNode(35);
 
    	cout << "Inorder Traversal of given tree\n";
    	printInorder(root);
 
    	transformTree(root);
 
    	cout << "\n\nInorder Traversal of transformed tree\n";
    	printInorder(root);
 
    	return 0;
}

