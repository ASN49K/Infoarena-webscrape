#include <stdio.h>

#define NMax 1024

int n, m, a[NMax], b[NMax], s[NMax][NMax], sol[NMax];

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			s[i][j] = s[i][j-1];
			if (s[i][j] < s[i-1][j])
				s[i][j] = s[i-1][j];

			if (a[i] == b[j])
			{
				if (s[i][j] < s[i-1][j-1] + 1)
					s[i][j] = s[i-1][j-1] + 1;
			}
		}
	}

	printf("%d\n", s[n][m]);

	int i = n, j = m, sl = 0;

	while (i != 0 && j != 0)
	{
		if (a[i] == b[j])
		{
			sol[sl++] = a[i];
			i--;
			j--;
		} else {
			if (s[i-1][j] > s[i][j-1])
				i--;
			else
				j--;
		}		
	}

	for (sl--; sl >= 0; sl--)
		printf("%d ", sol[sl]);

	printf("\n");
	
	return 0;
}