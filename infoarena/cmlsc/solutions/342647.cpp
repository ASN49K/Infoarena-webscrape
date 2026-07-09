//Problema cel mai lung subsir comun - Infoarena

#include<stdio.h>

#define max(a,b) ((a>b)?a:b);

int m,n,i,j,a[1024],b[1024],d[1024][1024],sir[1024],k;

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d %d",&m,&n);

	for(i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);

	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(a[i]==b[j])
				d[i][j]=1+d[i-1][j-1];
			else
				d[i][j]=max(d[i-1][j],d[i][j-1]);
		}

	i=m;
	j=n;

	k=1;

	while(i)
	{
		if(a[i]==b[j])
		{
			sir[k]=a[i];
			k++;
			i--;
			j--;
		}
		else
		{
			if(d[i-1][j]<d[i][j-1])
				j--;
			else
				i--;
		}
	}

	printf("%d\n",k-1);

	for(i=k-1;i>=1;i--)
		printf("%d ",sir[i]);

	return 0;
}