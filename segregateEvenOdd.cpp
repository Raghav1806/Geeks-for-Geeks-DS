// Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *next;
}*newptr,*head,*end,*np;

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

void segregateEvenOdd(struct Node **head){
struct Node *end = *head;
struct Node *prev = NULL;
struct Node *curr = *head;
	while(end->next != NULL)
		end = end->next;

struct Node *newEnd = end;
	while((curr->data)%2 != 0 && curr != end){
		newEnd->next = curr;
		curr = curr->next;
		newEnd->next->next = NULL;
		newEnd = newEnd->next;
	}
	if(curr->data%2 == 0){
		*head = curr;
		while(curr != end){
			if(curr->data%2 == 0){
				prev = curr;
				curr = curr->next;
			}
			else{
				prev->next = curr->next;
				curr->next = NULL;
				newEnd->next = curr;
				newEnd = curr;
				curr = prev->next;
			}
		}
	}
	else
		prev = curr;

	if(newEnd != end && (end->data)%2 != 0){
		prev->next = end->next;
		end->next = NULL;
		newEnd->next = end;
	}
return;
}

int main(){
head = end = NULL;
int num,x;
cout<<"Enter the number of elements to be inserted\n";
cin>>num;
cout<<"Enter the elements of linked list\n";
	while(num--){
		cin>>x;
		insertEnd(x);
	}
cout<<"The entered linked list is\n";
display(head);
segregateEvenOdd(&head);
cout<<"The modified linked list is\n";
display(head);
return 0;
}
