// The power of p(prime) in n!

#include <bits/stdc++.h>

using namespace std;

int legendre(long long n, long long p)
{
	int ans =  0;
	while (true)
	{	
		if (p>n || p<=0)
			break;
		ans += n/p;
		p*=p;
	}

	return ans;
}
int legendre_better(long long n, long long p)
{
	int ans = 0;
	while (n)
	{
		ans+=n/p;
		n/=p;
	}

	return ans;
}
int main ()
{
	long long n,p;
	cin>>n>>p;
	cout<<legendre(n,p)<<" "<<legendre_better(n,p)<<endl;
}
