// Program to add an element to sorted linked list.

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *next;
}*newptr,*head,*end,*temp,*np;

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
	if(head == NULL){
		head = end = np;
	}
	else{
		end->next = np;
		end = np;
	}
}

void insert(struct Node **head, struct Node **end, int num){
np = createNewNode(num);
struct Node *curr;

	if(*head == NULL || (*head)->data >= num){
		np->next = *head;
		*head = np;
	}	
	else{
		curr = *head;
		while(curr->next != NULL && curr->next->data < num)
			curr = curr->next;
	}
np->next = curr->next;
curr->next = np;
}

int main(){
head = end = NULL;
int num;
insertEnd(1);
insertEnd(2);
insertEnd(4);
insertEnd(5);
insertEnd(6);
display(head);
cout<<"Enter the number to be inserted in linked list\n";
cin>>num;
insert(&head,&end,num);
cout<<"The updated linked list is:\n";
display(head);
return 0;
}
