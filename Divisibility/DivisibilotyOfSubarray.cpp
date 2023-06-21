// Number of subarrays divisible by m
// Take the prefix sum
// The sum of a subarray will be Pj-Pi
// For (Pj-Pi)%m==0 Pj==Pi
// Also consider the 0s


#include <bits/stdc++.h>

using namespace std;

int solve (int arr[], int n, int m)
{
	int sum = 0;
	for (int i=0;i<n;i++)
	{
		sum+=arr[i];
		arr[i]=sum;
	}

	for (int i=0;i<n;i++)
	{
		arr[i]%=m;
	}

	map<int,int> brr;
	brr[arr[0]]++;
	int count = 0;
	for (int i=1;i<n;i++)
	{
		if (brr[arr[i]])
		{
			count++;

			if(arr[i]==0)
				count++;

		}
		
		brr[arr[i]]++;
		
	}

	return count;
}
int main ()
{
	int n,m;
	cin>>n>>m;
	int arr[n];
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}


	cout<<solve(arr,n,m)<<endl;
}
