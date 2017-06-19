// Given two Binary Search Trees, find common nodes in them. In other words, find intersection of two BSTs.
// Iterative inorder traversal [using 2 stacks] is implemented in this case

#include <iostream>
#include <stack>
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

// function to print comon elements in given 2 trees
void printCommon(struct Node *root1, struct Node *root2){
	stack<struct Node*> stack1, s1, s2;

	while(1){
		// push nodes of first tree in stack s1
		if(root1){
			s1.push(root1);
			root1 = root1->left;
		}

		// push the nodes of second tree in stack s2
		else if(root2){
			s2.push(root2);
			root2 = root2->left;
		}

		else if(!s1.empty() && !s2.empty()){
			root1 = s1.top();
			root2 = s2.top();

			if(root1->key == root2->key){
				cout<<root1->key<<" ";
				s1.pop();
				s2.pop();

				// move to inorder successor
				root1 = root1->right;
				root2 = root2->right;
			}

			else if(root1->key < root2->key){
				s1.pop();
				root1 = root1->right;
				root2 = NULL;
			}

			else if(root1->key > root2->key){
				s2.pop();
				root2 = root2->right;
				root1 = NULL;
			}
		}

	// both roots and both stacks are empty
	else
		break;
	}
}

void inorder(struct Node *root){
	if(root){
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}

struct Node *insert(struct Node *root, int key){
	if(root == NULL)
		return newNode(key);

	if(key < root->key)
		root->left = insert(root->left, key);
	else 
		root->right = insert(root->right, key);

// return the unchanged root pointer
return root;
}

int main(){
    
	// Create first tree as shown in example
    	Node *root1 = NULL;
    	root1 = insert(root1, 5);
    	root1 = insert(root1, 1);
    	root1 = insert(root1, 10);
    	root1 = insert(root1,  0);
    	root1 = insert(root1,  4);
    	root1 = insert(root1,  7);
    	root1 = insert(root1,  9);
 
    	// Create second tree as shown in example
    	Node *root2 = NULL;
    	root2 = insert(root2, 10);
    	root2 = insert(root2, 7);
    	root2 = insert(root2, 20);
    	root2 = insert(root2, 4);
    	root2 = insert(root2, 9);
 
    	cout << "Tree 1 : ";
    	inorder(root1);
    	cout << "\n";
 
    	cout << "Tree 2 : ";
    	inorder(root2);
 
    	cout << "\nCommon Nodes: ";
    	printCommon(root1, root2);
 
    	return 0;
}

