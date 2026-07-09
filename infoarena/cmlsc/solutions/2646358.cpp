#include <cstdio>

using namespace std;

int max(int a, int b) {
	return a > b ? a:b;
}


int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);


	int n, m;
	scanf("%d%d", &n, &m);
	char a[n+1], b[m+1];
	short cmlsc[n+1][m+1];
	for(int i=0; i<=n; ++i)
		for(int j=0; j<=m; ++j)
			cmlsc[i][j] = 0;

	for(int i=1; i<=n; ++i)
		scanf("%d", &a[i]);
	for(int j=1; j<=m; ++j)
		scanf("%d", &b[j]);

	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if (a[i] == b[j])
				cmlsc[i][j] = max(max(cmlsc[i-1][j], cmlsc[i][j-1]), cmlsc[i-1][j-1] + 1);
			else
				cmlsc[i][j] = max(cmlsc[i-1][j], cmlsc[i][j-1]);

	printf("%d\n", cmlsc[n][m]);
	int currentj = m, currenti = n, i=0;
	char sol[cmlsc[n][m]];

	while(currenti && currentj && i<cmlsc[n][m]) {
		if (a[currenti] == b[currentj] && cmlsc[currenti][currentj] == cmlsc[currenti-1][currentj-1] + 1) {
			sol[i] = a[currenti];
			++i;

			--currenti;
			--currentj;
		} else {
			if (cmlsc[currenti][currentj] == cmlsc[currenti - 1][currentj])
				--currenti;
			else
				--currentj;
		}
	}

	for(i=cmlsc[n][m] - 1; i>=0; --i)
		printf("%d ", sol[i]);

	return 0;
}
