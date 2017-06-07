// Program to evaluate Postfix Expression

#include<iostream>
#include<cstdlib>

using namespace std;

struct stackNode{
int s;
struct stackNode *next;
}*head,*end;

struct stackNode *createNewNode(int x){
	struct stackNode *newptr = new stackNode;
	newptr->s = x;
	newptr->next = NULL;
	return newptr;
}

void display(struct stackNode *head){
	while(head != NULL){
		cout<<head->s<<" ";
		head = head->next;
	}
cout<<"\n";
}

void insertEnd(int x){
	struct stackNode *np = createNewNode(x);
	if(head == NULL && end == NULL)
		head = end = np;
	else{
		end->next = np;
		end = np;
	}
}

int findStrlen(string s){
int size,i;
size = 0;
	for(i=0; s[i] != '\0'; i++)
		size++;	
return size;
}

int isEmpty(struct stackNode *head){
	if(head == NULL)
		return 1;
}

char peek(struct stackNode *head){
	if(head != NULL)		
		return head->s;
	else
		return -1;
}

char pop(struct stackNode **end){
	struct stackNode *prev,*temp;
	temp = head;	
	while(temp != NULL){
		prev = temp;
		temp = temp->next;
	} 
	temp = *end;
	*end = prev;
	free(temp);
}

int evaluatePostfix(char s[], int len){
int i;
	if(head == NULL)
		return -1;
	for(i=0; i<len; i++){
		if('0' <= s[i] && s[i] <= '9')
			insertEnd(s[i]-'0');
		else{
			int val1 = pop(&end);
			int val2 = pop(&end);
			switch(s[i]){
				case '+': 
					insertEnd(val2+val1);
					break;
				case '-':
					insertEnd(val2-val1);
					break;
				case '*':
					insertEnd(val2*val1);
					break;
				case '/':
					insertEnd(val2/val1);
					break;
			}
		}
	}
return pop(&end);
}

int main(){
	head = end = NULL;
	char s[100];
cout<<"Enter the string\n";
cin>>s;
int len = findStrlen(s);
int ans;
ans = evaluatePostfix(s, len);
cout<<"Value of given postfix expression is "<<ans<<"\n";
return 0;
}
