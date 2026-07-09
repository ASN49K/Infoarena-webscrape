#include<iostream>
#include<fstream>
using namespace std;

int** build_matrix(int rows, int cols) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new int[cols];
	}
	return matrix;
}

int main() {
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	int m, n, i, j, s = 0, p = 1;
	fin >> m >> n;
	int* v1 = new int[1025];
	int* v2 = new int[1025];
	int **a = build_matrix(1025, 1025);
	int* c = new int[1025];


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
	for (j = 2; j <= n + 1; j++) {
		for (i = 2; i <= m + 1; i++) {
			if (v1[i-1] == v2[j-1]) {
				a[i][j] = a[i - 1][j - 1] + 1;
				s++;
				c[p] = v1[i-1];
				p++;
			}
			else {
				a[i][j] = max(a[i - 1][j], a[i][j - 1]);
			}
		}
	}
	fout << s << '\n';
	for (i = 1; i <= p-1; i++) {
		fout << c[i] << " ";
	}
	return 0;

}