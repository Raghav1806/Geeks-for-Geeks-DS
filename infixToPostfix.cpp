/* Algorithm
1. Scan the infix expression from left to right.
2. If the scanned character is an operand, output it.
3. Else,
…..3.1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty), push it.
…..3.2 Else, Pop the operator from the stack until the precedence of the scanned operator is less-equal to the precedence of the operator residing on the top of the stack. Push the scanned operator to the stack. [No 2 operators of sae priority stay together in stack]
4. If the scanned character is an ‘(‘, push it to the stack.
5. If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
6. Repeat steps 2-6 until infix expression is scanned.
7. Pop and output from the stack until it is not empty.
*/

#include<bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int prec(char c){
	if(c == '^')
		return 3;
	else if(c == '*' || c == '/')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else
		return -1;
}

void infixToPostfix(string s){
	std::stack<char> st;
	st.push('N');
	int l = s.length();
	string ns;
	for(int i = 0; i<l; i++){
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			ns += s[i];

		else if(s[i] == '(')
			st.push('(');

		else if(s[i] == ')'){
			while(st.top() != 'N' && st.top() != '('){
				char c = st.top();
				st.pop();
				ns += c;
			}
		if(st.top() == '('){
			char c = st.top();
			st.pop();
		}
		}

// If an operator is scanned
		else{
			while(st.top() != 'N' && prec(s[i]) <= prec(st.top())){
				char c = st.top();
				st.pop();
				ns += c;
			}
			st.push(s[i]);
		}
	}
// Pop all remaining elements from stack
		while(st.top() != 'N'){
			char c = st.top();
			st.pop();
			ns += c;
		}
cout<<ns<<"\n";
}

int main(){
string exp = "a+b*(c^d-e)^(f+g*h)-i";
infixToPostfix(exp);
return 0;
}
