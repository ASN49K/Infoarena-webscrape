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
		mat[i][0] = 0;
	}
	for (int i = 0; i <= n; i++)
		mat[0][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
			if (mm[i] == nn[j])
			{
				mat[i][j] += 1;;
			}
		}
	}
	int maxl = mat[m][n];
	int k = maxl;
	printf("%d\n", mat[m][n]);
	result = new int[maxl+1];
	
	for (i = m, j = n; maxl;)
	{
		if (mm[i] == nn[j])
		{
			result[maxl] = mm[i];
			maxl--;
		}
		if (mat[i - 1][j] == maxl)
			i--;
		else
			j--;
	}
	for (i = 1; i <= k; i++)
		printf("%d ", result[i]);
	delete[] result;
	delete[] mm;
	delete[] nn;
	return 0;
}



