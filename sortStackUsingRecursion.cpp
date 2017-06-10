// Program to sort stack using recurision
#include<iostream>
#include<cstdlib>
using namespace std;

struct stackNode{
	int data;
	struct stackNode *next;
}*head;

int isEmpty(){
	if(head == NULL)
		return 1;
return 0;
}

struct stackNode *createNewStackNode(int x){
	struct stackNode *newptr = new stackNode;
	newptr->data = x;
	newptr->next = NULL;
return newptr;
}

void push(struct stackNode **head, int x){
struct stackNode *np = createNewStackNode(x);
	if(*head == NULL)
		*head = np;
	else{
		struct stackNode *temp = *head;
		*head = np;
		(*head)->next = temp;
	}
}

int pop(struct stackNode **head){
	int x;
	struct stackNode *temp;
	temp = *head;
	x = (*head)->data;
	*head = (*head)->next;
	free(temp);

	return x;
}

int top(){
	return head->data;
}

void display(struct stackNode *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
cout<<"\n";
}

void sortedInsert(struct stackNode **head, int x){
	if(isEmpty() || x > top()){
		push(head, x);
		return;
	}

	// If top is greater, remove top item and recur
	int temp = pop(head);
	sortedInsert(head, x);

	// put back the top item removed earlier
	push(head, temp);
}

void sortStack(struct stackNode **head){
	if(!isEmpty()){
		int x = pop(head);
		sortStack(head);
		sortedInsert(head, x);
	}
}

int main(){
head = NULL;

push(&head, 6);
push(&head, 3);
push(&head, 5);
push(&head, 0);
push(&head, -10);

display(head);

sortStack(&head);

display(head);
return 0;
}

