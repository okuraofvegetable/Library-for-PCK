#include <cstdio>
using namespace std;
typedef long long ll;
#define MAX_N 1000
#define MAX_M 1000
int N,M,Q;
struct BIT
{
	ll bit[MAX_N+1];
	void add(int i,ll x)
	{
		while(i<=N)
		{
			bit[i]+=x;
			i+=i&-i;
		}
		return;
	}
	ll sum(int i)
	{
		ll res=0;
		while(i>0)
		{
			res+=bit[i];
			i-=i&-i;
		}
		return res;
	}
};
BIT bits[MAX_M+1];
void Add(int i,int j,ll x)
{
	while(i<=M)
	{
		bits[i].add(j,x);
		i+=i&-i;
	}
	return;
}
ll Sum(int i,int j)
{
	ll res=0;
	while(i>0)
	{
		res+=bits[i].sum(j);
		i-=i&-i;
	}
	return res;
}
int main()
{
	scanf("%d %d %d",&N,&M,&Q);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			ll x;
			scanf("%lld",&x);
			Add(i,j,x);
		}
	}
	for(int i=0;i<Q;i++)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			int x,y;
			ll a;
			scanf("%d %d %lld",&x,&y,&a);
			ll n=Sum(x,y)-Sum(x-1,y)-Sum(x,y-1)+Sum(x-1,y-1);
			a-=n;
			Add(x,y,a);
		}
		else
		{
			int x1,y1,x2,y2;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			printf("%lld\n",Sum(x2,y2)-Sum(x2,y1-1)-Sum(x1-1,y2)+Sum(x1-1,y1-1));
		}
	}
	return 0;
}
