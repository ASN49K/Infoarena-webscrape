#include <cstdio>
int a[1030],b[1030],n,m,max=0;
bool sol[1030],sir[1030];

int valid()
{
	int cnt=0,j=1;
	for (int i=1;i<=n;++i)
		if (sol[i])
			cnt++;
	for (int i=1;i<=n&&j<=m;++i)
		if (sol[i])
			for(;j<=n&&a[i]!=b[j];++j);
	if (j<=m)
		return cnt;
	return 0;
}

void back(int p)
{
	if (p==n+1)
	{
		int k=valid();
		if (k>max)
		{
			max=k;
			for (int i=1;i<=n;++i)
				sir[i]=sol[i];
		}
		return;
	}
	sol[p]=0;
	back(p+1);
	sol[p]=1;
	back(p+1);
}

int main()
{
	freopen ("cmlsc.in","r",stdin);
	freopen ("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=m;++i)
		scanf("%d",&b[i]);
	back(1);
	printf("%d\n",max);
	for (int i=1;i<=n;++i)
		if (sir[i])
			printf("%d ",a[i]);
	return 0;
}
