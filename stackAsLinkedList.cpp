// Implementing stack as linked

#include<iostream>
#include<cstdlib>
using namespace std;

struct stackNode{
	int data;
	struct stackNode *next;
};

struct stackNode *createNewNode(int x){
	struct stackNode *newptr = new stackNode;
	newptr->data = x;
	newptr->next = NULL;
return newptr;
}

int isEmpty(struct stackNode *head){
	return !head;
}

void push(struct stackNode **head, int x){
	struct stackNode *newptr = createNewNode(x);
	newptr->next = *head;
	*head = newptr;
cout<<x<<" pushed to stack\n";
}

int pop(struct stackNode **head){
	if(isEmpty(*head))
		return -1;
	struct stackNode *temp = *head;
	*head = (*head)->next;
	int popped = temp->data;
	free(temp);
return popped;
}

int peek(struct stackNode *head){
	if(isEmpty(head))
		return -1;
	return head->data;
}

int main(){
	struct stackNode *head = NULL;

push(&head, 10);
push(&head, 20);
push(&head, 30);

cout<<"Top element is "<<peek(head)<<"\n";
return 0;
}
