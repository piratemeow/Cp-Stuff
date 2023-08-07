#include<bits/stdc++.h>
using namespace std;

// Building Pascal's triangle 
// Complexity O(N^2)


const int N = 1e4, m = 1e9 +7;

int c[N+3][N+3];

int main ()
{
	int n,r;
	cin>>n>>r;
	c[0][0]=1;

	for (int i=1;i<=N;i++)
	{
		c[i][0]=1;
		//c[i][i]=1;
		for (int j = 1;j<=i;j++)
		{
			c[i][j] = c[i-1][j-1] + c[i-1][j]%m;
		}

	}

	cout<<c[5][5]<<endl;	
}
