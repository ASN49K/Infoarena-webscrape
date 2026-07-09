#include <stdio.h>
#define NMAX 1030

int a[NMAX], b[NMAX], x[NMAX][NMAX];
int n, m;

int inline MAX(int a, int b)
{ return a > b ? a:b;}


void reconstituie(int i, int j)
{
	if ( i >= 1 && j >= 1)
	{
		if ( a[i] == b[j])
		{
			reconstituie(i-1, j-1);
			printf("%d ", a[i]);
		}
		else
		   if ( x[i-1][j] > x[i][j-1])
			   reconstituie(i-1, j);
		   else
			   reconstituie(j, i-1);

	}

}

int main()
{
	int i, j;
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for ( i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for ( i = 1; i <= m; i++)
		scanf("%d", &b[i]);

	for ( i = 1; i <= n; i++)
	for ( j = 1; j <= m; j++)
		if ( a[i] == b[j])
		   x[i][j] = x[i-1][j-1] + 1;
		else
		   x[i][j] = MAX(x[i-1][j], x[i][j-1]);

	printf("%d\n", x[n][m]);
	reconstituie(n, m);
	printf("\n");

	return 0;
}

