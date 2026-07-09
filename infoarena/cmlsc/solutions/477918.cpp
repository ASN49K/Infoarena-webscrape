#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define NMAX 1030
int x[NMAX], y[NMAX], a[NMAX][NMAX];

void show(int i, int j) {
	if (i > 0 && j > 0) {
		if (a[i][j] == a[i-1][j-1]+1 && x[i] == y[j]) { 
			show(i-1, j-1);
			printf("%d ", x[i]);
		} else if (a[i][j] == a[i-1][j])
			show(i-1, j);
		else
			show(i, j-1);
	}
}

int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	int M, N;
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= M; i++) scanf("%d", &x[i]);
	for (int i = 1; i <= N; i++) scanf("%d", &y[i]);
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++) {
			a[i][j] = max(a[i-1][j], a[i][j-1]);
			a[i][j] = max(a[i][j], a[i-1][j-1] + (x[i] == y[j] ? 1 : 0));
		}

	printf("%d\n", a[M][N]);
	show(M, N);
	printf("\n");
	return 0;
}
