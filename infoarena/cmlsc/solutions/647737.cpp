#include<stdio.h>
# define infile "cmlsc.in"
# define outfile "cmlsc.out"
#define Nmax 1025

long a[Nmax],b[Nmax],d[Nmax][Nmax],sir[Nmax];
long n,m,best;

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int main()
{
	int i,j;
	freopen (infile,"r",stdin);
	scanf("%ld%ld",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%ld",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%ld",&b[i]);
	fclose(stdin);
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				d[i][j]=1+d[i-1][j-1];
			else
				d[i][j]=max(d[i-1][j],d[i][j-1]);
			
	for(i=n, j=m; i; )
		if( a[i]==b[j])
		{
			sir[++best]=a[i];
			i--;j--;
		}
		else if(d[i-1][j] < d[i][j-1])
			j--;
		else
			i--;
	
	freopen(outfile,"w",stdout);
	printf("%ld\n",best);
	for(i=best;i;i--)
		printf("%ld ",sir[i]);
	fclose(stdout);
	
	return 0;
}
