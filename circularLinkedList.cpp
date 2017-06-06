// Insertion in circular linked list

#include<iostream>

using namespace std;

struct Node{
int data;
struct Node *next;
}*last;

struct Node *addToEmpty(int x){
	if(last != NULL)
		return last;

struct Node *temp = new Node;
temp->data = x;
last = temp;
last->next = last;
return last;
}

void addBegin(int x){
	if(last == NULL)
		last = addToEmpty(x);

	else{
		struct Node *temp = new Node;
		temp->data = x;
		temp->next = last->next;
		last->next = temp;
	}
}

void addEnd(int x){
	if(last == NULL)
		last = addToEmpty(x);
	else{
		struct Node *temp = new Node;
		temp->data = x;
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}

void addAfter(int data, int item){
	if(last != NULL){
		struct Node *temp,*p;
		p = last->next;
		do{
			if(p->data == item){
				temp = new Node;
				temp->data = data;
				temp->next = p->next;
				p->next = temp;

				if(p == last)
					last = temp;
			}
			p = p->next;
		}while(p != last->next);
	}
}

void traverse(){
struct Node *p;
	if(last == NULL)
		cout<<"List is empty!\n";
	else{
		p = last->next;
		do{
			cout<<p->data<<"->";
			p = p->next;
		}while(p != last->next);
	}
}

int main(){
last = NULL;
addToEmpty(6);
addBegin(4);
addEnd(8);
addBegin(2);
addEnd(12);
addAfter(10,8);
traverse();
return 0;
}
