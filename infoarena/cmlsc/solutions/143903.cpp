#include <stdio.h>
long i,j,h,n,m;
long a[1034],b[1034],v[1034];
int mt[1034][1034];

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%ld %ld",&m,&n);
	for (i=1; i<=m; i++)
		scanf("%ld",&a[i]);
	for (i=1; i<=n; i++)
		scanf("%ld",&b[i]);
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
		{
			if (a[i]!=b[j])
			{
				mt[i][j]=mt[i-1][j];
				if (mt[i][j]<mt[i][j-1])
					mt[i][j]=mt[i][j-1];
			}
			else mt[i][j]=mt[i-1][j-1]+1;
		}
	i=m;
	j=n;
	while (i>0 && j>0)
	{
		if (a[i]==b[j])
		{
			h++;
			v[h]=a[i];
			i--;
			j--;
		}
		else if (mt[i-1][j]==mt[i][j])
				i--;
			 else j--;
	}
	printf("%ld\n",h);
	for (i=h; i>1; i--)
		printf("%ld ",v[i]);
	if (h>1)
		printf("%ld\n",v[1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
