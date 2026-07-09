/*
 * cmlsc.c
 *
 *  Created on: Jun 16, 2011
 *      Author: mihai
 */
#include <stdio.h>
#define MAX 1024
#define maxim(a, b) ((a > b) ? a : b)

int main() {

	int M, N, i, j, k = 0;
	int data[MAX][MAX], A[MAX], B[MAX], sir[MAX];

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &M, &N);

	for (i = 1; i <= M; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 1; i <= N; i++) {
		scanf("%d", &B[i]);
	}

	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++) {
			if (A[i] == B[j])
				data[i][j] = data[i - 1][j - 1] + 1;
			else
				data[i][j] = maxim(data[i-1][j],data[i][j-1]);
		}
	}

	for (i = M, j = N; i && j;) {

		if (A[i] == B[j])
			sir[++k] = A[i], i--, j--;
		else if (data[i - 1][j] < data[i][j - 1])
			j--;
		else
			i--;
	}

	printf("%d\n", k);
	for (i = k; i; i--) {
		printf("%d ", sir[i]);
	}
	return 0;
}
