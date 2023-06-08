#include <bits/stdc++.h>
using namespace std;


// Double hashing 
// For minimizing the odds of a wrong answer
// If the hash pair of two string are equal then the two strings are equal

const int base1 = 127;
const int m1 = 1e9 + 7; // alse 1e9+9 can be used

const int base2 = 211;
const int m2 = 1e9 + 9;

const int N = 1e5 + 7;

int power1[N];
int power2[N];

void prec()
{
	power1[0]=1;
	power2[0]=1;
	for (int i=1;i<N;i++)
	{
		power1[i] = 1ll*power1[i-1]*base1%m1;
		power2[i] = 1ll*power2[i-1]*base2%m2;
	}

}


pair<int,int> getHash(string s)
{
	int hash1 = 0;
	int hash2 = 0;
	for (int i=0;i<s.size();i++)
	{
		hash1+=1ll*s[i]*power1[i]%m1;
		hash1%=m1;
		hash2+=1ll*s[i]*power2[i]%m2;
		hash2%=m2;
	}

	return {hash1,hash2};
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
		cout<<getHash(s).first<<" "<<getHash(s).second <<endl;
	}
}
