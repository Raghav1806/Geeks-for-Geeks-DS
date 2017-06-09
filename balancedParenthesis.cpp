#include<bits/stdc++.h>
using namespace std;

int findLen(char exp[]){
int ans = 0;
int i;
	for(i=0; exp[i] != '\0'; i++)
		ans++;
return ans;
}

int main(){
char exp[100];
int len,i,check;
check = 1;
char a;

cout<<"Enter the expression\n";
cin>>exp;
len = findLen(exp);
stack<char> s;

	for(i=0; i<len; i++){
		if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
			s.push(exp[i]);		
		}
		else{
			switch(exp[i]){
				case ')':
					a = s.top();
					s.pop();
					if(a != '(')
						check = -1;
					break;

				case '}':
					a = s.top();
					s.pop();
					if(a != '{')
						check = -1;
					break;
				case ']':
					a = s.top();
					s.pop();
					if(a != '[')
						check = -1;
					break;
			}
		}
	}

if(s.empty() && check == 1)
	cout<<"Balanced\n";
else
	cout<<"Not Balanced\n";

return 0;
}
