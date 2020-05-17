#include<stdio.h> 
#include<stdlib.h> 
#include<iostream>
using namespace std;
int _lis( int a[], int n, int *mr) 
{ 
    if (n == 1) 
        return 1; 
    int res, meh = 1;//meh = LIS ending of array
    for (int i = 1; i < n; i++) 
    { 
        res = _lis(a, i, mr);//get all LIS recursively uptil array[n-2] 
        if (a[i-1] < a[n-1] && res + 1 > meh) 
            meh = res + 1; //update meh when needed
    } 
    if (*mr < meh) //compare meh with max
       *mr = meh;//update max when needed 
  
    return meh;//return length  
} 
  
int lis(int a[], int n) 
{ 
    int max = 1; //max stores result
    _lis( a, n, &max ); //_lis stores the result in max
  
  
    return max; 
} 
  
int main() 
{ 
    int a[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)//input n elements in an array
    {
      cin>>a[i];
    } 
    printf("Length of lis is %dn", 
           lis( a, n )); //print the length of the list
    return 0; 
}