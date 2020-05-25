#include<bits/stdc++.h> 
using namespace std; 

bool isPalindrome(string str, int low, int high) //comparator function
{ 
	while (low < high) 
	{ 
		if (str[low] != str[high]) 
			return false; 
		low++; 
		high--; 
	} 
	return true; 
} 

void allPalPartUtil(vector<vector<string> >&allPart, vector<string> &currPart, 
				int start, int n, string str) // Recursive function to find all palindromic partitions of str[start..n-1] 
{ 
	 
	if (start >= n)// If 'start' has reached len 
	{ 
		allPart.push_back(currPart); 
		return; 
	} 

		for (int i=start; i<n; i++) // Pick all possible ending points for substrings 

	{ 
		
		if (isPalindrome(str, start, i)) // If substring str[start..i] is palindrome 
		{ 
			
			currPart.push_back(str.substr(start, i-start+1)); // Add the substring to result 

			
			allPalPartUtil(allPart, currPart, i+1, n, str); // Recur for remaining remaining substring 
			
			currPart.pop_back();// Remove substring str[start..i] from current partition  
		} 
	} 
} 

void allpalpart(string str) 
{ 
	int n = str.length(); 
	vector<vector<string> > allPart; //store all pallindromic partitions

	vector<string> currPart;//store current pallindromic partition

	allPalPartUtil(allPart, currPart, 0, n, str); //recursively generate all partitions

	for (int i=0; i< allPart.size(); i++ ) //print generated partitioned
	{ 
		for (int j=0; j<allPart[i].size(); j++) 
			cout << allPart[i][j] << " "; 
		cout << "\n"; 
	} 
} 


int main() 
{ 
	string str;
    cin>>str; 
	allpalpart(str); 
	return 0; 
}
