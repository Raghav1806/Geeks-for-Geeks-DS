// Program to add elements at the end of linked list

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *next;
}*newptr,*head,*temp,*end,*np;

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
}

void insert(int x){
np = createNewNode(x);
	if(head == NULL){
		head = np;
		end = np;
	}		
	else{
		end->next = np;
		end = np;
	}
}

int main(){
head = end = NULL;
insert(1);
insert(2);
insert(3);
insert(4);
insert(5);
display(head);
return 0;
}
