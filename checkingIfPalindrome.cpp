// Function to check if a singly linked list is palindrome

/* This method takes O(n) time and O(1) extra space.
1) Get the middle of the linked list.
2) Reverse the second half of the linked list.
3) Check if the first half and second half are identical.
4) Construct the original linked list by reversing the second half again and attaching it back to the first half
*/

#include<iostream>

using namespace std;

struct Node{
char data;
struct Node *next;
}*newptr,*head,*end,*np;

struct Node *createNewNode(char x){
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

void insertEnd(char x){
np = createNewNode(x);
	if(head == NULL)
		head = end = np;
	else{
		end->next = np;
		end = np;
	}
}

bool isPalindrome(struct Node *head){
struct Node *slowptr = head;
struct Node *fastptr = head;
struct Node *midNode = NULL;	// for handling odd size list
struct Node *secondHalf = head;
struct Node *prevOfSlowptr = head;
bool res = true;

	if(head != NULL && head->next != NULL){
		// get the middle of list
		while(fastptr != NULL && fastptr->next != NULL){
			fastptr = fastptr->next->next;
		// we need prev of slowptr for odd size list
			prevOfSlowptr = slowptr;
			slowptr = slowptr->next;
		}
		// fastptr would be NULL only for even size list
		if(fastptr != NULL){
			midNode = slowptr;
			slowptr = slowptr->next;
		}
		// reverse second half and compare with first half
		secondHalf = slowptr;
		prevOfSlowptr->next = NULL;
		reverse(&secondHalf);
		res = compareLists(head,secondHalf);
		reverse(&secondHalf);
		// If odd size list
		if(midNode != NULL){
			prevOfSlowptr->next = midNode;
			midNode->next = secondHalf;
		}
		else
			prevOfSlowptr->next = secondHalf;
	}
return res;
}

void reverse(struct Node **head){
struct Node *prev = NULL;
struct Node *curr = *head;
struct Node *next = NULL;
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
*head = prev;
}

bool compareLists(struct Node *head1, struct Node *head2){
struct Node *temp1 = head1;
struct Node *temp2 = head2;
	while(temp1 && temp2){
		if(temp1->data == temp2->data){
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else 
			return 0;
	}
	if(temp1 == NULL && temp2 == NULL)
		return 1;

return 0;	// will reach here when one is NULL and other is not
}

int main(){
head = end = NULL;
char s[100];
int i;
cout<<"Enter the string\n";
cin>>s;
	for(i=0;s[i] != '\0';i++){
		insertEnd(s[i]);
		display(head);
			if(isPalindrome(head))
				cout<<"Is Palindrome\n";
			else
				cout<<"Not Palindrome\n";
	}
return 0;
}
