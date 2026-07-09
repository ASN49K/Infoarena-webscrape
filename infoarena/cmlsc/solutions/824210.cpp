#include <stdio.h>

#define max(a,b) ((a>b)? a:b)
#define MAX 1024

int main()
{
	int *a = new int[MAX];
	int *b = new int[MAX];
	int *c = new int[MAX];
	int **mat = new int*[MAX+1];

	int index, i,j, m,n;
	for (i=0; i<MAX; i++)
		mat[i] = new int[MAX+1];
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &m, &n);

	for (i=0; i<m; i++)
	{ scanf("%d", &a[i]); mat[i][0] = 0; }
	mat[m][0] = 0;

	for (i=0; i<n; i++)
	{ scanf("%d", &b[i]); mat[0][i] = 0;}
	mat[0][n] = 0;


	//for (i=0; i<m; i++)
	//	printf("%i ", a[i]);
	//printf("\n");
	//for (i=0; i<n; i++)
	//	printf("%i ", b[i]);
	//printf("\n");

	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
			if (a[i] == b[j])
				mat[i+1][j+1] = 1 + mat[i][j];
			else
				mat[i+1][j+1] = max(mat[i][j+1], mat[i+1][j]);

	//for (i=0; i<m+1; i++)
	//{
	//	for (j=0; j<n+1; j++)
	//		printf("%d ", mat[i][j]);
	//	printf("\n");
	//}

	for (i=m-1, j=n-1, index=0; i>=0;)
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

	printf("%d\n", index);
	for (i=index-1; i>=0; i--)
		printf("%d ", c[i]);

	return 0;
}