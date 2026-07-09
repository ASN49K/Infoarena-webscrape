#include <stdio.h>
#include <stdlib.h>
#define maxim(a,b) ((a>b)?a:b)
#define FOR(i,a,b) for(i=a;i<=b;++i)
#define NMax 1024
int m,n,a[NMax],b[NMax],d[NMax][NMax],sir[NMax],bst=-1;
int main()
{
	int i,j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%i%i",&m,&n);
    FOR(i,0,m-1)
		scanf("%i",&a[i]);
	FOR(i,0,n-1)
			scanf("%i",&b[i]);
    FOR(i,0,m-1)
	   FOR(j,0,n-1)
	      if(a[i]==b[j])
			d[i][j]=1+d[i-1][j-1];
		  else
			d[i][j]=maxim(d[i-1][j],d[i][j-1]);
    for(i=m-1,j=n-1;i; )
	{
		if(a[i]==b[j])
		{
			sir[++bst]=a[i];
			--i;
			--j;
		}else if(d[i-1][j]<d[i][j-1])
		{
			--j;
		}else
		   --i;
	}
	printf("%i\n",bst+1);
	for(i=bst;i>=0;--i)
		printf("%i ",sir[i]);
    return 0;
}
