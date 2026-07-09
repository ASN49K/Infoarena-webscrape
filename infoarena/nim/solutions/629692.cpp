#include<cstdio>
using namespace std;

int n,k,x,xorsum;

void read(),solve();

int main()
{
	read();
	solve();
	
	return 0;
}

void read()
{
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	scanf("%d",&n);
}

void solve()
{
	for(;n--;)
	{
		scanf("%d",&k);
		xorsum=0;
		for(;k--;)
		{
			scanf("%d",&x);
			xorsum=xorsum^x;
		}
		if(xorsum)printf("DA\n");
		else      printf("NU\n");
	}
}
