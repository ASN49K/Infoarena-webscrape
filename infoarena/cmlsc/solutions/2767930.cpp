#include <iostream>
#include <fstream>
#include <vector>

#define NMAX 1025

using namespace std;

fstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int m, n, A[NMAX], B[NMAX], D[NMAX][NMAX], sir[NMAX], cnt;

int main() {

	fin >> m >> n;
	for (int i = 1; i <= m; i++) {
		fin >> A[i];
	}

	for (int i = 1; i <= n; i++) {
		fin >> B[i];
	}

	for (int i = 1; i < m+1; i++) {
		for (int j = 1; j < n+1; j++) {
			if (A[i] == B[j]) {
				D[i][j] = D[i - 1][j - 1] + 1;
			}
			else {
				D[i][j] = max(D[i - 1][j], D[i][j - 1]);
			}
		}
	}

	int i = m;
	int j = n;

	cout << i << ' ' << j;
	while (i > 0 && j > 0) {
		if (A[i] == B[j]) {
			sir[++cnt] = A[i];
			i--;
			j--;
		}
		else if (D[i - 1][j] < D[i][j - 1]) {
			j--;
		}
		else {
			i--;
		}
	}

	fout << cnt << '\n';
	for (int i = cnt; i > 0; i--) {
		fout << sir[i] << ' ';
	}

	return 0;
}