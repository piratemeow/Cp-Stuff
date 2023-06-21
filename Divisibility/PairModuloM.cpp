// To find the number of pairs in an array whose sum is divisible by m


#include <bits/stdc++.h>

using namespace std;

int solve (int arr[], int n, int m)
{
	for (int i=0;i<n;i++)
	{
		arr[i]%=m;
	}

	map<int,int> brr;
	brr[arr[0]]++;
	int count = 0;
	for (int i=1;i<n;i++)
	{
		if (brr[m-arr[i]])
		{
			count++;
			brr[m-arr[i]]--;
			
		}
		else
		{
			brr[arr[i]]++;
		}
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
