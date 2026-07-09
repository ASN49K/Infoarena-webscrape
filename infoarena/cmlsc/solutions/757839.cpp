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

int mm[1025];
int nn[1025];
int a[1026][1026];

int main()
{
	int m,n;
	
	int i,j;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d%d",&n,&m);
 
	for(i=0;i<n;i++)
	scanf("%d",&nn[i]);

	for(j=0;j<m;j++)
	scanf("%d",&mm[j]);
    
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	if(nn[i-1] == mm[j-1])
		a[i][j] = max(a[i][j-1],a[i-1][j-1]+1,a[i-1][j]);
	else
		a[i][j] = max(a[i][j-1],a[i-1][j-1],a[i-1][j]);

	printf("%d\n",a[n][m]);

	i=0;
	while( a[n][m] )
	{
		if(a[n][m] == a[n-1][m])
			n--;
		else if(a[n][m] == a[n][m-1])
			m--;
		else if(a[n][m] == a[n-1][m-1]+1)
			{n--;m--;nn[i++] = mm[m];}
		else{n--;m--;}
	}

	for(i--;i>0;i--)
		printf("%d ",nn[i]);
	printf("%d\n",nn[0]);
	return 0;	
}
