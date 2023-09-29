#include <bits/stdc++.h>
using namespace std;




struct node
{
	node* links[26];
	bool flag = false;

	bool containsKey(char ch)
	{
		return links[ch-'a']!=NULL;
	}

};

class trie{

private:
	node* root; 

public:

	trie()
	{
		
		root = new node();
	}

	void insert (string s)
	{

		node* nod = root;
		for (int i=0;i<s.size();i++)
		{

			if (!nod->containsKey(s[i]))
			{

				nod->links[s[i]-'a'] = new node();
				nod = nod->links[s[i]-'a'];
			}
			else
			{
				nod = nod->links[s[i]-'a'];
			}
		}

		nod->flag = true;
	}

	bool search(string s)
	{

		node* nod = root;

		for (int i=0;i<s.size();i++)
		{
			if (nod->containsKey(s[i]))
			{
				nod = nod->links[s[i]-'a'];
			}
			else
			{
				return false;
			}
		}

		if (nod->flag!=true)
		{
			return false;
		}

		return true;
	}

	bool prefix(string s)
	{
		node* nod = root;

		for (int i=0;i<s.size();i++)
		{
			if (nod->containsKey(s[i]))
			{
				nod = nod->links[s[i]-'a'];
			}
			else
			{
				return false;
			}
		}

		// if (nod->flag!=true)
		// {
		// 	return false;
		// }

		return true;
	}

};

int main()
{
	int t;
	cin>>t;

	trie* root = new trie();

	while (t--)
	{
		string s;
		cin>>s;
		root->insert(s);
	}
	
	string s;
	cin>>s;
	cout<<root->search(s)<<endl;
	cout<<root->prefix(s)<<endl;
}
