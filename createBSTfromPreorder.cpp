// Program to construct BST from given preorder traversal

/*
Algorithm

1. Create an empty stack.

2. Make the first value as root. Push it to the stack.

3. Keep on popping while the stack is not empty and the next value is greater than stack’s top value. Make this value as the right child of the last popped node. Push the new node to the stack.

4. If the next value is less than the stack’s top value, make this value as the left child of the stack’s top node. Push the new node to the stack.

5. Repeat steps 2 and 3 until there are items remaining in pre[].

*/

#include <iostream>
#include <cstdlib>
using namespace std;

// binary tree node has data, pointer to left child and a pointer to right child
typedef struct Node{
	int data;
	struct Node *left, *right;
}Node;

// stack has array of nodes, capacity, and top
typedef struct Stack{
	int top;
	int capacity;
	Node** array;
}stack;

Node *newNode(int data){
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

Stack *createStack(int capacity){
	Stack *stack = new Stack;
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (Node **)malloc(sizeof(stack)*stack->capacity);
	return stack; 
}

int isFull(Stack *stack){
	return stack->top == stack->capacity-1;
}

int isEmpty(Stack *stack){
	return stack->top == -1;
}

void push(Stack *stack, Node *item){
	if(isFull(stack))
		return;
	stack->array[++stack->top] = item;
}

Node *pop(Stack *stack){
	if(isEmpty(stack))
		return NULL;
	return stack->array[stack->top--];
}

Node *peek(Stack *stack){
	return stack->array[stack->top];
}

Node *constructTree(int pre[], int size){
	Stack *stack = createStack(size);
	Node *root = newNode(pre[0]);
	push(stack, root);
	int i;
	Node *temp;

	for(i=1; i<size; i++){
		temp = NULL;
	// keep popping while next value is greater than stack' top value
		while(!isEmpty(stack) && pre[i] > peek(stack)->data)
			temp = pop(stack);

		if(temp != NULL){
			temp->right = newNode(pre[i]);
			push(stack, temp->right);
		}

		else{
			peek(stack)->left = newNode(pre[i]);
			push(stack, peek(stack)->left);
		}
	}
return root;
}

void printInorder(Node *node){
	if(node == NULL)
		return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    Node *root = constructTree(pre, size);
 
    cout<<"Inorder traversal of the constructed tree: \n";
    printInorder(root);
 
    return 0;
}

