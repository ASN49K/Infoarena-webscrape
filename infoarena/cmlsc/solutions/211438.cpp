#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1025

int N, M;
int sol[MAXN];
int A[MAXN], B[MAXN];
int d[MAXN][MAXN];

int main (){
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	
	int i, j;
	for (scanf("%d %d", &N, &M), i = 1; i <= N; ++ i)
		scanf ("%d ", A + i);
	for (i = 1; i <= M; ++ i) scanf ("%d ", B + i);

	for (i = 1; i <= N; ++ i)
		for (j = 1; j <= M; ++ j)
			if (A[i] == B[j]) d[i][j] = 1 + d[i-1][j-1];
   			else d[i][j] = max (d[i-1][j], d[i][j-1]);
	
	/*for (i = 1; i <= N; ++ i, printf ("\n"))
		for (j = 1; j <= M; ++ j) printf ("%d ", d[i][j]);*/
	
	int cnt = 0;
	for (i = N, j = M; i && j;)
		if (A[i] == B[j]) sol[++cnt] = A[i], --i, --j;
		else 
			if (d[i-1][j] >= d[i][j-1]) --i;
			else --j;

	printf ("%d\n", d[N][M]);
	for (; cnt; --cnt)
		printf ("%d ", sol[cnt]);
	     	
	return 0;
}

