// Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer.

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *next;
}*newptr,*np,*head,*end,*temp,*prev;

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

void rotate(struct Node **head, int k){
     	if (k == 0)
       		return;
struct Node* current = *head;
int count = 1;
    	while (count < k && current != NULL){
        	current = current->next;
        	count++;
    	}

    	if (current == NULL)
        	return;
 
    	struct Node *kthNode = current;
 
    	while (current->next != NULL)
        	current = current->next;

current->next = *head;
*head = kthNode->next;
kthNode->next = NULL;
}

int main(){
int k;
head = end = NULL;
insertEnd(1);
insertEnd(2);
insertEnd(3);
insertEnd(4);
insertEnd(5);
display(head);
cout<<"Enter the value of k\n";
cin>>k;
rotate(&head,k);
display(head);
return 0;
}
