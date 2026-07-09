#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	int m, n, i, j, s = 0, p = 1;
	fin >> m >> n;
	const int x = 1024;
	int v1[x], v2[x], a[x + 1][x + 1], c[x];
	while (!fin.eof()) {
		for (i = 1; i <= m; i++) {
			fin >> v1[i];
		}
		for (i = 1; i <= n; i++) {
			fin >> v2[i];
		}
	}
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			a[1][j] = 0;
			a[i][1] = 0;
		}
	}
	for (j = 2; j <= n+1; j++) {
		for (i = 2; i <= m+1; i++) {
			if (v1[i] == v2[j]) {
				a[i][j] = a[i - 1][j - 1] + 1;
				s++;
				c[p] = v1[i];
				p++;
			}
			else {
				a[i][j] = max(a[i - 1][j], a[i][j - 1]);
			}
		}
	}
	fout << s << '\n';
	for (i = 1; i <= p; i++) {
		fout << c[i] << " ";
	}
	return 0;

}