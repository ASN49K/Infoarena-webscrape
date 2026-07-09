#include<cstdio>
void read(),sol();
int t,n,val,s;
int main()
{
	read();
	return 0;
}
void read()
{
	int i;
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	scanf("%d", &t);
	for(i=1;i<=t;i++)
	{
		scanf("%d", &n);
		sol();
	}
}
void sol()
{
	int i,v;
	scanf("%d", &v);
	for(i=2;i<=n;i++)
	{
		scanf("%d", &val);
		v=v^val;
	}
	if(v)
		printf("DA\n");
	else
		printf("NU\n");
}