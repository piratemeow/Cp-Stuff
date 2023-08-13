#include <bits/stdc++.h>
using namespace std;

// Substring hashing
// formula ((pref[j]-pref[i-1])/base^i)%m
// Double hashing 
// For minimizing the odds of a wrong answer
// If the hash pair of two string are equal then the two strings are equal

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

	int inverse1 = bigmod(base1,m1-2,m1);
	int inverse2 = bigmod(base2,m2-2,m2);


	inv1[0]=1;
	inv2[0]=1;

	for (int i=1;i<N;i++)
	{
		power1[i] = 1ll*power1[i-1]*base1%m1;
		power2[i] = 1ll*power2[i-1]*base2%m2;

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

pair<int,int> pref[N];

void buildPref(string s)
{
	long long hs1 = 0;
	long long hs2 = 0;
	for (int i=0;i<s.size();i++)
	{
		hs1+=1ll*s[i]*power1[i]%m1;
		hs1%=m1;
		hs2+=1ll*s[i]*power2[i]%m2;
		hs2%=m2;
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

	pair<int,int> s_hash = getHash(s);
	pair<int,int> sub_hash = getHashSub(2,4);

	cout<<s_hash.first<<" "<<s_hash.second<<endl;
	cout<<sub_hash.first<<" "<<sub_hash.second<<endl;

}
