#include<iostream> 
#include<string.h>
using namespace std; 

int max(int a, int b); 


int lcs( char *X, char *Y, int m, int n ) //Returns length of LCS for X[0..m-1], Y[0..n-1] 
{ 
	int L[m + 1][n + 1]; 
	int i, j; 
	
	for (i = 0; i <= m; i++) 
	{ 
		for (j = 0; j <= n; j++) //L[i][j] contains length of LCS
		{ 
		if (i == 0 || j == 0) 
			L[i][j] = 0; 
	
		else if (X[i - 1] == Y[j - 1]) 
			L[i][j] = L[i - 1][j - 1] + 1; 
	
		else
			L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
		} 
	} 
		
	return L[m][n]; //returns length of LCS
} 

int max(int a, int b) 
{ 
	return (a > b)? a : b; //returns max of two numbers
} 

int main() 
{ 
	char X[1000],Y[1000];
	cin>>X>>Y;
	
	int m = strlen(X); 
	int n = strlen(Y); 
	
	cout << "Length of LCS is "
		<< lcs( X, Y, m, n ); 
	
	return 0; 
}