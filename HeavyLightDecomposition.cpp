#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define MAX_N 100100
#define MAX_LOG_V 20
vector<int> g[MAX_N];
int N,Q,root=0;
int parent[MAX_LOG_V][MAX_N];
int depth[MAX_N],chnum[MAX_N];
void dfs(int v,int p,int d)
{
	chnum[v]=1;
	depth[v]=d;
	parent[0][v]=p;
	for(int i=0;i<g[v].size();i++)
	{
		if(g[v][i]!=p)
		{
			dfs(g[v][i],v,d+1);
			chnum[v]+=chnum[g[v][i]];
		}
	}
	return;
}
vector<int> top;
int pathtop[MAX_N];
int heavy[MAX_N];
int toseg[MAX_N];
void decompose(int v,int p,bool istop)
{
	if(istop)top.pb(v);
	int hev = -1;
	int val = -1;
	for(int i=0;i<g[v].size();i++)
	{
		if(g[v][i]==p)continue;
		if(val<chnum[g[v][i]])
		{
			val = chnum[g[v][i]];
			hev = g[v][i];
		}
	}
	heavy[v]=hev;
	for(int i=0;i<g[v].size();i++)
	{
		if(g[v][i]==p)continue;
		if(g[v][i]==hev)decompose(g[v][i],v,false);
		else decompose(g[v][i],v,true);
	}
}
void construct_toseg()
{
	int id = 0;
	for(int i=0;i<top.size();i++)
	{
		int now = top[i];
		while(1)
		{
			if(now==-1)break;
			toseg[now]=id++;
			pathtop[now]=top[i];
			now = heavy[now];
		}
	}
}
void init()
{
	dfs(root,-1,0);
	for(int i=0;i<MAX_LOG_V-1;i++)
	{
		for(int v=0;v<N;v++)
		{
			if(parent[i][v]==-1)parent[i+1][v]=-1;
			else parent[i+1][v]=parent[i][parent[i][v]];
		}
	}
	return;
}
int lca(int u,int v)
{
	if(depth[u]>depth[v])swap(u,v);
	for(int i=19;i>=0;i--)
	{
		if(((depth[v]-depth[u])>>i)&1)v=parent[i][v];
	}
	if(u==v)return u;
	for(int i=19;i>=0;i--)
	{
		if(parent[i][u]!=parent[i][v])
		{
			u=parent[i][u];
			v=parent[i][v];
		}
	}
	return parent[0][u];
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		g[a].pb(b);
		g[b].pb(a);
	}
	init();
	decompose(0,-1,true);
	construct_toseg();
	for(int i=0;i<N;i++)
	{
		printf("%d %d %d\n",heavy[i],pathtop[i],toseg[i]);
	}
	return 0;
}

