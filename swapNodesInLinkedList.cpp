// Given a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links.

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *next;
}*newptr,*head,*end,*np,*prevX,*currX,*prevY,*currY,*temp;

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

void swapNodes(struct Node *head,int x,int y){
	if(x == y)
		return;
prevX = NULL;
currX = head;
	while(currX != NULL && currX->data != x){
		prevX = currX;
		currX = currX->next;
	}
prevY = NULL;
currY = head;
	while(currY != NULL && currY->data != y){
		prevY = currY;
		currY = currY->next;
	}

	if(currX == NULL || currY == NULL)
		return;
	if(prevX != NULL)
		prevX->next = currY;
	else
		head = currY;
	if(prevY != NULL)
		prevY->next = currX;
	else
		head = currX;
temp = currY->next;
currY->next = currX->next;
currX->next = temp;
}

int main(){
int a,b;
head = end = NULL;

insertEnd(1);
insertEnd(2);
insertEnd(3);
insertEnd(4);
insertEnd(5);

display(head);

cout<<"Enter the elements to be swapped\n";
cin>>a>>b;
swapNodes(head,a,b);

cout<<"After swapping, linked list becomes\n";
display(head);
return 0;
}
