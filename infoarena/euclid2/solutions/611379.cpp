#include<cstdio>
using namespace std;

int T,a,b,cmmdc(int,int);

void read(),solve();

int main()
{
	read();
	solve();
	
	return 0;
}

void read()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&T);
}

void solve()
{
	for(;T--;)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
}

int cmmdc(int x,int y)
{
	while(1)
	{
		if(a>=b)a%=b;
		else b%=a;
		if(a==0)return b;
		if(b==0)return a;
	}
}
