#include <bits/stdc++.h>
using namespace std;

int arr[10000000];
int seg[4*100000000];



void build(int indx,int l, int r)
{
	if (l==r)
	{
		seg[indx]=arr[l];
		return;
	}

	int mid = (l+r)/2;

	build(2*indx+1,l,mid);
	build(2*indx+2,mid+1,r);

	seg[indx]=max(seg[2*indx+1],seg[2*indx+2]);

}

int query(int indx,int low,int high, int l, int r)
{
	if (low<=l && high>=r)
	{
		return seg[indx];
	}
	if (high<l || low>r)
	{
		return INT_MIN;
	}
	int mid = (l+r)/2;
	int left = query(2*indx+1,low,high,l,mid);
	int right = query(2*indx+2,low,high,mid+1,r);

	return max(left,right);

}

int main ()
{
	int n;
	cin>>n;

	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	build(0,0,n-1);

	int q;
	cin>>q;
	while (q--)
	{
		int low,high;
		cin>>low>>high;
		int ans = query(0,low,high,0,n-1);

		cout<<ans<<endl;
	}

}
