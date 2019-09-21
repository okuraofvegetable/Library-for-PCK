#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define dmp(x) cerr << __LINE__ << " " << #x << " " << x << endl;
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
template<class T,class U>
ostream& operator << (ostream& os,pair<T,U>& p){
	os << p.fi << ',' << p.sec; return os;
}
template<class T,class U>
istream& operator >> (istream& is,pair<T,U>& p){
	is >> p.fi >> p.sec; return is;
}
template<class T>
ostream& operator << (ostream &os,const vector<T> &vec){
	for(int i=0;i<vec.size();i++){
		os << vec[i];
		if(i+1<vec.size())os << ' ';
	}
	return os;
}
template<class T>
istream& operator >> (istream &is,vector<T>& vec){
	for(int i=0;i<vec.size();i++)is >> vec[i];
	return is;
}
void fastio(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
}
// verified ABC 090 D
// https://atcoder.jp/contests/arc090/submissions/7634267
struct WeightedUnionFind{
  vector<int> par;
  vector<int> rank;
  vector<int> diff;
  void init(int n){
    par.resize(n);
    for(int i=0;i<n;i++)par[i]=i;
    rank.resize(n,0);
    diff.resize(n);
  }
  int find(int x){
    if(par[x]==x)return x;
    else{
      int r = find(par[x]);
      diff[x] += diff[par[x]];
      return par[x] = r;
    }
  }
  int weight(int x){
    find(x);
    return diff[x];
  }
  int dist(int x,int y){ // x -> y
    assert(same(x,y));
    return weight(y)-weight(x);
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y,int w){ // set diff(x,y) = w
    w += weight(x);
    w -= weight(y);
    x = find(x);
    y = find(y);
    if(x==y)return;
    if(rank[x]<rank[y]){
      swap(x,y);
      w = -w;
    }
    if(rank[x]==rank[y])rank[x]++;
    par[y] = x;
    diff[y] = w;
    return;
  }
};
WeightedUnionFind uf;
int N,M;
int main(){
  cin >> N >> M;
  uf.init(N);
  for(int i=0;i<M;i++){
    int l,r,d;
    cin >> l >> r >> d;
    l--;r--;
    if(uf.same(l,r)){
      if(uf.dist(l,r)!=d){
        cout << "No" << endl;
        return 0;
      }
    }else{
      uf.unite(l,r,d);
    }
  }
  cout << "Yes" << endl;
	return 0;
}
