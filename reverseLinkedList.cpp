// Program to reverse a linked list
// Cre­ate 3 nodes, cur­rN­ode, Pre­vN­ode and nextNode.
// Ini­tial­ize them as cur­rN­ode = head; nextN­ode = null; pre­vN­ode = null;
// Now keep revers­ing the point­ers one by one till currNode!=null

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *next;
}*newptr,*head,*end,*np,*currNode,*nextNode,*prevNode;

struct Node* createNewNode(int x){
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

void reverse(struct Node **head){
prevNode = NULL;
currNode = *head;
nextNode = NULL;
	while(currNode != NULL){
		nextNode = currNode->next;
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
	}
*head = prevNode;
}

int main(){
head = end = currNode = prevNode = nextNode = NULL;
insertEnd(1);
insertEnd(2);
insertEnd(3);
insertEnd(4);
insertEnd(5);
cout<<"Initial linked list is:\n";
display(head);
reverse(&head);
cout<<"Reversed linked list is:\n";
display(head);
return 0;
}
