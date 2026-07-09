// Longest_Common_substring.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#define maxn 1029

int Dp[maxn][maxn], A[maxn], B[maxn], Ans[maxn];

void Read_data(int *n, int *m) {
	FILE *fin = fopen("cmlsc.in", "r");
	int i;
	fscanf(fin, "%d %d", &(*n), &(*m));
	for (i = 1; i <= *n; i++) {
		fscanf(fin, "%d", &A[i]);
	}
	for (i = 1; i <= *m; i++) {
		fscanf(fin, "%d", &B[i]);
	}
	fclose(fin);
}

int Maxim(int x, int y) {
	return x > y ? x : y;
}

void LCS(int n, int m, int *size) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (A[i] == B[j]) {
				Dp[i][j] = Dp[i - 1][j - 1] + 1;
			} else {
				Dp[i][j] = Maxim(Dp[i - 1][j], Dp[i][j - 1]);
			}
		}
	}
	i = n;
	j = m;
	while (i > 0 && j > 0) {
		if (A[i] == B[j]) {
			Ans[(*size)++] = A[i];
			i--;
			j--;
		} else if (Dp[i - 1][j] > Dp[i][j - 1]) {
			i--;
		} else {
			j--;
		}
	}
}

void Print(int size) {
	FILE *fout = fopen("cmlsc.out", "w");
	fprintf(fout, "%d \n", size);
	int i;
	for (i = size - 1; i >= 0; i--) {
		fprintf(fout, "%d ", Ans[i]);
	}
	fprintf(fout, "\n");
	fclose(fout);
}

int main() {
	int n, m, size = 0;
	Read_data(&n, &m);
	LCS(n, m, &size);
	Print(size);
    return 0;
}

