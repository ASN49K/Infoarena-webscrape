#include <cstdio>

const int N=1<<8;

bool fr1[N],fr2[N];

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int m,n,x,i;
	scanf("%d%d",&m,&n);
	for (i=1;i<=m;i++)
	{
		scanf("%d",&x);
		fr1[x]=true;
	}
	int nr=0;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (fr1[x])
		{
			nr++;
			fr2[x]=true;
		}
	}
	printf("%d\n",nr);
	for (i=0;i<=256;i++)
		if (fr1[i] && fr2[i])
			printf("%d ",i);
	return 0;
}
