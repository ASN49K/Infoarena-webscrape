#include <cstring>
#include <cstdio>
#include <cmath>

int a[1025];
int b[1025];
int c[1025];
int n, m, p;

struct Spot {
	int x, y;
	int k;
};

Spot spot[1025][1025];

int main() {
	FILE * in = fopen("cmlsc.in", "rt");
	FILE * out = fopen("cmlsc.out", "wt");

	fscanf(in, "%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		fscanf(in, "%d", &a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		fscanf(in, "%d", &b[i]);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				spot[i][j].k = spot[i - 1][j - 1].k + 1;
				spot[i][j].x = i;
				spot[i][j].y = j;
			} else {
				if (spot[i - 1][j].k > spot[i][j - 1].k) {
					spot[i][j] = spot[i - 1][j];
				} else {
					spot[i][j] = spot[i][j - 1];
				}
			}
		}
	}

	int x = n;
	int y = m;

	while (x && y) {
		if (a[x] == b[y]) {
			c[p++] = a[x];
			--x;
			--y;
		} else {
			Spot t = spot[x][y];
			x = t.x;
			y = t.y;
		}
	}

	fprintf(out, "%d\n", p);
	for (int i = p - 1; i >= 0; --i) {
		fprintf(out, "%d ", c[i]);
	}

	fclose(in);
	fclose(out);
}
