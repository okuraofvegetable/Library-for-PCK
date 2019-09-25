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
const ll MOD = 1000000021ll;
struct ModInt{
	ll val;
	ModInt():val(0ll){}
	ModInt(ll v):val(((v%MOD)+MOD)%MOD){}
	ModInt exp(ll y)const{
		if(!y)return ModInt(1ll);
		ModInt a = exp(y/2ll);
		a *= a;
		if(y&1)a*=(*this);
		return a;
	}
	bool operator==(const ModInt& x)const{return val==x.val;}
	inline bool operator!=(const ModInt& x)const{return !(*this==x);}
	bool operator<(const ModInt& x)const{return val<x.val;}
	bool operator>(const ModInt& x)const{return val>x.val;}
	inline bool operator>=(const ModInt& x)const{return !(*this<x);}
	inline bool operator<=(const ModInt& x)const{return !(*this>x);}
	ModInt& operator+=(const ModInt& x){if((val+=x.val)>=MOD)val-=MOD;return *this;}
	ModInt& operator-=(const ModInt& x){if((val+=MOD-x.val)>=MOD)val-=MOD;return *this;}
	ModInt& operator*=(const ModInt& x){(val*=x.val)%=MOD;return *this;}
	ModInt operator+(const ModInt& x)const{return ModInt(*this)+=x;}
	ModInt operator-(const ModInt& x)const{return ModInt(*this)-=x;}
	ModInt operator*(const ModInt& x)const{return ModInt(*this)*=x;}
};
istream& operator>>(istream&i,ModInt&x){i>>x.val;return i;}
ostream& operator<<(ostream&o,const ModInt&x){o<<x.val;return o;}
ModInt pow(ModInt a,ll x){
	ModInt res = ModInt(1ll);
	while(x){
		if(x&1)res *= a;
		x >>= 1;
		a = a*a;
	}
	return res;
}
ModInt inverse(ModInt a){
  return pow(a,MOD-2ll);
}
ll rng(ll a,ll b){
  random_device seed_gen;
  default_random_engine engine(seed_gen());
  return uniform_int_distribution<ll>(a,b)(engine);
} 
struct RollingHash{
  const string s;
  vector<ModInt> hash_A,hash_B;
  vector<ModInt> rui_A,rui_B; 
  static ModInt A;
  static ModInt B;
  RollingHash(string str):s(str){
    construct();
  }
  void construct(){
    rui_A.resize(s.size());
    rui_B.resize(s.size());
    hash_A.resize(s.size());
    hash_B.resize(s.size());
    rui_A[0]=rui_B[0]=ModInt(1ll);
    for(int i=1;i<s.size();i++){
      rui_A[i]=rui_A[i-1]*A;
      rui_B[i]=rui_B[i-1]*B;
    }
    hash_A[0]=ModInt((int)s[0]);
    hash_B[0]=ModInt((int)s[0]);
    for(int i=1;i<s.size();i++){
      hash_A[i]=hash_A[i-1]+(ModInt((int)s[i])*rui_A[i]);
      hash_B[i]=hash_B[i-1]+(ModInt((int)s[i])*rui_B[i]);
    }
  }
  using Hash = pair<ModInt,ModInt>;
  Hash hash(int s,int t){
    Hash res;
    res.first = hash_A[t];
    if(s>0){
      res.first -= hash_A[s-1];
      res.first *= inverse(rui_A[s]);
    }
    res.sec = hash_B[t];
    if(s>0){
      res.sec -= hash_B[s-1];
      res.sec *= inverse(rui_B[s]);
    }
    return res;
  }
};
ModInt RollingHash::A = ModInt(rng(5ll,MOD-1ll));
ModInt RollingHash::B = ModInt(rng(5ll,MOD-1ll));
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
string s;
string t;
string S;
int main(){
  fastio();
  cin >> s;
  cin >> t;
  while(S.size()<s.size()+t.size())S += s;
  RollingHash sh(S);
  RollingHash th(t);
  auto tt = th.hash(0,t.size()-1);
  DirectedGraph G(s.size());
  for(int i=0;i<s.size();i++){
    auto h = sh.hash(i,i+t.size()-1);
    if(tt==h){
      G.add_edge(i,(i+t.size())%s.size());
    }
  }
  G.toposort();
  if(G.exist_loop()){
    cout << -1 << endl;
  }else{
    cout << G.longest_path() << endl;
  }
  return 0;
}
