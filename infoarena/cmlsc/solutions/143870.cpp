#include <stdio.h>

#define NMAX 1024

short int n,m,i,j,a[NMAX],b[NMAX],d[NMAX][NMAX];
char r[NMAX][NMAX];
long int sol[NMAX];

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d %d",&n,&m);

	for (i=1;i<=n;i++) scanf("%ld",&a[i]);
	for (i=1;i<=m;i++) scanf("%ld",&b[i]);

	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (a[i]==b[j]) r[i][j]=0,d[i][j]=d[i-1][j-1]+1;
				else {
					if (d[i-1][j]>d[i][j-1]) d[i][j]=d[i-1][j],r[i][j]=1;
						else d[i][j]=d[i][j-1],r[i][j]=2;
				}

	printf("%ld\n",d[n][m]);
	
	for (i=n,j=m;i&&j;i--)
		if (r[i][j]==0) sol[ ++sol[0] ] = a[i],i--,j--;
			else if (r[i][j]==1) i--;
				else j--;
				
	for (i=sol[0];i;i--) printf("%ld ",sol[i]);
	return 0;
}
