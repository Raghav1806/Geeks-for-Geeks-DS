// Program to find if there is a triplet in a balanced BST that adds to zero
// Expected time complexity is O(n^2) and only O(Logn) extra space can be used. 

/* Algorithm:

1) Convert given BST to Doubly Linked List (DLL)
2) Now iterate through every node of DLL and if the key of node is negative, then find a pair in DLL with sum equal to key of current 
node multiplied by -1.

*/

#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

// A function to convert given BST to DLL
void convertBSTtoDLL(struct Node *root, struct Node **head, struct Node **tail){
	if(root == NULL)
		return;
	// first convert left subtree
	if(root->left)
		convertBSTtoDLL(root->left, head, tail);

	root->left = *tail;

	if(*tail)
		(*tail)->right = root;
	else
		*head = root;

	*tail = root;

	if(root->right)
		convertBSTtoDLL(root->right, head, tail);
}

bool isPresentInDLL(struct Node *head, struct Node *tail, int sum){
	while(head != tail){
		int curr = head->data + tail->data;
		if(curr == sum)
			return true;
		else if(curr > sum)
			tail = tail->left;
		else
			head = head->right;
	}
return false;
}

bool isTripletPresent(struct Node *root){
	if(root == NULL)
		return false;
	// convert given BST to DLL
	struct Node *head = NULL;
	struct Node *tail = NULL;
	convertBSTtoDLL(root, &head, &tail);
	// iterate through every node and find if their is a pair equal to -1*head->key
	while((head->right != tail) && (head->data < 0)){
		if(isPresentInDLL(head->right, tail, -1*head->data))
		return true;
	else
		head = head->right;
	}
	return false;
}

struct Node *newNode(int x){
	struct Node *newptr = new Node();
	newptr->data = x;
	newptr->left = NULL;
	newptr->right = NULL;
return newptr;
}

void inorder(struct Node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

struct Node *insert(struct Node *root, int x){
	struct Node *newptr = newNode(x);
	if(root == NULL)
		return newptr;
	if(x <= root->data)
		root->left = insert(root->left, x);
	else
		root->right = insert(root->right, x);
return root;
}

int main(){
	struct Node *root = NULL;
	int size, num;
	cout<<"Enter the number of elements of BST ";
	cin>>size;
	cout<<"Enter the elements of BST\n";
	while(size--){
		cin>>num;
		root = insert(root, num);
	}
	cout<<"Inorder traversal of BST is\n";
	inorder(root);
	if(isTripletPresent(root))
		cout<<"Present";
	else
		cout<<"Not Present";
	cout<<"\n";
return 0;
}
