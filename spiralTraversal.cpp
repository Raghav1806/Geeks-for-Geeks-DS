// Level order traversal in spiral form [using 2 stacks]

#include <iostream>
#include <stack>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

void printSpiral(struct Node *root){
	if(root == NULL)
		return;

	stack<struct Node*> S1;	// to be printed from right to left
	stack<struct Node*> S2; // to be printed from left to right

	// push first level to first stack 
	S1.push(root);

	while(!S1.empty() || !S2.empty()){
		while(!S1.empty()){
			struct Node *temp = S1.top();
			S1.pop();
			cout<<temp->data<<" ";

			// right is pushed before left
			if(temp->right)
				S2.push(temp->right);
			if(temp->left)
				S2.push(temp->left);
		}
		while(!S2.empty()){
			struct Node *temp = S2.top();
			S2.pop();
			cout<<temp->data<<" ";

			// left is pushed before right
			if(temp->left)
				S1.push(temp->left);
			if(temp->right)
				S1.push(temp->right);
		}
	}
}

struct Node *newNode(int x){
	struct Node *newptr = new Node;
	newptr->data = x;
	newptr->left = NULL;
	newptr->right = NULL;
return newptr;
}

int main(){
	struct Node *root = newNode(1);
	root->right = newNode(3);
    	root->left->left  = newNode(7);
    	root->left->right = newNode(6);
    	root->right->left  = newNode(5);
    	root->right->right = newNode(4);
    
cout << "Spiral Order traversal of binary tree is \n";
printSpiral(root);
cout<<"\n";
return 0;
}


