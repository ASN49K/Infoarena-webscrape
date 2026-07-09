#include <stdio.h>
#include <stdlib.h>

#define MAX_N 15
#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"

int A[MAX_N];
int B[MAX_N];

short O[MAX_N][MAX_N];
int S[MAX_N];
int N, M, i;
int L;

	inline int MAX (int a, int b)
	{
		if (a > b) return a; else return b;
	}

	void build (int n, int m, int l)
	{
	   int i, j;
	   for (i = n; i; --i)
		for (j = m; j; --j)
		{
			if (O[i][j] == O[i - 1][j - 1] + 1 && O[i - 1][j] == O[i][j - 1] == O[i - 1][j - 1] == 0)
			{
				int k;
                printf ("%d\n%d ", L, A[i]);
				for (k = 2; k <= L; ++k)
					printf ("%d ", S[k]);
				exit (0);
                        }
			if (O[i][j] == O[i - 1][j - 1] + 1)
			{
				S[l] = A[i];
				build (i - 1, j - 1, l - 1);
			}
		}
	}

	void solve ()
	{
		int i, j;
		for (i = 1; i <= N; ++i)
		    for (j = 1; j <= M; ++j)
			if (A[i] == B[j])
				O[i][j] = O[i - 1][j - 1] + 1;
			else O[i][j] = MAX (O[i - 1][j], O[i][j - 1]);
		L = O[N][M];
		build (N, M, L);
	}

	int main ()
	{
		freopen (FIN, "r", stdin);
		freopen (FOUT, "w", stdout);

		scanf ("%d %d", &N, &M);
		for (i = 1; i <= N; ++i) scanf ("%d", A + i);
		for (i = 1; i <= M; ++i) scanf ("%d", B + i);

		solve ();
                return 0;
	}
