#include <cstdio>
#include <algorithm>
struct UnionFind{
	vector<int> par,rank;
	void init(int n){
    par.resize(n);
    rank.resize(n,0);
		for(int i=0;i<n;i++){
			par[i] = i;
		}
	}
	int find(int x){
		if(par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x,int y){
		x = find(x);
		y = find(y);
		if(x==y)return;
		if(rank[x] < rank[y])par[x] = y;
		else{
			par[y] = x;
			if(rank[x] == rank[y])rank[x]++;
		}	
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
}uf;
int main(){
	return 0;
}
