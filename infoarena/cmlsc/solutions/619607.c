#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a > b) ? a : b)
int main () {

freopen ("cmlsc.in", "r", stdin);
freopen ("cmlsc.out", "w", stdout);

int n, m;

scanf ("%d%d", &n, &m);

int a[n], b[m], i, j;

for (i = 0; i < n; i++)
	scanf ("%d", &a[i]);
for (j = 0; j < m; j++)
	scanf ("%d", &b[j]);

int** lcs = calloc (n + 1, sizeof (int));

for (i = 0; i < n + 1; i++)
	lcs[i] = calloc (m + 1, sizeof (int));

for (i = 1; i < n + 1; i++)
	for (j = 1; j < m + 1; j++)
		if (a[i - 1] == b[j - 1])
			lcs[i][j] = lcs[i - 1][j - 1] + 1;
		else
			lcs[i][j] = max (lcs[i - 1][j], lcs[i][j - 1]);
printf ("%d\n", lcs[n][m]); 
i--;
j--;
int sir [lcs [n][m]], k = 0;
while (lcs[i][j] != 0)
{
	if (a[i - 1] == b[j - 1])
	{
		sir[k++] = a[i-1];
		i--;
		j--;
	}
	else
		if (lcs[i-1][j] > lcs[i][j-1])
			i--;
		else
			j--;
}
for (i = lcs[n][m] - 1; i >= 0; i--)
	printf ("%d ", sir[i]);

return 0;
}
