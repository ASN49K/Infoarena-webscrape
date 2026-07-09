#include <cstdio>
#include <algorithm>

using namespace std;

const int NMAX = 1030;

int N, M;
int A[NMAX], B[NMAX], R[NMAX];
int D[NMAX][NMAX];

int main(void) {
	freopen("cmlsc.in", "rt", stdin);
//	freopen("cmlsc.out", "wt", stdout);
	int i, j;

	scanf(" %d %d", &N, &M);

	for (i = 1; i <= N; ++i)
		scanf(" %d", A + i);
	for (i = 1; i <= M; ++i)
		scanf(" %d", B + i);
	
	for (i = 1; i <= N; ++i)
		for (j = 1; j <= M; ++j)
			if (A[i] == B[j])
				D[i][j] = D[i-1][j-1] + 1;
			else
				D[i][j] = max(D[i-1][j], D[i][j-1]);
	
	i = N; j = M;
	while (D[i][j] > 0) {
		if (A[i] == B[j]) {
			R[D[i][j]] = A[i]; 
			--i; --j;
		} else {
			if (D[i][j] == D[i-1][j]) 
				--i;
			else 
				--j;
		}
	}
	
	printf("%d\n", D[N][M]);
	for (i = 1; i <= D[N][M]; ++i)
		printf("%d ", R[i]);
	printf("\n");

	return 0;
}
