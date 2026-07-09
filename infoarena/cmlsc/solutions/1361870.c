#include <stdio.h>


#define MAX(a, b) ((a > b))? a : b

void afisare(int *a, int *b, int i, int j)
{
	if ( i < 0 || j < 0 || a[i] != b[j])
		return;
	afisare(a, b, i-1, j - 1);
	printf("%d ", a[i]);
}

int main(void)
{
	FILE *f_in = freopen("cmlsc.in", "rt", stdin);
	FILE *f_out = freopen("cmlsc.out", "wt", stdout);

	int m, n;
	scanf("%d %d\n", &m, &n);
	
	int c[m + 1][n + 1];
	int a[m], b[n];
	int index1, index2;

	int i, j;

	for (i = 0; i < m; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < n; i++)
		scanf("%d", &b[i]); 		
	
	for (i = 0; i <= m; ++i)
		c[i][0] = 0;
	
	for (i = 0; i <= n; ++i)
		c[0][i] = 0;

	for (i = 1; i  <= m; i++)
		for (j = 1; j <= n; j++) {
			if (a[i-1] == b[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
				}
			else
				c[i][j] = MAX(c[i-1][j], c[i][j-1]);
		}
	int s[MAX(n,m)];	
	int numb = 0;

/*	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}
*/

	for (i = m, j = n; i && j; )
		if (a[i-1] == b[j - 1]) {
			s[numb++] = a[i-1];
			i--; j--;
		}
		
		else if (c[i - 1][j] < c[i][j - 1])
			j--;
		else
			i--;

	printf("%d\n", numb);	
	for (i = numb - 1; i != -1; i--)
		printf("%d ", s[i]);

}
