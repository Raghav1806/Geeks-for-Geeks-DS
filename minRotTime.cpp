/*
1) Create an empty Q.
2) Find all rotten oranges and enqueue them to Q.  Also enqueue 
   a delimiter to indicate beginning of next time frame. 
3) While Q is not empty do following
   3.a) While delimiter in Q is not reached 
       (i) Dequeue an orange from queue, rot all adjacent oranges.
           While rotting the adjacents, make sure that time frame 
           is incremented only once. And time frame is not icnremented
           if there are no adjacent oranges.
   3.b) Dequeue the old delimiter and enqueue a new delimiter. The 
        oranges rotten in previous time frame lie between the two
        delimiters. 
*/

/* 
0: Empty cell

1: Cells have fresh oranges

2: Cells have rotten oranges 
*/

#include<bits/stdc++.h>
#define R 3
#define C 5
using namespace std;

// function to check whether a cell is valid/invalid
bool isValid(int i, int j){
	return(i >= 0 && j >= 0 && i < R && j < C);
}

// structure for storing coordinates of cell
struct element{
	int x, y;
};

// function to check whether the cell is delimiter (-1, -1)
bool isDelim(element temp){
	return(temp.x == -1 && temp.y == -1);
}

// function to check whether there is still a fresh orange remaining
bool checkAll(int A[][C]){
	int i, j;
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			if(A[i][j] == 1)
				return true;
		}
	}
return false;
}

// function for checking if it is possible to rot all oranges or not
int rotOranges(int A[][C]){
int i, j;	
	queue<element> Q;
	element temp;
	int ans = 0;

	// store all cells having rotten orange in first time frame
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			if(A[i][j] == 2){
				temp.x = i;
				temp.y = j;
				Q.push(temp);
			}
		}
	}
	// Add a delimiter
	temp.x = -1;
	temp.y = -1;
	Q.push(temp);

	while(!Q.empty()){
		// this flag is used to determine whether even a single orange gets rotten in current time frame
		bool flag = false;

		while(!isDelim(Q.front())){
			temp = Q.front();
		// check if right adjacent cell can be rotten
			if(isValid(temp.x+1, temp.y) && A[temp.x+1][temp.y] == 1){
			if(!flag){
				ans++;
				flag = true;
			}			
				// make orange rotten
				A[temp.x+1][temp.y] = 2;
				// push adjacent orange to queue
				temp.x++;
				Q.push(temp);
				// Move back to current cell
				temp.x--;
			}

			if(isValid(temp.x-1, temp.y) && A[temp.x-1][temp.y] == 1){
			if(!flag){
				ans++;
				flag = true;
			}	

			A[temp.x-1][temp.y] = 2;
			temp.x--;
			Q.push(temp);
			temp.x++;
			}

			if(isValid(temp.x, temp.y+1) && A[temp.x][temp.y+1] == 1){
				if(!flag){
					ans++;
					flag = true;
				}
			A[temp.x][temp.y+1] = 2;
			temp.y++;
			Q.push(temp);
			temp.y--;
			}

			if(isValid(temp.x, temp.y-1) && A[temp.x][temp.y-1] == 1){
				if(!flag){
					ans++;
					flag = true;
				}

			A[temp.x][temp.y-1] = 2;
			temp.y--;
			Q.push(temp);
			}

		Q.pop();
		}

	// Pop the delimiter
	Q.pop();
// If oranges were rotten in current frame then separate rotten oranges using delimiter for next frame.
	if(!Q.empty()){
		temp.x = -1;
		temp.y = -1;
		Q.push(temp);
	}
// If queue was empty, then no rotten oranges are left to process
return (checkAll(A)) ? -1:ans;
}

int main(){
    int arr[][C] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};
    int ans = rotOranges(arr);
    if (ans == -1)
        cout << "All oranges cannot rot\n";
    else
         cout << "Time required for all oranges to rot => " << ans << endl;
    return 0;
}
