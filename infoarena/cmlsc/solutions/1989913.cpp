#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;

#define nMax 1024

int M, N, A[nMax], B[nMax], D[nMax][nMax], sir[nMax], bst;

int maxim(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &M, &N);
	int i, j;

	for (i = 1; i <= M; ++i) {
		scanf("%d", &A[i]);
	}

	for (i = 1; i <= N; ++i) {
		scanf("%d", &B[i]);
	}

	for (i = 1; i <= M; ++i)
		for (j = 1; j <= N; ++j) {
			if (A[i] == B[j])
				D[i][j] = 1 + D[i - 1][j - 1];
			else
				D[i][j] = maxim(D[i - 1][j], D[i][j - 1]);
		}


	for (i = M, j = N; i; )
		if (A[i] == B[j]) {
			sir[++bst] = A[i];
			--i;
			--j;
		}
		else if (D[i - 1][j] < D[i][j - 1])
			--j;
		else
			--i;

		printf("%d\n", bst);
		for (i = bst; i; --i)
			printf("%d ", sir[i]);

	system("Pause");
	return 0;
}