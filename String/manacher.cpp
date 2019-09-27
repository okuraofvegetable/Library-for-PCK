#include <bits/stdc++.h>
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
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
vector<int> Manacher(const string &_s){
  //return longest palindrome's length.
	int n=_s.size();
	string s(2*n+1,'$');
	for(int i=0;i<n;i++)s[2*i+1]=_s[i];
	n=2*n+1;
	vector<int> rad(n);
  int i = 0, j = 0;
	while(i<n){
		while(i-j>=0&&i+j<n&&s[i-j]==s[i+j])j++;
		rad[i]=j;
		int k;
		for(k=1;i-k>=0&&rad[i-k]<rad[i]-k;k++)rad[i+k]=rad[i-k];
		i+=k;
		j=max(j-k,0);
	}
	return rad;
}
int main(){
	string s;
	cin >> s;
	cout << Manacher(s) << endl;
	return 0;
}
