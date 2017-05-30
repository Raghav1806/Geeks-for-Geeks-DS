// Program to merge two separate linked list in ascending order

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *next;
}*newptr,*np,*head1,*end1,*head2,*end2,*newHead;

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

void insertEnd(struct Node **head, struct Node **end, int x){
np = createNewNode(x);
	if(*head == NULL){
		*head = *end = np;
	}
	else{
		(*end)->next = np;
		*end = np;
	}
}

struct Node* sortedMerge(struct Node* head1, struct Node* head2){
struct Node* result = NULL;

  	if (head1 == NULL) 
     		return(head2);
  	else if (head2==NULL) 
     		return(head1);
 
  	if (head1->data <= head2->data){
     		result = head1;
     		result->next = sortedMerge(head1->next, head2);
  	}
  	
	else{
     		result = head2;
     		result->next = sortedMerge(head1, head2->next);
  	}
  	
return(result);
}

int main(){
head1 = end1 = head2 = end2 = newHead = NULL;
insertEnd(&head1,&end1,1);
insertEnd(&head1,&end1,3);
insertEnd(&head1,&end1,5);
insertEnd(&head1,&end1,7);
insertEnd(&head1,&end1,9);
cout<<"First linked list is:\n";
display(head1);
insertEnd(&head2,&end2,2);
insertEnd(&head2,&end2,4);
insertEnd(&head2,&end2,6);
insertEnd(&head2,&end2,8);
insertEnd(&head2,&end2,10);
cout<<"Second linked list is:\n";
display(head2);
newHead = sortedMerge(head1,head2);
cout<<"Sorted merged linked list is:\n";
display(newHead);
return 0;
}
