#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){

	FILE *input = fopen("cmlsc.in", "r");
	FILE *output = fopen("cmlsc.out", "w");

	int m=0, n=0;
	fscanf(input, "%d %d", &m, &n);

	int *v1 = (int*)malloc(m*sizeof(int));
	int *v2 = (int*)malloc(n*sizeof(int));
	for (int i = 0; i < m; i++)
	{
		fscanf(input, "%d", &v1[i]);
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(input, "%d", &v2[i]);
	}

	int **C = (int**)malloc(n*sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		C[i] = (int*)malloc(m*sizeof(int));
	}
	for (int i = 0; i < m; i++)
	{
		C[i][0] = 0;
	}
	for (int j = 0; j < n; j++)
	{
		C[0][j] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			
			if (v1[i] == v2[j])
			{
				C[i][j] = C[i - 1][j - 1] + 1;
			}
			else{
				C[i][j] = max(C[i][j - 1], C[i - 1][j]);
			}
		}
	}
	//print  out the nr of the longest common subseq
	fprintf(output, "%d\n", C[m-1][n-1]);
	//print out the subsequence
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (C[i][j - 1] != C[i][j] && C[i - 1][j] != C[i][j])
			{
				fprintf(output, "%d ", v1[j]);
			}
		}
	}

	return 0;
}