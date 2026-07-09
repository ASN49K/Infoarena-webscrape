#include <iostream>
#include <cstdio>

using namespace std;

int A[1025], B[1025], best[1025][1025], ans[1025], N, M;

int main()
{
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	
	scanf ("%d %d", &N, &M);
	
	for (int i = 1; i <= N; ++i) scanf ("%d", &A[i]);
	for (int i = 1; i <= M; ++i) scanf ("%d", &B[i]);
	
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if (A[i] == B[j]) best[i][j] = 1 + best[i-1][j-1];
			else best[i][j] = max(best[i-1][j], best[i][j-1]);

	printf ("%d\n", best[N][M]);		
			
	int i = N, j = M;
			
	while (i && j)
	{
		if (A[i] == B[j])
		{
			ans[++ans[0]] = A[i];
			--i;
			--j;
		}	
		else if (best[i][j] == best[i-1][j]) --i;
		else --j;
	}	
	
	for (int i = ans[0]; i >= 1; --i) printf ("%d ", ans[i]);
	
	return 0;
}