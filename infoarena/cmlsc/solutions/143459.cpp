#include <stdio.h>
#define Nmax 1001

int a[Nmax], b[Nmax], i, j, n, m;
int c[Nmax][Nmax];

inline int max(int x, int y) { return x>y?x:y; }
void afis(int,int);

int main()
{
	freopen("cmlsc.in", "r", stdin);
	scanf("%d %d\n", &n, &m);
	for (i=1; i<=n; i++) scanf("%d ", &a[i]);
	for (i=1; i<=m; i++) scanf("%d ", &b[i]);
	fclose(stdin);
	for (i=1; i<=m; i++)
		if (a[1]==b[i]) c[i][1]=1; 
	for (i=1; i<=n; i++)
		if (a[i]==b[1]) c[1][i]=1; 
	for (i=2; i<=n; i++)
		for (j=2; j<=m; j++)
			if (a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=max(c[i-1][j],c[i][j-1]);
	freopen("cmlsc.out", "w", stdout);
	printf("%d\n", c[n][m]);
	afis(m,n);
	fclose(stdout);
	return 0;
}

void afis(int x, int y)
{
	if (!x || !y) return;
	if (a[x]==b[y])
	{
		afis(x-1,y-1);
		printf("%d ", a[x]);
	}
	else
	{
		if (c[x-1][y]>c[x][y-1]) afis(x-1,y);
		else afis(x,y-1);
	}
}