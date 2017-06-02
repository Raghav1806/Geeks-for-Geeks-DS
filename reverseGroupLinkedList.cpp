// Reverse a linked list in groups of given size

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *next;
}*head,*end,*np,*newptr;

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

struct Node *reverse(struct Node *head, int k){
struct Node *curr = head;
struct Node *next = NULL;
struct Node *prev = NULL;
int count = 0;
	while(curr != NULL && count<k){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	if(next != NULL)
		head->next = reverse(next,k);
return prev;
}

int main(){
head = end = NULL;
int k;
insertEnd(1);
insertEnd(2);
insertEnd(3);
insertEnd(4);
insertEnd(5);
display(head);
cout<<"Enter the value of K\n";
cin>>k;
head = reverse(head,k);
cout<<"Modified linked list is\n";
display(head);
return 0;
}
