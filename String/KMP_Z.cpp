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
struct KMP{
  string s;
  // a[i] is maximum common length of
  // prefix and suffix of s[0...i-1]
  vector<int> a;
  KMP(string s):s(s){}
  void construct(){
    a.resize(s.size()+1);
    a[0] = -1;
    int j = -1;
    for(int i=0;i<s.size();i++){
      while(j>=0&&s[i]!=s[j])j=a[j];
      j++;
      a[i+1]=j;
    }
  }
};
struct Zarray{
  string s;
  vector<int> z;
  Zarray(string s):s(s){}
  void construct(){
    z.resize(s.size());
    z[0] = s.size();
    int i = 1, j = 0;
    while (i<s.size()){
      while (i+j<s.size() && s[j] == s[i+j])j++;
      z[i] = j;
      if(j==0){
        i++;
        continue;
      }
      int k = 1;
      while (i+k < s.size() && k+z[k] < j){
        z[i+k] = z[k];
        k++;
      }
      i += k;
      j -= k;
    }
  }
};
int main(){
  fastio();
  return 0;
}
