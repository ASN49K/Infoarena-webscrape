#include <cstdio>

#define MAXN 1030

int N, M;
int v[MAXN], u[MAXN];
int A[MAXN][MAXN];

void ReadData() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%d", v+i);
	for (int i = 0; i < M; ++i)
		scanf("%d", u+i);
}

inline int max(int a, int b) { return (a > b ? a : b); }

void Solve() {
	for (int i = N-1 ; i >= 0; --i)
		for (int j = M-1; j >= 0; --j)
			if (v[i] == u[j])
				A[i][j] = A[i+1][j+1] + 1;
			else
				A[i][j] = max(A[i+1][j], A[i][j+1]);
}

void WriteData() {
	printf("%d\n", A[0][0]);
	int i = 0, j = 0;
	while (i < N && j < M)
		if (v[i] == u[j]) {
			printf("%d ", v[i]);
			++i, ++j;
		}
		else
			if (A[i+1][j] > A[i][j+1])
				++i;
			else
				++j;
}

int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	ReadData();
	Solve();
	WriteData();
}