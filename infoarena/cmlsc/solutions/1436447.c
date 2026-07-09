#include <stdio.h>

#define FILE_IN "cmlsc.in"
#define FILE_OUT "cmlsc.out"
#define MAX_SIZE 1024

int max(int a, int b)
{
	return a >= b ? a : b;
}



int main() 
{
	freopen(FILE_IN,"r",stdin);
	freopen(FILE_OUT,"w",stdout);
	int m, n;
	int a[MAX_SIZE], b[MAX_SIZE];
	scanf("%d %d", &m, &n);
	int i, j;
	for (i = 0; i < m; i++)
	{
		scanf("%d", a+i);
	}
	for (i=0; i < n; i++)
	{
		scanf("%d", b+i);
	}	
	int mat[MAX_SIZE+1][MAX_SIZE+1];
	for (i = 0; i <= m; i++)
	{
		mat[i][0] = 0;
	}
	for (j = 0; j <= n; j++)
	{
		mat[0][j] = 0;
	}
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (a[i-1] == b[j-1])
				mat[i][j] = mat[i-1][j-1] + 1;
			else
				mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
		}
	}
	printf("%d\n", mat[m][n]);
	i = m;
	j = n;
	int rez[MAX_SIZE], k=0;
	while ( i>0 && j>0 )
	{
		if (a[i-1] == b[j-1])
		{
			rez[k++] = a[i-1];
			i--;
			j--;	
		}
		else if (mat[i-1][j] >= mat[i][j-1])
			i--;
		else
			j--;
	}
	while( k > 0)
	{
		printf("%d ", rez[--k]);
	}
	printf("\n");
	return 0;
}
