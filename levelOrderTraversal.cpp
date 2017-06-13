/*
Algorithm:

printLevelorder(tree)
1) Create an empty queue q
2) temp_node = root
3) Loop while temp_node is not NULL
    a) print temp_node->data.
    b) Enqueue temp_node’s children (first left then right children) to q
    c) Dequeue a node from q and assign it’s value to temp_node
*/

#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

void printLevelOrder(Node *root){
	if(root == NULL)
		return;

	// Create an empty queue for level order traversal
	queue <Node*> q;

	q.push(root);

	while(q.empty() == false){
		// print front of queue and remove it from queue
		Node *node = q.front();
		cout<<node->data<<" ";
		q.pop();

		// enqueue left child
		if(node->left != NULL)
			q.push(node->left);

		// enqueue right child
		if(node->right != NULL)
			q.push(node->right);
	}
}

struct Node *newNode(int x){
	struct Node *temp = new Node;
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int main(){
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout<<"Level order traversal of binary tree is: ";
	printLevelOrder(root);
	cout<<"\n";
return 0;
}
