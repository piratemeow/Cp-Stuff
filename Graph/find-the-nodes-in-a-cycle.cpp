#include<bits/stdc++.h>
using namespace std;



// To find and print the cycle in a connected graph. There can be 
// multiple cycle but only one cyle will be printed
// the nodes of the cycle will be printed in sorted order
// Samsung interview question 



int cycle_start = -1;
int cycle_end = -1;

void dfs(int ver, int parr,vector<int>&par, vector<vector<int>>&G, vector<int>&visi)
{
	visi[ver] = 0;
	

	// cout<<parr<<" "<<ver<<endl;
	for (int i=0;i<G[ver].size();i++)
	{
		if (visi[G[ver][i]]==0  && G[ver][i]!=parr)
		{
			// cout<<ver<<" "<<G[ver][i]<<endl;
			cycle_start = G[ver][i];
			cycle_end = ver;
			visi[G[ver][i]]=1;
			visi[ver] = 1;

			return;
		}

		else if (visi[G[ver][i]]==-1)
		{
			par[G[ver][i]] = ver;
			dfs(G[ver][i],ver,par,G,visi);
		}
	}

	visi[ver] = 1;
}

// void backtrack(int ver, vector<vector<int>>&G, )


int main()
{
	int n;
	cin>>n;
	vector<vector<int>>G(n+1);
	int m;
	cin>>m;
	for (int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}


	vector<int>visi(n+1,-1);
	vector<int> par(n+1,-1);
	
	dfs(1,-1,par,G,visi);
		

	// cout<<cycle_start<<" "<<cycle_end<<endl;
	// for (int i=1;i<=n;i++)
	// {
	// 	cout<<par[i]<<endl;
	// }
	
	vector<int> a;
	a.push_back(cycle_start);
	while(cycle_end!=cycle_start)
	{
		a.push_back(cycle_end);
		cycle_end = par[cycle_end];
	}
	
	sort(a.begin(),a.end());
	for (int i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}



}
