#include<stdio.h>
#define N 1030
int a[N],b[N],d[N][N],n,m,best,v[N];
inline int max(int x,int y)
{
        if(x>y)
                return x;
        return y;
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(i=1; i<=m; i++)
		scanf("%d",&b[i]);
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			if(a[i]==b[j])
				d[i][j]=d[i-1][j-1]+1;
			else
				d[i][j]=max(d[i-1][j],d[i][j-1]);
		}
	}
	for(i=n, j=m; i&&j; )
	{
		if(a[i]==b[j])
		{
			v[++best]=a[i];
			i--;
			j--;
		}
		else
		if(d[i-1][j]<d[i][j-1])
			j--;
		else
			i--;
	}
	printf("%d\n",d[n][m]);
	//printf("%d\n",best);
	for(i=best; i>0; i--)
			printf("%d ",v[i]);
	printf("\n");
	return 0;
}


