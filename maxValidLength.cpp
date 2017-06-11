// Given a string consisting of opening and closing parenthesis, find length of the longest valid parenthesis substring.

#include<iostream>
#include<stack>
using namespace std;

int main(){
stack<char> s;
int i, ans;
i = ans = 0;
char A[100], x;
	
	cout<<"Enter the expression\n";
	cin>>A;

	while(A[i] != '\0'){
		if(A[i] == '(')
			s.push(A[i]);
		else if(A[i] == ')' && !(s.empty())){
			x = s.top();
			if(x == '('){
				s.pop();
				ans += 2;			
			}
		}
	i++;
	}
cout<<ans<<"\n";
return 0;
}
