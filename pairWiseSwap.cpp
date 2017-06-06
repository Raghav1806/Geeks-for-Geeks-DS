// Given a singly linked list, write a function to swap elements pairwise.

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *next;
}*head,*end,*newptr,*np;

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
	if(head == NULL && end == NULL)
		head = end = np;
	else{
		end->next = np;
		end = np;
	}
}

void pairwiseSwap(struct Node **head){
	if(*head == NULL || (*head)->next == NULL)
		return;
struct Node *prev = *head;
struct Node *curr = (*head)->next;

*head = curr;
	while(1){
		struct Node *next = curr->next;
		curr->next = prev;

		if(next == NULL || next->next == NULL){
			prev->next = next;
			break;
		}

		prev->next = next->next;

		prev = next;
		curr = prev->next;
	}
}

int main(){
head = end = NULL;
int num,x;
cout<<"Enter number of elements to be inserted in linked list\n";
cin>>num;
cout<<"Enter the elements of linked list\n";
	while(num--){
		cin>>x;
		insertEnd(x);
	}
cout<<"The inserted linked list is\n";
display(head);
pairwiseSwap(&head);
cout<<"The modified linked list is\n";
display(head);
return 0;
}
