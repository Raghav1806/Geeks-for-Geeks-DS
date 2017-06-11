#include<iostream>
#include<cstdlib>
using namespace std;

struct queueNode{
int data;
struct queueNode *next;
}*front, *rear;

struct queueNode *createNewNode(int x){
struct queueNode *newptr = new queueNode;
newptr->data = x;
newptr->next = NULL;
return newptr;
}

// Elemination at front, add at rear
void dequeue(){
struct queueNode *temp = front;
front = front->next;
free(temp);
}

void enqueue(int x){
struct queueNode *newptr = createNewNode(x);
	if(front == NULL && rear == NULL)
		front = rear = newptr;
	else{
		rear->next = newptr;
		rear = newptr;
	}
}

void display(){
struct queueNode *temp = front;
	while(temp != NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
cout<<"\n";
}


int main(){
front = rear = NULL;
enqueue(1);
enqueue(2);
enqueue(3);
enqueue(4);
enqueue(5);
display();
dequeue();
display();
return 0;
}
