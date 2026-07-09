#include<stdio.h>
#define Nmax 1025


int m,n,a[Nmax],b[Nmax],x[Nmax][Nmax],c[Nmax];

int maxim(int p,int q)
{ 	return ((p>q)?p:q);
}

int main()
{	int i,j,nr;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%d",a+i);
	for (i=1;i<=m;i++)
		scanf("%d",b+i);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (a[i]==b[j]) x[i][j]=x[i-1][j-1]+1;
			else x[i][j]=maxim(x[i-1][j],x[i][j-1]);
	for (i=n,j=m,nr=0;j>0&&i>0;)
		if (a[i]==b[j]) c[++nr]=a[i],--i,--j;
		else if (x[i-1][j]>x[i][j-1]) --i;
			 else --j;
	printf("%d\n",x[n][m]);
	for (i=nr;i;i--)
		printf("%d ",c[i]);
	return 0;
}
