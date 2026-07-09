#include<cstdio>

using namespace std;
int n,x,y;
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
	scanf("%d",&n);
}
void solve()
{
	freopen("euclid2.out","w",stdout);
	for(;n;n--)
	{
		scanf("%d%d",&x,&y);
		if(x%y==0)
		{printf("%d\n",y);continue;}
		if(y%x==0)
		{printf("%d\n",x);continue;}
		if(x==2||y==2)
		{printf("1\n");continue;}
		while(x%y&&y%x)
			if(x>y)
				y=x%y;
			else
				x=y%x;
		if(x)
			printf("%d\n",x);
		else
			printf("%d\n",y);
	}
}
			