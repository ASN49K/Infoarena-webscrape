#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, A[1025], B[1025], d[1025][1025], s[1025];

int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}	
	for (int i = 1; i <= M; ++i) {
		scanf("%d", &B[i]);
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (A[i] == B[j]) {
				d[i][j] = d[i-1][j-1] + 1;
			} else {
				d[i][j] = max( d[i][j-1], d[i-1][j] );
			}
		}
	}

	for (int i = N, j = M; i; ) {
		if (A[i] == B[j]) {
			s[++s[0]] = A[i];
			--i;
			--j;
		} else if (d[i-1][j] < d[i][j-1]) {
			--j;
		} else {
			--i;
		}
	}

	printf("%d\n", s[0]);
	for (int i = s[0]; i > 0; --i) {
		printf("%d ", s[i]);
	}
	printf("\n");

	return 0;
}
