#include<stdio.h>
#define dim 1025

int n,m,i,j,a[dim],b[dim],c[dim][dim],x[dim],k;

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d%d",&n,&m);

	for(i=1; i<=n; ++i)

		scanf("%d",&a[i]);

	for(j=1; j<=m; ++j)

		scanf("%d",&b[j]);

	for(i=1; i<=n; ++i)

		for(j=1; j<=m; ++j)
		{
			if(a[i]==b[j])

				c[i][j]=c[i-1][j-1]+1;

			else
			{
				if(c[i-1][j]>c[i][j-1])

					c[i][j]=c[i-1][j];

				else

					c[i][j]=c[i][j-1];

			}
		}
    printf("%d\n",c[n][m]);
	for(i=n; i; --i)

		for(j=m; j; --j)

			if(a[i]==b[j])

				x[++k]=a[i];

	for(i=k; i; --i)

    	printf("%d ",x[i]);







	return 0;
}
