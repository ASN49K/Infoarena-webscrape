#include<stdio.h>

int max(int a, int b, int c)
{
	if(a>b)
	{
		if(a>c)
			return a;

		return c;
	}
	if(b>c)
		return b;
	return c;
}

int main()
{
	int m,n;
	int mm[1025];
	int nn[1025];
	int a[1026][1026];
	int i,j;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d%d",&n,&m);
 
	for(i=0;i<n;i++)
	{
	scanf("%d",&nn[i]);
	a[i][0] = i;
	}

	a[i][0] = i;

	for(j=0;j<m;j++)
	{
	scanf("%d",&mm[j]);
	a[0][j] = j;
	}

    a[0][j] = j;
    
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	if(nn[i-1] == mm[j-1])
		a[i][j] = max(a[i][j-1]+1,a[i-1][j-1]+1,a[i-1][j]+1);
	else
		a[i][j] = max(a[i][j-1],a[i-1][j-1],a[i-1][j]);

	printf("%d",a[n][m]);
	return 0;	
}
