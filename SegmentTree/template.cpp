// Template of segemnt tree
// Implemented for segment sum
// 0 based indexing is used
// The input for the segment and the update index has to be 0 based

#include<bits/stdc++.h>

using namespace std;

const int N = 1e7; // Change here
int arr[N];
int seg[4*N];

void build(int index, int l , int r)
{
    if (l==r)
    {
        seg[index]=arr[l];
        return;
    }

    int mid = (l+r)/2;
    build(2*index+1,l,mid);
    build(2*index+2,mid+1,r);

    seg[index] = seg[2*index+1] + seg[2*index+2]; // Change here
}

int query(int index, int low, int high, int l, int r)
{
    if (low<=l && high>=r)
    {
        return seg[index];
    }

    if (high<l || low>r)
    {
        return 0; // Change here
    }

    int mid = (l+r)/2;

    int left = query(2*index+1,low,high,l,mid);
    int right = query(2*index+2,low,high,mid+1,r);

    return left + right; // Change here
}

void update(int index,int l, int r, int i, int val)
{
    if (l==r and i==l)
    {
        seg[index] = val; // Change here
        arr[l] = val; // Change here

        return;
    }

    int mid = (l+r)/2;

    if (i<=mid)
    {
        update(2*index+1,l,mid,i,val);
    }

    else
    {
        update(2*index+2,mid+1,r,i,val);
    }

    seg[index] = seg[2*index+1] + seg[2*index+2]; // Change here
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
        int a;
        cin>>a;
        if (a==1) // Means update
        {
            int i, val;
            cin>>i>>val;
            update(0,0,n-1,i-1,val);
        }

        else
        {
            int i,j;
            cin>>i>>j;
            cout<<query(0,i-1,j-1,0,n-1)<<endl;
        }
    }
}
