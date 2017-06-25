// Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.

/*
Rabin Karp algorithm needs to calculate hash values for following strings.

1) Pattern itself.
2) All the substrings of text of length m. 
*/

#include <iostream>
#include <cstring>
using namespace std;

// d is no. of characters in input alphabet
#define d 256

/*
pat -> pattern
txt -> text
q -> prime number
*/

void search(char pat[], char txt[], int q){
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0;	// hash value for pattern
	int t = 0;	// hash value for txt
	int h = 1;

	// the value of h would be pow(d, M-1)%q
	for(i=0; i<M-1; i++)
		h = (h*d)%q;

	// calculate hash value of pattern and first window of text
	for(i=0; i<M; i++){
		p = (d*p + pat[i])%q;
		t = (d*t + txt[i])%q;
	}
	
	// slide the pattern over text one by one
	for(i=0; i<=N-M; i++){
		// check the hash values of current window of text and pattern. If he hash values match then only check for characters one by one.
		if(p == t){
			for(j=0; j<M; j++){
				if(txt[i+j] != pat[j])
					break;
			}
			if(j == M)
				cout<<"Pattern found at index "<<i<<"\n";
		}
		// calculate hash value for next window of text, remove leading digit, add trailing digit
		if(i < N-M){
			t = (d*(t-txt[i]*h) + txt[i+M])%q;
				if(t<0)
					t += q;
		}
	}
}

int main(){
	char txt[100], pat[100];
	cout<<"Enter the text\n";
	cin>>txt;
	cout<<"Enter the pattern to be searched for\n";
	cin>>pat;
	int q = 101;	// A prime number
	search(pat, txt, q);
return 0;
}
