#include <iostream>

using namespace std;

#define NM 1030

int N, M, A[NM], B[NM];
int LCS[NM][NM], sol[NM], dim;

void get_sol(int i, int j)
{
	if (!i || !j) return ;
	
	if (LCS[i][j] == LCS[i-1][j-1] + 1)
	{
		sol[++dim] = A[i];
		get_sol(i-1, j-1);
	}	
	else 
		if (LCS[i][j] == LCS[i-1][j]) get_sol(i-1, j);
		else get_sol(i, j-1);   
}

int main()
{
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	
	scanf ("%d %d", &N, &M);
	
	for (int i = 1; i <= N; ++i) scanf ("%d ", &A[i]);
	for (int i = 1; i <= M; ++i) scanf ("%d ", &B[i]);
	
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
		{
			if (A[i] == B[j]) LCS[i][j] = LCS[i-1][j-1] + 1;
			
			int kk = max (LCS[i-1][j], LCS[i][j-1]);
			LCS[i][j] = max (LCS[i][j], kk);
		}	
			
	get_sol(N, M);
	
	printf ("%d\n", LCS[N][M]);
	
	for (int i = dim; i >= 1; --i) printf ("%d ", sol[i]);
		
	return 0;
}