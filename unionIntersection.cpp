// Given two Linked Lists, create union and intersection lists that contain union and intersection of the elements present in the given lists. Order of elments in output lists doesn’t matter.

// hash table is used, range of elements : 0-100

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *next;
}*newptr,*np;

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
	if(*head == NULL && *end == NULL)
		*head = *end = np;
	else{
		(*end)->next = np;
		*end = np;
	}
}

void findUnionIntersection(struct Node *head1, struct Node *head2){
int hash[100],i;
	
	for(i=0;i<100;i++)
		hash[i] = 0;

	while(head1 != NULL){
		hash[head1->data]++;
		head1 = head1->next;
	}

// Finding Intersection and union
	while(head2 != NULL){
		if(hash[head2->data] != 0)
			cout<<head2->data<<" is present in both linked lists\n";
		else if(hash[head2->data] == 0)
			cout<<head2->data<<" is not present in both linked lists\n";	
		head2 = head2->next;
	}
}

int main(){
struct Node *head1, *head2, *end1, *end2;
head1 = head2 = end1 = end2 = NULL;
int num,x;
cout<<"Enter number of elements of first linked list\n";
cin>>num;
cout<<"Enter the elements of first linked list\n";
	while(num--){
		cin>>x;
		insertEnd(&head1, &end1, x);
	}
cout<<"First linked list is\n";
display(head1);

cout<<"Enter number of elements of second linked list\n";
cin>>num;
cout<<"Enter the number of elements of second linked list\n";
	while(num--){
		cin>>x;
		insertEnd(&head2, &end2, x);
	}
cout<<"Second linked list is\n";
display(head2);
findUnionIntersection(head1, head2);
return 0;
}

