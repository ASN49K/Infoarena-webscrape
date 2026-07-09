#include<cstdio>
int a[100001];
int b[100001];
int c[100001];
{

	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int n,m,i,k=0,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;i++)
			if(a[i]==b[j])
				c[++k]=a[i];
	printf("%d\n",k);
	for(i=1;i<=k;i++)
		printf("%d ",c[i]);
	return 0;
}