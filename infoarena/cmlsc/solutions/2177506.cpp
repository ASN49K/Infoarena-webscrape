#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N, M, lsol, A[1030], B[1030], sol[1030], best[1030][1030];

inline int _max(int a, int b) {
	return (a > b ? a : b);
}

int main() {
	fin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		fin >> A[i];
	}
	for (int j = 1; j <= M; ++j) {
		fin >> B[j];
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (A[i] == B[j]) {
				best[i][j] = 1 + best[i - 1][j - 1];
			}
			else {
				best[i][j] = _max(best[i][j - 1], best[i - 1][j]);
			}
		}
	}

	int i = N, j = M;
	while (i) {
		if (A[i] == B[j]) {
			sol[++lsol] = A[i];
			--i;
			--j;
		}
		else {
			if (best[i - 1][j] < best[i][j - 1]) {
				--j;
			}
			else {
				--i;
			}
		}
	}

	fout << lsol << '\n';
	for (int i = lsol; i; --i) {
		fout << sol[i] << ' ';
	}

	fout.close();
	return 0;

}
