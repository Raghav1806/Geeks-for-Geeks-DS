// Doubly linked list initialization

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *prev;
struct Node *next;
};

// Insert a new node at the front of linked list
void push(struct Node **head, int x){
	struct Node *newptr = new Node;
	newptr->data = x;
	newptr->next = *head;
	newptr->prev = NULL;

	if(*head != NULL)
		(*head)->prev = newptr;

	*head = newptr;
}

// insert new node after given prev node
void insertAfter(struct Node *prevNode, int x){
	if(prevNode == NULL){
		cout<<"Given previous node cannot be NULL\n";
		return;
	}

	struct Node *newNode = new Node;
	newNode->data = x;
	newNode->next = prevNode->next;
	prevNode->next = newNode;
	newNode->prev = prevNode;

	if(newNode->next != NULL)
		newNode->next->prev = newNode;
}

// Given reference to the head of a DLL and an int, append new node at the end
void append(struct Node **head, int x){
	struct Node *newNode = new Node;
	struct Node *last = *head;

	newNode->data = x;
	newNode->next = NULL;
	
	if(*head == NULL){
		newNode->prev = NULL;
		*head = newNode;
		return;
	}
	
	while(last->next != NULL)
		last = last->next;

	last->next = newNode;
	newNode->prev = last;

	return;
}

void printList(struct Node *head){
	struct Node *last;
	cout<<"\nTraversal in forward direction\n";
	while(head != NULL){
		cout<<head->data<<"<->";
		last = head;
		head = head->next;
	}
	cout<<"\nTraversal in reverse direction\n";
	while(last != NULL){
		cout<<last->data<<"<->";
		last = last->prev;
	}
cout<<"\n";
}

int main(){
struct Node *head = NULL;
append(&head, 6);
push(&head, 7);
push(&head, 1);
append(&head, 4);
insertAfter(head->next, 8);
cout<<"Created DLL is";
printList(head);
return 0;
}
