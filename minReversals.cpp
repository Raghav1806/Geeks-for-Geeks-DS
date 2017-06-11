/* 
Given an expression with only ‘}’ and ‘{‘. The expression may not be balanced. Find minimum number of bracket reversals to make the expression balanced.
*/

#include<iostream>
#include<stack>
using namespace std;

int countMinReversals(char exp[]){
stack<char> s;
int i=0;
	while(exp[i] != '\0'){
		if(exp[i] == '}' && !s.empty()){
			if(s.top() == '{')
				s.pop();
			else
				s.push(exp[i]);
		}
		else
			s.push(exp[i]);
	i++;
	}
int reducedLen = s.size();
int n = 0;	// count opening brackets at end of stack
	while(!s.empty() && s.top() == '{'){
		s.pop();
		n++;
	}
return (reducedLen/2 + n%2);	
}

int main(){
char exp[100];
cout<<"Enter the expression\n";
cin>>exp;
cout<<countMinReversals(exp)<<"\n";
return 0;
}
