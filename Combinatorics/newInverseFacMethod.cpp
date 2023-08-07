#include <bits/stdc++.h>
using namespace std;


// As the factorials are pre calculated the complexity will be O(logr)
// This uses a different method to calculate the modular inverse of a n factorials


const int N = 1e6 , m = 1e9 + 7;

int fac[N+2];
int invfac[N+2];



int power(int a, int b)
{
	int ans = 1;

	while (b)
	{
		if (b&1)
		{
			ans = 1ll*ans*a%m;
		}
		
		a = 1ll*a*a %m;
		b>>=1;
	}

	return ans;
}


int nCr(int n, int r)
{
	if (n<r || n<0)
	{
		return 0;
	}
	return 1ll * fac[n] * invfac[r] %m * invfac[n-r] %m;
}


int nPr(int n, int r)
{
	if (n<0 || n<r )
	{
		return 0;
	}

	return 1ll* fac[n] * invfac[n-r] %m;
}
int main ()
{
	int n,r;
	cin>>n>>r;

	fac[0]=1;
	for (int i=1;i<=N+1;i++)
	{
		fac[i] = 1ll*i*fac[i-1]%m;
		//cout<<fac[i]<<endl;
	}

	// This is another way of calculating inverse modulo of factorial
	invfac[N+1] = power(fac[N+1],m-2);
	invfac[0]=1;

	for (int i=N;i>=1;i--)
	{
		invfac[i] = 1ll * (i+1) * invfac[i+1] %m; 
	}

	cout<<power(fac[10000],m-2)<<" "<<invfac[10000];

	


}
