#include<cstdio>

using namespace std;
int n,x,y,aux;
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
		while(y)
		{
			aux=y;
			y=x%y;
			x=aux;
		}
		printf("%d\n",x);
	}
}
			