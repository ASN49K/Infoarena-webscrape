#include<cstdio>
#include<malloc.h>

#define max(a, b) (a > b ? a : b)

using namespace std;

void printLongestCommonSequence(int, int, int *, int **);

int main()
{
	int n, m;
	int *a, *b;
	int **mat;

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	//read data and allocate memory
	scanf("%d%d", &n, &m);

	a = new int[n + 1];
	b = new int[m + 1];
	mat = (int **)calloc(n, sizeof(int*));
	for(int i = 0; i <= n; i++)
		mat[i] = (int *)calloc(m + 1, sizeof(int));

	for(int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for(int i = 1; i <= m; i++)
		scanf("%d", b + i);

	//computing result
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i] == b[j])
				mat[i][j] = mat[i - 1][j - 1] + 1;
			else
				mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);

	//printing result
	printf("%d\n", mat[n][m]);
	printLongestCommonSequence(n, m, a, mat);
	puts("");

	return 0;
}

void printLongestCommonSequence(int i, int j, int *a, int **mat)
{
	if(i > 0 && j > 0)
	{
		if(mat[i - 1][j] > mat[i][j - 1] && mat[i - 1][j] > mat[i - 1][j - 1])
		{
			printLongestCommonSequence(i - 1, j, a, mat);
			return;
		}
		if(mat[i][j - 1] > mat[i - 1][j] && mat[i][j - 1] > mat[i - 1][j - 1])
		{
			printLongestCommonSequence(i, j - 1, a, mat);
			return;
		}
		printLongestCommonSequence(i - 1, j - 1, a, mat);
		if(mat[i - 1][j - 1] == mat[i][j] - 1)
			printf("%d ", a[i]);
	}
}
