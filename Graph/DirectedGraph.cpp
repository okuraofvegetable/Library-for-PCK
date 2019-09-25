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
template<class T>
using MaxHeap = priority_queue<T>;
template<class T>
using MinHeap = priority_queue<T,vector<T>,greater<T> >;
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
// verified ABC135F https://atcoder.jp/contests/abc135/submissions/7692789
struct DirectedGraph{
  struct edge{
    int to;
    ll cost;
    edge(){}
    edge(int to,ll cost):to(to),cost(cost){}
  };
  int N;
  vector<vector<edge> > g;
  vector<bool> used;
  vector<int> topo;
  vector<int> rev;
  bool sorted = false;
  DirectedGraph(int N):N(N){
    g.resize(N);
  }
  void add_edge(int s,int t,ll cost = 1ll){
    g[s].pb(edge(t,cost));
  }
  void dfs(int v){
    used[v] = true;
    for(int i=0;i<g[v].size();i++){
      int u = g[v][i].to;
      if(used[u])continue;
      dfs(u);
    }
    topo.pb(v);
  }
  void toposort(){
    used.resize(N,false);
    for(int i=0;i<N;i++){
      if(!used[i])dfs(i);
    }
    reverse(all(topo));
    rev.resize(N);
    for(int i=0;i<N;i++){
      rev[topo[i]] = i;
    }
    sorted = true;
  }
  bool exist_loop(){
    assert(sorted);
    for(int i=0;i<N;i++){
      for(int j=0;j<g[i].size();j++){
       int s = i, t = g[i][j].to;
       if(rev[s]>=rev[t])return true;
      }
    }
    return false;
  } 
  ll longest_path(){
    assert(sorted);
    vector<ll> dp(N,0ll);
    ll len = 0ll;
    for(int i=0;i<N;i++){
      int s = topo[i];
      for(int j=0;j<g[s].size();j++){
        edge e = g[s][j];
        chmax(dp[e.to],dp[s]+e.cost);
      }
      chmax(len,dp[s]);
    }
    return len;
  }
};
int main(){
  fastio();
  return 0;
}
