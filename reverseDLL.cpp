// Reversing a doubly linked list

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *prev;
struct Node *next;
};

void reverse(struct Node **head){
	struct Node *temp = NULL;
	struct Node *curr = *head;
// swap next and prev for all nodes of linked list
	while(curr != NULL){
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}
// before changing head, check for cases like empty list/list with 1 node
	if(temp != NULL)
		*head = temp->prev;
}

void push(struct Node **head, int x){
	struct Node *newNode = new Node;
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = *head;

	if(head != NULL)
		(*head)->prev = newNode;
	*head = newNode;
}

void printList(struct Node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
cout<<"\n";
}

int main(){
struct Node *head = NULL;
push(&head, 2);
push(&head, 4);
push(&head, 8);
push(&head, 10);
  
cout<<"Original DLL\n";
printList(head);

reverse(&head);
cout<<"Reversed DLL\n";
printList(head);  
return 0;
}
