#include <cstdio>
using namespace std;
int max(int a, int b)
{
	if (a>b)
		return a;
	return b;
}
int v1[1027],v2[1027],sol[1027],k;
int best[1027][1027];
int main()
{
	int m,n,i,y;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d\n",&m,&n);
	for (i=1;i<m;++i)
		scanf("%d ",&v1[i]);
	scanf("%d\n",&v1[m]);
	for (i=1;i<n;++i)
		scanf("%d ",&v2[i]);
	scanf("%d",&v2[n]);
	for (i=1;i<=n;++i)
		for (y=1;y<=m;++y)
			if (v1[y]==v2[i])
				best[y][i]=best[y-1][i-1]+1;
			else
				best[y][i]=max(best[y-1][i],best[y][i-1]);
	for (y=n,i=m;i && y;)
		if (v1[i]==v2[y])
			{sol[++k]=i;--i;--y;}
		else
			if (best[i-1][y]>best[i][y-1])
				--i;
			else
				--y;
	printf("%d\n",best[m][n]);
	for (i=1026;i;--i)
		if (sol[i])
			printf("%d ",v1[sol[i]]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
