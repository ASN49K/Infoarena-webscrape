// cel mai lung subsir comun.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 1024
int M, N, size;
int A[MAX_SIZE + 3], B[MAX_SIZE + 3], sol[MAX_SIZE + 3];
int DP[MAX_SIZE + 3][MAX_SIZE + 3];

inline int _max(int a, int b)
{
	return (a > b ? a : b);
}

void readData()
{
	freopen("cmlsc.in", "r", stdin);

	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
	for (int j = 1; j <= M; ++j)
		scanf("%d", &B[j]);

	fclose(stdin);
}

void CMLSC ()
{
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
		{
			if (A[i] == B[j])
				DP[i][j] = 1 + DP[i - 1][j - 1];
			else DP[i][j] = _max(DP[i - 1][j], DP[i][j - 1]);
		}
}

void print()
{
	int i = N, j = M;
	while (i)
	{
		if (A[i] == B[j])
		{
			sol[++size] = A[i];
			--i;
			--j;
		}
		else if (DP[i - 1][j] > DP[i][j - 1])
		{
			--i;
		}
		else
		{
			--j;
		}
	}



	freopen("cmlsc.out", "w", stdout);

	printf("%d\n", size);
	for (int i = size; i; --i)
	{
		printf("%d ", sol[i]);
	}
	printf("\n");


	fclose(stdout);
}

int main()
{
	readData();
	CMLSC();
	print();
	return 0;
		
}

