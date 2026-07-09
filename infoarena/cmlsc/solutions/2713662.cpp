// infoarena.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>

int max(int a, int b)
{
	return a >= b ? a : b;
}

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	int m, n, *mm, *nn, *result, **mat,i,j;
	scanf("%d %d", &m, &n);
	mm = new int[m+1];
	nn = new int[n+1];
	for (int i = 1; i <=m; i++)
	{
		scanf("%d", &mm[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &nn[i]);
	}
	mat = new int*[m+1];
	for (int i = 0; i <= m; i++)
	{
		mat[i] = new int[n+1];
	}
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
			{
				mat[i][j] = 0;
				//printf("%d ",mat[i][j]);

				continue;
			}
			if (mm[i] == nn[j])
			{
				mat[i][j] = mat[i-1][j-1] + 1;
			}
			else
				mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
			//printf("%d ",mat[i][j]);
		}
		//printf("\n");
	}
	int maxl = mat[m][n];
	int k = maxl;
	printf("%d\n", mat[m][n]);
	result = new int[maxl+1];
	
	for (i = m, j = n; maxl;)
	{
		if (mat[i - 1][j] == maxl)
		{
			i--;
			continue;
		}
		if (mat[i][j-1] == maxl)
		{
			j--;
			continue;
		}
		result[maxl] = mm[i];
		i--; j--; maxl--;
	}
	for (i = 1; i <= k; i++)
		printf("%d ", result[i]);
	for (i = 0; i < m; i++)
		delete[] mat[i];
	delete[] mat;
	delete[] result;
	delete[] mm;
	delete[] nn;
	return 0;
}



