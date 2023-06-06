#include <bits/stdc++.h>
using namespace std;


const int base = 127; // This should be a prime number that is bigger than the maximum character(ascii) in the string
const int m = 1e9 + 7; // alse 1e9+9 can be used

const int N = 1e5 + 7;

int power[N];
// To set the value in power array
void prec()
{
	power[0]=1;

	for (int i=1;i<N;i++)
	{
		power[i] = 1ll*power[i-1]*base%m;
	}
}

// Does the hashing magic
int getHash(string s)
{
	int hash = 0;
	for (int i=0;i<s.size();i++)
	{
		hash+=1ll*s[i]*power[i]%m;
		hash%=m;
	}

	return hash;
}

int main ()
{
	int n;
	cin>>n;
	prec();
	while (n--)
	{
		string s;
		cin>>s;
		cout<<getHash(s)<<endl;
	}
}
