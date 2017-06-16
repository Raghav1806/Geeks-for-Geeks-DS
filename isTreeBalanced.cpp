// Program to check if a tree is height balanced or not
#include <iostream>
using namespace std;

struct Node{
int data;
struct Node *left;
struct Node *right;
};

bool isBalanced(struct Node *root, int *height){
	int lh = 0;	// height of left sub tree
	int rh = 0;	// height of right sub tree

	int l, r;
	l = r = 0;	// l, r will be true if left and right subtrees are balanced respectively

	if(root == NULL){
		*height = 0;
		return true;
	}

	l = isBalanced(root->left, &lh);
	r = isBalanced(root->right, &rh);

	*height = (lh > rh ? lh:rh) + 1;

	// if differences b/w heights of left and right subtrees is ore than 2 then this node is not balanced
	if((lh-rh >= 2) || (rh-lh >= 2))
		return 0;

	else
		return l&&r;
}

struct Node *newNode(int x){
	struct Node *newptr = new Node;
	newptr->data = x;
	newptr->left = NULL;
	newptr->right = NULL;
return newptr;
}

int main()
{
  int height = 0;
    
  /* Constructed binary tree is
             1
           /   \
         2      3
       /  \    /
     4     5  6
    /
   7
  */   
  struct Node *root = newNode(1);  
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->left->left->left = newNode(7);
 
  if(isBalanced(root, &height))
  	cout<<"Tree is balanced\n";
  else
    	cout<<"Tree is not balanced\n";   

  return 0;
}


