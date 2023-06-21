#include <bits/stdc++.h>
using namespace std;

// Same as using the real way of division that we learned as kids
bool isDivisible(string a, int b)
{
	int ans = 0;
	for (int i=0;i<a.size();i++)
	{
		ans = (ans * 10 + (a[i]-'0')) % b;
	}

	if (ans==0)
		return true;
	else
		return false;
}

int main ()
{
	string a;
	int b;
	cin>>a>>b;


	if (isDivisible(a,b))
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}

}
