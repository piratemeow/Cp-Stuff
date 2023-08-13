#include <bits/stdc++.h>
using namespace std;

// Substring hashing
// formula ((pref[j]-pref[i-1])/base^i)%m
// Double hashing 
// For minimizing the odds of a wrong answer
// If the hash pair of two string are equal then the two strings are equal


// To find the number of divisors of a string
// Complexity O(nlogn)


const int base1 = 127;
const int m1 = 1e9 + 7; // also 1e9+9 can be used

const int base2 = 211;
const int m2 = 1e9 + 9;

const int N = 1e5 + 7;

int power1[N];
int power2[N];
int inv1[N];
int inv2[N];

int bigmod(int a, int b, int m)
{
	int ans = 1;
	while (b)
	{
		if (b&1)
		{
			ans = 1ll*ans*a%m;
		}

		b>>=1;
		a = 1ll*a*a%m;
	}

	return ans;
}

void prec()
{
	power1[0]=1;
	power2[0]=1;
	for (int i=1;i<N;i++)
	{
		power1[i] = 1ll*power1[i-1]*base1%m1;
		power2[i] = 1ll*power2[i-1]*base2%m2;
	}

	int inverse1 = bigmod(base1,m1-2,m1);
	int inverse2 = bigmod(base2,m2-2,m2);


	inv1[0]=1;
	inv2[0]=1;

	for (int i=1;i<N;i++)
	{
		inv1[i] = 1ll*inv1[i-1]*inverse1%m1;
		inv2[i] = 1ll*inv2[i-1]*inverse2%m2;
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

pair<long long,long long> pref[N];

void buildPref(string s)
{
	long long hs1 = 0;
	long long hs2 = 0;
	for (int i=0;i<s.size();i++)
	{
		hs1+=1ll*s[i]*power1[i]%m1;
		hs2+=1ll*s[i]*power2[i]%m2;
		pref[i]={hs1,hs2};
	}
}


pair<int,int> getHashSub (int i, int j) // 0 based && indexing i<=j
{
	pair<int,int> ans;
	if (i==0)
	{
		
		int hs1 = 1ll*pref[j].first%m1;
		int hs2 = 1ll*pref[j].second%m2;

		ans = {hs1,hs2};
	}

	else
	{
		int hs1 = 1ll*(pref[j].first-pref[i-1].first+m1)*inv1[i]%m1;
		int hs2 = 1ll*(pref[j].second-pref[i-1].second+m2)*inv2[i]%m2;
		ans = {hs1,hs2};

	}

	return ans;

}

int main ()
{

	string s;
	cin>>s;

	prec();
	buildPref(s); //To build prefix sum 


	int n = s.size();
	int ans = 1; // As every string is a divisor of itself

	for (int len = 1; len<=n/2;len++)
	{
		bool flag = 1;
		for (int i=0;i+len-1<n;i+=len)
		{
			flag &= (getHashSub(0,len-1)==getHashSub(i,i+len-1));
		}

		ans+=flag;
	}

	cout<<ans<<endl;

}
