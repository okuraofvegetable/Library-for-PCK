#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
#define LLINF 1000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
struct edge{
	int from,to;
	edge(){}
	edge(int f,int t):from(f),to(t){}
};
struct Tree{
	int V;
	int root;
	vector<int> depth;
	vector<int> par;
	vector<int> subtree_size;
	vector<int> centroid;
	vector<vector<edge> > G;
	Tree(){}
	Tree(int v,int r=0){
		V = v;
		root = r;
		G.resize(V);
		depth.resize(V);
		par.resize(V);
		subtree_size.resize(V);
	}
	void add_edge(int u,int v){
		G[u].pb(edge(u,v));
		G[v].pb(edge(v,u));
	}
	int dfs(int v,int p,int d){
		depth[v]=d;
		par[v]=p;
		subtree_size[v]=1;
		bool is_centroid = true;
		for(int i=0;i<G[v].size();i++){
			int u = G[v][i].to;
			if(u==p)continue;
			subtree_size[v]+=dfs(u,v,d+1);
			if(subtree_size[u]>V/2)is_centroid=false;
		}
		if(V-subtree_size[v]>V/2)is_centroid=false;
		if(is_centroid)centroid.pb(v);
		return subtree_size[v];
	}
	void dfs(){
		dfs(root,-1,0);
	}
};
int N;
int main(){
	cin >> N;
	Tree G(N);
	for(int i=0;i<N-1;i++){
		int x,y;
		cin >> x >> y;
		x--;y--;
		G.add_edge(x,y);
	}
	G.dfs();
	return 0;
}
