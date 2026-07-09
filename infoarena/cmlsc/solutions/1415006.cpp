#include <stdio.h>

#define MAXLEN 1024

int a[MAXLEN], b[MAXLEN];
int c[MAXLEN + 1][MAXLEN + 1];

void reconstruct_path(int i, int j)
{
	if(c[i][j] == 0)
		return;

	if(c[i - 1][j] < c[i][j - 1])
		reconstruct_path(i, j - 1);
	else
	{
		if(c[i - 1][j] > c[i][j - 1])
			reconstruct_path(i - 1, j);
		else
		{
			if(c[i - 1][j - 1] + 1 == c[i][j])
			{
				reconstruct_path(i - 1, j - 1);
				printf("%d ", a[i - 1]);
			}
			else
				reconstruct_path(i, j - 1);
		}
	}
}

int main(void)
{
	int i, j, n, m;

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d%d", &n, &m);

	for(i = 0; i < n; i++)
		scanf("%d", a + i);
	for(i = 0; i < m; i++)
		scanf("%d", b + i);

	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
		{
			if(a[i - 1] == b[j - 1])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = c[i - 1][j] < c[i][j - 1] ? c[i][j - 1] : c[i - 1][j];
		}

	printf("%d\n", c[n][m]);

	reconstruct_path(n, m);

	return 0;
}
