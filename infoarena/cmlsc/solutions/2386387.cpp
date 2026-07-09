#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main() {
	short m, n, *v, **s;
	fin >> m >> n;
	v = new short[m + 1];
	s = new short*[n + 1];
	s[0] = new short[m + 1];
	s[0][0] = 0;
	for (short i = 1; i <= m; ++i) {
		fin >> v[i];
		s[0][i] = 0;
	}
	for (short i = 1; i <= n; ++i) {
		fin >> v[0];
		s[i] = new short[m + 1];
		s[i][0] = 0;
		for (short j = 1; j <= m; ++j) {
			if (v[0] == v[j]) {
				s[i][j] = s[i - 1][j - 1] + 1;
			}
			else {
				s[i][j] = max(s[i - 1][j], s[i][j - 1]);
			}
		}
	}
	short l = s[n][m], *u = new short[l];
	for (short i = n, j = m; i > 0; --j) {
		if (s[i][j] == s[i - 1][j - 1] + 1) {
			u[--l] = v[j];
			--i;
		}
	}
	l = s[n][m];
	for (short i = 0; i < l; ++i) {
		fout << u[i] << " ";
	}
}