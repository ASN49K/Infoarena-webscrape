#include<stdio.h>
const int N=1025;
int a[N][N];
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int m,n,i,j;
	int x[N],y[N],s[N],l=0;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;++i)
		scanf("%d",&x[i]);
	for(i=1;i<=n;++i)
		scanf("%d",&y[i]);
	for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
		{
			if(x[i]==y[j])
				a[i][j]=a[i-1][j-1]+1;
			else
				a[i][j]=a[i-1][j]>a[i][j-1]?a[i-1][j]:a[i][j-1];
		}
	for(i=m, j=n; i;)
	{
		if(x[i]==y[j])
			s[++l]=x[i], --i, --j;
		else
			if(a[i-1][j]<a[i][j-1])
				--j;
			else
				--i;
	}
	printf("%d\n",l);
	for(i=l; i; --i)
		printf("%d ",s[i]);
	return 0;
}
