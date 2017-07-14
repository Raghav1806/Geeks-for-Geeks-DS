/*
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to reach (m, n) is sum of all the costs on that path (including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.
*/

#include <iostream>
using namespace std;

int findMin(int a, int b, int c){
	if(a <= b && a <= c)
		return a;
	else if(b <= a && b <= c)
		return b;
	else
		return c;
}

int main(){
	int row, column, i, j, m, n;
	cout<<"Enter the rows and columns in the 2D array\n";
	cin>>row>>column;
	int cost[row][column], minCost[row][column];
	cout<<"Enter the values in cost matrix\n";
	for(i=0; i<row; i++){
		for(j=0; j<column; j++)
			cin>>cost[i][j];
	}

	minCost[0][0] = cost[0][0];
	cout<<minCost[0][0]<<"c\n";

	for(i=1; i<row; i++){
		minCost[i][0] = minCost[i-1][0] + cost[i][0];
	}

	for(j=1; j<column; j++){
		minCost[0][j] = minCost[0][j-1] + cost[0][j];
	}

	for(i=1; i<row; i++){
		for(j=1; j<column; j++){
			minCost[i][j] = findMin(minCost[i-1][j-1], minCost[i-1][j], minCost[i][j-1]) + cost[i][j];

		}
	}

	for(i=0; i<row; i++){
		for(j=0; j<column; j++)
			cout<<minCost[i][j]<<" ";
		cout<<"\n";
	}
	
	cout<<minCost[2][2]<<"\n";

return 0;
}


