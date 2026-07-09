#include<cstdio>

using namespace std;

int c[1026][1026];

int max(int a, int b)
{
	if(a>b)
		return a;
	return b;
}

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	int n, m, i, j;
	int x[1026], y[1026];

	scanf("%d%d", &n, &m);

	for(i=1; i<=n; ++i)
		scanf("%d", &x[i]);
	for(j=1; j<=m; ++j)
		scanf("%d", &y[j]);

	for(i=1; i<=n; ++i)
		for(j=1; j<=m; ++j)
			if(x[i]==y[j])
				c[i][j] = c[i-1][j-1] +1;
			else
				c[i][j] = max(c[i-1][j], c[i][j-1]);

	printf("%d\n", c[n][m]);

	int sol[c[n][m] + 1];
	sol[0] = 0;
	i=n;
	j=m;

	for(int k=c[n][m]; k>0; --k)
	{
		while(x[i]!=y[j])
		{
			if(c[i][j]==c[i-1][j])
				--i;
			else
				--j;
		}
		if(i==0 || j==0)
			break;
		sol[k] = x[i];
		--i;
		--j;
	}

	for(i=1; i<=c[n][m]; ++i)
		printf("%d ", sol[i]);
	printf("\n");
	return 0;
}
