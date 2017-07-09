#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

enum Color {RED, BLACK};

struct Node{
	int data;
	bool color;
	struct Node *left;
	struct Node *right;
	struct Node *parent;

	// constructor
	Node(int data){
		this->data = data;
		left = right = parent = NULL;
	}
};

// class to represent Red-Black Tree
class RBTree{
	private:
		struct Node *root;
	protected:
		void rotateLeft(struct Node *&, struct Node *&);
		void rotateRight(struct Node *&, struct Node *&);
		void fixViolation(struct Node *&, struct Node *&);
	public:
		// constructor
		RBTree(){
			root = NULL;
		}
		void insert(const int &n);
		void inorder();
		void levelOrder();
};

// a recursive function to do inorder traversal
void inorderHelper(struct Node *root){
	if(root == NULL)
		return;

	inorderHelper(root->left);
	cout<<root->data<<" ";
	inorderHelper(root->right);
}

// a utility function to insert a new node with given key in BST
struct Node *BSTInsert(struct Node *root, struct Node *pt){
	// if tree is empty, return new node
	if(root == NULL)
		return pt;

	// otherwise, recur down the tree
	if(pt->data < root->data){
		root->left = BSTInsert(root->left, pt);
		root->left->parent = root;
	}
	else if(pt->data > root->data){
		root->right = BSTInsert(root->right, pt);
		root->right->parent = root;
	}

	// return the unchanged node pointer
	return root;
}

// utility function to do level order traversal
void levelOrderHelper(struct Node *root){
	if(root == NULL)
		return;

	std::queue<Node *> q;
	q.push(root);

	while(!q.empty()){
		struct Node *temp = q.front();
		cout<<temp->data<<" ";
		q.pop();

		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);
	}	
}

void RBTree::rotateLeft(struct Node *&root, struct Node *&pt){
	
	struct Node *ptRight = pt->right;
	pt->right = ptRight->left;

	if(pt->right != NULL)
		pt->right->parent = pt;

	ptRight->parent = pt->parent;
	
	if(pt->parent == NULL)
		root = ptRight;

	else if(pt == pt->parent->left)
		pt->parent->left = ptRight;
	else
		pt->parent->right = ptRight;

	ptRight->left = pt;
	pt->parent = ptRight;
}

void RBTree::rotateRight(struct Node *&root, struct Node *&pt){

	struct Node *ptLeft = pt->left;
	pt->left = ptLeft->right;

	if(pt->left != NULL)
		pt->left->parent = pt;

	ptLeft->parent = pt->parent;

	if(pt->parent == NULL)
		root = ptLeft;

	else if(pt == pt->parent->left)
		pt->parent->left = ptLeft;
	else
		pt->parent->right = ptLeft;

	ptLeft->right = pt;
	pt->parent = ptLeft;	 
}

// this function fixes violations caused by BST insertion
void RBTree::fixViolation(struct Node *&root, struct Node *&pt){
	
	struct Node *parentPt = NULL;
	struct Node *grandParentPt = NULL;

	while((pt != root) && (pt->color == RED) && (pt->parent->color) == RED){
		parentPt = pt->parent;
		grandParentPt = pt->parent->parent;

		// case: A
		// Parent of pt is left child of grand parent of pt
		if(parentPt == grandParentPt->left){
			struct Node *unclePt = grandParentPt->right;
			// case: 1
			// the uncle of pt is also red, only recoloring is required
			if(unclePt != NULL && unclePt->color == RED){
				grandParentPt->color = RED;
				parentPt->color = BLACK;
				unclePt->color = BLACK;
				pt = grandParentPt;
			}

			else{
				// case: 2
				// pt is right child of its parent, right rotation required
				if(pt == parentPt->right){
					rotateLeft(root, parentPt);
					pt = parentPt;
					parentPt = pt->parent;
				}

				// case: 3
				// pt is left child of its parent, right rotation is required
				rotateRight(root, grandParentPt);
				swap(parentPt->color, grandParentPt->color);
				pt = parentPt;
			}
		}

		// case: B
		// Parent of pt is right child of grand parent of pt
		else{
			struct Node *unclePt = grandParentPt->left;

			// case: 1
			// the uncle of pt is also red, only recoloring required
			if((unclePt != NULL) && (unclePt->color == RED)){
				grandParentPt->color = RED;
				parentPt->color = BLACK;
				unclePt->color = BLACK;
				pt = grandParentPt;
			}
			else{
				// case: 2
				// pt is left child of its parent, right rotation required
				if(pt == parentPt->left){
					rotateRight(root, parentPt);
					pt = parentPt;
					parentPt = pt->parent;
				}

				// case: 3
				// pt is right child of its parent, left rotation required
				rotateLeft(root, grandParentPt);
				swap(parentPt->color, grandParentPt->color);
				pt = parentPt;
			}
		}
	}
	
	root->color = BLACK;
}

// function to insert a new node with given data
void RBTree::insert(const int &data){
	struct Node *pt = new Node(data);
	
	// do a normal BST insert
	root = BSTInsert(root, pt);

	// fix Red Black tree violations
	fixViolation(root, pt);
}

// function to do inorder and level order traversals
void RBTree::inorder(){
	inorderHelper(root);
}

void RBTree::levelOrder(){
	levelOrderHelper(root);
}

int main(){

    	RBTree tree;
 
    	tree.insert(7);
    	tree.insert(6);
    	tree.insert(5);
    	tree.insert(4);
    	tree.insert(3);
    	tree.insert(2);
    	tree.insert(1);
 
    	cout << "Inoder Traversal of Created Tree\n";
    	tree.inorder();
 
    	cout << "\n\nLevel Order Traversal of Created Tree\n";
    	tree.levelOrder();

return 0;
}
