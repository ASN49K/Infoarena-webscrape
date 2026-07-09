#include <stdio.h>

#define nmax 105

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int n,m,a[nmax],b[nmax],c[nmax][nmax],sir[nmax],bst;

int main()
{
	int i,j;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d%d",&m,&n);
	for(i=1;i<=m;++i)
		scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
		scanf("%d",&b[i]);

	for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
			if(a[i]==b[j])
				c[i][j]=1+c[i-1][j-1];
			else
				c[i][j]=max(c[i-1][j],c[i][j-1]);

	for(i=m, j=n; i;)
		if(a[i]==b[j])
			{
				sir[++bst]=a[i];
				--i;
				--j;
			}
		else
			if(c[i-1][j]<c[i][j-1])
				--j;
			else
				--i;

	printf("%d\n",bst);
	for(i=bst;i>0;--i)
		printf("%d ",sir[i]);

	return 0;
}