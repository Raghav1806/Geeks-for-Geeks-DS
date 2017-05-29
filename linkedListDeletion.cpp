// Program to delete given number in linked list

#include<iostream>
#include<cstdlib>

using namespace std;

struct Node{
int data;
struct Node *next;
}*newptr,*head,*end,*np,*temp;

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
	if(head == NULL){
		head = end = np;
	}
	else{
		end->next = np;
		end = np;
	}
}

void deletePos(struct Node *head,int pos){
pos--;
	while(pos--){
		head = head->next;
	}
temp = head->next;
head->next = head->next->next;
free(temp);	
}

int main(){
head = end = NULL;
int pos;
insertEnd(1);
insertEnd(2);
insertEnd(3);
insertEnd(4);
insertEnd(5);
cout<<"Initial linked list is: ";
display(head);
cout<<"Enter index number to be deleted\n";
cin>>pos;
deletePos(head,pos);
cout<<"Final linked list will be\n";
display(head);
return 0;
}
