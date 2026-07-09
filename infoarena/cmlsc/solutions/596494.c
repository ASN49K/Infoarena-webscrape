/*
 * cmlsc.c
 *
 *  Created on: Jun 16, 2011
 *      Author: mihai
 */
#include <stdio.h>
#include <stdlib.h>

void print(int** reconstruct, int* A, int size1, int size2) {

	if (size1 == 0 || size2 == 0)
		return;
	if (reconstruct[size1][size2] == 5) {
		print(reconstruct, A, size1 - 1, size2 - 1);
		printf("%d ", A[size1]);
	} else if (reconstruct[size1][size2] == 1)
		print(reconstruct, A, size1 - 1, size2);
	else
		print(reconstruct, A, size1, size2 - 1);
}

int main() {

	int M, N, i, j;
	int ** data, *A, *B, **reconstruct;

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &M, &N);
	M++;
	N++;

	data = (int**) calloc(M, sizeof(int*));
	reconstruct = (int**) calloc(M, sizeof(int*));
	A = (int*) calloc(M, sizeof(int));
	B = (int*) calloc(M, sizeof(int));

	for (i = 0; i < M; i++) {
		data[i] = (int*) calloc(N, sizeof(int));
		reconstruct[i] = (int*) calloc(N, sizeof(int));
	}

	for (i = 1; i < M; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 1; i < N; i++) {
		scanf("%d", &B[i]);
	}

	for (i = 1; i < M; i++) {
		for (j = 1; j < N; j++) {
			if (A[i] == B[j]) {
				data[i][j] = data[i - 1][j - 1] + 1;
				reconstruct[i][j] = 5;//val
			} else if (data[i - 1][j] >= data[i][j - 1]) {
				data[i][j] = data[i - 1][j];
				reconstruct[i][j] = 1; // sus
			} else {
				data[i][j] = data[i][j - 1];
				reconstruct[i][j] = 2; //stanga

			}
		}
	}
	M--;
	N--;
	printf("%d\n", data[M][N]);
	print(reconstruct, A, M, N);

	return 0;

}
