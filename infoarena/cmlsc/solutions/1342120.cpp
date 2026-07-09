#include <iostream>
#include <fstream>

using namespace std;

int n, m, v[1025], u[1025], w[1025][1025], k = 0;

int main() 
{
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");

	fin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		fin >> v[i];
	}
	for (int j = 1; j <= m; ++j) {
		fin >> u[j];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (v[i] == u[j]) {
				w[i][j] = w[i - 1][j - 1] + 1;
			} else {
				w[i][j] = w[i - 1][j] > w[i][j - 1] ? w[i - 1][j] : w[i][j - 1];
			}
		}
	}

	int i = n, j = m;
	while ((i > 0) && (j > 0)) {
		if (w[i][j] == w[i - 1][j - 1] + 1) {
			u[++k] = v[i];
			--i;
			--j;
		} else if (w[i - 1][j] < w[i][j - 1]) {
			--j;
		} else {
			--i;
		}
	}

	fout << k << "\n";
	for (int i = k; i > 0; --i) {
		fout << u[i] << " ";
	}

	return 0;
}