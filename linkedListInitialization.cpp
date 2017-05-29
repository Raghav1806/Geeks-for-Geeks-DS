// Program to initialize a linked list by adding elements at start

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *next;
}*newptr,*head,*temp,*np;

struct Node *createNewNode(int x){
newptr = new Node;
newptr->data = x;
newptr->next = NULL;
return newptr;
}

void display(struct Node *head){
temp = head;
	while(temp->next != NULL){
		temp = temp->next;
		cout<<temp->data<<"->";
	}
cout<<"\n";
}

void insertNode(int x){
np = createNewNode(x);
	if(head == NULL)
		head = np;
	else{
		temp = head;
		head = np;
		np->next = temp;
	}
}

int main(){
head = NULL;
insertNode(1);
insertNode(2);
insertNode(3);
insertNode(4);
insertNode(5);
display(head);
return 0;
}
