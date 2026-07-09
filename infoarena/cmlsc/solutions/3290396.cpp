#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

const int nmax = 1 << 10;
int N, M, K;
unsigned char a[nmax + 1], b[nmax + 1], c[nmax + 1];
short dp[nmax + 1][nmax + 1];

void readInput() {
	FILE* f = fopen("cmlsc.in", "r");
	fscanf(f, "%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		fscanf(f, "%d", &a[i]);
	}
	for (int i = 1; i <= M; ++i) {
		fscanf(f, "%d", &b[i]);
	}
}

inline int max(short a, short b) {
	return a > b ? a : b;
}

void solve() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	K = dp[N][M];
	for (int i = N, j = M, k = K; k > 0;) {
		if (a[i] == b[j]) {
			c[k--] = a[i];
			--i, --j;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) {
			--i;
		}
		else {
			--j;
		}
	}
}

void writeOutput() {
	FILE* f = fopen("cmlsc.out", "w");
	fprintf(f, "%d\n", K);
	for (int i = 1; i <= K; ++i) {
		fprintf(f, "%d ", c[i]);
	}
}

int main() {
	readInput();
	solve();
	writeOutput();
}