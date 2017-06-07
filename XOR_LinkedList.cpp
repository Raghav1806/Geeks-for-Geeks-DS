// Implementing a memory-efficient linked list

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *npx;	// XOR of next & prev node
};

// returns XORed value of the node addresses
struct Node *XOR(struct Node *a, struct Node *b){
	return (struct Node*)((unsigned long)(a) ^ (unsigned long)(b));
}

// Insert Node at beginning of XORed linked list
void insert(struct Node **head, int x){
	struct Node *newNode = new Node;
	newNode->data = x;
	newNode->npx = XOR(*head, NULL);

	if(*head != NULL){
		struct Node *next = XOR((*head)->npx, NULL);
		(*head)->npx = XOR(newNode, next);
	}

	*head = newNode;
}

void printList(struct Node *head){
	struct Node *curr = head;
	struct Node *prev = NULL;
	struct Node *next;

	cout<<"Elements of Linked List\n";
	while(curr != NULL){
		cout<<curr->data<<" ";
		next = XOR(prev, curr->npx);
	prev = curr;
	curr = next;
	}
cout<<"\n";
}

int main (){
struct Node *head = NULL;
insert(&head, 10);
insert(&head, 20);
insert(&head, 30);
insert(&head, 40);
printList(head);
return 0;
}
