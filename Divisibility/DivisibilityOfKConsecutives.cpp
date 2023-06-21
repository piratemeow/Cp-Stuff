/* Problem: Given an integer n find an array of n integers
			where the product of any subarray will be divisible by the
			length of that subarray
*/


// Any K consecutive numbers has atleast 1 number that is divisible by K
// That means the product of K consecutive numbers will always be divisible by K

#include <bits/stdc++.h>
using namespace std;

void solve(int arr[],int n)
{
	
	for (int i=0;i<n;i++)
	{
		arr[i]=i+1;
	}

	
}


int main ()
{

	int n;
	cin>>n;
	int arr[n];
	solve(arr,n);

	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

