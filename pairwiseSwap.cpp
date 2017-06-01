// Given a singly linked list, write a function to swap elements pairwise.

// Recursive Solution: If there are 2 or more than 2 nodes in Linked List then swap the first two nodes and recursively call for rest of the list.

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *next;
}*head,*np,*newptr,*end;

struct Node *createNewNode(int x){
newptr = new Node;
newptr->data = x;
newptr->next = NULL;
return newptr;
}

void display(struct Node *head){
	while(head != NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
cout<<"\n";
}

void insertEnd(int x){
np = createNewNode(x);
	if(head == NULL)
		head = end = np;
	else{
		end->next = np;
		end = np;
	}
}

void swap(int *a, int *b){
int temp;
temp = *a;
*a = *b;
*b = temp;
}

void pairwiseSwap(struct Node *head){
	if(head != NULL && head->next != NULL){
		swap(&head->data, &head->next->data);
		pairwiseSwap(head->next->next);
	}
}

int main(){
head = end = NULL;
insertEnd(1);
insertEnd(2);
insertEnd(3);
insertEnd(4);
insertEnd(5);
display(head);
pairwiseSwap(head);
display(head);
return 0;
}
