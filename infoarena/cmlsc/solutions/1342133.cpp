#include <iostream>
#include <fstream>

using namespace std;

#define MAX_N							1025

int n, m, v[MAX_N], u[MAX_N], w[MAX_N][MAX_N], sir[MAX_N], k = 0;

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

	for (int i = n, j = m; i > 0; ) {
		if (v[i] == u[j]) {
			sir[++k] = v[i];
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
		fout << sir[i] << " ";
	}
	fout << "\n";

	return 0;
}