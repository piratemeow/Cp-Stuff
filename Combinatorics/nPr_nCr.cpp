#include <bits/stdc++.h>
using namespace std;


// As the factorials are pre calculated the complexity will be O(logr)


const int N = 1e6 , m = 1e9 + 7;

int fac[N+2];



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
	return 1ll * fac[n] * power(fac[r],m-2) %m * power(fac[n-r],m-2) %m;
}


int nPr(int n, int r)
{
	if (n<0 || n<r )
	{
		return 0;
	}

	return 1ll* fac[n] * power(fac[n-r],m-2) %m;
}
int main ()
{
	int n,r;
	cin>>n>>r;

	fac[0]=1;
	for (int i=1;i<=N;i++)
	{
		fac[i] = 1ll*i*fac[i-1]%m;
		//cout<<fac[i]<<endl;
	}

	cout<<nPr(12,5)<<endl;


}
