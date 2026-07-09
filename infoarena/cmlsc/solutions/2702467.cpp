#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <queue>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1024], b[1024], d[1024][1024];

struct top {
	int size = 0, v[1024];
};

top* rez = new top;
top* add = new top;

int main() {
	int ans = 0, k = 0;
	fin >> n >> m;
	for (int i = 1; i <= n; ++i)
		fin >> a[i];
	for (int i = 1; i <= m; ++i)
		fin >> b[i];

	for (int i = 1; i <= n; ++i) {

		for (int j = 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				add->size += 2;
				add->v[++k] = a[i];
				d[i][j] = d[i - 1][j - 1] + 2;
			}

			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]) - 1;
			ans = max(ans, d[i][j]);
		}

		if (ans > rez->size) rez = add;
	}

	fout << ans << "\n";

	for (int i = 1; i <= ans; i++)
		fout << rez->v[i] << " ";
}