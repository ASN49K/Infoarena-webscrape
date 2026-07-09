#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define maxN 1030
#define PB push_back

int A[maxN], B[maxN];
int dp[maxN][maxN];
vector <int> sol;

int main()
{
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	
	int N, M;
	
	scanf ("%d %d", &N, &M);
	
	for (int i = 1; i <= N; ++ i) scanf ("%d", &A[i]);
	for (int i = 1; i <= M; ++ i) scanf ("%d", &B[i]);
	
	for (int i = 1; i <= N; ++ i)
		for (int j = 1; j <= M; ++ j)
			if (A[i] == B[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
		else dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
	
	for (int i = N, j = M; i && j; )
	{
		if (A[i] == B[j])
		{
			sol.PB (A[i]);
			i --, j --;
			continue;
		}
		
		if (dp[i][j - 1] > dp[i - 1][j])
		{
			j = j - 1;
			continue;
		}
		else i = i - 1;
	}
	
	printf ("%d\n", dp[N][M]);
	
	for (int i = sol.size() - 1; i >= 0; -- i) printf ("%d ", sol[i]);
	
	return 0;
}
