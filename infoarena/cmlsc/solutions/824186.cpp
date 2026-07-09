#include <stdio.h>

#define max(a,b) ((a>b)? a:b)
#define MAX 1024


int main()
{
	int a[MAX], b[MAX], c[MAX], mat[MAX+1][MAX+1], index, i,j, m,n;
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%i %i\n", &m, &n);
	for (i=0; i<m; i++)
		scanf("%i", &a[i]);
	for (i=0; i<n; i++)
		scanf("%i", &b[i]);

	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
			if (a[i] == b[j])
				mat[i+1][j+1] = 1 + mat[i][j];
			else
				mat[i+1][j+1] = max(mat[i][j+1], mat[i+1][j]);

	for (i=m-1, j=n-1, index=0; i>0;)
		if (a[i] == b[j])
		{
			c[index++] = a[i];
			i--;
			j--;
		}
		else if (mat[i+1][j] > mat[i][j+1])
			j--;
		else
			i--;

	printf("%i\n", index);
	for (i=index-1; i>=0; i--)
		printf("%i ", c[i]);

	return 0;
}